cmake_minimum_required(VERSION 3.10)

project(Loadcurl)
find_package(CURL)
add_executable(Loadcurl main.cpp)

if(CURL_FOUND)
    target_include_directories(clib PRIVATE ${CURL_INCLUDE_DIR})
    target_link_libraries(Loadcurl ${CURL_LIBRARY})
    message(FATAL_ERROR "CURL library is found")
else(CURL_FOUND)
    message(FATAL_ERROR "CURL library not found")
endif(CURL_FOUND)

