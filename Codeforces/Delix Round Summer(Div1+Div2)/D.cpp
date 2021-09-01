#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

void solve(){
	ll n,k,x,y;
	cin>>n>>k;

	vector<ll>a(n-1),b(n-1),c(n-1);
	for(ll i=1;i<=n-1;i++){
		cout<<"or "<<" "<<i<<" "<<i+1<<endl;//fflush(stdout);
		cin>>b[i-1];

		cout<<"and "<<" "<<i<<" "<<i+1<<endl;//fflush(stdout);
		cin>>c[i-1];

		a[i-1]=b[i-1]-c[i-1]; 
	}

	for(ll i=2;i<n-1;i++){
		b[i]=b[i]|b[i-1];
		c[i]=c[i]&c[i-1];
	}

	ll c1=b[n-1]-c[n-1];
	b[n-1]=b[n-1]|b[0];
	c[n-1]=c[n-1]&c[0];

	ll c2=b[n-1]-c[n-1];

	a[0]=c1^c2;
	vector<ll>arr(n);
	for(ll i=0;i<n;i++){
		arr[i+1]=a[i]^arr[i];
	}

	/*ll xor1=0,xor2=0;

	for(ll i=0;i<n-1;i++){
		if(i!=0)
			xor2=xor2
	}*/

	sort(arr.begin(),arr.end());
	cout<<"finish "<<arr[k-1]<<endl;//fflush(stdout);
	
}
 

int main() {
	//ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
	}
}