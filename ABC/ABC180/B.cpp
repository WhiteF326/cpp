#include <bits/stdc++.h>
using namespace std;

vector<int> AllDivs(int d){
    vector<int> resDivs(0);
    for(int i = 1; i < (int)sqrt(d); i++){
        if(d % i == 0){
            resDivs.push_back(i);
            resDivs.push_back(d / i);
        }
    }
    sort(resDivs.begin(), resDivs.end());
    return resDivs;
}

bool IsPrime(int num){
    bool ans = true;
    if(num < 2) return false;
    else if (num == 2) return true;
    else{
        for(int i = 2; i <= (int)sqrt(num); i++){
            if(num % i == 0){
                ans = false;
            }
        }
    }
    return ans;
}

int NextPrime(int d){
    int ans = d;
    while(true){
        ans++;
        if(IsPrime(ans)) break;
    }
    return ans;
}

int main(){
  int n; cin >> n;
  double m = 0, e = 0, c = 0;
  for(int i = 0; i < n; i++){
    double t; cin >> t;
    m += abs(t);
    e += pow(t, 2);
    c = max(c, abs(t));
  }
  e = sqrt(e);
  cout << fixed << setprecision(0) <<m << endl;
  cout << setprecision(15) << e << endl;
  cout << defaultfloat << c << endl;
  
  return 0;
}