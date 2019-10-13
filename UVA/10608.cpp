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
const int MOD = 1e3 + 7;
const int nn = 1e5 + 15;
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };

int n, m, cnt = 0;
vector<int> gr[nn];
int vis[nn];

void DFS(int u)
{
	vis[u] = 1;
	cnt++;
	for (auto it : gr[u])
	{
		if (!vis[it])
			DFS(it);
	}
}
void intial()
{
	for (int i = 0; i <= n; i++)
		gr[i].clear();
	memset(vis, 0, sizeof(vis));
}
int main()
{
	fast();
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			gr[u].push_back(v);
			gr[v].push_back(u);
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				DFS(i);
				res = max(res, cnt);
				cnt = 0;
			}
		}
		cout << res << endl;
		intial();
	}
	return 0;
}