#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
  for(int f = 0; f < 10; f++){
    int fs = f * f;
    ofstream ofs("testcases/06_min_" + to_string(f) + ".txt");
    ofs << fs << " " << fs << endl;
    for(int i = 0; i < fs; i++){
      for(int j = 0; j < fs - 1; j++) ofs << 1 << " ";
      ofs << 1 << endl;
    }
  }
}