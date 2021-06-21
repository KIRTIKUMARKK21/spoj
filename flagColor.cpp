#include<bits/stdc++.h>
using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define   pb              push_back
#define   rep(i,a,b)      for(int i=a;i<b;i++)
#define   vl              vector<ll>
#define   vi              vector<int>
#define   lb              lower_bound
#define   ub              upper_bound
// vector<vector<int>> vec( n , vector<int> (m, 0));
// priority_queue<pi, vector<pi>, greater<pi>>q;
typedef int64_t ll;
#define   pi              pair<ll, int>
bool prime[100000];
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
//https://codeforces.com/contest/1534/problem/A
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool dfs(vector<vector<char>>&mat, int i, int j, int n, int m)
{
	for (int k = 0; k < 4; k++)
	{
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if ((i1 >= 0 && i1 < n) && (j1 >= 0 && j1 < m))
		{
			if (mat[i1][j1] != '.')
			{
				if (mat[i][j] == mat[i1][j1])
				{
					return 0;
				}

			}
			else
			{
				if (mat[i][j] == 'R')
				{
					mat[i1][j1] = 'W';
				}
				else
				{
					mat[i1][j1] = 'R';

				}
				if (!dfs(mat, i1, j1, n, m))
				{
					return 0;
				}
			}

		}

	}
	return 1;


}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mat( n , vector<char> (m, '0'));
	bool flag = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
			if (mat[i][j] != '.')
			{
				flag = 1;
			}
			/* code */
		}
		/* code */
	}
	if (flag == 0)
	{
		mat[0][0] = 'R';
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mat[i][j] != '.')
			{
				if (!dfs(mat, i, j, n, m))
				{
					cout << "NO" << endl;
					return;
				}
			}

		}
		// cout << endl;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << mat[i][j] << "" ;

		}
		cout << endl;

	}



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

