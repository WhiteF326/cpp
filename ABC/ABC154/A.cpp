#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  string s, t; cin >> s >> t;
  int a, b; cin >> a >> b;
  unordered_map<string, int> d;
  for(int i = 0; i < a; i++) d[s]++;
  for(int i = 0; i < b; i++) d[t]++;
  string u; cin >> u; d[u]--; int ans = 0;
  cout << d[s] << " " << d[t] << endl;
}