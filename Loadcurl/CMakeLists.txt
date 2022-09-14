cmake_minimum_required(VERSION 3.0)

project(Loadcurl)

find_package(CURL)
add_executable(curltest main.cpp)
if(CURL_FOUND)
    target_include_directories(curltest PRIVATE ${CURL_INCLUDE_DIR})
    target_link_libraries(curltest ${CURL_LIBRARY})
else(CURL_FOUND)
    message(FATAL_ERROR "CURL library not found")
endif(CURL_FOUND)