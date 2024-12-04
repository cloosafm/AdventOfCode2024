#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

int check_level(const std::list<int>& levels) {
	std::list<int>::const_iterator it = levels.begin();
	std::list<int>::const_iterator it_next = std::next(it);
	if (*it > *it_next) {
		while (it_next != levels.end()) {
			if (*it <= *it_next) {
				return 0;
			}
			if (abs(*it - *it_next) > 3) {
				return 0;
			}
			++it;
			++it_next;
		}
	}
	if (*it < *it_next) {
		while (it_next != levels.end()) {
			if (*it >= *it_next) {
				return 0;;
			}
			if (abs(*it - *it_next) > 3) {
				return 0;
			}
			++it;
			++it_next;
		}
	}
	if (*it == *it_next) {
		return 0;
	}
	return 1;
}


int main() {
	int safe_lvls = 0;
	std::list<int> levels;
	// std::ifstream puzzle_input("input_test");
	std::ifstream puzzle_input("input_puzzle");
	std::string line;
	if (puzzle_input.is_open()) {
		while (getline(puzzle_input, line)) {
			levels.clear();
			std::istringstream iss(line);
			int number;
			while (iss >> number) {
				levels.push_back(number);
			}
			safe_lvls += check_level(levels);
		}

		puzzle_input.close();
	} else {
		std::cerr << "Unable to open file";
	}
	std::cout << "Safe levels: " << safe_lvls << std::endl;
	return 0;
}


