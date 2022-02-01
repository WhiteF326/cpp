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
  
  int t; cin >> t;
  query(t){
    int n; cin >> n;
    vector<int> a(n);
    aryin(a, n);

    priority_queue<int> q;
    for(int e : a) q.push(e);

    vector<bool> filled(n + 1, false);
    while(!q.empty()){
      int d = q.top();
      q.pop();
      if(d > n){
        q.push(d / 2);
      }else if(filled[d] && d != 1){
        q.push(d / 2);
      }else{
        filled[d] = true;
      }
    }

    bool ans = true;
    for(int i = 1; i <= n; i++){
      if(filled[i] == false) ans = false;
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}