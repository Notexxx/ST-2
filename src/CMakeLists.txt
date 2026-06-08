add_library(circle circle.cpp tasks.cpp)
target_include_directories(circle PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(ST-2 main.cpp)
target_link_libraries(ST-2 circle)
