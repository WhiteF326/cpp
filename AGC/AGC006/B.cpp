#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  
  int n, x; cin >> n >> x;

  if(x == 1 || x == 2 * n - 1){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;

    if(n == 2){
      cout << "1\n2\n3" << endl;
      return 0;
    }

    set<int> s;
    for(int i = 0; i < 2 * n - 1; i++){
      s.insert(i + 1);
    }
    vector<int> rv(0);
    vector<int> acc = {3, 0, 1, 2};
    if(x == 2 * n - 2){
      for(int i = x - 2; i <= 2 * n - 1; i++){
        s.erase(s.find(i));
        rv.push_back(i);
      }
      for(int i = 0; i < 4; i++){
        acc[i] = (acc[i] + 2) % 4;
      }
    }else{
      for(int i = x - 1; i <= x + 2; i++){
        s.erase(s.find(i));
        rv.push_back(i);
      }
    }

    auto itr = s.begin();
    for(int i = 0; i < (2 * n - 5) / 2; i++){
      cout << *itr << endl;
      itr++;
    }
    for(int i = 0; i < 4; i++){
      cout << rv[acc[i]] << endl;
    }
    for(int i = 0; i < (2 * n - 5) / 2 + 1; i++){
      cout << *itr << endl;
      itr++;
    }
  }
}