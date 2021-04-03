#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int n, k, x, y; cin >> n >> k >> x >> y;
  if(n > k){
    cout << k * x + (n - k) * y << endl;
  }else{
    cout << n * x << endl;
  }
}