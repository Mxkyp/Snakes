#include "../include/logic.h"
#include "raylib.h"
#include "../include/render.h"
#include <stdlib.h>

void StartTimer(Timer *timer, double lifetime)
{
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

bool TimerDone(Timer timer)
{
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer)
{
    return GetTime() - timer.startTime;
}

Snake initSnake(void){
  Snake new = {.speed = {CUBE_SIZE, 0}, .position = { 16 * CUBE_SIZE, 8 * CUBE_SIZE},
               .next = NULL, .before = NULL};
  return new;
}

void changeDirection(Vector2 *snakeSpeed){
  if(IsKeyPressed(KEY_UP)){
    snakeSpeed->x = 0;
    snakeSpeed->y = -25;
  }
  else if( IsKeyPressed(KEY_DOWN) ){
    snakeSpeed->x = 0;
    snakeSpeed->y = 25;
  }
  else if( IsKeyPressed(KEY_LEFT) ){
    snakeSpeed->x = -25;
    snakeSpeed->y = 0;
  }
  else if( IsKeyPressed(KEY_RIGHT) ){
    snakeSpeed->x = 25;
    snakeSpeed->y = 0;
  }
}

void updateSnake(Timer *clock, Snake *snake){
     if(TimerDone(*clock)){
        snake->position.y += snake->speed.y;
        snake->position.x += snake->speed.x;
        StartTimer(clock, 0.5);
     }
}
