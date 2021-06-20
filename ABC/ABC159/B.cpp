#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

bool isPalindrome(string s){
  bool res = true;
  for(int i = 0; i < s.length() / 2; i++){
    if(s[i] != s[s.length() - i - 1]) res = false;
  }
  return res;
}

int main(){
  string s; cin >> s;
  int n = s.length();
  if(n % 2 == 0){
    cout << "No" << endl;
  }else{
    if(isPalindrome(s) && isPalindrome(s.substr(0, (n - 1) / 2)) && isPalindrome(s.substr((n + 1) / 2))){
      cout << "Yes" << endl;
    }else cout << "No" << endl;
  }
}