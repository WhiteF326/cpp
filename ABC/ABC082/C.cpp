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
    int n; cin >> n;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        mp[a]++;
    }
    int ans = 0;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        if(itr->first > itr->second){
            ans += itr->second;
        }else{
            ans += itr->second - itr->first;
        }
    }
    cout << ans << endl;
}