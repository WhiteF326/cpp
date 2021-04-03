#include <bits/stdc++.h>
using namespace std;

int fact(int x){
  return x <= 1 ? 1 : x * fact(x - 1);
}

int main(){
  int n; cin >> n; vector<vector<int>> pos(n, vector<int>(2));
  vector<int> per(n);
  for(int i = 0; i < n; i++){
    cin >> pos[i][0] >> pos[i][1];
    per[i] = i + 1;
  }
  double ans = 0.0;
  for(int i = 0; i < fact(n); i++){
    double dist = 0.0;
    for(int j = 0; j < n - 1; j++){
      int l = per[j] - 1, m = per[j + 1] - 1;
      dist += sqrt(pow(pos[l][0] - pos[m][0], 2) + pow(pos[l][1] - pos[m][1], 2));
    }
    ans += dist;
    next_permutation(per.begin(), per.end());
  }
  cout << fixed << setprecision(12) << (ans / fact(n)) << endl;
}