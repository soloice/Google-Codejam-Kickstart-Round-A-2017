#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define MAXN 2050
using namespace std;

int n;
long long x[MAXN], y[MAXN], z[MAXN], r[MAXN];
long long xmin, xmax, ymin, ymax, zmin, zmax;

// enumerate 4 possible pairs of opposite vertices
bool left_bottom_corner(long long edge) // xmin, ymin, zmin
{
	for (int k = 0; k < n; k++)
	{
		//can't be put into the lower or upper cube
		if ((x[k] + r[k] > xmin + edge || y[k] + r[k] > ymin + edge || z[k] + r[k] > zmin + edge) && 
			(x[k] - r[k] < xmax - edge || y[k] - r[k] < ymax - edge || z[k] - r[k] < zmax - edge))
			return false;
	}
	return true;
}

bool right_bottom_corner(long long edge) // xmax, ymin, zmin
{
	for (int k = 0; k < n; k++)
	{
		//can't be put into the lower or upper cube
		if ((x[k] - r[k] < xmax - edge || y[k] + r[k] > ymin + edge || z[k] + r[k] > zmin + edge) &&
			(x[k] + r[k] > xmin + edge || y[k] - r[k] < ymax - edge || z[k] - r[k] < zmax - edge))
			return false;
	}
	return true;
}

bool left_top_corner(long long edge)  // xmin, ymax, zmin
{
	for (int k = 0; k < n; k++)
	{
		//can't be put into the lower or upper cube
		if ((x[k] + r[k] > xmin + edge || y[k] - r[k] < ymax - edge || z[k] + r[k] > zmin + edge) &&
			(x[k] - r[k] < xmax - edge || y[k] + r[k] > ymin + edge || z[k] - r[k] < zmax - edge))
			return false;
	}
	return true;
}

bool right_top_corner(long long edge)  // xmax, ymax, zmin
{
	for (int k = 0; k < n; k++)
	{
		//can't be put into the lower or upper cube
		if ((x[k] - r[k] < xmax - edge || y[k] - r[k] < ymax - edge || z[k] + r[k] > zmin + edge) &&
			(x[k] + r[k] > xmin + edge || y[k] + r[k] > ymin + edge || z[k] - r[k] < zmax - edge))
			return false;
	}
	return true;
}

int solve()
{
	int i;
	long long low = 0, high = 0, mid;
	xmin = x[0]; ymin = y[0]; zmin = z[0];
	xmax = x[0]; ymax = y[0]; zmax = z[0];
	for (i = 0; i < n; i++)
	{
		xmin = min(x[i] - r[i], xmin);	xmax = max(x[i] + r[i], xmax);
		ymin = min(y[i] - r[i], ymin);	ymax = max(y[i] + r[i], ymax);
		zmin = min(z[i] - r[i], zmin);	zmax = max(z[i] + r[i], zmax);
	}
	high = max(max(xmax - xmin, ymax - ymin), zmax - zmin);

	while (high - low > 1) // the answer lies in (low, high]
	{
		mid = (high + low) / 2;
		if (left_bottom_corner(mid) || left_top_corner(mid) || right_bottom_corner(mid) || right_top_corner(mid))
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	return int(high);
}

int main()
{
	freopen("C-large-practice.in", "r", stdin);
	freopen("C-large-practice.out", "w", stdout);

	int cs, n_case;
	scanf("%d", &n_case);
	for (int cs = 1; cs <= n_case; cs++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld %lld %lld %lld", &x[i], &y[i], &z[i], &r[i]);
		}
		printf("Case #%d: %d\n", cs, solve());
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}