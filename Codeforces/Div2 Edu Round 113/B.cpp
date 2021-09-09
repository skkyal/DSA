#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define mod 1000000007

ll MAX=LLONG_MAX;
ll MIN=LLONG_MIN;

ll pdouble(ll a){cout<<fixed<<setprecision(10)<<a;}
ll max(ll a,ll b,ll c){return max(a,max(b,c));}

void solve(){
	ll n;cin>>n;
	string s;cin>>s;

	vector<vector<char>>a(n,vector<char>(n,'#'));
	vector<bool>v(n,false);

	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			if(i==j) {a[i][j]='X';continue;}

			if(a[i][j]!='#') continue;

			if(s[i]=='1' && s[j]=='1'){
				a[i][j]='=';
				a[j][i]='=';
			}

			else if(s[i]=='1' && s[j]=='2'){
				a[i][j]='=';
				a[j][i]='=';
			}

			else if(s[i]=='2' && s[j]=='1'){
				a[i][j]='=';
				a[j][i]='=';
			}

			else if(s[i]=='2' && s[j]=='2'){
				if(!v[i]){
					v[i]=true;
					a[i][j]='+';
					a[j][i]='-';
				}
				else{
					a[i][j]='-';
					a[j][i]='+';
					v[j]=true;
				}
			}
		}
	}

	for(ll i=0;i<n;i++){
		if(s[i]=='2' && v[i]==false){
			cout<<"NO";return;
		}
	}

	cout<<"YES";
	for(ll i=0;i<n;i++){
		cout<<"\n";
		for(ll j=0;j<n;j++){
			cout<<a[i][j];
		}
	}
}
 

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}
int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
		cout<<"\n";
	}
}