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
const ll inf = 100000000;
const int N = 200005;
int tree[2 * N];
int n;
void update(int k, int x) {
	k += n;
	tree[k] = x; k >>= 1;
	while (k >= 1) {
		tree[k]  = min(tree[2 * k], tree[2 * k + 1]);
		k >>= 1;
	}
}
int query(int a, int b) {
	a += n, b += n;
	int s = inf;
	while (a <= b) {
		if (a & 1) s = min(s, tree[a++]);
		if (~b & 1) s = min(s, tree[b--]);
		a >>= 1, b >>= 1;
	}
	return s;
}
void solve()
{
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		arr[i] = v;
		update(i, v);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 1)
		{
			int mi = query(l - 1, r - 1);
			int cnt = 0;
			for (int i = l - 1; i < r; i++)
			{
				if (arr[i] == mi)
				{
					cnt++;
				}

			}
			update(l + cnt - 2, mi);
			arr[l + cnt - 2] = mi;

		}
		if (c == 2)
		{
			cout << query(l - 1, r - 1) << endl;
		}
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


