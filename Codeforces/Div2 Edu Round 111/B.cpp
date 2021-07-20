#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,a,b;
	cin>>n>>a>>b;

	string s;
	cin>>s;

	ll f1=0,f2=0;
	ll ans=(a+b)*n,c1=0,c2=0,o=0,z=0;

	for(ll i=0;i<n;i++){
		if(s[i]=='0')
			z++;
		else{
			if(z>0){
				f1=1;
				c1=c1+(a*z+b);
			}
			z=0;
			o++;
		}
	}
	//cout<<ans<<" ";
	c1=c1+(a*o+b);
	if(z>0) c1=c1+(a*z+b);

	if(f1=1)
	ans=max(ans,c1);

	z=0;o=0;

	for(ll i=0;i<n;i++){
		if(s[i]=='1')
			o++;
		else{
			if(o>0){
				c2=c2+(a*o+b);
				f2=1;
			}
			o=0;
			z++;
		}
	}

	c2=c2+(a*z+b);
	if(o>0) c2=c2+(a*o+b);

	if(f2==1)
	ans=max(c2,ans);

	//cout<<c1<<" "<<c2<<" ";
	cout<<ans<<"\n";


}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}