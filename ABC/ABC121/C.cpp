#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, m; cin >> n >> m; vector<pair<long long, long long>> ab;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;
    ab.push_back(make_pair(a, b));
  }
  sort(ab.begin(), ab.end());
  long long ans = 0; int pointer = 0;
  while(m > 0){
    ans += ab[pointer].first * min(ab[pointer].second, m);
    m -= ab[pointer].second;
    pointer++;
  }
  cout << ans << endl;
}