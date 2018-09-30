#include<bits/stdc++.h>
using namespace std;

struct vec
{
	int a, b, c;
	vec()
	{
		a=b=c=0;
	}
};

vec cross(vec x, vecy)
{
	vec t;
	t.x=x.b*y.c-x.c*y.b;
	t.y=-x.a*y.c+x.c*y.a;
	t.z=x.a*y.b-y.a*x.b;
	
	return t;
}

int val(vec x)
{
	int t=x.a*x.a+x.b*x.b+x.c*x.c;
	return sqrt(t);
}

int main()
{

}

