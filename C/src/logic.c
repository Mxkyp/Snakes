#include "../include/logic.h"
#include "../include/constans.h"
#include "raylib.h"
#include <stdlib.h>

void StartTimer(Timer *timer, double lifetime){
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

bool TimerDone(Timer timer){
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer){
    return GetTime() - timer.startTime;
}

Snake initSnake(void){
  Snake new = {.speed = {CUBE_SIZE, 0}, .last_move_direction = RIGHT,
               .position = { 16 * CUBE_SIZE, 8 * CUBE_SIZE},
               .next = NULL, .before = NULL};
  return new;
}

void changeDirection(Snake *snake){
  if(IsKeyPressed(KEY_UP) &&  snake->last_move_direction != DOWN){
    snake->speed.x = 0;
    snake->speed.y = -25;
  }
  else if( IsKeyPressed(KEY_DOWN) && snake->last_move_direction != UP){
    snake->speed.x = 0;
    snake->speed.y = 25;
  }
  else if( IsKeyPressed(KEY_LEFT) && snake->last_move_direction != RIGHT){
    snake->speed.x = -25;
    snake->speed.y = 0;
  }
  else if( IsKeyPressed(KEY_RIGHT) && snake->last_move_direction != LEFT){
    snake->speed.x = 25;
    snake->speed.y = 0;
  }
}

void updateLastMoveDirection(Snake *snake){
  if(snake->speed.y == -CUBE_SIZE && snake->speed.x == 0){
    snake->last_move_direction = UP;
  }
  else if(snake->speed.y == CUBE_SIZE && snake->speed.x == 0){
    snake->last_move_direction = DOWN;
  }
  else if(snake->speed.y == 0 && snake->speed.x == -CUBE_SIZE){
    snake->last_move_direction = LEFT;
  }
  else if(snake->speed.y == 0 && snake->speed.x == CUBE_SIZE){
    snake->last_move_direction = RIGHT;
  }
}


void updateSnake(Timer *clock, Snake *snake){
     if(TimerDone(*clock)){
        updateLastMoveDirection(snake);
        snake->position.y += snake->speed.y;
        snake->position.x += snake->speed.x;

        if(snake->position.y > W_HEIGHT){
          snake->position.y = 0;
        } else if (snake->position.y < 0){
          snake->position.y = W_HEIGHT;
        }

        if(snake->position.x > W_WIDTH){
          snake->position.x = 0;
        } else if (snake->position.x < 0){
          snake->position.x = W_WIDTH;
        }

        StartTimer(clock, SECONDS_BEFORE_MOVE);
     }
}
