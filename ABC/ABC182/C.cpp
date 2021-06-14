#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

const ll modv = 1000000007;

int main(){
  long long n; cin >> n;
  vector<int> digits(0);
  while(n > 0){
    digits.push_back((n % 10) % 3);
    n /= 10;
  }
  int diff = accumulate(digits.begin(), digits.end(), 0) % 3;
  if(diff == 0){
    cout << 0 << endl;
  }else if(diff == 1){
    // 1である桁を1個消すか2である桁を2個消す
    if(find(digits.begin(), digits.end(), 1) != digits.end() && digits.size() > 1){
      cout << 1 << endl;
    }else if(count(digits.begin(), digits.end(), 2) >= 2 && digits.size() > 2){
      cout << 2 << endl;
    }else cout << -1 << endl;
  }else{
    if(find(digits.begin(), digits.end(), 2) != digits.end() && digits.size() > 1){
      cout << 1 << endl;
    }else if(count(digits.begin(), digits.end(), 1) >= 2 && digits.size() > 2){
      cout << 2 << endl;
    }else cout << -1 << endl;
  }
}