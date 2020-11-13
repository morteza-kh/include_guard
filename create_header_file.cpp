/* in the name of Allah */

#include <boost/predef.h>
#include <fstream>
#include <iostream>
#include <regex>

#if BOOST_OS_WINDOWS
#	include <Windows.h>
#endif

#include <boost/algorithm/string.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>


auto main(int argc, char const **argv) -> int {
	auto make_header = [](auto file_name) {
		std::ofstream ofs { file_name };
		auto uuid  = boost::algorithm::to_upper_copy(boost::uuids::to_string(boost::uuids::random_generator()()));
		auto guard = "I" + std::regex_replace(uuid, std::regex { "-" }, "_");

		ofs << "#ifndef " + guard + "\n#define " + guard + "\n\n#endif /* !" + guard + " */";
		ofs.close();
	};

	for (int i = 1; i < argc; i++) {
		make_header(argv[i]);
	}

	return 0;
}
