#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m; vector<vector<int>> sp(n, vector<int>(2, 0));
  int ac = 0, wa = 0;
  for(int i = 0; i < m; i++){
    int p; cin >> p; string s; cin >> s;
    if(s == "AC"){sp[p - 1][0] = 1;}
    else if(s == "WA" && sp[p - 1][0] == 0){sp[p - 1][1]++;}
  }
  for(int i = 0; i < n; i++){
    if(sp[i][0] == 1){wa += sp[i][1]; ac++;}
  }
  cout << ac << " " << wa << endl;
}