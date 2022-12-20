#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

int priority(char item)
{
	if ('a' <= item && item <= 'z')
		return item - 96;
	else if ('A' <= item && item <= 'Z')
		return item - 64 + 26;
		
	return 0;
}

void fillMap(const std::string &line, std::map<char, int>& map)
{
	for (auto i = 0; i < line.length(); i++)
	{
		char c = line[i];
		if (map.find(c) == map.end())
			map[c] = 1;
	}
}

void solve_3_2(const std::string& path)
{
	std::ifstream file(path);
	std::string line;
	int count = 1;
	std::map<char, int> group1;
	std::map<char, int> group2;
	int total = 0;

	while (std::getline(file, line))
	{
		if (count % 3 == 1)//line group 1
		{
			group1.clear();
			fillMap(line, group1);
		}
		else if (count % 3 == 2)//line group 2
		{
			group2.clear();
			fillMap(line, group2);
		}
		else if (count % 3 == 0)//line group 3
		{
			char repeated = ' ';

			for (auto i = 0; i < line.length(); i++)
			{
				char c = line[i];

				if (group1.find(c) != group1.end() &&
					group2.find(c) != group2.end())
				{
					repeated = c;
				}
			}
					
			std::cout << "repeated " << repeated << " priority "<< priority(repeated)<<std::endl;
			total += priority(repeated);
		}

		count++;
	}

	std::cout << "Total " << total << std::endl;
}

void solve_3(const std::string& path)
{
	std::ifstream file(path);
	std::string line;
	int sum = 0;

	while (std::getline(file, line))
	{
		std::map<char, int> items;
		int half = line.length() / 2;
		char repeated = ' ';

		for (auto i = 0; i < half; i++)
		{
			char c = line[i];
			if (items.find(c) == items.end())
				items[c] = 1;
		}

		for (auto i = half; i < line.length(); i++)
		{
			char c = line[i];
			if (items.find(c) != items.end())
				repeated = c;
		}

		int p = priority(repeated);
		std::cout << "repeated in " << line << " -> " << repeated << " cost: " <<p<< std::endl;
		sum += p;
	}

	std::cout << " suma " << sum << std::endl;
}