#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int t; cin >> t;
  query(t){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    map<char, int> c;
    for(char v : s) c[v]++;

    vector<int> vc(0);
    for(auto p : c) vc.push_back(p.second);

    int cx = vc.size();
    int o = 0, e = 0;
    for(int i = 0; i < cx; i++){
      if(vc[i] % 2){
        o++;
      }
      e += vc[i] / 2;
    }

    if(o == 0){
      if(k % 2 == 0){
        cout << n / k << "\n";
      }else{
        cout << max(1, (e / k) * 2) << "\n";
      }
    }else{
      if(o >= k){
        cout << 1 + (e / k) * 2 << "\n";
      }else{
        if((o % k) + (e % k) >= k){
          cout << min((int)ceil((double)e / k) * 2, 1 + (e / k) * 2) << "\n";
        }else{
          cout << max(1, (e / k) * 2) << "\n";
        }
      }
    }
  }

  fflush(stdout);
}