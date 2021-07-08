#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  int f = stoi(s.substr(0, 2));
  int e = stoi(s.substr(2, 2));

  if(f > 0 && f <= 12 && e > 0 && e <= 12){
    cout << "AMBIGUOUS" << endl;
  }else if(f > 0 && f <= 12){
    cout << "MMYY" << endl;
  }else if(e > 0 && e <= 12){
    cout << "YYMM" << endl;
  }else cout << "NA" << endl;
}