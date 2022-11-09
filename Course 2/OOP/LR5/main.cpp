/*
Добавить к программе Занятия 3: 
Создать иерархию графических классов. Описания классов оформить в отдельном модуле.

			ТОЧКА     ОТРЕЗОК    ОКРУЖНОСТЬ	
			
			ПРЯМОУГОЛЬНИК ТРЕУГОЛЬНИК ЭЛЛИПС
			
                                    РОМБ 
			
Добавить методы движения фигур:
	a) прямолинейное движение с отражением от стенок экрана
	b) вращение вокруг центра фигуры
При описании методов движения и рисования фигур использовать статические (не виртуальные) методы.
*/

#include "main.h"
#include "point.h"
#include "line.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "rhombus.h"
#include "ellipse.h"
#include <vector>

using namespace std;

tPoint p = tPoint();
vector <tPoint> points;

tLine l = tLine(100, 100, 300, 300);
vector <tLine> lines;

tRectangle r = tRectangle(200, 120);
vector <tRectangle> rectangles;

tTriangle t = tTriangle(100, 0, 100, 120, 50, 240);
vector <tTriangle> triangles;

tCircle c = tCircle(200, 200, 100);
vector <tCircle> circles;

tRhombus rh = tRhombus(150, 100);
vector <tRhombus> rhombuses;

tEllipse e = tEllipse(150, 100);
vector <tEllipse> ellipses;


