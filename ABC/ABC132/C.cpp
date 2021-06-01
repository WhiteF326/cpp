#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> dif(n);
  for(int i = 0; i < n; i++){scanf("%d", &dif[i]);}
  sort(dif.begin(), dif.end());
  cout << dif[n / 2] - dif[n / 2 - 1] << endl;
}