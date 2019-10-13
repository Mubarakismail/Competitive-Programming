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
const int nn = 1e5 + 15;
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };

int main()
{
	fast();
	int n;
	while (cin>>n)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		if (n == 1)
			cout << "Jolly\n";
		else
		{
			set<int> st;
			for (int i = 0; i < n - 1; i++)
				st.insert(abs(arr[i] - arr[i + 1]));
			int x = 1;
			int res = 0;
			for (auto it : st)
			{
				if (it != x)
					res = 1;
				else
					x++;
			}
			if (x == n&&!res)
				cout << "Jolly\n";
			else
				cout << "Not jolly\n";
		}
	}
	return 0;
	
}
