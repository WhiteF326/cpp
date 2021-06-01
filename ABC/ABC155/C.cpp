#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(i, j) make_pair(i, j);
using ll = long long;
using ld = long double;

int main(){
  int n; cin >> n;
  map<string, int> a;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    a[s]++;
  }
  int maxapr = 0;
  for(auto itr = a.begin(); itr != a.end(); itr++){
    maxapr = max(maxapr, itr->second);
  }
  vector<string> anslist;
  for(auto itr = a.begin(); itr != a.end(); itr++){
    if(itr->second == maxapr){
      anslist.push_back(itr->first);
    }
  }
  sort(anslist.begin(), anslist.end());
  for(int i = 0; i < anslist.size(); i++){
    cout << anslist[i] << endl;
  }
}