/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouakrad <ouakrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:25:41 by ouakrad           #+#    #+#             */
/*   Updated: 2023/10/14 23:12:11 by ouakrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	size_t	start_pos;
	size_t	found_pos;

	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];
	std::ifstream input_file(filename);
	if (!input_file)
	{
		std::cerr << "Error: Unable to open input file." << std::endl;
		return (1);
	}
	std::ofstream output_file(filename + ".replace");
	if (!output_file)
	{
		std::cerr << "Error: Unable to create output file." << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(input_file, line))
	{
		std::string replaced_line;
		start_pos = 0;
		while (true)
		{
			found_pos = line.find(s1, start_pos);
			if (found_pos == std::string::npos)
			{
				replaced_line += line.substr(start_pos);
				break ;
			}
			replaced_line += line.substr(start_pos, found_pos - start_pos);
			replaced_line += s2;
			start_pos = found_pos + s1.length();
		}
		output_file << replaced_line << std::endl;
	}
	std::cout << "Done." << std::endl;
	return (0);
}
