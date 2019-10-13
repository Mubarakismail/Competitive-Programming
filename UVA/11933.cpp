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

string to_Binary(ll x)
{
	string res = "";
	while (x>0)
	{
		res += char(x % 2 + '0');
		x /= 2;
	}
	return res;
}

ll To_Decinmal(string s)
{
	ll x = 1, res = 0;
	for (int i = 0; i < sz(s); i++)
	{
		res += (s[i] - '0')*x;
		x *= 2;
	}
	return res;
}

void split(string s)
{
	string fst = "", lst = "";
	int cnt = 0;
	for (int i = 0; i < sz(s); i++)
	{
		if (s[i] == '1')
		{
			if (cnt % 2)
				lst += "1", fst += "0";
			else
				fst += "1", lst += "0";
			cnt++;
		}
		else
			fst += "0", lst += "0";
	}
	cout << To_Decinmal(fst) << " " << To_Decinmal(lst) << endl;
}

int main()
{
	fast();
	ll x;
	while (cin>>x,x)
	{
		string s = to_Binary(x);
		split(s);
	}
	return 0;
}
