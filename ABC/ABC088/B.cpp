#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n); vector<int> a(n);
  for(int i = 0; i < n; i++){scanf("%d", &a[i]);}
  sort(a.begin(), a.end(), greater<int>());
  vector<int> score(2);
  for(int i = 0; i < n; i++){
    score[i % 2] += a[i];
  }
  printf("%d", score[0] - score[1]);
}