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

int n;
vector<int> a(200);
vector<set<int>> mlist(200, set<int>());
bool found = false;

void dfs(int ptn, int depth){
  if(depth == min(8, n)) return;
  if(ptn && !found){
    int ptr = 0;
    for(int i = 0; i <= depth; i++){
      if(ptn & (1 << i)){
        ptr = (ptr + a[i]) % 200;
      }
    }
    mlist[ptr].insert(ptn);
    if(mlist[ptr].size() == 2){
      found = true;
      cout << "Yes" << endl;
      // decode
      for(int vl : mlist[ptr]){
        queue<int> anslist;
        for(int j = 0; j < 10; j++){
          if(vl & (1 << j)) anslist.push(j + 1);
        }
        cout << anslist.size() << " ";
        while(!anslist.empty()){
          cout << anslist.front() << " ";
          anslist.pop();
        }
        cout << endl;
      }
    }
  }
  if(!found) dfs(ptn + (1 << (depth + 1)), depth + 1);
  if(!found) dfs(ptn, depth + 1);
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  dfs(0, 0);
  dfs(1, 0);
  if(!found){
    cout << "No" << endl;
  }
}