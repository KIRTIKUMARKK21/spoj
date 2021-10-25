// https://codeforces.com/contest/1602/problem/B

// changing of array will be stopped when frequency of element equals to its self 
// or when frequency of all element are different let it be f1,f2,f3,f4--fk.
// then in next step frequency of element becomes equal to itself .
// so let at starting frequency of two element were same say f
// second step frequency become 4f it will increse exponentially but number of element is less than
// n so max step will be log(N)

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
#define   print(ans)      printf("%.9f\n",ans)
#define all(x) (x).begin(), (x).end()
typedef int64_t ll;
typedef unsigned long long ull;
typedef long double lld;
#define   pi              pair<ll, int>
#define nline "\n"

//========================================Debugging Starts=================================

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << "\n";
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//==========================================Debugging Ends==========================================

// vector<vector<int>> vec( n , vector<int> (m, 0));
// priority_queue<pi, vector<pi>, greater<pi>>q;

bool prime[100000];
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
void SieveOfEratosthenes()
{
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= 100000; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p * p; i <= 100000; i += p)
				prime[i] = false;
		}
	}
}
long long binpow(long long a, long long b) {
	a %= MOD;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res % MOD
	       ;
}
ll invmd(ll n)
{
	return (binpow(n, MOD - 2));
}
void solve()
{
	int n;
	cin>>n;
	vector<int>v(n+1,0);
	rep(i,1,n+1)
	{
		cin>>v[i];
	}
	vector<vector<int>>dp;
	dp.pb(v);
	int cnt=0;
	// int t=50;
	while(1)
	{
		map<int,int>mp;
		rep(i,1,n+1)
		{
			mp[v[i]]++;

		}
		vector<int>temp(n+1,0);
		rep(i,1,n+1)
		{
			temp[i]=mp[v[i]];
		}
		vector<int>temp2=dp[dp.size()-1];
		if(temp2==temp)
		{
			break;
		}
		dp.pb(temp);
		v=temp;

	}
	debug(dp);
	int q;
	cin>>q;
	while(q--)
	{
		int x,k;
		cin>>x>>k;
		if(k>=dp.size()-1)
		{
			cout<<dp[dp.size()-1][x]<<nline;

		}
		else

		{
			cout<<dp[k][x]<<nline;
		}

	}
	

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}