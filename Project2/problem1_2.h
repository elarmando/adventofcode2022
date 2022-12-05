#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "util.h"

class Top3 {
private:
	int top1;
	int top2;
	int top3;

	void swap(int& n, int& n2)
	{
		int t = n;
		n = n2;
		n2 = t;
	}

public:
	Top3()
	{
		top1 = -1;
		top2 = -1;
		top3 = -1;
	}

	void save(int num)
	{
		if (num > top1)
		{
			swap(top2, top3);
			swap(top2, top1);
			top1 = num;
		}
		else if (num > top2)
		{
			swap(top2, top3);
			top2 = num;
		}
		else if (num > top3)
		{
			top3 = num;
		}

	}

	void show()
	{
		std::cout << "1)" << top1 << std::endl;
		std::cout << "2)" << top2 << std::endl;
		std::cout << "3)" << top3 << std::endl;
		std::cout << "Total " << top1 + top2 + top3 << std::endl;
	}
};


void solve_1_2(std::string file)
{
	std::ifstream ifile(file.c_str());
	std::string line;

	int biggest = -1;
	int sum = 0;
	Top3 top;

	while (std::getline(ifile, line))
	{
		if (line.size() == 0)//new elf
		{
			top.save(sum);
			sum = 0;
		}
		else
		{
			sum += parse(line);
		}
	}

	if (sum > 0)
		top.save(sum);

	top.show();
}


