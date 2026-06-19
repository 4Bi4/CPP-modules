#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
	int			value;
	double		score;
	std::string	name;

	Data();
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();
};

#endif
