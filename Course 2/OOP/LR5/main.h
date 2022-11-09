#ifndef MAIN_H
#define MAIN_H

#include <GL/glut.h>
#include <cmath>
#include <iostream>

#define win_size 700
#define figure 3
// 0 point
// 1 line
// 2 rectangle
// 3 triangle
// 4 circle
// 5 rhombus
// 6 ellipse

#define action 2
// 0 Полет
// 1 Вращение
// 2 Вращение и полёт

#define count 3

enum fig
{
	point,
	line,
	rectangle,
	triangle,
	circle,
	rhombus,
	ellipse,
};

#endif
