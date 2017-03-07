#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#define MOD 1000000007
using namespace std;

long long r, c, res;

long long rev2, rev6;


inline long long sum(long long range)
{
	return (range + 1) * range % MOD * rev2 % MOD;
}

inline long long square(long long range)
{
	// n(n + 1)(2n + 1) / 6;
	return range * (range + 1) % MOD * (2 * range + 1) % MOD * rev6 % MOD;
}

inline long long cube(long long range)
{
	long long res = sum(range);
	return res * res % MOD;
}


long long ExGCD(long long a, long long b, long long& x, long long& y) // ax+by=1
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	long long d = ExGCD(b, a%b, x, y);
	long long temp = x;
	x = y;
	y = temp - a / b*y;
	return d;
}


int main()
{
		freopen("A-large.in", "r", stdin);
		freopen("A-large.out", "w", stdout);

	int q;
	int cs, n_case;
	scanf("%d", &n_case);
	//rev2 = (1 + MOD) / 2;
	long long dum;
	ExGCD(2, MOD, rev2, dum);
	rev2 = (rev2 % MOD + MOD) % MOD;
	//cout << 2 * rev2 % MOD << endl;
	
	ExGCD(6, MOD, rev6, dum);
	rev6 = (rev6 % MOD + MOD) % MOD;
	//cout << 6 * rev6 % MOD << endl;

	//for (long long i = 1; i <= MOD; i++)
	//{
	//	if (i * 2 % MOD == 1)
	//		rev2 = i;
	//	else if (i * 6 % MOD == 1)
	//		rev6 = i;
	//}
	for (int cs = 1; cs <= n_case; cs++)
	{
		scanf("%lld %lld", &r, &c);
		res = 0;
		if (r > c) //ensure r <= c
		{
			long long tmp = r;
			r = c;
			c = tmp;
		}

		r--; c--;
		long long rc1 = (r + c + 1) % MOD;

		long long c0 = (r * c % MOD + rc1) % MOD;
		long long c1 = rc1 + 1;

		long long answer = c0 * sum(r) % MOD + cube(r) - c1 * square(r);

		printf("Case #%d: %lld\n", cs, (answer % MOD + MOD) % MOD);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}