#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;

  int key = 0;
  for(int i = 1; i * (i - 1) / 2 <= 100000; i++){
    if((i * (i - 1) / 2) == n){
      key = i;
    }
  }

  if(key){
    vector<queue<int>> anslist(key);
    int ctr = 0;
    for(int i = 0; i < key - 1; i++){
      for(int j = i + 1; j < key; j++){
        anslist[i].push(ctr);
        anslist[j].push(ctr);
        ctr++;
      }
    }

    cout << "Yes" << endl;
    cout << key << endl;

    for(int i = 0; i < key; i++){
      cout << anslist[i].size() << " ";
      while(!anslist[i].empty()){
        cout << anslist[i].front() + 1 << " ";
        anslist[i].pop();
      }
      cout << endl;
    }
  }else{
    cout << "No" << endl;
  }
}