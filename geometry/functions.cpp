
struct POINT
{
	INT xx, yy;
};
struct EQUATION
{
	INT a, b, c;
}; //

bool onSegment(POINT pp, POINT qq, POINT rr)
{
	if (qq.xx <= max(pp.xx, rr.xx) && qq.xx >= min(pp.xx, rr.xx) && qq.yy <= max(pp.yy, rr.yy) && qq.yy >= min(pp.yy, rr.yy))
		return true;
	else
		return false;
}

INT orientation(POINT p1, POINT p2, POINT p3)
{
	INT val = (p2.yy - p1.yy) * (p3.xx - p2.xx) - (p2.xx - p1.xx) * (p3.yy - p2.yy);

	if (val == 0)
		return 0; // colinear

	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool doIntersect(POINT p1, POINT q1, POINT p2, POINT q2)
{
	INT o1 = orientation(p1, q1, p2);
	INT o2 = orientation(p1, q1, q2);
	INT o3 = orientation(p2, q2, p1);
	INT o4 = orientation(p2, q2, q1);

	if (o1 != o2 && o3 != o4)
		return true;

	if (o1 == 0 && onSegment(p1, p2, q1)) // p1, q1 and p2 are colinear and p2 lies on segment p1q1
		return true;

	if (o2 == 0 && onSegment(p1, q2, q1)) // p1, q1 and p2 are colinear and q2 lies on segment p1q1
		return true;

	if (o3 == 0 && onSegment(p2, p1, q2)) // p2, q2 and p1 are colinear and p1 lies on segment p2q2
		return true;

	if (o4 == 0 && onSegment(p2, q1, q2)) // p2, q2 and q1 are colinear and q1 lies on segment p2q2
		return true;

	return false;
}

EQUATION convert_to_equation(POINT p1, POINT p2)
{
	EQUATION temp;

	temp.aa = p2.yy - p1.yy;
	temp.bb = p1.xx - p2.xx;
	temp.cc = p1.yy * (p2.xx - p1.xx) + p1.xx * (p1.yy - p2.yy);

	return temp;
}

POINT sol_2_equation(EQUATION eq1, EQUATION eq2)
{
	POINT temp;

	INT value = eq1.aa * eq2.bb - eq2.aa * eq1.bb;

	POINT pp;

	pp.xx = 0;
	pp.yy = 0;

	if (value == 0)
		return pp;

	temp.xx = (eq1.bb * eq2.cc - eq2.bb * eq1.cc) / value;
	temp.yy = (eq1.cc * eq2.aa - eq2.cc * eq1.aa) / value;

	return temp;
}

POINT sol_2_eq_from_point(POINT p1, POINT p2, POINT p3, POINT p4)
{
	EQUATION eq1, eq2;

	eq1 = convert_to_equation(p1, p2);
	eq2 = convert_to_equation(p2, p3);

	POINT temp = sol_2_equation(eq1, eq2);

	return temp;
}
