#pragma once
#include "MainAoC.h"

class day01
{
public:
	static void part1();
	static void part2();
private :
	static int GetSpelledNumber(std::string input);
	static int TryGetSpelledNumber(std::string line,int index, int sens);
};

