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
// #define query(t) while(t--)
#define aryin(a, n) for(int i = 0; i < n; i++) cin >> a[i];
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)


// Query

struct Query{
    int x, y, l, r, no;
};
struct Info{
    int c, d;
};

vector<Query> qur(101101);

vector<map<int, Info>> ncl(101101, map<int, Info>());
vector<vector<int>> nd(101101);

// Query


// RMQ LCA

template<class T, T (*op)(T, T)>
class AnySparseTable {
public:
    AnySparseTable() {}
    AnySparseTable(const vector< T > &v) {
        int b = 0;
        while((1 << b) <= v.size()) ++b;
        st.assign(b, vector< T >(1 << b));
        for(int i = 0; i < v.size(); i++) {
            st[0][i] = v[i];
        }
        for(int i = 1; i < b; i++) {
            for(int j = 0; j + (1 << i) <= (1 << b); j++) {
                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        lookup.resize(v.size() + 1);
        for(int i = 2; i < lookup.size(); i++) {
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    inline T prod(int l, int r) {
        int b = lookup[r - l];
        return op(st[b][l], st[b][r - (1 << b)]);
    }
private:
    vector<vector<T>> st;
    vector<int> lookup;
};

struct Node{
    int value, depth;
};
Node op(Node a, Node b){
    if(a.depth < b.depth) return a;
    else return b;
}

AnySparseTable<Node, op> st;

// --RMQ LCA


// Euler Tour

struct Edge{
    int to, c, d;
};
int n, q;
vector<vector<Edge>> g(101101);
int t = 0;
int w[202202], in[101101], out[101101], col[202202], len[202202];
vector<int> depth;
vector<bool> visited(101101, 0);

void euler(int p){
    w[t] = p;
    in[p] = t;
    t++;
    for(auto v : g[p]){
        if(visited[v.to]) continue;
        visited[v.to] = true;

        col[t] = v.c;
        len[t] = v.d;
        depth[v.to] = depth[p] + 1;

        euler(v.to);

        len[t] = -v.d;
        w[t] = p;
        t++;
    }
    out[p] = t;
}

int getLCA(int u, int v){
    if(in[u] > out[v]) swap(u, v);
    return st.prod(in[u], out[v]).value;
};

int getDist(int u, int v){
    return len[out[u] - 1] + len[out[v] - 1] - len[out[getLCA(u, v)] - 1] * 2;
};

// Euler Tour


// another dfs

int cc[10000], cw[10000];
vector<bool> visited2(101101, 0);

void dfs(int p){
    for(auto lp : nd[p]){
        ncl[p][lp].c = cc[lp];
        ncl[p][lp].d = cw[lp];
    }
    for(auto v : g[p]){
        if(visited2[v.to]) continue;
        visited2[v.to] = true;
        cc[v.c]++;
        cw[v.c] += v.d;

        dfs(v.to);

        cc[v.c]--;
        cw[v.c] -= v.d;
    }
}

// another dfs


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ifstream ifs("b05.in");
    
    ifs >> n >> q;
    dsu ds(n);
    vector<vector<int>> h(n);
    for(int i = 0; i < n - 1; i++){
        int l, r, c, d; ifs >> l >> r >> c >> d;
        l--, r--, c--;
        g[l].push_back({r, c, d});
        g[r].push_back({l, c, d});
        h[l].push_back(r);
        h[r].push_back(l);
        ds.merge(l, r);
    }

    visited[0] = true;
    visited2[0] = true;

    depth.assign(n, 0);
    euler(0);
    for(int i = 1; i < 2 * n - 1; i++){
        len[i] += len[i - 1];
    }

    vector<Node> spt(n * 2 - 1);
    for(int i = 0; i < n * 2 - 1; i++){
        spt[i].value = w[i];
        spt[i].depth = depth[w[i]];
    }

    st = AnySparseTable<Node, op>(spt);

    for(int i = 0; i < q; i++){
        int x, y, l, r; ifs >> x >> y >> l >> r;
        x--, l--, r--;
        qur[i] = {x, y, l, r, i};

        nd[l].push_back(x);
        nd[r].push_back(x);
        nd[getLCA(l, r)].push_back(x);

        // int deflen = getDist(l, r);
        // cout << deflen << endl;
    }

    dfs(0);

    for(int i = 0; i < q; i++){
        int x = qur[i].x, y = qur[i].y, l = qur[i].l, r = qur[i].r;
        int ans = getDist(l, r);
        int deflen = ncl[l][x].d + ncl[r][x].d - 2 * ncl[getLCA(l, r)][x].d;
        ans -= deflen;
        int cnt = ncl[l][x].c + ncl[r][x].c - 2 * ncl[getLCA(l, r)][x].c;
        ans += cnt * y;
        cout << ans << "\n";
    }

    fflush(stdout);
}
