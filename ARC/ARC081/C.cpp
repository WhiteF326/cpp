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
    unordered_map<long long, long long> a;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        a[x]++;
    }
    vector<pair<long long, long long>> mp;
    for(auto itr = a.begin(); itr != a.end(); itr++){
        if(itr->second >= 2){
            mp.push_back(make_pair(itr->first, itr->second));
        }
    }
    if(mp.size() == 0){
        cout << 0 << endl;
        return 0;
    }else if(mp.size() < 2 && mp[0].second < 4){
        cout << 0 << endl;
        return 0;
    }
    int d = mp.size() - 1;
    sort(mp.begin(), mp.end());
    if(mp[d].second >= 4){
        cout << mp[d].first * mp[d].first << endl;
    }else{
        cout << mp[d].first * mp[d - 1].first << endl;
    }
}