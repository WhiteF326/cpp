#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n, p; cin >> n >> p;
  vector<int> a(n);
  aryin(a, n);

  sort(all(a));

  unordered_map<int, int> hs;
  for(int i = 0; i < n; i++){
    hs[(a[i] - i + p) % p]++;
  }

  queue<int> q;

  int ptr = 0;

  for(int i = max(1, a[n - 1] - n); i <= a[n - 1]; i++){
    if(ptr < n){
      while(i > a[ptr]){
        hs[(a[ptr] - ptr + p) % p]--;
        ptr++;
      }
    }
    bool flg = true;
    // left
    if(hs[(i + 1) % p]){
      flg = false;
    }
    // right
    if(ptr >= p) flg = false;
    if(flg) q.push(i);
  }
  cout << q.size() << endl;
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }cout << endl;
}