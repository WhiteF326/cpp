#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n,x,y,ans;cin>>n>>x;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  vector<bool>b(n,false);
  y=x-1;
  ans=0;
  while(1){
    if(b[y]==false){
      b[y]=true;
      y=a[y]-1;
      ans++;
    } 
    else break;
  }
  // rep(i,n)cout<<b[i];
  // cout<<endl;
  cout<<ans<<endl;
	return 0;
}
