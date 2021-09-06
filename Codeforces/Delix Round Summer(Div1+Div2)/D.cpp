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

	vector<ll>a(n-1),b(n-1),c(n-1),arr;
	for(ll i=1;i<=n-1;i++){
		cout<<"or "<<" "<<i<<" "<<i+1<<endl;//fflush(stdout);
		cin>>b[i-1];

		cout<<"and "<<" "<<i<<" "<<i+1<<endl;//fflush(stdout);
		cin>>c[i-1];

		a[i-1]=b[i-1]+c[i-1]; 
	}

	cout<<"or "<<" "<<1<<" "<<3<<endl;//fflush(stdout);
	cin>>x;

	cout<<"and "<<" "<<1<<" "<<3<<endl;//fflush(stdout);
	cin>>y;

	x=x+y;
	x=(a[0]+a[1]-x)/2;
	arr.push_back(a[0]-x);
	x=a[0]-x;

	for(ll i=0;i<n-1;i++){
		x=a[i]-x;
		arr.push_back(x);
	}

	sort(arr.begin(),arr.end());
	cout<<"finish "<<arr[k-1]<<endl;//fflush(stdout);
	
}
 

int main() {
	//ipop();

	int t=1,x=1;
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
	}
}