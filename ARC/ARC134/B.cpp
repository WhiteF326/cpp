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
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  ll n; cin >> n;
  string s; cin >> s;

  int right = n - 1;
  int left = 0;
  for(int i = 0; i < 26; i++){
    for(int j = right; j > left; j--){
      if(s[j] == 'a' + i){
        bool flg = true;
        while(s[left] <= 'a' + i){
          left++;
          if(left == n){
            flg = false;
            break;
          }
        }

        if(flg && left < j){
          swap(s[left], s[j]);
          right = j - 1;
        }
      }
    }
  }

  cout << s << endl;
}
