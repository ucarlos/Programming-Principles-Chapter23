cmake_minimum_required(VERSION 3.17)
project(Chapter23)

set(CMAKE_CXX_STANDARD 17)

#add_executable(Chapter23 main.cpp)
add_executable(TestMailFile TestMailFile.cc MailFile.cc)
add_executable(Chapter23_TryThis01 Chapter23_TryThis01.cc MailFile.cc)
add_executable(Regex_Example Regex_Example.cc)
add_executable(Regex_Tester Regex_Tester.cc)

# Problems
add_executable(Chapter23_01 Chapter23_01.cc MailFile.cc)
add_executable(Chapter23_02 Chapter23_02.cc MailFile.cc)
