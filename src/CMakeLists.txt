add_executable (cpprest-request client.cpp)
target_link_libraries (cpprest-request PRIVATE cpprestsdk::cpprest)