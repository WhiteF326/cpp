#ifdef _DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
#define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


#define SIZE(buff) (sizeof(buff)/sizeof(buff[0]))  
int main() {  
    // The original sequence is: {10,8,8,7,5,5,5,3,1}  
    int x[] = {-10,-8,-8,-7,-5,-5,-5,-3,-1};  
  
    int p1 = lower_bound(x, x+SIZE(x), -5) - x;  
    int p2 = upper_bound(x, x+SIZE(x), -5) - x;  
  
    printf("x[%d] (=%d) <= %d\n", p1, -x[p1], 5);  
    printf("x[%d] (=%d) < %d\n", p2, -x[p2], 5);  
  
    return 0;  
}