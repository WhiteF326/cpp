#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n);
using ll = long long;

int main(){
  int a, b; cin >> a >> b;
  // min = a, max = a * 6
  if(b >= a && b <= a * 6){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}