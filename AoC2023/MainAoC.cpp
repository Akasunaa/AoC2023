#include "MainAoC.h"
#include "day01.h"
#include "day02.h"
#include "day03.h"

using namespace std;

const char* const cookie = "53616c7465645f5ff61f8871a115473198961b16eaa316a2ad880ce1a5b23ecee19b142aa06a32213d1743006ccddf898362691809ff591ed50c178c8542479c";


//"53616c7465645f5f58d47c724ef9d2523cb628b6f5aaf7ed9b3fb5b0019a53ec316b2c1d071f7bad6243844e82c2b107bcc8e5dfdf7bfd6e149eedc809dc99c7";




int main() {
	day03::part2();
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
