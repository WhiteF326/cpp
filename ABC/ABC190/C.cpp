#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  vector<vector<int>> judge(m, vector<int>(2));
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a--; b--;
    judge[i][0] = a;
    judge[i][1] = b;
  }
  int k; cin >> k;
  vector<vector<int>> bNum(k, vector<int>(2));
  for(int i = 0; i < k; i++){
    int c, d; cin >> c >> d;
    c--; d--;
    bNum[i][0] = c;
    bNum[i][1] = d;
  }
  int ans = 0;
  vector<int> bin_digit(k, 0);
  for(int i = 0; i < (int)pow(2, k); i++){
    int res = 0;
    vector<int> dishes(n, 0);
    for(int j = 0; j < k; j++){
      dishes[bNum[j][bin_digit[j]]]++;
    }
    for(int j = 0; j < m; j++){
      if(dishes[judge[j][0]] > 0 && dishes[judge[j][1]] > 0){
        res++;
      }
    }
    ans = max(ans, res);
    bin_digit[0]++;
    for(int td = 0; td < k - 1; td++){
      if(bin_digit[td] == 2){
        bin_digit[td] = 0;
        bin_digit[td + 1]++;
      }else break;
    }
  }
  cout << ans << endl;
}