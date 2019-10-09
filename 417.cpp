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

map<string, int> res;
bool valid(string s)
{
	set<char> st;
	for (int i = 0; i < sz(s); i++)
		st.insert(s[i]);
	return sz(st) == sz(s) && sz(s) < 6;
}

void generateRes()
{
	int idx = 1;
	queue<string> qq;
	qq.push("");
	while (!qq.empty())
	{
		string cur = qq.front();
		qq.pop();
		for (char i = 'a'; i <= 'z'; i++)
		{
			if (sz(cur) >= 1 && i <= cur.back())
				continue;
			cur += i;
			if (valid(cur))
			{
				res[cur] = idx;
				qq.push(cur);
				idx++;
			}
			cur.pop_back();
		}
	}
}

int main()
{
	fast();
	generateRes();
	string s;
	while (cin>>s)
	{
		if (res.find(s) == res.end())
			cout << 0 << endl;
		else
			cout << res[s] << endl;
	}
	return 0;
}