#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;

#define query(t) for(int _ = 0; _ < t; _++)


int main(){
  int t; cin >> t;
  query(t){
    vector<int> x(3);
    for(int i = 0; i < 3; i++) cin >> x[i];
    sort(all(x), greater<int>());
    int m; cin >> m;

    int pos = accumulate(all(x), 0) - 3;
    if(m > pos) cout << "No" << endl;
    else if(m == pos){
      cout << "Yes" << endl;
    }else{
      int posm = max(0, x[0] - (x[1] + x[2]) - 1);
      if(posm <= m) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
  }
}