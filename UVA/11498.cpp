#define __USE_MINGW_ANSI_STDIO
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define all(v)		((v).begin()), ((v).end())
#define sz(v)		((int)((v).size()))
#define endl		"\n"
#define fx(n)		fixed<<setprecision(n)
#define mk			make_pair	

void fast()
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	/*#ifdef ONLINE_JUDGE
	//freopen("output.txt", "w", stdout);
	freopen("path.in", "r", stdin);
	#endif*/
}
const double pi = 2 * acos(0.0);
const ll oo = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int nn = 1e3 + 15;
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };

int solve(pair<int, int> a, pair<int, int> b)
{
	if (a.first > b.first and a.second > b.second)
		return 1;
	else if (a.first < b.first and a.second > b.second)
		return 2;
	else if (a.first > b.first and a.second < b.second)
		return 4;
	else if (a.first < b.first and a.second < b.second)
		return 3;
	else
		return 0;
}


int main()
{
	fast();
	int tc;
	while (cin >> tc,tc)
	{
		pair<int, int> point;
		cin >> point.first >> point.second;
		for (int i = 0; i < tc; i++)
		{
			pair<int, int> x;
			cin >> x.first >> x.second;
			int res = solve(x, point);
			if (!res)
				cout << "divisa\n";
			else if (res == 1)
				cout << "NE\n";
			else if (res == 2)
				cout << "NO\n";
			else if (res == 3)
				cout << "SO\n";
			else
				cout << "SE\n";
		}
	}
	return 0;
}