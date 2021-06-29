#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;


bool IsPrime(int num)
{
  bool ans = true;
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else
  {
    for (int i = 2; i <= (int)sqrt(num); i++)
    {
      if (num % i == 0)
      {
        ans = false;
      }
    }
  }
  return ans;
}

int NextPrime(int d)
{
  int ans = d;
  while (true)
  {
    ans++;
    if (IsPrime(ans))
      break;
  }
  return ans;
}

int main(){
  int a = 2;
  ofstream ofs("primes.txt");
  while(a < 55555){
    ofs << a << endl;
    a = NextPrime(a);
  }
}