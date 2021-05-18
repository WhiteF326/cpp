#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int h, w; cin >> h >> w;
  vector<string> s(h, "");
  for(int i = 0; i < h; i++) cin >> s[i];

  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  vector<vector<pair<bool, int>>> stage(h, vector<pair<bool, int>>(w, make_pair(false, 0)));
  bool flg = false;

  while(q.empty()){
    //
  }

}