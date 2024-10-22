#include "../include/snake.h"
#include "../include/render.h"
#include "../include/logic.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#define SECONDS_BEFORE_MOVE 0.5

int main(void){
  createWindow();

  Snake snake = initSnake();
  Timer clock;
  StartTimer(&clock, SECONDS_BEFORE_MOVE);

  while(!WindowShouldClose()){
   BeginDrawing();
   ClearBackground(RAYWHITE);
   drawGrid();

   changeDirection(&snake.speed);
   updateSnake(&clock, &snake);
   renderSnake(snake.position);
   EndDrawing();
   }

  CloseWindow();
}
