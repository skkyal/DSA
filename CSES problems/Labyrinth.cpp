#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;

	vector<string>a(n);
	string b,ans;
	for(int i=0;i<n;i++) cin>>a[i];

	int sx,sy,ex,ey;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='A')
				sx=i,sy=j;
			else if(a[i][j]=='B')
				ex=i,ey=j;
		}
	}

	int dx[4]={-1,0,1,0};
	int dy[4]={0,1,0,-1};
	string step="URDL";

	vector<vector<bool>>v(n,vector<bool>(m,false));
	vector<vector<int>>prev(n,vector<int>(m));
	queue<pair<int,int>>q;
	q.push({sx,sy});
	v[sx][sy]=true;

	while(!q.empty()){
		int xx=q.front().first,yy=q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			int x=xx+dx[i],y=yy+dy[i];
			if(x<0 || y<0 || x>=n || y>=m || a[x][y]=='#' ||v[x][y]==true) continue;

			v[x][y]=true;
			prev[x][y]=i;
			if(x==ex && y==ey) break;
			q.push({x,y});
		}

	}

	if(v[ex][ey]){
		cout<<"YES"<<"\n";
		vector<int> s;

		while(!(sx==ex && sy==ey)){
			int x=prev[ex][ey];
			s.push_back(x);
			ex-=dx[x],ey-=dy[x];
		}
		reverse(s.begin(),s.end());
		cout<<s.size()<<"\n";
		for(int i=0;i<s.size();i++){
			cout<<step[s[i]];
		}
	}
	else{
		cout<<"NO";
	}


	
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}