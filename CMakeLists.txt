cmake_minimum_required(VERSION 3.8.0)
Project(CI-CD-Tests
	DESCRIPTION "Testing continuous-delivery/continuous-integration for C++ projects with GitHub"
	LANGUAGES CXX)

# Conan places find modules in the build directory
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

add_executable(StringViewSupport src/StringViewSupport.cpp)
target_compile_features(StringViewSupport PUBLIC cxx_std_17)

add_library(lib
	${CMAKE_SOURCE_DIR}/src/lib.cpp)
target_include_directories(lib
	PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include/lib>
	PUBLIC $<INSTALL_INTERFACE:include/lib>)
target_compile_features(lib
	PUBLIC cxx_constexpr)

# Documentation
find_package(Doxygen
	REQUIRED  dot
	OPTIONAL_COMPONENTS mscgen dia)

# Doxygen navigation on the left side
set(DOXYGEN_DISABLE_INDEX YES)
set(DOXYGEN_GENERATE_TREEVIEW YES)

# Public documentation
doxygen_add_docs(doc
	docs
	include/lib)

# Unit Testing
find_package(Catch2 REQUIRED)

add_executable(Tests
	${CMAKE_SOURCE_DIR}/test/tests.cpp)
target_link_libraries(Tests
	Catch2::Catch2
	lib)

include(CTest)
enable_testing()
add_test(NAME libTests COMMAND Tests)
