#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n), d(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(), a.end(), greater<int>());
  int first = a[0];
  // nearest with first / 2 ?
  for(int i = 0; i < n; i++){
    d[i] = abs(min(a[i] - ceil(first / 2), a[i] - floor(first / 2)));
  }
  d[0] = INT_MAX;
  int second = a[distance(d.begin(), min_element(d.begin(), d.end()))];

  cout << first << " " << second << endl;
}