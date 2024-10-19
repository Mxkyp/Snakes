cmake_minimum_required(VERSION 3.29.2)
project(Csnake VERSION 1.0
               DESCRIPTION "SNAPSHOT"
               LANGUAGES C)

##PROGRAM
set(SRC "./src/")
set(INCLUDE "./include/")
set(GAME "snake")
set(MAIN "${SRC}main.c")
set(H_SNAKE "${INCLUDE}snake.h")

add_executable(${GAME} ${MAIN} ${H_SNAKE})

##TEST_SUITE
set(T_SRC "./test/")
set(TEST "test")
set(T_SNAKE "${T_SRC}testSnake.c")

add_executable(${TEST} ${T_SNAKE} ${H_SNAKE})
target_link_libraries(${TEST} criterion)
add_test(${TEST} test)
