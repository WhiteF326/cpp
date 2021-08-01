#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  int x, y; cin >> x >> y;
  vector<vector<int>> b(x - 1, vector<int>(y - 1));
  for(int i = 0; i < x - 1; i++){
    for(int j = 0; j < y - 1; j++){
      cin >> b[i][j];
      assert(b[i][j] > 0 && b[i][j] <= 10e+9);
    }
  }
  assert(x > 0 && x <= 100);
  assert(y > 0 && y <= 100);

  vector<vector<int>> a(x, vector<int>(y, 1));

  for(int i = 1; i < x; i++){
    for(int j = 1; j < y; j++){
      a[i][j] = b[i - 1][j - 1] ^ a[i - 1][j] ^ a[i][j - 1] ^ a[i - 1][j - 1];
    }
  }
  cout << "Yes" << endl;
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}