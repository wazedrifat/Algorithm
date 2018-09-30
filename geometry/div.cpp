PII add_div(PII x , PII y)
{
	PII temp;
	
	INT GCD=__gcd(x.second,y.second);
	INT LCM=(x.second/GCD)*y.second;
	
	temp.second=LCM;
	temp.first=(LCM/x.second)*x.first+(LCM/y.second)*y.first;
	
	GCD=__gcd(temp.first,temp.second);
	temp.first/=GCD;
	temp.second/=GCD;
	
	return temp;
}

PII subs_div(PII x , PII y)
{
	PII temp;
	
	INT GCD=__gcd(x.second,y.second);
	INT LCM=(x.second/GCD)*y.second;
	
	temp.second=LCM;
	temp.first=(LCM/x.second)*x.first-(LCM/y.second)*y.first;
	
	GCD=__gcd(temp.first,temp.second);
	temp.first/=GCD;
	temp.second/=GCD;
	
	return temp;
}

PII mult_div(PII x , PII y)
{
	PII temp;
	
	temp.first=x.first*y.first;
	temp.second=x.second*y.second;
	
	INT GCD=__gcd(temp.first,temp.second);
	temp.first/=GCD;
	temp.second/=GCD;
}

PII div_div(PII x , PII y)
{
	PII temp;
	
	temp.first=x.first*y.second;
	temp.second=x.second*y.first;
	
	INT GCD=__gcd(temp.first,temp.second);
	temp.first/=GCD;
	temp.second/=GCD;
}