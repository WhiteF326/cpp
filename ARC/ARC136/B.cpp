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


// Ο(1)
void triple_swap(int &a, int &b, int &c){
  int tmp = a;
  a = c;
  c = b;
  b = tmp;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> a(n);
  aryin(a, n);
  vector<int> b(n);
  aryin(b, n);

  for(int i = 0; i < n - 3; i++){
    // pos を算出
    int pos = -1;
    for(int j = i; j < n; j++){
      if(a[j] == b[i]){
        pos = j;
        break;
      }
    }
    if(pos == -1){
      cout << "No" << endl;
      return 0;
    }

    // 一番後ろなら一度前へ
    if(pos == n - 1){
      triple_swap(a[pos - 2], a[pos - 1], a[pos]);
      pos -= 2;
    }
    // 偶奇が一致しなかったら一度前へ
    if(pos % 2 != i % 2){
      triple_swap(a[pos - 1], a[pos], a[pos + 1]);
      pos++;
    }
    // 後ろへ移動する
    while(pos > i){
      triple_swap(a[pos - 2], a[pos - 1], a[pos]);
      pos -= 2;
    }
  }

  // 残る最後の 3 要素を swap してみて一致するか？
  for(int i = 0; i < 3; i++){
    if(a[n - 3] == b[n - 3] && a[n - 2] == b[n - 2] && a[n - 1] == b[n - 1]){
      cout << "Yes" << endl;
      return 0;
    }
    triple_swap(a[n - 3], a[n - 2], a[n - 1]);
  }

  cout << "No" << endl;
}
