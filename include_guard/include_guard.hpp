/* in the name of Allah */

#ifndef I4EA5D014_5FB6_4DA7_8E3E_A4308D51F4CF
#define I4EA5D014_5FB6_4DA7_8E3E_A4308D51F4CF

#include <boost/predef.h>

#if BOOST_OS_WINDOWS
#include <Windows.h>
#endif

#include <iostream>
#include <regex>
#include <boost/algorithm/string.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>

#if BOOST_OS_WINDOWS
class clipboard : public boost::noncopyable {
public:
	clipboard() {
		OpenClipboard(0);
		EmptyClipboard();
	}
	~clipboard() { CloseClipboard(); }

	auto commit(std::string const &data) -> void {
		auto output = data.data();
		auto len	= data.size() + 1;
		auto hMem	= GlobalAlloc(GMEM_MOVEABLE, len);

		memcpy(GlobalLock(hMem), output, len);
		GlobalUnlock(hMem);
		SetClipboardData(CF_TEXT, hMem);
	}
};
#endif

class include_guard {
	std::string guard_;

public:
	include_guard()
		: guard_ { "I" + std::regex_replace(
							 boost::algorithm::to_upper_copy(boost::uuids::to_string(boost::uuids::random_generator()())),
							 std::regex { "-" },
							 "_") } {}

	auto generate() -> std::string { return "#ifndef " + guard_ + "\n#define " + guard_ + "\n\n#endif /* !" + guard_ + " */\n"; }
};

#endif /* !I4EA5D014_5FB6_4DA7_8E3E_A4308D51F4CF */
