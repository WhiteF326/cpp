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
    //逆に000~999がsの中に見出せるか？
    int n; cin >> n;
    string s; cin >> s;
    vector<int> dPt(n, 0);
    for(int i = 0; i < n; i++){
        dPt[i] = stoi(s.substr(i, 1));
    }
    int ans = 0;
    for(int i = 0; i <= 999; i++){
        int fDigit = 0;
        vector<int> tDigit(3);
        tDigit[0] = (int)floor(i / 100) % 10;
        tDigit[1] = (int)floor(i / 10) % 10;
        tDigit[2] = i % 10;
        for(int j = 0; j < n; j++){
            if(dPt[j] == tDigit[fDigit]) fDigit++;
            if(fDigit == 3){ans++; break;}
        }
    }
    cout << ans << endl;
}