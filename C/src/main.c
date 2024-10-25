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

  while(!WindowShouldClose()){
   BeginDrawing();
   ClearBackground(RAYWHITE);
   drawGrid();

   fruitHandler(&snake, &fruit);
   renderObject(fruit.position, MAGENTA);

   changeDirection(&snake);
   growSnake(&snake, &fruit);
   renderSnake(&snake);
   EndDrawing();
   }

  CloseWindow();
}
