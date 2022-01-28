#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define pdesc(t) t, vector<t>, greater<t>
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n; cin >> n;
  vector<int> a(n);
  aryin(a, n);

  map<int, int> dc;
  for(auto v : a){
    if(v % 4 == 0) dc[4]++;
    else if(v % 2 == 0) dc[2]++;
    else dc[1]++;
  }

  if(dc[4] - dc[1] >= -(n % 2)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}