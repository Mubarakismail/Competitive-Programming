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
int n;
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
	int tc, idx = 0;
	cin >> tc;
	while (tc--)
	{
		int res1 = 0, res2 = 0;
		cin >> n;
		makeSet();
		cin.ignore();
		string s;
		//getline(cin, s);
		while (getline(cin, s) && s != "")
		{
			stringstream ss(s);
			string type;
			int a, b;
			ss >> type >> a >> b;
			if (type == "c")
				UnionSet(a, b);
			else
			{
				if (find_set(a) == find_set(b))
					res1++;
				else
					res2++;
			}
		}
		if (idx)
			cout << endl;
		cout << res1 << "," << res2 << endl;
		idx++;
	}
	return 0;
}