#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) for(int _ = 0; _ < t; _++)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


namespace convexhull{
  template <typename T>
  class Point{
    public:
      T x, y;
      Point(T x, T y){
        this->x = x;
        this->y = y;
      }
      Point(){
        x = 0;
        y = 0;
      }

      bool operator< (const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
      }
  };

  template <typename T>
  struct ConvexHull{
    T cross(const Point<T> &O, const Point<T> &A, const Point<T> &B){
      return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
    }

    vector<Point<T>> convexHull(vector<Point<T>> P){
      int n = P.size();
      int k = 0;

      if(n <= 3) return P;
      vector<Point<T>> H(2 * n);

      sort(all(P));

      for(int i = 0; i < n; i++){
        while(k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
        H[k++] = P[i];
      }
      for(int i = n - 1, t = k + 1; i > 0; i--){
        while(k >= t && cross(H[k - 2], H[k - 1], P[i - 1]) <= 0) k--;
        H[k++] = P[i - 1];
      }

      H.resize(k - 1);
      return H;
    }
  };
}

using namespace convexhull;
int main(){
  int n; cin >> n;
  vector<Point<double>> a(n);
  for(int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    a[i] = Point<double>(x, y);
  }

  auto convexHull = ConvexHull<double>();
  auto ch = convexHull.convexHull(a);

  for(auto v : ch){
    cout << v.x << " " << v.y << endl;
  }
}