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

int main() {
    int n; cin >> n;

    vector<int> dp(n + 1, 1 << 29);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int p = 1; i + p <= n; p *= 6){
            dp[i + p] = min(dp[i + p], dp[i] + 1);
        }
        for(int p = 1; i + p <= n; p *= 9){
            dp[i + p] = min(dp[i + p], dp[i] + 1);
        }
    }

    cout << dp[n] << endl;
}