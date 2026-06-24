#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _data(other._data) {}

Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);
	_maxSize = other._maxSize;
	_data    = other._data;
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_data.size() >= _maxSize)
		throw SpanFullException();
	_data.push_back(n);
}

int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted(_data);
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 1; i + 1 < sorted.size(); ++i)
	{
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw NoSpanException();

	int minVal = *std::min_element(_data.begin(), _data.end());
	int maxVal = *std::max_element(_data.begin(), _data.end());
	return (maxVal - minVal);
}

const char *Span::SpanFullException::what() const throw()
{
	return ("Span is already full!");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Not enough elements to compute a span");
}
