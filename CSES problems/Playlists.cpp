#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;
	cin>>n;
	unordered_map<int,int>m;
	m.reserve(n);
	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	int len=0,ans=0,st=0;
	for(int i=0;i<n;i++){
		if(m[a[i]]==0){
			len++;
			ans=max(ans,len);
			m[a[i]]=1;
		}
		else{
			m[a[st]]=0;
			st++;
			i--;
			len--;
		}
		//cout<<len<<" ";
	}
	cout<<ans;
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