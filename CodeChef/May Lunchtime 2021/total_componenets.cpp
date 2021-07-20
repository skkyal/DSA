#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;

int N=1e7+1;
vector<int>p(N+1,0);
void seive(){
	for(int i=3;i<=N;i+=2) p[i]=1;
	p[2]=1;

	for(int i=3;i*i<=N;i=i+2){
		if(p[i]==1){
			for(int j=i*i;j<=N;j=j+i){
				p[j]=0;
			}
		}
	}
	for(int i=1;i<=N;i++) p[i]+=p[i-1];
}


void solve(){
	int n;cin>>n;
	if(n<=3){
		cout<<n-1<<"\n";
		return;
	}

	cout<<p[n]-p[n/2]+1<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	cin>>t;
	seive();
	while(t--){
		solve();
	}
}