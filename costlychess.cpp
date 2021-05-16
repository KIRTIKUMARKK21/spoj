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
#define   pp              pair<int,int>
#define   pi              pair<ll, pp>
int dx[] = {2, 2, -2, -2, 1, -1, -1, 1};
int dy[] = {1, -1, -1, 1, 2, 2, -2, -2};
void solve(int a)
{

	int b, c, d;
	cin >> b >> c >> d;
	int visited[8][8] = {0};
	vector<vector<ll>> dist( 8 , vector<ll> (8, 1e18));
	dist[a][b] = 0;
	priority_queue<pi, vector<pi>, greater<pi>>q;
	q.push({0, {a, b}});
	while (!q.empty())
	{
		ll w = q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		if (x == c && y == d)
		{
			cout << w << endl;
			return;
		}
		q.pop();
		if (!visited[x][y])
		{
			visited[x][y] = 1;
			for (int i = 0; i < 8; i++)
			{
				int xn = x + dx[i];
				int yn = y + dy[i];
				if ((xn >= 0 && xn < 8) && (yn >= 0 && yn < 8))
				{
					if (dist[x][y] + x * xn + y * yn < dist[xn][yn])
					{
						dist[xn][yn] = dist[x][y] + x * xn + y * yn;
						q.push({dist[xn][yn], {xn, yn}});
					}
				}
			}
		}

	}
	cout << -1 << endl;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int a;
	while (cin >> a)
	{
		solve(a);
	}
	return 0;
}


