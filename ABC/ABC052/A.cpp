#include <bits/stdc++.h>
using namespace std;

int fact(int x) {return x <= 1 ? 1 : x * fact(x - 1);}

int main(){
  int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
  cout << (int)max(a * b, c * d) << endl;
}