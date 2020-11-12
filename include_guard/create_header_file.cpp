/* in the name of Allah */

#include <fstream>
#include <iostream>
#include "include_guard.hpp"

auto main(int argc, char const **argv) -> int {
	class header {
		std::ofstream ofs_;

	public:
		header(std::string const &file_name)
			: ofs_ { file_name } {}
		auto operator<<(std::string const &str) -> header & { return ofs_ << str, *this; }
		virtual ~header() { ofs_.close(); }
	};

	for (int i = 1; i < argc; i++) {
		(header { argv[i] }) << make_include_guard();
	}

	return 0;
}
