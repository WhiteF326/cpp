#ifdef _DEBUG
#define _GLIBCXX_DEBUG
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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s, t; cin >> s >> t;
    int n = s.length();
    for(int i = 0; i < n; i++){
        bool res = false;
        set<char> left, right;
        if(s[i] == '@'){
            left = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
        }else{
            left.insert(s[i]);
        }
        if(t[i] == '@'){
            right = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
        }else{
            right.insert(t[i]);
        }

        for(char c : left){
            if(right.find(c) != right.end()){
                res = true;
            }
        }

        if(!res){
            cout << "You will lose" << endl;
            return 0;
        }
    }
    cout << "You can win" << endl;
}
