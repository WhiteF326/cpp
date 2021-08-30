#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
  ll n, m; cin >> n >> m;

  ll d = 1, c = 0;
  while(n > m * d){
    d *= 3;
    c++;
  }

  cout << c << endl;
}
