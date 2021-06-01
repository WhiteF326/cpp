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
  sort(points.begin(), points.end());
  for(int i = 0; i < n - 2; i++){
    for(int j = i + 1; j < n - 1; j++){
      for(int k = j + 1; k < n; k++){
        // i, jから式を作ってkを判定する
        double a;
        if(points[j].first - points[i].first){
          a = (double)(points[j].second - points[i].second) / (double)(points[j].first - points[i].first);
        }else{
          a = 0;
        }
        double b = (double)points[i].second - (a * (double)points[i].first);
        if(points[k].second == points[k].first * a + b){
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}