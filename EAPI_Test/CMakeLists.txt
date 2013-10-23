cmake_minimum_required(VERSION 2.6)

set(CMAKE_VERBOSE_MAKEFILE ON)

# Add compiler flag for MSVC 2012
if(MSVC_VERSION EQUAL 1700)
  add_definitions(-D_VARIADIC_MAX=10)
endif()
if(WIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS -MTd )
	include_directories(${CMAKE_SOURCE_DIR}/common/include/gtest)
	include_directories(${CMAKE_SOURCE_DIR}/SEMA_Lib/EAPI/libsema)
	include_directories(${CMAKE_SOURCE_DIR}/SEMA_Lib/EAPI/eapi/include)
	include_directories(${CMAKE_SOURCE_DIR}/SEMA_Lib/EAPI/eapi/include/winnt)
	include_directories(${CMAKE_SOURCE_DIR}/SEMA_Lib/EAPI/test/EAPI_Test/inc)
	include_directories(${CMAKE_SOURCE_DIR}/common/include)
	
	link_directories(${CMAKE_SOURCE_DIR}/common/Windows_lib/gtest)

endif(WIN32)

add_executable(testmain 
	UnitTestingTestCase/testmain.cpp
	UnitTestingAPI/EAPI_Unit_testing.cpp
	UnitTestingAPI/UnitTesting_EApiBoardGetStringA.cpp
	UnitTestingAPI/UnitTesting_EApiBoardGetValue.cpp
	UnitTestingTestCase/UnitTesting_TestCase_EApiBoardGetStringA.cpp
	UnitTestingTestCase/UnitTesting_TestCase_EApiBoardGetValue.cpp
	)
# Specify MainTest's link libraries
# Create dependency of MainTest on googletest
target_link_libraries(testmain gtest.lib )
target_link_libraries(testmain libsemaadmin)
target_link_libraries(testmain libsema)
if(MSVC)
  set(Suffix ".lib")
endif()

target_link_libraries(testmain  EApi_1)