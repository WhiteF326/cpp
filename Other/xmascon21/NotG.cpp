#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n;
    cin >> n;
    long long x=0,tg=0;
    for(long long i=0;i<n;i++){
      tg^=i;
      long long v;
      cin >> v;
      x^=v;
    }
    if(x==tg){cout << "White\n";}
    else{cout << "Black\n";}
  }
  return 0;
}