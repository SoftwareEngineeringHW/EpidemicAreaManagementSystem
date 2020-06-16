include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/cpp-httplib-master/out ${PROJECT_SOURCE_DIR}/server)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/UnitTests)
set(BINARY ${CMAKE_PROJECT_NAME}_test)
file(GLOB_RECURSE TEST_SOURCES false ../server/*.cc)
set(ServerSources ${TEST_SOURCES})
set(UnitTestMain TestMain.cc)
set(gTestLibPath /usr/lib/gtest)
LINK_LIBRARIES("${gTestLibPath}/libgmock.a" 
"${gTestLibPath}/libgmock_main.a" 
"${gTestLibPath}/libgtest.a" 
"${gTestLibPath}/libgtest_main.a" 
"/usr/lib64/mysql/libmysqlservices.a"
"/usr/lib64/mysql/libmysqlclient.a"
pthread dl)
add_executable(${BINARY}_1 ${ServerSources} ${UnitTestMain} test1.cc)

