#include <bits/stdc++.h>
using namespace std;

int main(){
  ofstream outputfile("test.txt");
  vector<int> v(4, 1);
  for(int i = 0; i < 81; i++){
    outputfile << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    v[3]++;
    if(v[3] == 4) v[3] = 1, v[2]++;
    if(v[2] == 4) v[2] = 1, v[1]++;
    if(v[1] == 4) v[1] = 1, v[0]++;
  }
}