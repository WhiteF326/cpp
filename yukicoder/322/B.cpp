#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  string s; cin >> s;
  string tomake = "kyoprotenkei90";
  map<char, int> ap, bp;
  for(int i = 0; i < 14; i++){
    ap[tomake[i]]++;
  }
  for(int i = 0; i < 14; i++){
    bp[s[i]]++;
  }
  for(auto x : ap){
    if(bp[x.first] < x.second){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}