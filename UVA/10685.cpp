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

vector<int>parent, rnk;
int n, m;
void makeSet()
{
	parent.clear();
	rnk.clear();
	parent.resize(n + 1);
	rnk.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		rnk[i] = 0;
		parent[i] = i;
	}
}

int find_set(int u)
{
	if (u == parent[u])
		return u;
	return parent[u] = find_set(parent[u]);
}

void UnionSet(int u, int v)
{
	u = find_set(u);
	v = find_set(v);
	if (u!=v)
	{
		if (rnk[u] < rnk[v])
			swap(u, v);
		parent[v] = u;
		if (rnk[u] == rnk[v])
			rnk[u]++;
	}
}
int main()
{
	fast();
	while (cin >> n >> m)
	{
		if (!n&&!m)
			break;
		makeSet();
		map<string, int> mp;
		map<int, int> cnt;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			mp[s] = i + 1;
		}
		for (int i = 0; i < m; i++)
		{
			string u, v;
			cin >> u >> v;
			if (find_set(mp[u]) != find_set(mp[v]))
				UnionSet(mp[u], mp[v]);
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt[find_set(i)]++;
			res = max(res, cnt[parent[i]]);
		}
		cout << res << endl;
	}
	return 0;
}