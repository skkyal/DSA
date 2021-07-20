#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree{
	vector<ll>tree,arr;

	ll constructSt(ll ss,ll se,ll si){
		if(ss==se){
			tree[si]=arr[ss];
			return arr[ss];
		}
		ll mid=(ss+se)/2;
		tree[si]=constructSt(ss,mid,2*si+1)+
				 constructSt(mid+1,se,2*si+2);
		return tree[si];
	}

	ll getSumUtil(ll qs,ll qe,ll ss,ll se,ll si){
		if(se<qs || ss>qe) return 0;
		if(qs<=ss && qe>=se) return (ll)tree[si];
		ll mid=(ss+se)/2;

		return	(ll)getSumUtil(qs,qe,ss,mid,2*si+1)+
				(ll)getSumUtil(qs,qe,mid+1,se,2*si+2);
	}

	void updateUtil(ll ss,ll se,ll i,ll si,ll diff){
		if(i<ss || i>se) return;
		tree[si]=tree[si]+diff;
		if(se>ss){
			ll mid=(ss+se)/2;
			updateUtil(ss,mid,i,2*si+1,diff);
			updateUtil(mid+1,se,i,2*si+2,diff);
		}
	}
public:
	SegmentTree(vector<ll>&a){
		tree.resize(4*a.size(),0);
		arr=a;
		constructSt(0,a.size()-1,0);
	}

	ll getSum(ll a,ll b){
		return getSumUtil(a,b,0,arr.size()-1,0);
	}

	void update(ll i,ll val){
		ll diff=val;
		arr[i]+=val;
		updateUtil(0,arr.size()-1,i,0,diff);
	}
};

void solve(){
	ll n,m;
	cin>>n>>m;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	for(ll i=n-1;i>=1;i--) a[i]=a[i]-a[i-1];

	SegmentTree st(a);

	for(ll i=0;i<m;i++){
		ll x,a,b,u;
		cin>>x;
		if(x==1){
			cin>>a>>b>>u;
				st.update(a-1,u);
			if(b<n)
				st.update(b,-u);
		}
		else{
			cin>>a;
			cout<<st.getSum(0,a-1)<<"\n";
		}
	}
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