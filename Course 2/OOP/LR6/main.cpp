/*
Добавить к программе Занятия 3: 
Создать иерархию графических классов-> Описания классов оформить в отдельном модуле->

			ТОЧКА     ОТРЕЗОК    ОКРУЖНОСТЬ	
			
			ПРЯМОУГОЛЬНИК ТРЕУГОЛЬНИК ЭЛЛИПС
			
                                    РОМБ 
			
Добавить методы движения фигур:
	a) прямолинейное движение с отражением от стенок экрана
	b) вращение вокруг центра фигуры
При описании методов движения и рисования фигур использовать статические (не виртуальные) методы->
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
#include <array>

using namespace std;

tPoint* arr[13];

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


	glPointSize(arr[0]->getSize());
	arr[0]->draw();
	glEnd();
	dynamic_cast<tLine*>(arr[1])->draw();
	glEnd();
	dynamic_cast<tRectangle*>(arr[2])->draw();
	glEnd();
	glPointSize(arr[0]->getSize());
	glBegin(GL_POINTS);
	glEnd();
	dynamic_cast<tTriangle*>(arr[6])->draw();
	glEnd();
	dynamic_cast<tCircle*>(arr[3])->draw();
	glEnd();
	dynamic_cast<tRhombus*>(arr[4])->draw();
	glEnd();
	dynamic_cast<tEllipse*>(arr[5])->draw();
	glEnd();


	glutSwapBuffers();
}

void timer(int = 0)
{

	arr[6] = new tTriangle(100, 0, 100, 120, 50, 240);
	arr[1] = new tLine(100, 100, 300, 300);
	arr[2] = new tRectangle(200, 120);
	arr[3] = new tCircle(200, 200, 100);
	arr[4] = new tRhombus(150, 100);
	arr[5] = new tEllipse(150, 100);
	arr[0] = new tPoint();
	arr[7] = new tTriangle();
	arr[8] = new tLine();
	arr[9] = new tRectangle();
	arr[10] = new tCircle();
	arr[11] = new tRhombus();
	arr[12] = new tEllipse(); 	


		for (size_t i = 0; i < 360; ++i)
		{
			//point
			if (arr[0]->getX() < 0 || arr[0]->getX() < 0 || arr[0]->getX() > win_size || arr[0]->getX() > win_size)
						arr[0]->setVecX(-1 * arr[0]->getVecX());
					if (arr[0]->getY() < 0 || arr[0]->getY() < 0 || arr[0]->getY() > win_size || arr[0]->getY() > win_size)
						arr[0]->setVecY(-1 * arr[0]->getVecY());
			arr[0]->move();	

			//line
			if (dynamic_cast<tLine*>(arr[1])->getXl() < 0 || dynamic_cast<tLine*>(arr[1])->getXr() < 0 || dynamic_cast<tLine*>(arr[1])->getXl() > win_size || dynamic_cast<tLine*>(arr[1])->getXr() > win_size)
						dynamic_cast<tLine*>(arr[1])->setVecX(-1 * dynamic_cast<tLine*>(arr[1])->getVecX());
					if (dynamic_cast<tLine*>(arr[1])->getYl() < 0 || dynamic_cast<tLine*>(arr[1])->getYr() < 0 || dynamic_cast<tLine*>(arr[1])->getYl() > win_size || dynamic_cast<tLine*>(arr[1])->getYr() > win_size)
						dynamic_cast<tLine*>(arr[1])->setVecY(-1 * dynamic_cast<tLine*>(arr[1])->getVecY());
					switch (action)
					{
						case 0:
							dynamic_cast<tLine*>(arr[1])->move();
							break;
						case 1:
							dynamic_cast<tLine*>(arr[1])->rotate(i);
							break;
						case 2:
							dynamic_cast<tLine*>(arr[1])->move();
							dynamic_cast<tLine*>(arr[1])->rotate(i);
							break;
					}

			//rectangle
			if (dynamic_cast<tRectangle*>(arr[2])->getXtl() < 0 || dynamic_cast<tRectangle*>(arr[2])->getXtr() < 0 || dynamic_cast<tRectangle*>(arr[2])->getXbl() < 0 || dynamic_cast<tRectangle*>(arr[2])->getXbr() < 0)
					dynamic_cast<tRectangle*>(arr[2])->setVecX(-1 * dynamic_cast<tRectangle*>(arr[2])->getVecX());
				if (dynamic_cast<tRectangle*>(arr[2])->getYtl() < 0 || dynamic_cast<tRectangle*>(arr[2])->getYtr() < 0 || dynamic_cast<tRectangle*>(arr[2])->getYbl() < 0 || dynamic_cast<tRectangle*>(arr[2])->getYbr() < 0)
					dynamic_cast<tRectangle*>(arr[2])->setVecY(-1 * dynamic_cast<tRectangle*>(arr[2])->getVecY());
				if (dynamic_cast<tRectangle*>(arr[2])->getXtl() > win_size || dynamic_cast<tRectangle*>(arr[2])->getXtr() > win_size || dynamic_cast<tRectangle*>(arr[2])->getXbl() > win_size || dynamic_cast<tRectangle*>(arr[2])->getXbr() > win_size)
					dynamic_cast<tRectangle*>(arr[2])->setVecX(-1 * dynamic_cast<tRectangle*>(arr[2])->getVecX());
				if (dynamic_cast<tRectangle*>(arr[2])->getYtl() > win_size || dynamic_cast<tRectangle*>(arr[2])->getYtr() > win_size || dynamic_cast<tRectangle*>(arr[2])->getYbl() > win_size || dynamic_cast<tRectangle*>(arr[2])->getYbr() > win_size)
					dynamic_cast<tRectangle*>(arr[2])->setVecY(-1 * dynamic_cast<tRectangle*>(arr[2])->getVecY());
				switch (action)
				{
					case 0:
						dynamic_cast<tRectangle*>(arr[2])->move();
						break;
					case 1:
						dynamic_cast<tRectangle*>(arr[2])->rotate(i);
						break;
					case 2:
						dynamic_cast<tRectangle*>(arr[2])->move();
						dynamic_cast<tRectangle*>(arr[2])->rotate(i);
						break;
				}

			//triangle
			if (dynamic_cast<tTriangle*>(arr[6])->getV1X() < 0 || dynamic_cast<tTriangle*>(arr[6])->getV2X() < 0 || dynamic_cast<tTriangle*>(arr[6])->getV3X() < 0)
					dynamic_cast<tTriangle*>(arr[6])->setVecX(-1 * dynamic_cast<tTriangle*>(arr[6])->getVecX());
				if (dynamic_cast<tTriangle*>(arr[6])->getV1Y() < 0 || dynamic_cast<tTriangle*>(arr[6])->getV2Y() < 0 || dynamic_cast<tTriangle*>(arr[6])->getV3Y() < 0)
					dynamic_cast<tTriangle*>(arr[6])->setVecY(-1 * dynamic_cast<tTriangle*>(arr[6])->getVecY());
				if (dynamic_cast<tTriangle*>(arr[6])->getV1X() > win_size || dynamic_cast<tTriangle*>(arr[6])->getV2X() > win_size || dynamic_cast<tTriangle*>(arr[6])->getV3X() > win_size)
					dynamic_cast<tTriangle*>(arr[6])->setVecX(-1 * dynamic_cast<tTriangle*>(arr[6])->getVecX());
				if (dynamic_cast<tTriangle*>(arr[6])->getV1Y() > win_size || dynamic_cast<tTriangle*>(arr[6])->getV2Y() > win_size || dynamic_cast<tTriangle*>(arr[6])->getV3Y() > win_size)
					dynamic_cast<tTriangle*>(arr[6])->setVecY(-1 * dynamic_cast<tTriangle*>(arr[6])->getVecY());
				switch (action)
				{
					case 0:
						dynamic_cast<tTriangle*>(arr[6])->move();
						break;
					case 1:
						dynamic_cast<tTriangle*>(arr[6])->rotate(i);
						break;
					case 2:
						dynamic_cast<tTriangle*>(arr[6])->move();
						dynamic_cast<tTriangle*>(arr[6])->rotate(i);
						break;
				}

			//Circle
			if (dynamic_cast<tCircle*>(arr[3])->getR() > dynamic_cast<tCircle*>(arr[3])->getX() || dynamic_cast<tCircle*>(arr[3])->getR() > (win_size - dynamic_cast<tCircle*>(arr[3])->getX()))
				dynamic_cast<tCircle*>(arr[3])->setVecX(-1 * dynamic_cast<tCircle*>(arr[3])->getVecX());
			if (dynamic_cast<tCircle*>(arr[3])->getR() > dynamic_cast<tCircle*>(arr[3])->getY() || dynamic_cast<tCircle*>(arr[3])->getR() > (win_size - dynamic_cast<tCircle*>(arr[3])->getY()))
				dynamic_cast<tCircle*>(arr[3])->setVecY(-1 * dynamic_cast<tCircle*>(arr[3])->getVecY());
			dynamic_cast<tCircle*>(arr[3])->move();

			//rhombus
			if (dynamic_cast<tRhombus*>(arr[4])->getXtl() < 0 || dynamic_cast<tRhombus*>(arr[4])->getXtr() < 0 || dynamic_cast<tRhombus*>(arr[4])->getXbl() < 0 || dynamic_cast<tRhombus*>(arr[4])->getXbr() < 0)
					dynamic_cast<tRhombus*>(arr[4])->setVecX(-1 * dynamic_cast<tRhombus*>(arr[4])->getVecX());
				if (dynamic_cast<tRhombus*>(arr[4])->getYtl() < 0 || dynamic_cast<tRhombus*>(arr[4])->getYtr() < 0 || dynamic_cast<tRhombus*>(arr[4])->getYbl() < 0 || dynamic_cast<tRhombus*>(arr[4])->getYbr() < 0)
					dynamic_cast<tRhombus*>(arr[4])->setVecY(-1 * dynamic_cast<tRhombus*>(arr[4])->getVecY());
				if (dynamic_cast<tRhombus*>(arr[4])->getXtl() > win_size || dynamic_cast<tRhombus*>(arr[4])->getXtr() > win_size || dynamic_cast<tRhombus*>(arr[4])->getXbl() > win_size || dynamic_cast<tRhombus*>(arr[4])->getXbr() > win_size)
					dynamic_cast<tRhombus*>(arr[4])->setVecX(-1 * dynamic_cast<tRhombus*>(arr[4])->getVecX());
				if (dynamic_cast<tRhombus*>(arr[4])->getYtl() > win_size || dynamic_cast<tRhombus*>(arr[4])->getYtr() > win_size || dynamic_cast<tRhombus*>(arr[4])->getYbl() > win_size || dynamic_cast<tRhombus*>(arr[4])->getYbr() > win_size)
					dynamic_cast<tRhombus*>(arr[4])->setVecY(-1 * dynamic_cast<tRhombus*>(arr[4])->getVecY());
				switch (action)
				{
					case 0:
						dynamic_cast<tRhombus*>(arr[4])->move();
						break;
					case 1:
						dynamic_cast<tRhombus*>(arr[4])->rotate(i);
						break;
					case 2:
						dynamic_cast<tRhombus*>(arr[4])->move();
						dynamic_cast<tRhombus*>(arr[4])->rotate(i);
						break;
				}

				//ellipse
				if (dynamic_cast<tEllipse*>(arr[5])->getA() > dynamic_cast<tEllipse*>(arr[5])->getX() || dynamic_cast<tEllipse*>(arr[5])->getA() > (win_size - dynamic_cast<tEllipse*>(arr[5])->getX()))
				dynamic_cast<tEllipse*>(arr[5])->setVecX(-1 * dynamic_cast<tEllipse*>(arr[5])->getVecX());
				if (dynamic_cast<tEllipse*>(arr[5])->getB() > dynamic_cast<tEllipse*>(arr[5])->getY() || dynamic_cast<tEllipse*>(arr[5])->getB() > (win_size - dynamic_cast<tEllipse*>(arr[5])->getY()))
				dynamic_cast<tEllipse*>(arr[5])->setVecY(-1 * dynamic_cast<tEllipse*>(arr[5])->getVecY());
				switch (action)
				{
					case 0:
						dynamic_cast<tTriangle*>(arr[5])->move();
						break;
					case 1:
						dynamic_cast<tEllipse*>(arr[5])->rotate(i);
						break;
					case 2:
						dynamic_cast<tEllipse*>(arr[5])->move();
						dynamic_cast<tEllipse*>(arr[5])->rotate(i);
						break;
				}

			Display();
		}
			

	glutTimerFunc(5, timer, 0);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(win_size, win_size);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("6");
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, win_size, 0, win_size);
	glutDisplayFunc(Display);
	timer();
	glutMainLoop();	
}
