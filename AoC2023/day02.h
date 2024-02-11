#pragma once
#include "MainAoC.h"

class day02
{
public:
	static void part1();
	static void part2();
private:
	static bool IsColorCorrect(std::string game, std::string color, int limit);
	static int MaxColor(std::string game, std::string color);
};

