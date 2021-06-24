#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int q; cin >> q;
  deque<int> d;
  queue<int> anslist;
  for(int i = 0; i < q; i++){
    int t, x; cin >> t >> x;
    if(t == 1){
      d.push_front(x);
    }else if(t == 2){
      d.push_back(x);
    }else{
      anslist.push(d[x - 1]);
    }
  }
  while(!anslist.empty()){
    cout << anslist.front() << endl;
    anslist.pop();
  }
}