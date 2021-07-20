#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string s){
	for(ll i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-1-i])
			return false;
	}
	return true;
} 
void solve(){
	ll n,k,m=1e9+7;
	string s;
	cin>>n>>k;
	cin>>s;

	ll ans=1,sum=0,x,z=1,y,mid;

	if(n%2==0) mid=n/2;
	else mid=(n+1)/2;

	for(ll i=0;i<mid;i++){
		sum+=(z-1)*pow(k,n/2-i+1);

		x=s[i]-'a'+1,y=s[n-i-1]-'a'+1;
		if(i!=mid) z=min(x,y);
		
		ans=ans*x;
	
	}

	if(check(s)) ans=(ans-1+m)%m;
	/*if(n%2==1) {
		x=s[n/2]-'a';
		//cout<<x<<" ";
		ans=((ans%m)*((x+1)%m))%m;
	}*/

	cout<<ans<<" "<<sum<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1,x=1;
	cin>>t;
	
	while(t--){
		cout<<"Case #"<<x<<":"<<" ";
		x++;
		solve();
	}
}