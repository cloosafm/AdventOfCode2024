#include <set>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <cmath>

int main() {
	std::multiset<int> set_left, set_right;
	std::ifstream puzzle_input("input_puzzle");
	std::string line;
	if (puzzle_input.is_open()) {
		while (getline(puzzle_input, line)) {
			std::istringstream iss(line);
			int number1, number2;
			iss >> number1 >> number2;
			set_left.insert(number1);
			set_right.insert(number2);
		}
		puzzle_input.close();
	} else {
		std::cerr << "Unable to open file";
	}

	int simil = 0;
	if (set_left.size() == set_right.size()) {
		std::multiset<int>::iterator it_left = set_left.begin();
		std::multiset<int>::iterator it_right = set_right.begin();
		while (it_left != set_left.end()) {
			int count_right = set_right.count(*it_left);
			simil += *it_left * count_right;
			++it_left;
		}
	std::cout << "Similarity score: " << simil << std::endl;
	} else {
		std::cerr << "Sets are not equal" << std::endl;
	}
}