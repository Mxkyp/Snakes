cmake_minimum_required(VERSION 3.29.2)
project(Csnake VERSION 1.0
               DESCRIPTION "SNAPSHOT"
               LANGUAGES C)


set(SRC "./src/")
set(INCLUDE "./include/")

set(GAME "snake")
set(MAIN "${SRC}main.c")
set(H_SNAKE "${INCLUDE}snake.h")

add_executable(${GAME} ${MAIN} ${H_SNAKE})
