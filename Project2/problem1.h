#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "util.h"


void solve_1(std::string file)
{
	std::ifstream ifile(file.c_str());
	std::string line;

	int biggest = -1;
	int sum = 0;

	while (std::getline(ifile, line))
	{
		if (line.size() == 0)//new elf
		{
			if (sum > biggest)
				biggest = sum;

			sum = 0;
		}
		else
		{
			sum += parse(line);
		}
	}

	if (sum > biggest)
		biggest = sum;

	std::cout << biggest<<std::endl;
}

