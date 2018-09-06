cmake_minimum_required(VERSION 3.12)
project(ce4302_Project1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ce4302_Project1 main.cpp Tools/randomGenerator.cpp Tools/randomGenerator.h Communication/messages.h processor/node.cpp processor/node.h Communication/bus.cpp Communication/bus.h Communication/controlBus.cpp Communication/controlBus.h Tools/fileWriter.cpp Tools/fileWriter.h Tools/JsonCodeDecode.cpp Tools/JsonCodeDecode.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(ce4302_Project1 Threads::Threads)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)
link_libraries(${JSONCPP_LIBRARIES})


target_link_libraries(ce4302_Project1 ${JSONCPP_LIBRARIES})