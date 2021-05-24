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

// tree very nice question
// question based on finding descendants
// two facts are imp for this -> 
    // i-> if distance of node from root is d that means it is present at depth d
    // ii ->  if any node is coming in path of b\w node and root it must be present above the node so that node must be in subtree of other node

// https://atcoder.jp/contests/abc202/tasks/abc202_e




const int N = 400005;
vector<int>start(N, 0);
vector<int>end(N, 0);
vector<int>visited(N, 0);
vector<int>ans[N];
int t = 0;
void dfs(int node, vector<int>adj[], int depth = 0)
{
	start[node] = t++;
	visited[node] = 1;
	ans[depth].pb(start[node]);
	for (auto it : adj[node])
	{
		if (!visited[it])
		{
			dfs(it, adj, depth + 1);
		}
	}
	end[node] = t;
}
void solve()
{
	int n;
	cin >> n;
	vector<int>adj[n + 1];
	for (int i = 2; i < n + 1; i++)
	{
		int p;
		cin >> p;
		adj[p].pb(i);
		adj[i].pb(p);
	}
	dfs(1, adj);
	int q;
	cin >> q;
	while (q--)
	{
		int u, d;
		cin >> u >> d;
		cout << lb(ans[d].begin(), ans[d].end(), end[u]) - lb(ans[d].begin(), ans[d].end(), start[u]) << endl;
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


