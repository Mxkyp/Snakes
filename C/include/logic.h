#ifndef LOGIC_H_
#define LOGIC_H_
#include "raylib.h"
typedef enum {UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3}Direction;

typedef struct Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
} Timer;


typedef struct snake_s Snake;
struct snake_s{
 Vector2 speed;
 Direction last_move_direction;
 Vector2 position;
 Snake *next;
 Snake *before;
};

/*
  gets the current time, and sets the expected lifetime
 */
void StartTimer(Timer *timer, double lifetime);

/*
 check if time since StartTimer is greater than lifetime
 */
bool TimerDone(Timer timer);

/*
  return elapsed time in seconds since StartTimer
 */
double GetElapsed(Timer timer);

/* return default snake config*/
Snake initSnake(void);

void updateLastMoveDirection(Snake *snake);

/* check for keypresses,
   if any arrow keys were pressed adjust snakeSpeed vector
  if user want do turn 180 degrees do nothing*/
void changeDirection(Snake *snake);
/*
  updates snake position vector, based on its speed vector
 */
void updateSnake(Timer *clock, Snake *snake);

#endif // LOGIC_H_
