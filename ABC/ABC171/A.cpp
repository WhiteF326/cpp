#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
void manyIntInput(vector<int> s){
  for(int i = 0; i < s.size(); i++) cin >> s[i];
}

int main(){
  char a[2]; cin >> a;
  if(a[0] < 'a') cout << "A";
  else cout << "a";
  cout << endl;
}