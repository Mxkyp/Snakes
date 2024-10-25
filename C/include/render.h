#ifndef RENDER_H_
#define RENDER_H_
#include <raylib.h>
#include "../include/logic.h"

void createWindow(void);

void drawGrid(void);

//Render the snake head at the specified position
//(1 cube right, 1 up off the center of the screen);
void renderObject(Vector2 position, Color color);


void renderSnake(Snake *snake);

#endif // RENDER_H_
