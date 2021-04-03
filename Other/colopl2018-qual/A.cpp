#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  int a, b; cin >> a >> b;
  string s; cin >> s;
  if(a <= s.length() && s.length() <= b){
    cout << "YES";
  }else cout << "NO";
  cout << endl;
}