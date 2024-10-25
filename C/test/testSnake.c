#include "../include/snake.h"
#include "../include/render.h"
#include "../include/logic.h"
#include <stdio.h>
#include <criterion/criterion.h>

Test(logic, updateSnake, .description = "snake position should equal the sum of his position and speed vectors"){
  Snake snake = initSnake(), snakeDefault = snake;
  Timer clock;
  StartTimer(&clock, 0.0);

  updateSnake(&clock, &snake);

  cr_assert(snake.position.y ==  snakeDefault.position.y + snakeDefault.speed.y);
  cr_assert(snake.position.x ==  snakeDefault.position.x + snakeDefault.speed.x);
}

Test(logic_edge_case, updateSnake, .description = "snake position should wrap after exceeding the screen"){
  Snake snake = initSnake();
  Timer clock;
  const int exp_x = 0;
  const int exp_y = 0;

  snake.position.x = 32 * 25;
  snake.position.y = 0;

  StartTimer(&clock, 0.0);
  updateSnake(&clock, &snake);

  cr_assert(snake.position.y ==  exp_x);
  cr_assert(snake.position.x ==  exp_y);
}

Test(logic, updateLastMoveDirection1, .description = "directions should be correctly identified" ){
  Snake snake = initSnake(); // on default last move direction matches the vector so is RIGHT

  snake.last_move_direction = DOWN; // forcibly change last_move_direction (vector still points right)
  updateLastMoveDirection(&snake); // update the last_move_direction
                                   // to match the vector which is pointing RIGHT
  cr_assert(snake.last_move_direction == RIGHT);

}
