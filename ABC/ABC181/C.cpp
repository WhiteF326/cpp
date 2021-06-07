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
  vector<pair<double, double>> points(n);
  for(int i = 0; i < n; i++){
    double x, y; cin >> x >> y;
    points[i] = mp(x, y);
  }

  for(int i = 0; i < n - 2; i++){
    for(int j = i + 1; j < n - 1; j++){
      for(int k = j + 1; k < n; k++){
        int x1 = points[i].first, y1 = points[i].second;
        int x2 = points[j].first, y2 = points[j].second;
        int x3 = points[k].first, y3 = points[k].second;
        x1 -= x3, x2 -= x3, y1 -= y3, y2 -= y3;
        if(x1 * y2 == x2 * y1){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}