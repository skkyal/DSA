#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
// lookup[i][j] is going to
// store index of minimum value in
// arr[i..j]. Ideally lookup
// table size should not be fixed
// and should be determined using
// n Log n. It is kept
// constant to keep code simple.
ll lookup[200005][100];
 
// Structure to represent a query range
struct Query {
    ll L, R;
};
 
// Fills lookup array
// lookup[][] in bottom up manner.
void preprocess(vector<ll>arr, ll n)
{
    // Initialize M for the
    // llervals with length 1
    for (ll i = 0; i < n; i++)
        lookup[i][0] = i;
 
    // Compute values from smaller
    // to bigger llervals
    for (ll j = 1; (1 << j) <= n; j++)
    {
        // Compute minimum value for
        // all llervals with size
        // 2^j
        for (ll i = 0; (i + (1 << j) - 1) < n; i++)
        {
            // For arr[2][10], we
            // compare arr[lookup[0][3]]
            // and arr[lookup[3][3]]
            if (arr[lookup[i][j - 1]]
                < arr[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j]
                    = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
 
// Returns minimum of arr[L..R]
ll query(vector<ll>&arr, ll L, ll R)
{
    // For [2,10], j = 3
    ll j = (ll)log2(R - L + 1);
 
    // For [2,10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (arr[lookup[L][j]]<= arr[lookup[R - (1 << j) + 1][j]])
        return arr[lookup[L][j]];
 
    else
        return arr[lookup[R - (1 << j) + 1][j]];
}
 
// Prlls minimum of given
// m query ranges in arr[0..n-1]

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	preprocess(a, n);

	for(ll i=0;i<m;i++){
		ll u,v;
		cin>>u>>v;
		cout<< query(a, u-1, v-1) << "\n";
	}

	//RMQ(a, n, q, m);

}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
