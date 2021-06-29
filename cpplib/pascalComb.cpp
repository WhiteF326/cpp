#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
  usage : pascalComb(s)
  s = max value you want to use -> Ο(s²)
  
  method C returns nCr
*/

struct pascalComb{
  vector<vector<ll>> f;
  int size;
  
  pascalComb(int size){
    this->size = size;

    f.resize(size + 5);
    for(int i = 0; i <= size; i++) f[i].resize(size + 5);
    f[0][0] = 1;
    for(int i = 1; i <= size; i++){
      f[i][0] = 1;
      for(int j = 1; j <= size; j++){
        f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
      }
    }
  }

  ll C(int n, int r){
    assert(n <= this->size);
    assert(r <= this->size);
    assert(r <= n);
    
    return f[n][r];
  }
};

int main(){
  cout << pascalComb(40).C(40, 20) << endl;
}