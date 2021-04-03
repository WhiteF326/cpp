#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;
  for(int i = 0; i < k; i++){
    if(n == 0){break;}
    vector<int> s((int)ceil(log10(n + 1)));
    for(int i = 0; i < s.size(); i++){
      s[i] = (n / (int)pow(10, s.size() - 1 - i)) % 10;
    }
    sort(s.begin(), s.end()); n = 0;
    for(int i = 0; i < s.size(); i++){
      n += s[i] * (int)pow(10, i);
    }
    for(int i = 0; i < s.size(); i++){
      n -= s[s.size() - 1 - i] * (int)pow(10, i);
    }
  }
  cout << n << endl;
}