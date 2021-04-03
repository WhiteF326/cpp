#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; scanf("%d", &n);
  vector<double> v(n);
  for(int i = 0; i < n; i++){scanf("%lf", &v[i]);}
  while(v.size() > 1){
    sort(v.begin(), v.end());
    double a = (v[0] + v[1]) / 2;
    v.erase(v.begin(), v.begin() + 2);
    v.push_back(a);
  }
  printf("%lf", v[0]);
}