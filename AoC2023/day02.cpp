#include "day02.h"

void day02::part1()
{
	std::vector<std::string> input = MainAoC::GetDayInput('2');

	const int blueLimit = 14;
	const int redLimit = 12;
	const int greenLimit = 13;
	int sum = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i].find("Game")!= std::string::npos && IsColorCorrect(input[i], "red", redLimit) && IsColorCorrect(input[i], "blue", blueLimit) && IsColorCorrect(input[i], "green", greenLimit)) sum += i+1;
	}
	std::cout << sum;
}

void day02::part2()
{
	std::vector<std::string> input = MainAoC::GetDayInput('2');
	int sum = 0;
	for (int i = 0; i < input.size(); i++) {
		sum += MaxColor(input[i], "red") * MaxColor(input[i], "blue") * MaxColor(input[i], "green");
	};
	std::cout << sum;
}

bool day02::IsColorCorrect(std::string game, std::string color, int limit)
{
	std::string::size_type pos = 0; 
	std::string::size_type numberPos = 0;
	while ((pos = game.find(color)) != std::string::npos) {
		game.replace(pos, 1, "/");
		numberPos = game.substr(0, pos-1).find_last_of(" ")+1;
		if (stoi(game.substr(numberPos, pos - numberPos)) > limit) return false;
	}
	return true;
}

int day02::MaxColor(std::string game, std::string color)
{
	int max = 0;
	int currentNumber = 0;
	std::string::size_type pos = 0;
	std::string::size_type numberPos = 0;
	while ((pos = game.find(color)) != std::string::npos) {
		game.replace(pos, 1, "/");
		numberPos = game.substr(0, pos - 1).find_last_of(" ") + 1;
		currentNumber = stoi(game.substr(numberPos, pos - numberPos));
		if (currentNumber > max) max = currentNumber;
	}
	return max;
}


