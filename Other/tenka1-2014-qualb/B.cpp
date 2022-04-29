#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#define print(x) cout << x << endl;
#define printarray(x) for(auto v : x) cout << v << " "; cout << endl;
#endif
#ifndef _DEBUG
#define print(x) 42;
#define printarray(x) 42;
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


constexpr int modline = 4;
constexpr ll mods[] = {916471357, 936547751, 951231241, 976977707};
constexpr ll bases[] = {10007, 15679, 20693, 25693};
constexpr ll invl[] = {116218862, 565608180, 738304014, 368310671};

struct RollingHash{
    string s;
    vector<vector<ll>> hash, pows, invs;

    RollingHash(string s){
        s = (char)0 + s;
        this->s = s;
        hash.resize(modline);
        pows.resize(modline);
        invs.resize(modline);
        for (int i = 0; i < modline; i++){
            hash[i].resize(s.length());
            pows[i].resize(s.length());
            invs[i].resize(s.length());
            pows[i][0] = 1;
            invs[i][0] = 1;
            hash[i][0] = (int)s[0];
            for (int j = 1; j < s.length(); j++){
                pows[i][j] = (pows[i][j - 1] * bases[i]) % mods[i];
                invs[i][j] = (invs[i][j - 1] * invl[i]) % mods[i];
                hash[i][j] = (pows[i][j] * (int)s[j]) % mods[i];
                hash[i][j] = (hash[i][j] + hash[i][j - 1]) % mods[i];
            }
        }
    }

    // get hash for [l: r)
    vector<ll> get(int l, int r){
        vector<ll> hashes(modline, 0);
        for (int i = 0; i < modline; i++){
            hashes[i] = hash[i][r] - hash[i][l] + mods[i];
            hashes[i] = (hashes[i] * invs[i][l]) % mods[i];
        }
        return hashes;
    }

    static bool sameHash(vector<ll> a, vector<ll> b){
        bool ans = true;
        for (int i = 0; i < modline; i++){
            if (a[i] != b[i]) ans = false;
        }
        return ans;
    }
};
#define modv 1000000007
#define mint modint1000000007


// int main() {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
    
//     int n; cin >> n;
//     string s; cin >> s;
//     RollingHash rh(s);
//     vector<RollingHash> t(n, RollingHash(""));
//     vector<int> l(n);
//     for(int i = 0; i < n; i++){
//         string v; cin >> v;
//         t[i] = RollingHash(v);
//         l[i] = int(v.length());
//     }

//     vector<mint> dp(s.length() + 1, 0);
//     dp[0] = 1;
//     for(int i = 0; i < s.length(); i++){
//         for(int j = 0; j < n; j++){
//             if(i + l[j] > s.length()) continue;
//             if(RollingHash::sameHash(rh.get(i, i + l[j]), t[j].get(0, l[j]))){
//                 dp[i + l[j]] += dp[i];
//             }
//         }
//     }

//     cout << dp[s.length()].val() << endl;
// }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    string s; cin >> s;
    vector<string> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    vector<mint> dp(s.length() + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < s.length(); i++){
        for(int j = 0; j < n; j++){
            if(i + t[j].length() > s.length()) continue;
            if(s.substr(i, t[j].length()) == t[j]){
                dp[i + t[j].length()] += dp[i];
            }
        }
    }

    cout << dp[s.length()].val() << endl;
}
