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

// https://cses.fi/problemset/task/1679/


const int N = 2e5 + 5;
vector<int>vis(N, 0);
stack<int>st;
vector<int>vis1(N, 0);
vector<int>pathvis(N, 0);
vector<int>par(N, 0);
int start ;
int endp;
bool cycleindg(int node, vector<int>adj[], int parent = -1)
{
	vis1[node] = 1;
	pathvis[node] = 1;
	par[node] = parent;
	for (auto it : adj[node])
	{
		if (!vis1[it])
		{
			if (cycleindg(it, adj, node))
			{
				return true;
			}
		}
		else if ( pathvis[it])
		{
			start = it;
			endp = node;
			return true;
		}
	}
	pathvis[node] = 0;
	return false;
}
void toposort(int node, vector<int>adj[])
{
	vis[node] = 1;
	for (auto it : adj[node])
	{
		if (!vis[it])
		{
			toposort(it, adj);
		}

	}
	st.push(node);
}
void solve()
{
	int n, m;
	cin >> n >> m;
	vector<int>adj[n + 1];
	for (int i = 0; i < m; ++i)
	{
		int c1, c2;
		cin >> c1 >> c2;
		adj[c1].pb(c2);
		/* code */
	}
	bool flag = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!vis1[i])
		{
			if (cycleindg(i, adj))
			{
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			toposort(i, adj);

		}

	}

	while (st.size() > 0)
	{
		cout << st.top() << " ";
		st.pop();
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
	solve();
	return 0;
}


