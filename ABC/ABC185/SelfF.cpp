#include <bits/stdc++.h>
using namespace std;


template <typename T>
struct SegTree{
    int size;
    vector<T> val;

    SegTree(int n){
        this->size = n;
        val.resize(n);
    }

    // モノイドの定義
    T merge(T a, T b){
        return a ^ b;
    }
    T e(){
        return 0;
    }
};


int main(){
}