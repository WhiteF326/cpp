#include <bits/stdc++.h>
using namespace std;

class topologicalSort{
public:
    topologicalSort(const vector<vector<int>>& g) : n(int(g.size())){
        lst = vector<int>(n);

        vector<int> inc(n, 0);
        for(int i = 0; i < n; i++){
            for(int v : g[i]){
                inc[v]++;
            }
        }

        // sorting
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!inc[i]) q.push(i);
        }

        int ptr = 0;
        while(!q.empty()){
            int d = q.front();
            q.pop();

            lst[ptr] = d;
            ptr++;
            for(int v : g[d]){
                inc[v]--;
                if(!inc[v]){
                    q.push(v);
                }
            }
        }

        if(ptr == n){
            succeed = true;
        }else{
            succeed = false;
        }
    }

    bool isDAG(){
        return succeed;
    }

    vector<int>& get(){
        return lst;
    }

private:
    int n;
    vector<int> lst;
    bool succeed;
};
