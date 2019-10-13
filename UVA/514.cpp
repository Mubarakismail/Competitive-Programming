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

vector<int> dirB, dirA;
stack<int> st;
void intial(int n)
{
	dirA.clear();
	for (int i = 1; i <= n; i++)
		dirA.push_back(i);
	while (st.size())
	{
		st.pop();
	}
}

int main()
{
	fast();
	int n;
	while (cin >> n, n)
	{
		dirB.clear();
		dirB.resize(n);
		while (cin >> dirB[0], dirB[0])
		{
			for (int i = 1; i < n; i++)
				cin >> dirB[i];
			intial(n);
			int idx = 0;
			for (int i = 0; i < n; i++)
			{
				if (idx < n&&dirA[i] == dirB[idx])
					idx++;
				else if (st.size() && st.top() == dirB[idx])
				{
					i--;
					st.pop();
					idx++;
				}
				else
					st.push(dirA[i]);
			}
			while (idx<n&& st.size())
			{
				if (st.top() == dirB[idx])
				{
					idx++;
					st.pop();
				}
				else
					break;
			}
			if (st.empty())
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		cout << endl;
	}
	return 0;
}
