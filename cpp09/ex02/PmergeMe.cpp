#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this == &other)
		return (*this);
	_vec = other._vec;
	_deq = other._deq;
	return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		char *end;
		errno     = 0;
		long  val = std::strtol(argv[i], &end, 10);
		if (*end != '\0' || errno == ERANGE || val <= 0 || val > INT_MAX)
			throw std::runtime_error(std::string("Error: invalid argument: ") + argv[i]);
		_vec.push_back(static_cast<int>(val));
		_deq.push_back(static_cast<int>(val));
	}
}

//	Jacobsthal-based insertion order

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
	std::vector<size_t> order;
	if (n == 0)
		return (order);

	order.push_back(0);
	if (n == 1)
		return (order);

	size_t t_prev = 1, t_curr = 3;
	while (true)
	{
		size_t from = (t_curr - 1 < n) ? t_curr - 1 : n - 1;
		for (size_t i = from; ; --i)
		{
			order.push_back(i);
			if (i == t_prev)
				break;
		}
		if (t_curr >= n)
			break;
		size_t next = t_curr + 2 * t_prev;
		t_prev      = t_curr;
		t_curr      = next;
	}
	return (order);
}

//	Binary insert helpers

void PmergeMe::insertVec(std::vector<int> &chain, int val, size_t upper)
{
	std::vector<int>::iterator pos =
		std::lower_bound(chain.begin(), chain.begin() + static_cast<std::ptrdiff_t>(upper), val);
	chain.insert(pos, val);
}

void PmergeMe::insertDeq(std::deque<int> &chain, int val, size_t upper)
{
	std::deque<int>::iterator pos =
		std::lower_bound(chain.begin(), chain.begin() + static_cast<std::ptrdiff_t>(upper), val);
	chain.insert(pos, val);
}

//	Ford-Johnson forvector

void PmergeMe::sortVec(std::vector<int> &v)
{
	size_t n = v.size();
	if (n <= 1)
		return ;

	bool odd;
	int  straggler;

	if (n % 2 == 1)
		odd = true;
	else
		odd = false;

	if (odd)
		straggler = v[n - 1];
	else
		straggler = 0;

	//	Pair up elements, larger first
	std::vector<std::pair<int, int> > pairs;
	size_t pairEnd = n - (odd ? 1 : 0);
	for (size_t i = 0; i + 1 < pairEnd; i += 2)
	{
		if (v[i] >= v[i + 1])
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
		else
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
	}

	//	Recursively sort the larger elements
	std::vector<int> largers;
	largers.reserve(pairs.size());
	for (size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].first);
	sortVec(largers);

	//	Reorder pairs to match sorted largers (stable, handles duplicates)
	std::vector<std::pair<int, int> > sorted;
	sorted.reserve(pairs.size());
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < largers.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].first == largers[i])
			{
				sorted.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	//	Build main chain — b1, a1, a2, ...
	std::vector<int> chain;
	chain.reserve(n);
	chain.push_back(sorted[0].second);
	for (size_t i = 0; i < sorted.size(); ++i)
		chain.push_back(sorted[i].first);

	//	Collect pending smallers (b2, b3, ...) and straggler
	std::vector<int> pending;
	for (size_t i = 1; i < sorted.size(); ++i)
		pending.push_back(sorted[i].second);
	if (odd)
		pending.push_back(straggler);

	//	Insert pending in Jacobsthal order with upper-bound restriction
	std::vector<size_t> order = jacobsthalOrder(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t idx = order[i];
		int    val = pending[idx];

		size_t upper;
		if (idx + 1 < sorted.size())
		{
			int pairedLarger = sorted[idx + 1].first;
			upper = chain.size();
			for (size_t j = 0; j < chain.size(); ++j)
			{
				if (chain[j] == pairedLarger)
				{
					upper = j;
					break;
				}
			}
		}
		else
			upper = chain.size();

		insertVec(chain, val, upper);
	}

	v = chain;
}

//	Ford-Johnson for deque

void PmergeMe::sortDeq(std::deque<int> &d)
{
	size_t n = d.size();
	if (n <= 1)
		return ;

	bool odd       = (n % 2 == 1);
	int  straggler = odd ? d[n - 1] : 0;

	//	Pair up elements, larger first
	std::deque<std::pair<int, int> > pairs;
	size_t pairEnd = n - (odd ? 1 : 0);
	for (size_t i = 0; i + 1 < pairEnd; i += 2)
	{
		if (d[i] >= d[i + 1])
			pairs.push_back(std::make_pair(d[i], d[i + 1]));
		else
			pairs.push_back(std::make_pair(d[i + 1], d[i]));
	}

	//	Recursively sort the larger elements
	std::deque<int> largers;
	for (size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].first);
	sortDeq(largers);

	//	Reorder pairs to match sorted largers
	std::deque<std::pair<int, int> > sorted;
	std::vector<bool>                used(pairs.size(), false);
	for (size_t i = 0; i < largers.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].first == largers[i])
			{
				sorted.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	//	Build main chain — b1, a1, a2, ..., ak
	std::deque<int> chain;
	chain.push_back(sorted[0].second);
	for (size_t i = 0; i < sorted.size(); ++i)
		chain.push_back(sorted[i].first);

	//	Collect pending smallers and straggler
	std::deque<int> pending;
	for (size_t i = 1; i < sorted.size(); ++i)
		pending.push_back(sorted[i].second);
	if (odd)
		pending.push_back(straggler);

	//	Insert pending in Jacobsthal order with upper-bound restriction
	std::vector<size_t> order = jacobsthalOrder(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		size_t idx = order[i];
		int    val = pending[idx];

		size_t upper;
		if (idx + 1 < sorted.size())
		{
			int pairedLarger = sorted[idx + 1].first;
			upper = chain.size();
			for (size_t j = 0; j < chain.size(); ++j)
			{
				if (chain[j] == pairedLarger)
				{
					upper = j;
					break;
				}
			}
		}
		else
			upper = chain.size();

		insertDeq(chain, val, upper);
	}

	d = chain;
}

void PmergeMe::run(int argc, char **argv)
{
	parseInput(argc, argv);

	std::cout << "Before: ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		if (i) std::cout << " ";
		std::cout << _vec[i];
	}
	std::cout << std::endl;

	//	Sort with vector and time it
	std::vector<int> vecCopy(_vec);
	clock_t          startVec = clock();
	sortVec(vecCopy);
	clock_t          endVec   = clock();
	double           timeVec  =
		static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;

	//	Sort with deque and time it
	std::deque<int> deqCopy(_deq);
	clock_t         startDeq = clock();
	sortDeq(deqCopy);
	clock_t         endDeq   = clock();
	double          timeDeq  =
		static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

	//	Print after (use vector result)
	std::cout << "After:  ";
	for (size_t i = 0; i < vecCopy.size(); ++i)
	{
		if (i) std::cout << " ";
		std::cout << vecCopy[i];
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vecCopy.size()
			  << " elements with std::vector : "
			  << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deqCopy.size()
			  << " elements with std::deque  : "
			  << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}
