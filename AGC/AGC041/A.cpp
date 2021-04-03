#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  if (abs(A-B)%2 == 0) cout << abs(A-B) / 2 << endl;
  else {
    cout << min((A+B-1)/2, (N*2-A-B+1)/2) << endl;
  }
}