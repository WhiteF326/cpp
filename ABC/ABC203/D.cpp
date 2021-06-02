#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

int main(){
  int n, k; cin >> n >> k;
  vector<vector<int>> stage(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) cin >> stage[i][j];
  }

  vector<vector<int>> medians(n, vector<int>(n - k + 1));
  for(int i = 0; i < n; i++){
    multiset<int, greater<int>> res;
    for(int j = 0; j < k - 1; j++){
      res.insert(stage[i][j]);
    }
    for(int j = k - 1; j < n; j++){
      res.insert(stage[i][j]);
      auto itr = res.begin();
      for(int x = 0; x < (int)floor(k / 2) + 1; x++) itr++;
      medians[i][j - k + 1] = *itr;
      res.erase(res.find(stage[i][j - k + 1]));
    }
  }

  vector<int> ans;
  for(int i = 0; i < n - k + 1; i++){
    for(int j = 0; j < k - 1; j++){
      multiset<int, greater<int>> res;
      for(int y = 0; y < k; y++){
        res.insert(medians[j + y][i]);
      }
      auto itr = res.begin();
      for(int x = 0; x < (int)floor(k / 2) + (k % 2); x++) itr++;
      ans.push_back(*itr);
    }
    
  }
  cout << *min_element(ans.begin(), ans.end()) << endl;
}