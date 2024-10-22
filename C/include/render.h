#ifndef RENDER_H_
#define RENDER_H_
#include <raylib.h>


void createWindow(void);

void drawGrid(void);
/*
  Render the snake head at the specified position (1 cube right, 1 up off the center of the screen);
 */
void renderSnake(Vector2 position);



#endif // RENDER_H_
