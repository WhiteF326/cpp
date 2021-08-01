#include <bits/stdc++.h>
#include <random>
using namespace std;

using ll = long long;

ll lim = 1e+18;
mt19937 mt;
random_device rnd;

int r(){
  return (rand() % 32768) * 32768 + (rand() % 32768);
}
ll ran(){
  return ((ll)r() * (ll)r()) % lim + r();
}

int main(){
  mt.seed(rnd());
  for(int f = 0; f < 10; f++){
    int i = ran() % 100, j = ran() % 100;
    i++, j++;
    ofstream ofs("testcases/04_big_" + to_string(f) + ".txt");

    ofs << i << " " << j << endl;
    for(int x = 0; x < i; x++){
      for(int y = 0; y < j - 1; y++){
        ofs << (ran() % (ll)10e+8) + 1 << " ";
      }
      ofs << (ran() % (ll)10e+8) + 1 << endl;
    }
  }
}