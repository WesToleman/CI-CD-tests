cmake_minimum_required(VERSION 3.8.0)
Project(CI-CD-Tests
	DESCRIPTION "Testing continuous-delivery/continuous-integration for C++ projects with GitHub"
	LANGUAGES CXX)

add_executable(StringViewSupport src/StringViewSupport.cpp)
target_compile_features(StringViewSupport PUBLIC cxx_std_17)
