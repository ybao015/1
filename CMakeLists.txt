CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)


ADD_EXECUTABLE(unit_test
	unit_test.cpp
)



ADD_EXECUTABLE(calculator
calculator.cpp
)

SET(DEBUG_FLAG "-g")
add_definitions(${DEBUG_FLAG})

TARGET_LINK_LIBRARIES(unit_test gtest)
TARGET_COMPILE_DEFINITIONS(unit_test PRIVATE gtest_disable_pthreads=ON)