#include <bits/stdc++.h>
using namespace std;

int main(){
  int nm; cin >> nm; vector<int> v(nm);
  for(int i = 0; i < nm; i++){ cin >> v[i]; }
  sort(v.begin(), v.end());
  vector<int> gcdl(v[nm - 1] + 1, 0);
  int maxgcdl = 0;
  for(int i = 2; i <= v[nm - 1]; i++){
    for(int j = 0; j < nm; j++){
      if(v[j] % i == 0){
        gcdl[i]++;
      }
    }
    if(gcdl[i] > gcdl[maxgcdl]){maxgcdl = i;}
  }
  cout << maxgcdl << endl;
}