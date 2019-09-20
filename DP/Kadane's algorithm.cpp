int MS()
{
	int maxi = INT_MIN, s = 0;

	for (int ii = 0; ii < n; ii++)
	{
		maxi = max(maxi, s + dp[ii]);
		s = max(0, s + dp[ii]);
	}

	return maxi;
}

PII MS()
{
	int maxi = INT_MIN, s = 0;
	PII answer;

	for (int ii = 0; ii < n; ii++)
	{
		cin >> a[ii];

		s += a[ii];

		if (maxi <= s)
		{
			maxi = s;
			answer.first = l;
			answer.second = ii;
		}

		if (s < 0)
		{
			s = 0;
			l = ii + 1;
		}
	}

	return answer;
}

int MS(int n, int m)
{
	int maxi = INT_MIN, s = 0, l = 0;
	PII p;
	p.first = 0;
	p.second = 0;

	FOR(i, 0, n - 1)
	{
		cin >> a[i];

		s += a[i];

		while (p.first <= i && s > m)
		{
			s -= a[l];
			l++;
		}

		if (s <= m && maxi <= s)
		{
			maxi = s;
			p.first = l;
			p.second = i;
		}

		if (s < 0)
		{
			s = 0;
			l = i + 1;
		}
	}

	return maxi;
}
