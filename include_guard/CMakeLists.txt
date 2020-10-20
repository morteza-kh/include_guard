# CMakeList.txt : CMake project for include_guard, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("include_guard")

# set(Boost_INCLUDE_DIR C:\Boost\include\boost-1_75)
# set(Boost_LIBRARY_DIR C:\Boost\lib)

# add_definitions(-DBOOST_ALL_DYN_LINK)

find_package(Boost 1.73 COMPONENTS system REQUIRED) 
if (Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIR})
	# link_directories(${Boost_LIBRARY_DIR})
	add_executable (${PROJECT_NAME} include_guard.hpp sample.cpp)
	target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})
endif()
