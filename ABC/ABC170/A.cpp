#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  for(int i = 0; i < 5; i++){
    int x; cin >> x;
    if(x == 0){cout << i + 1 << endl; return 0;}
  }
}