/* in the name of Allah */

#include <iostream>
#include "include_guard.hpp"

int main() {
	//(clipboard()).commit((include_guard().generate()));
	std::cout << (include_guard()).generate() << std::endl;
	std::cin.get();
	return 0;
}
