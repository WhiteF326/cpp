#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x)
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define all(x) x.begin(), x.end()
#define fs(n) fixed << setprecision(n)
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    bool isPrime[55556] = {false};
    memset(&isPrime, 1, 55556);
    for(int i = 2; i * i <= 55555; i++){
        if(!isPrime[i]) continue;
        for(int j = i * i; j <= 55555; j += i){
            isPrime[j] = false;
        }
    }

    int n; cin >> n;
    int st = 2;
    while(n && st <= 55555){
        if(isPrime[st] && st % 5 == 4){
            cout << st << " ";
            n--;
        }
        st++;
    }
    // if(n) print("failed");
}
