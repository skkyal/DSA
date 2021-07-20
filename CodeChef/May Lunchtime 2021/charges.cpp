#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	long long n,k;
	string s;
	
	cin>>n>>k;
	cin>>s;

	vector<long long>a(k);
	for(long long i=0;i<k;i++) cin>>a[i];

	long long sum=0;
	for(long long i=1;i<n;i++){
		if(s[i-1]==s[i]) sum+=2;
		else sum++;
	}

	for(long long i=0;i<k;i++){
		long long x=a[i]-1;
		if(x<0 || x>=n) continue;

		if(x<n-1){
			if(s[x]==s[x+1]){
				sum=sum-2+1;
			}
			else{
				sum=sum-1+2;
			}
		}

		if(x>0){
			if(s[x-1]==s[x]){
				sum=sum-2+1;
			}
			else{
				sum=sum-1+2;
			}
		}

		if(s[x]=='1') s[x]='0';
		else s[x]='1';

		cout<<sum<<"\n";

	}
	
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