#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <deque>
#include <vector>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void run(int argc, char **argv);

private:
	std::vector<int> _vec;
	std::deque<int>  _deq;

	void parseInput(int argc, char **argv);

	static void sortVec(std::vector<int> &v);
	static void sortDeq(std::deque<int> &d);

	static std::vector<size_t> jacobsthalOrder(size_t n);
	static void                insertVec(std::vector<int> &chain, int val, size_t upper);
	static void                insertDeq(std::deque<int> &chain, int val, size_t upper);
};

#endif