void Display()
{
	float mr = 0, mg = 0, mb = 0;
	while (!(mr + mg + mb))
	{
		mr = rand() % 2;
		mg = rand() % 2;
		mb = rand() % 2;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(mr, mg, mb);
	switch(figure)
	{
		case point:
		for (size_t j = 0; j < count; j++) {
			glPointSize(points[j].getSize());
			points[j].draw();
			glEnd();
		}
			break;
		case line:
			for (size_t j = 0; j < count; j++) {
				lines[j].draw();
				glEnd();
			}
			break;
		case rectangle:
			for (size_t j = 0; j < count; j++) {
				rectangles[j].draw();
				glEnd();
			}
			break;
		case triangle:
			for (size_t j = 0; j < count; j++) {
				glPointSize(p.getSize());
				glBegin(GL_POINTS);
				glEnd();
				triangles[j].draw();
				glEnd();
			}
			break;
		case circle:
			for (size_t j = 0; j < count; j++) {
				circles[j].draw();
				glEnd();
			}
			break;
		case rhombus:
			for (size_t j = 0; j < count; j++) {
				rhombuses[j].draw();
				glEnd();
			}
			break;
		case ellipse:
			for (size_t j = 0; j < count; j++) {
				ellipses[j].draw();
				glEnd();
			}
			break;
	}

	glutSwapBuffers();
}

void timer(int = 0)
{

	for (size_t vv = 0; vv < count; ++vv) {
		points.push_back(tPoint());
		lines.push_back(tLine(100, 100, 300, 300));
		rectangles.push_back(tRectangle(200, 120));
		triangles.push_back(tTriangle(100, 0, 100, 120, 50, 240));
		circles.push_back(tCircle(200, 200, 100));
		rhombuses.push_back(tRhombus(150, 100));
		ellipses.push_back(tEllipse(150, 100));
	}

	if (figure == point)
	{
		for (size_t i = 0; i < 360; ++i)
		{
		for (size_t j = 0; j < count; j++) {
			if (points[j].getX() < 0 || points[j].getX() < 0 || points[j].getX() > win_size || points[j].getX() > win_size)
						points[j].setVecX(-1 * points[j].getVecX());
					if (points[j].getY() < 0 || points[j].getY() < 0 || points[j].getY() > win_size || points[j].getY() > win_size)
						points[j].setVecY(-1 * points[j].getVecY());
			points[j].move();
		}	
		Display();
		}
	}
	switch(figure)
	{
		case line:
			for (size_t i = 0; i < 360; ++i)
			{
				for (size_t j = 0; j < count; j++) {
					if (lines[j].getXl() < 0 || lines[j].getXr() < 0 || lines[j].getXl() > win_size || lines[j].getXr() > win_size)
						lines[j].setVecX(-1 * lines[j].getVecX());
					if (lines[j].getYl() < 0 || lines[j].getYr() < 0 || lines[j].getYl() > win_size || lines[j].getYr() > win_size)
						lines[j].setVecY(-1 * lines[j].getVecY());
					switch (action)
					{
						case 0:
							lines[j].move();
							break;
						case 1:
							lines[j].rotate(i);
							break;
						case 2:
							lines[j].move();
							lines[j].rotate(i);
							break;
					}
				}
				Display();
			}
			break;
		case rectangle:
			for (size_t i = 0; i < 360; i++)
			{
				for (size_t j = 0; j < count; j++) {
				if (rectangles[j].getXtl() < 0 || rectangles[j].getXtr() < 0 || rectangles[j].getXbl() < 0 || rectangles[j].getXbr() < 0)
					rectangles[j].setVecX(-1 * rectangles[j].getVecX());
				if (rectangles[j].getYtl() < 0 || rectangles[j].getYtr() < 0 || rectangles[j].getYbl() < 0 || rectangles[j].getYbr() < 0)
					rectangles[j].setVecY(-1 * rectangles[j].getVecY());
				if (rectangles[j].getXtl() > win_size || rectangles[j].getXtr() > win_size || rectangles[j].getXbl() > win_size || rectangles[j].getXbr() > win_size)
					rectangles[j].setVecX(-1 * rectangles[j].getVecX());
				if (rectangles[j].getYtl() > win_size || rectangles[j].getYtr() > win_size || rectangles[j].getYbl() > win_size || rectangles[j].getYbr() > win_size)
					rectangles[j].setVecY(-1 * rectangles[j].getVecY());
				switch (action)
				{
					case 0:
						rectangles[j].move();
						break;
					case 1:
						rectangles[j].rotate(i);
						break;
					case 2:
						rectangles[j].move();
						rectangles[j].rotate(i);
						break;
				}
				}
				Display();
			}
			break;
		case triangle:
			for (size_t i = 0; i < 360; i++)
			{
				for (size_t j = 0; j < count; j++) {
				if (triangles[j].getV1X() < 0 || triangles[j].getV2X() < 0 || triangles[j].getV3X() < 0)
					triangles[j].setVecX(-1 * triangles[j].getVecX());
				if (triangles[j].getV1Y() < 0 || triangles[j].getV2Y() < 0 || triangles[j].getV3Y() < 0)
					triangles[j].setVecY(-1 * triangles[j].getVecY());
				if (triangles[j].getV1X() > win_size || triangles[j].getV2X() > win_size || triangles[j].getV3X() > win_size)
					triangles[j].setVecX(-1 * triangles[j].getVecX());
				if (triangles[j].getV1Y() > win_size || triangles[j].getV2Y() > win_size || triangles[j].getV3Y() > win_size)
					triangles[j].setVecY(-1 * triangles[j].getVecY());
				switch (action)
				{
					case 0:
						triangles[j].move();
						break;
					case 1:
						triangles[j].rotate(i);
						break;
					case 2:
						triangles[j].move();
						triangles[j].rotate(i);
						break;
				}
				}
				Display();
			}
			break;
		case circle:
		for (size_t i = 0; i < 360; i++)
		{
			for (size_t j = 0; j < count; j++) {
			if (circles[j].getR() > circles[j].getX() || circles[j].getR() > (win_size - circles[j].getX()))
				circles[j].setVecX(-1 * circles[j].getVecX());
			if (circles[j].getR() > circles[j].getY() || circles[j].getR() > (win_size - circles[j].getY()))
				circles[j].setVecY(-1 * circles[j].getVecY());
			circles[j].move();
			}
			Display();
		}
			break;
		case rhombus:
			for (size_t i = 0; i < 360; i++)
			{
				for (size_t j = 0; j < count; j++) {
				if (rhombuses[j].getXtl() < 0 || rhombuses[j].getXtr() < 0 || rhombuses[j].getXbl() < 0 || rhombuses[j].getXbr() < 0)
					rhombuses[j].setVecX(-1 * rhombuses[j].getVecX());
				if (rhombuses[j].getYtl() < 0 || rhombuses[j].getYtr() < 0 || rhombuses[j].getYbl() < 0 || rhombuses[j].getYbr() < 0)
					rhombuses[j].setVecY(-1 * rhombuses[j].getVecY());
				if (rhombuses[j].getXtl() > win_size || rhombuses[j].getXtr() > win_size || rhombuses[j].getXbl() > win_size || rhombuses[j].getXbr() > win_size)
					rhombuses[j].setVecX(-1 * rhombuses[j].getVecX());
				if (rhombuses[j].getYtl() > win_size || rhombuses[j].getYtr() > win_size || rhombuses[j].getYbl() > win_size || rhombuses[j].getYbr() > win_size)
					rhombuses[j].setVecY(-1 * rhombuses[j].getVecY());
				switch (action)
				{
					case 0:
						rhombuses[j].move();
						break;
					case 1:
						rhombuses[j].rotate(i);
						break;
					case 2:
						rhombuses[j].move();
						rhombuses[j].rotate(i);
						break;
				}
				}
				Display();
			}
			break;
		case ellipse:
			for (size_t i = 0; i < 360; i++)
			{
				for (size_t j = 0; j < count; j++) {
				if (ellipses[j].getA() > ellipses[j].getX() || ellipses[j].getA() > (win_size - ellipses[j].getX()))
				ellipses[j].setVecX(-1 * ellipses[j].getVecX());
				if (ellipses[j].getB() > ellipses[j].getY() || ellipses[j].getB() > (win_size - ellipses[j].getY()))
				ellipses[j].setVecY(-1 * ellipses[j].getVecY());
				switch (action)
				{
					case 0:
						ellipses[j].move();
						break;
					case 1:
						ellipses[j].rotate(i);
						break;
					case 2:
						ellipses[j].move();
						ellipses[j].rotate(i);
						break;
				}
				}
				Display();
			}
			break;
	}
	glutTimerFunc(5, timer, 0);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(win_size, win_size);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("4");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, win_size, 0, win_size);
	glutDisplayFunc(Display);
	timer();
	glutMainLoop();
	tPoint ** TP = new[topoint*];
}
