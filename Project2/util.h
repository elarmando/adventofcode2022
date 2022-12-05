#pragma once
#include <sstream>
#include <string>

int parse(const std::string& line)
{
	int num = 0;
	std::istringstream s(line);

	s >> num;
	return num;
}

