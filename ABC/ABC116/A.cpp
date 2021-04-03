#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  vector<int> lng(3);
  for(int i = 0; i < 3; i++) cin >> lng[i];
  sort(lng.begin(), lng.end());
  cout << (lng[0] * lng[1] / 2) << endl;
}