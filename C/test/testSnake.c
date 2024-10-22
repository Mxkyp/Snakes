#include "../include/snake.h"
#include "../include/render.h"
#include "../include/logic.h"
#include <stdio.h>
#include <criterion/criterion.h>


Test(logic, updateSnake, .description = "snake position should equal the sum of his position and speed vectors"){
  Snake snake = initSnake(), snakeDefault = snake;
  Timer clock;
  StartTimer(&clock, 0.4);
  updateSnake(&clock, &snake);

  cr_assert(snake.position.y ==  snakeDefault.position.y + snakeDefault.speed.y);
  cr_assert(snake.position.x ==  snakeDefault.position.x + snakeDefault.speed.x);
}

Test(logic_edge_case, updateSnake, .description = "snake position should wrap after exceeding the screen"){
  Snake snake = initSnake(), snakeDefault = snake;
  snake.position.x = 32 * 25;
  snake.position.y = 0;
  Timer clock;
  StartTimer(&clock, 0.4);

  cr_assert(snake.position.y ==  snakeDefault.position.y + snakeDefault.speed.y);
  cr_assert(snake.position.x ==  snakeDefault.position.x + snakeDefault.speed.x);
}
