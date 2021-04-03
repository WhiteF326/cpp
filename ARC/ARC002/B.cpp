#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
  return (x > 0) - (x < 0);
}

bool isLeapYear(int y, int m){
  return (y % 400 == 0 || (y % 4 == 0 && y % 100)) && m == 2;
}

int main(){
  string s; cin >> s;
  int y = stoi(s.substr(0, 4)), m = stoi(s.substr(5, 2)), d = stoi(s.substr(8, 2));
  const int mlast = 12;
  const vector<int> dlast = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  while(true){
    if(y % (m * d) == 0){
      printf("%d/%02d/%02d\n", y, m, d);
      break;
    }else{
      d++;
      if(d > (dlast[m - 1] + isLeapYear(y, m))){d = 1; m++;}
      if(m > mlast){m = 1; y++;};
    }
  }
  return 0;
}