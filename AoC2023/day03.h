#pragma once
#include "MainAoC.h"
class day03
{
public:
	static void part1();
	static void part2();

private : 
	static int GetFullNumber(int index, std::string line);
	static bool IsAdjacentToASymbol(std::vector<std::string> input, int x, int y, int lenght);
	static std::vector <std::tuple<int, int>> IsAdjacentToAGear(std::vector<std::string> input, int x, int y, int lenght);
};

