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
    Timer move_delay;
    Snake *next;
    Snake *before;
};

typedef struct fruit_s Fruit;
struct fruit_s{
 Vector2 position;
 Timer timer;
};


// return default snake config
Snake initSnake(void);

// return default fruit config
Fruit initFruit(void);

// first updates directon, then checks if snakeGrows
// then updates the snake position
void snakeHandler(Snake *snake, Fruit* fruit);

// if a FRUIT_LIFETIME has elapsed, respawn fruit
void fruitHandler(Snake *snake, Fruit *fruit);

// check for keypresses, if any arrow keys were pressed adjust snakeSpeed vector
// if user want do turn 180 degrees do nothing
void changeDirection(Snake *snake);

// adds a new snake cell if snake.position == fruit.position
void growSnake(Snake *snake, Fruit *fruit);

// move each snake cell to the postion of the cell before,
// move head
void updateSnake(Snake *snake);

// pick a random new position(thats not on the snake) for fruit;
void respawnFruit(Snake* snake, Fruit *fruit);

void updateLastMoveDirection(Snake *snake);

//check if a given point is on any part of the snake,
//if yes return true
bool checkIfAtSnake(Snake snake, Vector2 point);

// checks whether snake's head is on the fruit(their cooridantes are the same)
// returns true if yes
bool checkIfFruitWasEaten(Snake *snake, Fruit *fruit);
///////////////////////////////
////////////////MINOR FUNCTIONS
////////////////////////////////
////////////////
///////////////////////////////
////////////////BASIC UTILS
////////////////////////////////
void copyVector(Vector2 *dst, Vector2 *src);

// gets the current time, and sets the expected lifetime
void StartTimer(Timer *timer, double lifetime);

//check if time since StartTimer is greater than lifetime
bool TimerDone(Timer timer);

// return elapsed time in seconds since StartTimer
double GetElapsed(Timer timer);
#endif // LOGIC_H_
