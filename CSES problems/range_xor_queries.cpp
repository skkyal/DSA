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
		tree[si]=constructSt(ss,mid,2*si+1)^
				 constructSt(mid+1,se,2*si+2);
		return tree[si];
	}

	ll getSumUtil(ll qs,ll qe,ll ss,ll se,ll si){
		if(se<qs || ss>qe) return 0;
		if(qs<=ss && qe>=se) return (ll)tree[si];
		ll mid=(ss+se)/2;

		return	getSumUtil(qs,qe,ss,mid,2*si+1)^
				getSumUtil(qs,qe,mid+1,se,2*si+2);
	}

	void updateUtil(ll ss,ll se,ll i,ll val,ll si,ll diff){
		if(i<ss || i>se) return;
		
		if(ss==se)	tree[si]=val;	

		if(se>ss){
			ll mid=(ss+se)/2;
			updateUtil(ss,mid,i,val,2*si+1,diff);
			updateUtil(mid+1,se,i,val,2*si+2,diff);

			tree[si]=min(tree[2*si+1],tree[2*si+2]);
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
		ll diff=val-arr[i];
		arr[i]=val;
		updateUtil(0,arr.size()-1,i,val,0,diff);
	}
};

void solve(){
	ll n,m;
	cin>>n>>m;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	SegmentTree st(a);

	for(ll i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		//cout<<x<<" ";
		//if(x==2)
		cout<<st.getSum(a-1,b-1)<<"\n";
		//else st.update(a-1,b);
		
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