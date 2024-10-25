#include "../include/logic.h"
#include "../include/constans.h"
#include "raylib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

Snake initSnake(void){
  Snake new = {.speed = {CUBE_SIZE, 0}, .last_move_direction = RIGHT,
               .position = { 16 * CUBE_SIZE, 8 * CUBE_SIZE},
               .next = NULL, .before = NULL};

  StartTimer(&new.move_delay, SECONDS_BEFORE_MOVE); // set the time between each time the snake moves;
  return new;
}

Fruit initFruit(void){
  Fruit fruit;

  StartTimer(&fruit.timer, FRUIT_LIFETIME);
  fruit.position.y = (rand() % W_HEIGHT_IN_CUBES) * CUBE_SIZE;
  fruit.position.x = (rand() % W_WIDTH_IN_CUBES) * CUBE_SIZE;

  return fruit;
}

void snakeHandler(Snake *snake, Fruit* fruit){
   changeDirection(snake);
   growSnake(snake, fruit);
   updateSnake(snake);
}

void fruitHandler(Snake *snake, Fruit *fruit){
  if(TimerDone(fruit->timer)){ //check if the time between last fruit spawn
    respawnFruit(snake, fruit);
    StartTimer(&fruit->timer, FRUIT_LIFETIME); //restart the move timer
  }
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

void growSnake(Snake *snake, Fruit *fruit){
  if(checkIfFruitWasEaten(snake, fruit)){
    respawnFruit(snake,fruit);

    Snake *last = snake;
    for(; last->next != NULL; last = last->next);
    last->next = malloc(sizeof(*snake));

    copyVector(&last->next->position, &last->position);
    last->next->before = last;
    last->next->next = NULL;
  }

    updateSnake(snake);
}

void updateSnake(Snake *snake){
     if(TimerDone(snake->move_delay)){ //check if the time between moves has elapsed
        updateLastMoveDirection(snake);

        Snake *last = snake, *pre_last = last;
        for(; last->next != NULL; pre_last = last, last = last->next);
        for(; pre_last != NULL; pre_last = pre_last->before, last = last->before){
          copyVector(&last->position, &pre_last->position);
        }
        snake->position.y += snake->speed.y;
        snake->position.x += snake->speed.x;

        if(snake->position.y >= W_HEIGHT){
          snake->position.y = 0;
        } else if (snake->position.y < 0){
          snake->position.y = W_HEIGHT - CUBE_SIZE;
        }


        if(snake->position.x >= W_WIDTH){
          snake->position.x = 0;
        } else if (snake->position.x < 0){
          snake->position.x = W_WIDTH - CUBE_SIZE;
        }

        StartTimer(&snake->move_delay, SECONDS_BEFORE_MOVE); //restart the move timer
     }
}

void respawnFruit(Snake* snake, Fruit *fruit){
        srand(time(NULL));

        do{
          fruit->position.y = (rand() % W_HEIGHT_IN_CUBES) * CUBE_SIZE;
          fruit->position.x = (rand() % W_WIDTH_IN_CUBES) * CUBE_SIZE;
        }while(checkIfAtSnake(*snake, fruit->position));

    StartTimer(&fruit->timer, FRUIT_LIFETIME); //restart the move timer
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

bool checkIfAtSnake(Snake snake, Vector2 point){
  Snake *s = &snake;

  while(s){
    if(s->position.y == point.y && s->position.x == point.x){
      return true;
    }
    s = s->next;
  }

  return false;
}

bool checkIfFruitWasEaten(Snake *snake, Fruit *fruit){
  if(snake->position.y == fruit->position.y && snake->position.x == fruit->position.x){
    return true;
  }
  return false;
}

///////////////////////////////
////////////////BASIC UTILS
////////////////////////////////
void copyVector(Vector2 *dst, Vector2 *src){
  dst->x = src->x;
  dst->y = src->y;
}

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
