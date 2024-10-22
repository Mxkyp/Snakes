#include "../include/render.h"
#include "../include/constans.h"
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>

void createWindow(void){
  const int win_height = W_HEIGHT;
  const int win_width= W_WIDTH;
  const char win_title[] = "Snake";

  SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
  InitWindow(win_width, win_height, win_title);
}

void drawGrid(void){
  rlPushMatrix();

  rlTranslatef(0, 32 * CUBE_SIZE, 0);
  rlRotatef(90, 1, 0, 0);
  DrawGrid(100, CUBE_SIZE);

 rlPopMatrix();
}

void renderSnake(Vector2 position){
  static Vector2 snake_dim = {CUBE_SIZE, CUBE_SIZE};
  DrawRectangleV(position, snake_dim, PURPLE);
}


void renderFruit(void){

}
