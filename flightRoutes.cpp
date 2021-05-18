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

// https://cses.fi/problemset/task/1195
// flight_discount


void solve()
{
	int n, m;
	cin >> n >> m;
	std::vector<pi>adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int c1, c2, w;
		cin >> c1 >> c2 >> w;
		adj[c1].pb({w, c2});
	}
	std::vector<ll>disc(n + 1, 1e18);
	std::vector<ll>full(n + 1, 1e18);
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>>q;	
	// q.push({0, {1, 0}})
	q.push({0, {1, 0}});
	while (!q.empty())
	{
		ll d = q.top().first;
		int city = q.top().second.first;
		int flag = q.top().second.second;
		q.pop();
		if (flag == 1)
		{
			if (disc[city] < d) {continue;}
		}
		if (flag == 0)
		{
			if (full[city] < d)
			{
				continue;
			}
		}
		for (auto it : adj[city])
		{
			ll d2 = it.first;
			int c2 = it.second;
			// agar discount hai
			if (flag == 0)
			{
				// agle ko discount do
				if (d + d2 / 2 < disc[c2])
				{
					disc[c2] = d + d2 / 2;
					q.push({disc[c2], {c2, 1}});
				}

				// agle ko discount na do
				if (d + d2 < full[c2])
				{
					full[c2] = d + d2;
					q.push({full[c2], {c2, 0}});

				}

			}
			// agar discount nai hai
			if (flag == 1)
			{
				if (d + d2 < disc[c2])
				{
					disc[c2] = d + d2;
					q.push({disc[c2], {c2, 1}});
				}

			}
		}
	}
	cout << disc[n] << endl;

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

