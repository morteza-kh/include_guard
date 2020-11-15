/* in the name of Allah */

#include <boost/predef.h>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#if BOOST_OS_WINDOWS
#include <Windows.h>
#endif

#include <boost/algorithm/string.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

auto main(int argc, char const **argv) -> int {
	auto header_names = std::vector<std::string> { &argv[1], &argv[argc] };
	auto make_header  = [](auto const &file_name) {
		 std::ofstream ofs { file_name };
		 auto uuid	= boost::algorithm::to_upper_copy(boost::uuids::to_string(boost::uuids::random_generator()()));
		 auto guard = "I" + std::regex_replace(uuid, std::regex { "-" }, "_");

		 ofs << "#ifndef " + guard + "\n#define " + guard + "\n\n#endif /* !" + guard + " */";
		 ofs.close();
	};

	for (auto const &header_name : header_names) {
		make_header(header_name);
	}

	return 0;
}
