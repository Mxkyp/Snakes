#include "../include/snake.h"
#include "../include/render.h"
#include "../include/logic.h"
#include "../include/constans.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
  createWindow();

  Snake snake = initSnake();
  Fruit fruit = initFruit();
  Timer move_timer;
  StartTimer(&move_timer, SECONDS_BEFORE_MOVE);

  while(!WindowShouldClose()){
   BeginDrawing();
   ClearBackground(RAYWHITE);
   drawGrid();

   setFruitPosition(&snake, &fruit);
   renderObject(fruit.position);

   changeDirection(&snake);
   updateSnake(&move_timer, &snake);
   renderObject(snake.position);
   EndDrawing();
   }

  CloseWindow();
}
