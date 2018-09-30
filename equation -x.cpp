pair<double,double> sol(INT a, INT b, INT c)
{
	double sum=sqrt(b*b-4*a*c);
	
	pair<double,double> temp;
	
	temp.first=(-b+sum)/(2.0*a);
	temp.second=(-b-sum)/(2.0*a);
}