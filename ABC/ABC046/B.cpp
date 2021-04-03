#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, k; cin >> n >> k;
  cout << k * (long long)pow(k - 1, n - 1) << endl;
}