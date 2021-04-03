#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n);
  vector<int> dif(n);
  for(int i = 0; i < n; i++){scanf("%d", &dif[i]);}
  sort(dif.begin(), dif.end());
  printf("%d", dif[n / 2] - dif[n / 2 - 1]);
}