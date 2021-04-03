#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n; int divide = (int)pow(10, 9) + 7;
  long long power = 1;
  for(int i = 1; i <= n; i++){
    power *= i; power = power % divide;
  }
  cout << power << endl;
}