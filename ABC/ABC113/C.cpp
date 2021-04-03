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
    int n, m; cin >> n >> m;
    vector<vector<int>> py(n, vector<int>(0));
    vector<int> pList(m), yList(m);
    for(int i = 0; i < m; i++){
        int p, y; cin >> p >> y;
        py[p - 1].push_back(y);
        pList[i] = p - 1;
        yList[i] = y;
    }
    for(int i = 0; i < n; i++){
        sort(py[i].begin(), py[i].end());
    }
    for(int i = 0; i < m; i++){
        auto itr = find(py[pList[i]].begin(), py[pList[i]].end(), yList[i]);
        cout << setfill('0') << right << setw(6) << pList[i] + 1;
        cout << setw(6) << itr - py[pList[i]].begin() + 1 << endl;
    }
}