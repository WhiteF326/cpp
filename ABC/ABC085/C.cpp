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

int rm(int a, int b, int c){
  return a * 10000 + b * 5000 + c * 1000;
}
 
int main(){
    int fc, goal; cin >> fc >> goal;
    for(int i = 0; i <= fc; i++){
        for(int j = 0; j <= fc - i; j++){
            if(i + j > fc){break;}
            int k = fc - (i + j);
            if(rm(i, j, k) == goal){
                cout << i << " " << j  << " " << k << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}