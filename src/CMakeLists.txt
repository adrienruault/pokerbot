include_directories(${CMAKE_CURRENT_SOURCE_DIR})



add_executable(test_Card test_Card.cpp Card.cpp)

add_executable(test_Hand test_Hand.cpp Hand.cpp Card.cpp)

add_executable(test_Board test_Board.cpp Board.cpp Card.cpp)