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
const int nn = 2e6 + 15;
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };

int main()
{
	fast();
	string s;
	vector<string> arr;
	while (getline(cin,s))
	{
		if (s != "")
			arr.push_back(s);
	}
	string res = arr[0];
	for (int i = 1; i < sz(arr); i++)
	{
		if (res.back() == '-')
		{
			res.pop_back();
			res += arr[i];
		}
		else
		{
			res += " ";
			res += arr[i];
		}
	}
	set<string> ans;
	s = "";
	for (int i = 0; i < sz(res); i++)
	{
		if (isalpha(res[i]) || res[i] == '-')
			s += tolower(res[i]);
		else
		{
			if (sz(s))
				ans.insert(s);
			s = "";
		}
	}
	if (sz(s))
		ans.insert(s);
	for (auto it : ans)
		cout << it << endl;
	return 0;
}