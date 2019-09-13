int Set(int MASK, int pos) { return MASK = MASK | (1 << pos); }
int reset(int MASK, int pos) { return MASK = MASK & ~(1 << pos); }
bool check(int MASK, int pos) { return (bool)(MASK & (1 << pos)); }

int count(int MASK)
{
	int count = 0;

	for (int pos = 0; (1 << pos) < MASK; pos++)
		if (check(MASK, pos))
			count++;

	return count;
}

bool IsPowerOfTwo(int x)
{
	return (x && !(x & (x - 1)));
}

long long int LargestPowerOfTwo(long long int N) //lower_bound
{
	N = N | (N >> 1);
	N = N | (N >> 2);
	N = N | (N >> 4);
	N = N | (N >> 8);

	return (N + 1) >> 1;
}

int next_popcount(int n)
{
	int c = (n & -n);
	int r = n + c;
	return (((r ^ n) >> 2) / c) | r;
}

1. x ^ (x & (x - 1))	   // Returns the rightmost 1 in binary representation of x
	1010 = 010 2. x & (-x) // Returns the rightmost 1 in binary representation of x
		   1010 = 0010,
	1000 = 1000, 10101000 = 1000 3. x | (1 << n) // Returns the number x with the nth bit set.
							1010 = 1110

				 // Odd - Even checking ==>>
				 int x;
if (x & 1)
	-- > Odd else -- > Even

						   // 2^n dara gun or vag ==>>
						   gun-- > x << n
										   vag-- >
		x >> n

		// 2^n or 2 er power kina ==>>
		int x;
if (x & (x - 1))
	-- > 2 er power na else -- > 2 er power

									 // 2^n dara divisible naki ==>>
									 let,
		d = 2 ^ n

			int x,
		d = 8; // 8=2^3
if (x & (d - 1))
	-- > x, d dara divisible else -- > x, d dara divisible na

		//SWAP ==>>
		int x,
		y;
x = x ^ y;
y = x ^ y;
x = x ^ y;
