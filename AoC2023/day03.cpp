#include "day03.h"

void day03::part1()
{
	std::vector<std::string> input = MainAoC::GetDayInput('3');
	/*std::vector<std::string> input = {
	"467..114..",
	"...*......",
	"..35..633.",
	"......#...",
	"617*......",
	".....+.58.",
	"..592.....",
	"......755.",
	"...$.*....",
	".664.598.." };*/
	int sum = 0;
	int number = 0;
	int numberLenght = 0;
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].length(); j++) {
			if (isdigit(input[i][j])) {
				number = GetFullNumber(j, input[i]);
				numberLenght = std::to_string(number).length();
				if (IsAdjacentToASymbol(input,i,j,numberLenght)) sum += number;
				j += numberLenght;
			}
		}
	}
	std::cout << sum;
}

void day03::part2()
{
	std::vector<std::string> input = MainAoC::GetDayInput('3');
	/*std::vector<std::string> input = {
	"467..114..",
	"...*......",
	"..35..633.",
	"......#...",
	"617.......",
	".....+.58.",
	"..592.....",
	"......755.",
	"...$.*....",
	".664.598.." };*/
	std::map<std::string, std::vector<int>> gearMap;

	int sum = 0;
	int number = 0;
	int numberLenght = 0;
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].length(); j++) {
			if (isdigit(input[i][j])) {
				number = GetFullNumber(j, input[i]);
				numberLenght = std::to_string(number).length();
				std::vector<std::tuple<int, int>> gearsCoord = IsAdjacentToAGear(input, i, j, numberLenght);
				if (!gearsCoord.empty()) {
					for (auto gearCoord : gearsCoord) {
						if (std::get<0>(gearCoord) != -1) {
							std::string gearName = std::to_string(std::get<0>(gearCoord)) +"," + std::to_string(std::get<1>(gearCoord));
							if (gearMap.count(gearName) == 0) {
								std::vector<int> numbers;
								numbers.push_back(number);
								gearMap.insert({gearName, numbers});
							}
							else {
								gearMap[gearName].push_back(number);
							}
						}
					}			
				}		
				j+= numberLenght;
			}
		}
	}
	for (auto const& gear : gearMap)
	{
		if (gear.second.size() == 2) {
			sum += gear.second[0] * gear.second[1];
		}
	}
	std::cout << sum;
}

int day03::GetFullNumber(int startIndex, std::string line) {
	int currentIndex = startIndex;
	while (currentIndex<line.length() && isdigit(line[currentIndex])) { 
		currentIndex++;
	}
	return stoi(line.substr(startIndex, currentIndex));
};

bool day03::IsAdjacentToASymbol(std::vector<std::string> input,int x, int y, int lenght) {
	for (int i = x-1; i <= x+1; i++) {
		for (int j = y - 1; j <= y + lenght; j++) {
			if (i >= 0 && i < input.size() - 1 && j >= 0 && j < input[0].length() && input[i][j] != '.' && !isdigit(input[i][j])) return true;	
		}
	}
	return false;
}

std::vector <std::tuple<int, int>> day03::IsAdjacentToAGear(std::vector<std::string> input, int x, int y, int lenght) {
	std::vector <std::tuple<int, int>> gears;
	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + lenght; j++) {
			if (i >= 0 && i < input.size() - 1 && j >= 0 && j < input[0].length() && input[i][j] == '*') {
				gears.push_back(std::make_tuple(i, j));
			}
		}
	}
	return gears;
}