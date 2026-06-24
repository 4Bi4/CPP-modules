#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int n);
	int  shortestSpan() const;
	int  longestSpan() const;

	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end)
	{
		for (Iterator it = begin; it != end; ++it)
			addNumber(*it);
	}

	class SpanFullException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	unsigned int     _maxSize;
	std::vector<int> _data;
};

#endif
