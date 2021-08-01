#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char** argv){
  ifstream i_ifs(argv[1]);
  ifstream o_ifs(argv[2]);
  ifstream c_ifs(argv[3]);
  
  // same input
  int x, y; i_ifs >> x >> y;
  vector<vector<int>> b(x - 1, vector<int>(y - 1));
  for(int i = 0; i < x - 1; i++){
    for(int j = 0; j < y - 1; j++){
      i_ifs >> b[i][j];
    }
  }

  // code res
  string j; cin >> j;
  vector<string> yeslist = {
    "yes",
    "Yes",
    "yEs",
    "yeS",
    "YeS",
    "YEs",
    "yES",
    "YES"
  };
  bool flg = false;
  for(string jx : yeslist){
    if(jx == j) flg = true;
  }
  if(!flg) abort();
  vector<vector<int>> a(x, vector<int>(y));
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      cin >> a[i][j];
      if(a[i][j] < 0 || a[i][j] > 10e+9){
        cerr << "A" << to_string(i) << ", " << to_string(j) << " is bigger than 10e+9 or smaller than 1" << endl;
        abort();
      }
    }
  }

  // validate
  for(int i = 0; i < x - 1; i++){
    for(int j = 0; j < y - 1; j++){
      if((a[i][j] ^ a[i + 1][j] ^ a[i][j + 1] ^ a[i + 1][j + 1]) != b[i][j]){
        cerr << "Wrong Answer at " << to_string(i) << ", " << to_string(j) << endl;
        abort();
      }
    }
  }

  return 0;
}