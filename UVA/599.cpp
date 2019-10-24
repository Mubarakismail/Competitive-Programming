#define __USE_MINGW_ANSI_STDIO
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long long ull;
typedef pair<ll, ll> ii;

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
const int nn = 2e2 + 15;
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };

vector<int> gr[nn];
int vis[nn];
int cnt = 0;
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

int main()
{
	fast();
	int tc;
	cin >> tc;
	cin.ignore();
	while (tc--)
	{
		string s;
		while (getline(cin,s)&&s[0]!='*')
		{
			int u = s[1] - 'A';
			int v = s[3] - 'A';
			gr[u].push_back(v);
			gr[v].push_back(u);
		}
		getline(cin, s);
		int trees = 0, acorn = 0;
		for (int i = 0; i < sz(s); i += 2)
		{
			int node = s[i] - 'A';
			if (!vis[node])
			{
				DFS(node);
				if (cnt == 1)
					acorn++;
				else
					trees++;
				cnt = 0;
			}
		}
		cout << "There are " << trees << " tree(s) and " << acorn << " acorn(s).\n";
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < nn; i++)
			gr[i].clear();
	}
	return 0;
}