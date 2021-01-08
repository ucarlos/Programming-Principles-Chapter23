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
add_executable(Chapter23_03 Chapter23_03.cc MailFile.cc)
add_executable(Chapter23_04 Chapter23_04.cc MailFile.cc)
add_executable(Chapter23_06 Chapter23_06.cc)
add_executable(Chapter23_07 Chapter23_07.cc)
add_executable(Chapter23_08 Chapter23_08.cc)