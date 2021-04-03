#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n; cin >> n;
  vector<long long> res(0);
  for(int i = 2; i <= (int)sqrt(n); i++){
    for(int j = 2; j <= log(n) / log(i); j++){
      auto itr = find(res.begin(), res.end(), (long long)pow(i, j));
      if(distance(res.begin(), itr) == res.size()){
        res.push_back(pow(i, j));
      }
    }
  }
  cout << n - res.size() << endl;
}