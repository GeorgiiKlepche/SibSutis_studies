#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <GL/glut.h>
#include <cmath>
#include "rectangle.h"
#include "point.h"

class tRhombus : public tRectangle
{
	private:
		float _R2;
	public:
		tRhombus(float a, float b);
		tRhombus();
		void setR(float a);
		void setR2(float b);

		virtual void setXtl(float c, float fi = 0);
		virtual void setYtl(float c, float fi = 0);
		virtual void setXtr(float c, float fi = 0);
		virtual void setYtr(float c, float fi = 0);
		virtual void setXbl(float c, float fi = 0);
		virtual void setYbl(float c, float fi = 0);
		virtual void setXbr(float c, float fi = 0);
		virtual void setYbr(float c, float fi = 0);

		float getR2();
		virtual void draw();
};

#endif
