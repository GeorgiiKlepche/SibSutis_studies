#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <GL/glut.h>
#include <cmath>
#include "point.h"
#include <iostream>

class tEllipse : public tPoint
{
	private:
		float _A;
		float _B;

		float _R;
		float _Angle;
		float _fi;
		float _tX;
		float _tY;
	public:
		tEllipse(float A, float B);
		tEllipse();
		virtual void setA(float A);
		virtual void setB(float B);
		virtual void setAngle(float Angle);
		virtual void setR();
		virtual void setfi(float fi = 0);
		virtual void settX();
		virtual void settY();

		float getA();
		float getB();
		float getR();
		float getAngle();
		float gettX();
		float gettY();
		float getfi();

		float grTOrad(float Gr);
		virtual void rotate(float Gr);
		virtual void move();
		virtual void draw();
};


#endif
