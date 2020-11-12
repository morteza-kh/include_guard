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
auto clipboard_commit(std::string const &data) noexcept -> void {
	OpenClipboard(0);
	EmptyClipboard();
	auto output = data.data();
	auto len	= data.size() + 1;
	auto hMem	= GlobalAlloc(GMEM_MOVEABLE, len);

	memcpy(GlobalLock(hMem), output, len);
	GlobalUnlock(hMem);
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
}
#endif

auto make_include_guard() -> std::string {
	auto uuid  = boost::algorithm::to_upper_copy(boost::uuids::to_string(boost::uuids::random_generator()()));
	auto guard = "I" + std::regex_replace(uuid, std::regex { "-" }, "_");

	return "#ifndef " + guard + "\n#define " + guard + "\n\n#endif /* !" + guard + " */";
}

#endif /* !I4EA5D014_5FB6_4DA7_8E3E_A4308D51F4CF */
