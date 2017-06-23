include_directories(${CMAKE_CURRENT_SOURCE_DIR})



add_executable(test_Card test_Card.cpp ../src/Card.cpp)

add_executable(test_Hand test_Hand.cpp ../src/Hand.cpp ../src/Card.cpp)

add_executable(test_Board test_Board.cpp ../src/Board.cpp ../src/Card.cpp)

add_executable(test_Combination test_Combination.cpp ../src/Board.cpp ../src/Card.cpp ../src/Hand.cpp ../src/Combination.cpp)
