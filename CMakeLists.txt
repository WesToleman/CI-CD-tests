cmake_minimum_required(VERSION 3.8.0)
Project(CI-CD-Tests
	DESCRIPTION "Testing continuous-delivery/continuous-integration for C++ projects with GitHub"
	LANGUAGES CXX)

option(USE_CMAKE_CONAN "Automatically install conan dependencies" ON)

# Install conan dependencies automatically
if(USE_CMAKE_CONAN)
	if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
		message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
		file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
			"${CMAKE_BINARY_DIR}/conan.cmake")
	endif()

	include(${CMAKE_BINARY_DIR}/conan.cmake)

	conan_cmake_run(CONANFILE conanfile.txt
		BUILD missing)
endif()

# Conan places find modules in the build directory
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/modules
	                  ${CMAKE_SOURCE_DIR}/CMake/stabletec-cmake-scripts
	                  ${CMAKE_BINARY_DIR})

# Add targets for coverage reports
include(code-coverage)

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

target_code_coverage(lib)

# Unit Testing
find_package(Catch2 REQUIRED)

add_executable(Tests
	${CMAKE_SOURCE_DIR}/test/tests.cpp)
target_link_libraries(Tests
	PRIVATE Catch2::Catch2
	PRIVATE lib)
target_code_coverage(Tests EXCLUDE "${CMAKE_SOURCE_DIR}/test/*")

include(CTest)
enable_testing()
add_test(NAME libTests COMMAND Tests)
