#include "../include/render.h"
#include "../include/constans.h"
#include "../include/logic.h"
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include <stdlib.h>
void createWindow(void){
  const int win_height = W_HEIGHT;
  const int win_width= W_WIDTH;
  const char win_title[] = "Snake";

  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(win_width, win_height, win_title);
}

void drawGrid(void){
  rlPushMatrix();

  rlTranslatef(0, 20 * CUBE_SIZE, 0);
  rlRotatef(90, 1, 0, 0);
  DrawGrid(100 , CUBE_SIZE);

 rlPopMatrix();
}

void renderObject(Vector2 position, Color color){
  static Vector2 snake_dim = {CUBE_SIZE, CUBE_SIZE};
  DrawRectangleV(position, snake_dim, color);
}

void renderSnake(Snake *snake){
 static Vector2 snake_dim = {CUBE_SIZE, CUBE_SIZE};
 for(Snake *s = snake; s != NULL; s = s->next){
   DrawRectangleV(s->position, snake_dim, GREEN);
 }
}
