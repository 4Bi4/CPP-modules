/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 22:02:59 by labia-fe          #+#    #+#             */
/*   Updated: 2026/03/02 19:08:37 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	// Input check
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0]
		<< " <filename> <find> <replace>"
		<< std::endl;
		return (1);
	}
	
	// Open infile
	std::ifstream infile(argv[1]);
	if (!infile)
	{
		std::cerr << "Error: Could not open file "
		<< argv[1] << std::endl;
		return (1);
	}
	
	// Create outfile
	std::string outfilename = std::string(argv[1]) + ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile)
	{
		std::cerr << "Error: Could not create file "
		<< outfilename << std::endl;
		return (1);
	}

	// Assign s1 and s2 to std::string
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	// Read file contents
	std::string line;
	std::string content;
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += '\n';
	}
	
	// Replace file contents
	size_t i = 0;
	while ((i = content.find(argv[2], i)) != std::string::npos)
	{
		content.erase(i, s1.length());
		content.insert(i, s2);
		i += s2.length();
	}
	outfile << content;
	return (0);
}
