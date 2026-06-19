#include <iostream>
#include "Serializer.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << "  " << s << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
}

static void run(const std::string &label, Data &data)
{
	std::cout << "--- " << label << " ---" << std::endl;
	std::cout << "original  ptr : " << &data << std::endl;
	std::cout << "value         : " << data.value << std::endl;
	std::cout << "name          : " << data.name << std::endl;
	std::cout << "score         : " << data.score << std::endl;

	uintptr_t raw    = Serializer::serialize(&data);
	Data      *back  = Serializer::deserialize(raw);

	std::cout << "serialized    : " << raw << std::endl;
	std::cout << "deserialized  : " << back << std::endl;
	std::cout << "ptr match     : " << (back == &data ? "OK" : "KO") << std::endl;
	std::cout << "value match   : " << (back->value == data.value ? "OK" : "KO") << std::endl;
	std::cout << "name  match   : " << (back->name  == data.name  ? "OK" : "KO") << std::endl;
	std::cout << "score match   : " << (back->score == data.score ? "OK" : "KO") << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	title("TESTING BASIC SERIALIZATION");

	Data d1;
	d1.value = 42;
	d1.name  = "hello";
	d1.score = 9.81;
	run("standard data", d1);

	title("TESTING DIFFERENT VALUES");

	Data d2;
	d2.value = -100;
	d2.name  = "negative";
	d2.score = -3.14;
	run("negative values", d2);

	Data d3;
	d3.value = 0;
	d3.name  = "";
	d3.score = 0.0;
	run("zero / empty values", d3);

	title("TESTING EXTREME VALUES");

	Data d4;
	d4.value = 2147483647;
	d4.name  = "max int";
	d4.score = 1.7976931348623157e+308;
	run("INT_MAX + DBL_MAX", d4);

	Data d5;
	d5.value = -2147483648;
	d5.name  = "min int";
	d5.score = -1.7976931348623157e+308;
	run("INT_MIN + -DBL_MAX", d5);

	return (0);
}
