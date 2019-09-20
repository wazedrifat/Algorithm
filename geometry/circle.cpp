#include <bits/stdc++.h>
using namespace std;

#define D double
#define PDD pair<double, double>
#define PI 2.0 * acos(0.0)

struct point
{ //(x, y)
	D x, y;
	point(D _x = 0, D _y = 0)
	{
		x = _x;
		y = _y;
	}
};

struct QEQ //1 variable
{		   //ax^2+bx+c=0
	D a, b, c;
	EQ(D _a = 0, D _b = 0, D _c = 0)
	{
		a = _a;
		b = _b;
		c = _c;
	}
};

struct EQ3 //3 variable
{		   //ax+by+cz+d=0
	D a, b, c, d;
	EQ3(D _a = 0, D _b = 0, D _c = 0, D _d = 0)
	{
		a = _a;
		b = _b;
		c = _c;
		d = _d;
	}
}

struct circleEQ
{ //x^2+y^2+2gx+2fy+c=0
	D g, f, c;

	circleEQ(D _g = 0, D _f = 0, D _c = 0)
	{
		g = _g;
		f = _f;
		c = _c;
	}

	D radius()
	{
		return sqrt(g * g + f * f - c);
	}

	D area()
	{
		D r = radius();
		return PI * r * r;
	}

	D AngleInCenter(point p1, point p2)
	{
		p1.x += g;
		p2.x += g; //shifting center to (0, 0) point
		p1.y += f;
		p2.y += f;

		D dot = p1.x *p2.x + p1.y *p2.y //a.b

								 D val = sqrt(p1.x * p1.x + p1.y * p1.y) * sqrt(p2.x * p2.x + p2.y * p2.y);
		//|a| |b|

		return acos(dot / val); //theta=cos-1 ( a.b / |a||b|)
	}

	void CreateEQ(point p1, point p2, point p3)
	{
	}

	int PositionOfPoint(point p)
	{ //1 for outside, 0 for on the line, -1 for inside circle
		int v = p.x * p.x + p.y * p.y + 2 * g * p.x + 2 * f * p.y + c;
		// EQ of circlr @ point p
		if (v > 0)
			return 1;
		else if (v == 0)
			return 0;
		else
			return -1;
	}
};

int main()
{
}
