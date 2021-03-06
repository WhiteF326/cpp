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


constexpr ll mods[] = {916471357, 936547751, 951231241, 976977707};
constexpr ll bases[] = {10007, 15679, 20693, 25693};
constexpr ll invl[] = {116218862, 565608180, 738304014, 368310671};

struct RollingHash{
    string s;
    vector<vector<ll>> hash, pows, invs;

    RollingHash(string s){
        s = (char)0 + s;
        this->s = s;
        hash.resize(4);
        pows.resize(4);
        invs.resize(4);
        for (int i = 0; i < 4; i++){
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

    vector<ll> get(int l, int r){
        vector<ll> hashes(4, 0);
        for (int i = 0; i < 4; i++){
            hashes[i] = hash[i][r] - hash[i][l] + mods[i];
            hashes[i] = (hashes[i] * invs[i][l]) % mods[i];
        }
        return hashes;
    }

    static bool sameHash(vector<ll> a, vector<ll> b){
        bool ans = true;
        for (int i = 0; i < 4; i++){
            if (a[i] != b[i]) ans = false;
        }
        return ans;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s;
    int n = int(s.length());

    string t = s;
    reverse(all(t));

    RollingHash sr(s), tr(t);

    auto sr_binary = [&](int div){
        int l = 0, r = min(div, n - div) + 1;
        while(r - l > 1){
            int m = l + (r - l) / 2;
            if(RollingHash::sameHash(sr.get(0, m), sr.get(div, div + m))){
                l = m;
            }else{
                r = m;
            }
        }
        return min(l, n - div - 1);
    };
    auto tr_binary = [&](int div){
        int l = 0, r = min(div, n - div) + 1;
        while(r - l > 1){
            int m = l + (r - l) / 2;
            if(RollingHash::sameHash(tr.get(0, m), tr.get(n - div, n - div + m))){
                l = m;
            }else{
                r = m;
            }
        }
        return min(l, n - div - 1);
    };

    ll ans = 0;
    for(int l = 2; l < n - 1; l++){
        if(n - l >= l) continue;
        ans += max(0, sr_binary(l) + tr_binary(l) - n + l + 1);
    }
    cout << ans << endl;
}
