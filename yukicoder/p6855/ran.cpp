#include <bits/stdc++.h>
#include <random>
using namespace std;

using ll = long long;

ll lim = 1e+6;
ll blim = 1e+18;
mt19937 mt;
random_device rnd;

int r(){
  return (mt() % 32768) * 32768 + (mt() % 32768);
}
ll ran(){
  return ((ll)r() * (ll)r()) % blim + r();
}

int main(){
  mt.seed(71);
  for(int f = 9; f <= 9; f++){
    int n = ran() % (int)(1e+6);
    ofstream ofs("testcases/07_hand_" + to_string(f) + ".txt");

    ofs << n << endl;
    for(int i = 0; i < n - 2; i++){
      ofs << (ran() % lim) + 1 << " ";
    }
    ofs << (ran() % lim) + 1 << endl;
  }
}

// int main(){
//   mt.seed(63);
//   ifstream ifs("testcases/primes.txt");

//   vector<int> primes(78498);
//   for(int i = 0; i < 78498; i++) ifs >> primes[i];

//   for(int f = 4; f < 6; f++){
//     int n = ran() % (int)(1e+6);
//     ofstream ofs("testcases/07_primes_" + to_string(f) + ".txt");

//     ofs << n << endl;
    
//     for(int i = 0; i < n - 1; i++){
//       int p = ran() % 78498;
//       ofs << primes[p] << " ";
//     }
//     int p = ran() % 78498;
//     ofs << primes[p] << endl;
//   }
// }