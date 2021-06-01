#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int gcd(int i, int j){
  if(i % j){
    return gcd(j, i % j);
  }else return j;
}

int main(){
  int x; cin >> x;
  vector<bool> primeList(100201, true);
  primeList[1] = false;
  for(int i = 2; i < 317; i++){
    if(primeList[i]){
      for(int j = i * 2; j <= 100200; j += i){
        primeList[j] = false;
      }
    }
  }
  while(!primeList[x]) x++;
  cout << x << endl;
}