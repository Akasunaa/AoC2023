#include "day01.h"


void day01::part1()
{
	std::vector<std::string> input = MainAoC::GetDayInput('1');

	int sum = 0;
	for (int i=0; i < input.size(); i++) {
		int first = 0;
		int second = 0;
		for (auto value :input[i]) {
			if (isdigit(value)) {
				first = (value - '0') * 10;
				break;
			}
		}
		for (int l = input[i].length()-1; l >= 0; l--) {
			if (isdigit(input[i][l])) {
				second = input[i][l] - '0';
					break;			
			}
		}
		sum += first + second;
	}
	std::cout << sum;
}

void day01::part2()
{
	//std::vector<std::string> input = { "","eightwothree","abcone2threexyz","xtwone3four","4nineeightseven2","zoneight234","7pqrstsixteen" };
	std::vector<std::string> input = MainAoC::GetDayInput('1');
	int sum = 0;
	for (auto const& line : input) {
		int first = 0;
		int second = 0;
		for (int i = 0; i < line.length();i++) {
			if (isdigit(line[i])) {
				first = (line[i] - '0') * 10;
				break;
			}
			else {
				int value = TryGetSpelledNumber(line, i, 1);
				if (value != -1) {
					first = value*10;
					break;
				}
			}
		}
		for (int l = line.length() - 1; l >= 0; l--) {
			if (isdigit(line[l])) {
				second = line[l] - '0';
				break;
			}
			else {
				int value = TryGetSpelledNumber(line, l, -1);
				if (value != -1) {
					second = value;
					break;
				}
			}
		}
		sum += first + second;
	}
	std::cout << sum;
}

int day01::GetSpelledNumber(std::string input) {
	std::map<std::string, int> SpelledNumber= { {"one", 1},{"two", 2},{"three", 3},{"four", 4},{"five", 5},{"six", 6},{"seven", 7},{"eight", 8},{"nine", 9} };
	for (auto const& number : SpelledNumber) {
		if(input.find(number.first) != std::string::npos) {
			return number.second;
		}
	}
	return -1;
}

int day01::TryGetSpelledNumber(std::string line, int index, int sens)
{
	int spellednumber = -1;
	for (int i = 3; i < 6; i++) {
		if (sens == 1) {
			if (index+i-2 < line.length() && isdigit(line[index + i - 2])) return (line[index + i - 2] - '0');
			if (index + i <= line.length()) spellednumber = GetSpelledNumber(line.substr(index, i));
			if (spellednumber != -1) return spellednumber;
		}
		else{
			if (index-i+2 < line.length() && isdigit(line[index - i + 2])) return (line[index - i + 2] - '0');
			if (index>=i-1) spellednumber = GetSpelledNumber(line.substr(index-i+1, i));
			if (spellednumber != -1) return spellednumber;
		}
	}
	return spellednumber;
}

