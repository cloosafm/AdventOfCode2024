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
	int distance = 0;
	if (set_left.size() == set_right.size()) {
		std::multiset<int>::iterator it_left = set_left.begin();
		std::multiset<int>::iterator it_right = set_right.begin();
		while (it_left != set_left.end() && it_right != set_right.end()) {
			distance += std::abs(*it_right - *it_left);
			++it_left;
			++it_right;
		}
	std::cout << "Distance: " << distance << std::endl;
	} else {
		std::cerr << "Sets are not equal" << std::endl;
	}

	return 0;
}

