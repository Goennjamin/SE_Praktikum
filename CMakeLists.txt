cmake_minimum_required(VERSION 3.17)
project(ACS)

set(CMAKE_CXX_STANDARD 14)

add_executable(ACS main.cpp ACS.cpp ACS.h account.cpp account.h management.cpp management.h konto.cpp konto.h buchungssatz.cpp buchungssatz.h)
