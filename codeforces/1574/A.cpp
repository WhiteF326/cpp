#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define const constexpr
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;


int main(){
  int t; cin >> t;
  for(int i = 0; i < t; i++){
    int n; cin >> n;
    
    string s = "";
    for(int i = 0; i < n; i++) s += "()";
    
    cout << s << endl;
    for(int j = 0; j < n - 1; j++){
      swap(s[j * 2 + 1], s[j * 2 + 2]);
      cout << s << endl;
    }
  }
}