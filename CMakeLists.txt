cmake_minimum_required(VERSION 3.22)
project(ACS)

set(CMAKE_CXX_STANDARD 14)

add_executable(ACS main.cpp ACS.cpp ACS.h account.cpp account.h kontenmanagement.cpp kontenmanagement.h konto.cpp konto.h)
