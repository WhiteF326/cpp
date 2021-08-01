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
  for(int i = 0; i < 20; i++){
    ofstream ofs("rand_" + to_string(i) + ".txt");
    mt.seed(rnd());
    int q = r() % 100000; q++;
    ofs << q << endl;
    for(int i = 0; i < q; i++){
      ofs << ran() % lim << endl;
    }
  }
}