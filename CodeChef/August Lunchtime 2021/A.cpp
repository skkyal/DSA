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
	long long n,k,m=INT_MIN,ans=0;
	cin>>n>>k;

	vector<long long>a(n);
	for(long long i=0;i<n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}

	//long long m=*max_element(a.begin(),a.end()),ans=0;
	//cout<<m<<" ";
	for(long long i=0;i<n;i++){
		if(a[i]==m && i+1-k>=0){
			ans+=1LL*(n-i);
		}
	}

	cout<<ans<<"\n";
}
 

int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";
		//x++;
		solve();
	}
}