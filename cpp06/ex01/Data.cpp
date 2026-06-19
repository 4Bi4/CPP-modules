#include "Data.hpp"

Data::Data() : value(0), name(""), score(0.0) {}

Data::Data(const Data &other) : value(other.value), name(other.name), score(other.score) {}

Data &Data::operator=(const Data &other)
{
	if (this == &other)
		return (*this);
	value = other.value;
	name  = other.name;
	score = other.score;
	return (*this);
}

Data::~Data() {}
