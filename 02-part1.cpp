#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

int check_level(const std::list<int>& levels) {
    std::cout << "Checking levels: ";
    for (const int& level : levels) {
        std::cout << level << " ";
    }
    std::cout << std::endl;


	std::list<int>::const_iterator it = levels.begin();
	std::list<int>::const_iterator it_next = std::next(it);
	if (*it > *it_next) {
		std::cout << "	decrease" << std::endl;
		while (it_next != levels.end()) {
			++it;
			++it_next;
			if (*it >= *it_next) {
				std::cout << "	unsafe" << std::endl;
				return 0;;
			}
		}
	}
	if (*it < *it_next) {
		std::cout << "	increase" << std::endl;
		while (it_next != levels.end()) {
			++it;
			++it_next;
			if (*it <= *it_next) {
				std::cout << "	unsafe" << std::endl;
				return 0;;
			}
		}
	}
	if (*it == *it_next) {
		std::cout << "	same" << std::endl;
		return 0;
	}

	std::cout << "	safe" << std::endl;


    return levels.size();
}


int main() {
	int safe_lvls = 0;
	std::list<int> levels;
	std::ifstream puzzle_input("input_test");
	// std::ifstream puzzle_input("input_puzzle");
	std::string line;
	if (puzzle_input.is_open()) {
		while (getline(puzzle_input, line)) {
			levels.clear();
			std::istringstream iss(line);
            int number;
            while (iss >> number) {
                levels.push_back(number);
            }
			safe_lvls = check_level(levels);
		}

		puzzle_input.close();
	} else {
		std::cerr << "Unable to open file";
	}
	// int distance = 0;
	// if (set_left.size() == set_right.size()) {
	// 	std::multiset<int>::iterator it_left = set_left.begin();
	// 	std::multiset<int>::iterator it_right = set_right.begin();
	// 	while (it_left != set_left.end() && it_right != set_right.end()) {
	// 		distance += std::abs(*it_right - *it_left);
	// 		++it_left;
	// 		++it_right;
	// 	}
	// std::cout << "Distance: " << distance << std::endl;
	// } else {
	// 	std::cerr << "Sets are not equal" << std::endl;
	// }

	return 0;
}


