#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  string s[n]; int p[n], no[n];
  for(int i = 0; i < n; i++){cin >> s[i] >> p[i]; no[i] = i + 1;}
  for(int i = 0; i < n - 1; i++){
    for(int j = i + 1; j < n; j++){
      if(s[i] > s[j] || (s[i] == s[j] && p[i] < p[j])){
        swap(s[i], s[j]); swap(no[i], no[j]); swap(p[i], p[j]);
      }
    }
  }
  for(int i = 0; i < n; i++){cout << no[i] << endl;}
}