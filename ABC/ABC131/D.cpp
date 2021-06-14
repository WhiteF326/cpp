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
  int n; cin >> n;
  vector<pair<int, int>> jobs(n, pair<int, int>());
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    jobs[i] = make_pair(b, a);
  }
  sort(jobs.begin(), jobs.end());

  int t = 0;
  for(int i = 0; i < n; i++){
    t += jobs[i].second;
    if(jobs[i].first < t){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}