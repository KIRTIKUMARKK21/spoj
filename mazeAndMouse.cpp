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

// https://www.spoj.com/problems/MICEMAZE/

void solve()
{
	int n, e, t;
	cin >> n >> e >> t;
	vector<pi>adj[n + 1];
	int q;
	cin >> q;
	while (q--)
	{
		int m1, m2, w;
		cin >> m1 >> m2 >> w;
		adj[m1].pb({w, m2});

	}
	int ans = 0;
	for (int start = 1; start < n + 1; start++)
	{
		std::vector<int>visited(n + 1, 0);
		std::vector<ll>dist(n + 1, 1e18);
		priority_queue<pi, vector<pi>, greater<pi>>q;
		dist[start] = 0;
		q.push({0, start});
		while (!q.empty())
		{
			ll w = q.top().first;
			int city = q.top().second;
			if (city == e)
			{
				if (w <= t)
				{
					ans++;
				}
				break;
			}
			q.pop();
			if (!visited[city])
			{
				visited[city] = 1;
				for (auto it : adj[city])
				{
					int c2 = it.second;
					ll w2 = it.first;
					if (dist[city] + w2 < dist[c2])
					{
						dist[c2] = dist[city] + w2;
						q.push({dist[c2], c2});
					}
				}
			}
		}
	}
	cout << ans << endl;



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	solve();
	return 0;
}


