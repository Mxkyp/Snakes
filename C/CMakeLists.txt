cmake_minimum_required(VERSION 3.29.2)
project(Csnake VERSION 1.0
               DESCRIPTION "SNAPSHOT"
               LANGUAGES C)

##LOCALIZATIONS
set(SRC "./src/")
set(INCLUDE "./include/")
set(T_SRC "./test/")

##PROGRAM
set(GAME "snake")
set(MAIN "${SRC}main.c")
set(SNAKE "${SRC}snake.c")
set(RENDER "${SRC}render.c")
set(LOGIC "${SRC}logic.c")
set(H_SNAKE "${INCLUDE}snake.h")
set(H_RENDER "${INCLUDE}render.h")
set(H_LOGIC "${INCLUDE}logic.h")
set(H_CONSTANS "${INCLUDE}constans.h")

add_executable(${GAME} ${MAIN} ${SNAKE} ${LOGIC} ${RENDER} ${H_LOGIC} ${H_CONSTANTS} ${H_SNAKE} ${H_RENDER})
target_link_libraries(${GAME} raylib)

##TEST_SUITE
set(TEST "test")
set(T_SNAKE "${T_SRC}testSnake.c")

add_executable(${TEST} ${T_SNAKE} ${SNAKE} ${LOGIC} ${RENDER} ${H_LOGIC} ${H_CONSTANTS} ${H_SNAKE} ${H_RENDER})
target_link_libraries(${TEST} raylib)
target_link_libraries(${TEST} criterion)
add_test(${TEST} test)

##libraylib.so.550
