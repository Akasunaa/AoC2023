#include "MainAoC.h"
#include "day01.h"

using namespace std;

const char* const cookie = "A";



int main() {
	day01::part1();
}

std::vector<std::string> MainAoC::GetDayInput(char day)
{
	FILE* fp;
	std::stringstream ss;
	ss << "curl https://adventofcode.com/2023/day/";
	ss << day;
	ss << "/input -H \"Cookie:session=";
	ss << cookie;
	fp = _popen(ss.str().c_str(), "r");
	if (fp == nullptr) {
		cout << "popen failed";
	}

	std::string result;
	char buffer[128];
	while (fgets(buffer, 128, fp) != nullptr) {
		result += buffer;
	}
	std::vector<std::string> resultVector;
	std::string::size_type pos = 0;
	std::string::size_type prev = 0;
	while ((pos = result.find('\n', prev)) != std::string::npos) {
		resultVector.push_back(result.substr(prev, pos - prev));
		prev = pos + 1;
	}
	resultVector.push_back(result.substr(prev));
	return resultVector;
}
