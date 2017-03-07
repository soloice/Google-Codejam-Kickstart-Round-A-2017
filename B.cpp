#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#define MAXN (2050*4)
using namespace std;

bool f[MAXN][MAXN];
char s1[MAXN], s2[MAXN], buffer[MAXN];

// replace a '*' with 4 '?'s, where '?' can match 0~1 ordinary character.
void replace(char* s)
{
	int l = strlen(s);
	for (int i=0, j=0; i <= l; i++)
	{
		if (s[i] == '*')
		{
			buffer[j] = buffer[j + 1] = buffer[j + 2] = buffer[j + 3] = '?';
			j += 4;
		}
		else
		{
			buffer[j++] = s[i];
		}
	}
	strcpy(s, buffer);
}


bool dp()
{
	// f[i][j]: if s1[0..i) matches s2[0..j)
	int l1 = strlen(s1), l2 = strlen(s2);
	char* ss1 = s1 - 1;
	char* ss2 = s2 - 1;
	memset(f, 0, sizeof(f));
	int i, j, k, l, cnt;
	f[0][0] = true;
	// fill f[0][j]
	for (j = 1; ss2[j] == '?'; j++)
		f[0][j] = true;
	// fill f[i][0]
	for (i = 1; ss1[i] == '?'; i++)
		f[i][0] = true;


	for (i = 1; i <= l1; i++)
	{
		for (j = 1; j <= l2; j++)
		{
			bool c1 = (ss1[i] == '?'), c2 = (ss2[j] == '?');
			if (c1 && c2)
			{
				f[i][j] = f[i - 1][j] || f[i][j - 1] || f[i - 1][j - 1];
			}
			else if (c1 && !c2)
			{
				f[i][j] = f[i - 1][j] || f[i - 1][j - 1];
			}
			else if (!c1 && c2)
			{
				f[i][j] = f[i][j - 1] || f[i - 1][j - 1];
			}
			else
			{
				f[i][j] = f[i-1][j-1] && (ss1[i] == ss2[j]);
			}
		}

	}

	return f[l1][l2];
}

int main()
{
	freopen("B-large-practice.in", "r", stdin);
	freopen("B-large-practice.out", "w", stdout);

	int q;
	int cs, n_case;
	scanf("%d", &n_case);
	for (int cs = 1; cs <= n_case; cs++)
	{
		scanf("%s", s1);
		scanf("%s", s2);
		replace(s1);
		replace(s2);
		if (dp())
			printf("Case #%d: TRUE\n", cs);
		else
		{
			printf("Case #%d: FALSE\n", cs);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}