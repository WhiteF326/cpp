#include <bits/stdc++.h>
using namespace std;

int main(){
  int k, n; scanf("%d%d", &k, &n);
  vector<int> po(n);
  for(int i = 0; i < n; i++){scanf("%d", &po[i]);}
  vector<int> dist(n);
  for(int i = 0; i < n; i++){
    dist[i] = po[(i + 1) % n] - po[i];
    if(dist[i] < 0){dist[i] += k;}
  }
  sort(dist.begin(), dist.end());
  int ans = 0;
  for(int i = 0; i < n - 1; i++){ans += dist[i];}
  printf("%d", ans);
}