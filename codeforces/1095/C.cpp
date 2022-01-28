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
  
  int n, k; cin >> n >> k;
  int ch = 0;
  for(int i = 0; i < 31; i++){
    if(n & (1 << i)) ch++;
  }
  if(ch > k){
    cout << "NO" << endl;
  }else{
    priority_queue<int> q;
    for(int i = 0; i < 31; i++){
      if(n & (1 << i)) q.push(1 << i);
    }
    while(q.size() != k){
      int d = q.top();
      if(d == 1){
        cout << "NO" << endl;
        return 0;
      }
      q.pop();
      q.push(d / 2);
      q.push(d / 2);
    }

    cout << "YES" << endl;
    for(int i = 0; i < k; i++){
      cout << q.top() << " ";
      q.pop();
    }
    cout << endl;
  }
}