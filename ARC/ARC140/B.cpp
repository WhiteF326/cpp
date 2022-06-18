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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    string s; cin >> n >> s;

    int ans = 0;
    vector<int> v;
    for(int i = 1; i < n - 1; i++){
        if(s[i] == 'R'){
            // left
            if(s[i - 1] != 'A') continue;
            int left = 0;
            while(s[i - left - 1] == 'A'){
                left++;
                if(i - left - 1 < 0) break;
            }
            // right
            if(s[i + 1] != 'C') continue;
            int right = 0;
            while(s[i + right + 1] == 'C'){
                right++;
                if(i + right + 1 >= n) break;
            }

            v.push_back(min(left, right) * 2 + 1);
        }
    }

    // deque<int> deq;
    // for(int t : v) deq.push_back(t);

    // while(!deq.empty()){
    //     int t = deq.back();
    //     deq.pop_back();
    //     if(t > 3){
    //         deq.push_back(t - 2);
    //     }
    //     ans++;
    //     if(!deq.empty()){
    //         deq.pop_front();
    //         ans++;
    //     }
    // }

    multiset<int> st(all(v));
    while(!st.empty()){
        int t = *st.rbegin();
        st.erase(st.find(t));
        if(t > 3){
            st.insert(t - 2);
        }
        ans++;
        if(!st.empty()){
            st.erase(st.begin());
            ans++;
        }
    }

    cout << ans << endl;
}
