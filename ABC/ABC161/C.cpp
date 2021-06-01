#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, k; scanf("%lld%lld", &n, &k);
  printf("%lld", min((long long)abs(n - (long long)ceil(n / (long double)k) * k ),
                      (long long)abs(n - (long long)floor(n / (long double)k) * k )));
}