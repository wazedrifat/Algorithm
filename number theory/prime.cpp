w #include<bits / stdc++.h> using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n", (long long)clock() * 1000 / CLOCKS_PER_SEC);
#define MX 1000005 //1e6+5
#define LLI long long int

bool flag[MX];
vector<int> prime;

void SieveOfEratosthenes(int limit = MX)
{
	prime.clear();
	flag[0] = flag[1] = 1;

	prime.push_back(2);

	for (int i = 4; i <= limit; i += 2)
		flag[i] = 1;

	for (int i = 3; i * i < limit; i += 2)
		if (flag[i] == 0)
			for (int j = i * i; j <= limit; j += 2 * i)
				flag[j] = 1;

	for (int i = 3; i <= limit; i += 2)
		if (flag[i] == 0)
			prime.push_back(i);
}

bool SegmentedSieve_flag[MX];
vector<LLI> SegPrime;

void SegmentedSieve(LLI a, LLI b)
{
	SegPrime.clear();
	prime.clear();
	SieveOfEratosthenes((int)sqrt(b));
	if (a == 1)
		a++;

	for (LLI i = a + a & 1; i <= b; i += 2)
		SegmentedSieve_flag[i] = 1;

	for (int i = 0; i < prime.size() && prime[i] * prime[i] <= b; i++)
	{
		LLI p = prime[i];
		LLI j = p * p;

		if (j < a)
			j = ((a + p - 1) / p) * p;

		for (; j <= b; j += 2 * p)
			SegmentedSieve_flag[j - a] = 1;
	}

	for (LLI i = a; i <= b; i++)
		if (!SegmentedSieve_flag[i - a])
			SegPrime.push_back(i);
}

#define PII pair<int, int>
vector<PII> factors; //base, power i.e. (2^2) * (5^1) * (7^2)
void factorize(int n)
{
	int sqrtn = sqrt(n);
	for (int i = 0; i < prime.size() && prime[i] <= sqrtn; i++)
	{
		if (n % prime[i] == 0)
		{
			int cnt = 0;
			while (n % prime[i] == 0)
			{
				n /= prime[i];
				cnt++;
			}
			factors.push_back(PII(prime[i], cnt));
			sqrtn = sqrt(n);
		}
	}
	if (n != 1)
	{
		factors.push_back(PII(n, 1));
	}
}

int NumberOfDivisors(int n)
{
	int res = 1;
	prime.clear();
	SieveOfEratosthenes(n); //if use sqrt(n), remove flag[n] from loop cndition

	for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n && flag[n]; i++)
		if (n % prime[i] == 0)
		{
			int cnt = 0;
			for (; n && n % prime[i] == 0; cnt++)
				n /= prime[i];

			res *= cnt + 1;
		}

	if (n != 1)
		res = res << 1;
	return res;
}

int main()
{
	SieveOfEratosthenes();
	SegmentedSieve(100000, 200000);
	PrimeFactorization(980);
	int nod_252 = NumberOfDivisors(252);
}
