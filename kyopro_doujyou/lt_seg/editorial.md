# 解説

袋の中にある $i$ が書かれたボールの個数を $C_i$ とします。
クエリ $1$ は、$i \in [l:r]$ について、$C_i$ に $1$ を加算する処理に等しいです。

このことから、区間加算処理に対応した Lazy Segment Tree を使用することが思い浮かびますが、
今回はいくつかの情報を付加した構造体を Lazy Segment Tree 上で扱わないと、クエリ $2$ を処理できません。

## マージ操作について

今回のマージ操作は

- $C_{i \in \{l, r\}}$ について、$C_i$ がより大きい方の $i$ を返す

というものです。この処理は**モノイドです**。

## 持たせる構造体について

```cpp
struct S{
    int pos;
    ll value;
    int size;
};
```

このように、書かれた数 `pos` と個数 `value` を持たせて、
更に区間幅 `size` を持たせることで、区間加算に対応します。

## マージ操作の具体的なコード

```cpp
S op(S a, S b){
    if(a.value == b.value){
        if(a.pos < b.pos){
            return a;
        }else{
            return b;
        }
    }else if(a.value < b.value){
        return b;
    }else{
        return a;
    }
}
```

$a.pos, b.pos$ が書かれたボールの個数が同じ場合、より $pos$ が小さい方の要素をそのまま返します。

でなければ、個数が多い方の要素をそのまま返します。

## 解法

以上の構造体と、適切なマージ操作を定義したうえで、

- クエリ $t=1$ については、区間 $[l:r]$ に $1$ を加算する
- クエリ $t=2$ については、区間 $[l:r]$ をマージした結果の構造体から`pos`を取り出して出力する。

以上でこの問題が解けます。

## コード

```cpp
// ライブラリは省略

// セグメント木の各要素を構成する構造体
struct S{
    // 書かれている数
    int pos;
    // 個数
    ll value;
    // 区間加算のために区間幅を保持する
    int size;
};
// マージ処理
S op(S a, S b){
    if(a.value == b.value){
        if(a.pos < b.pos){
            return a;
        }else{
            return b;
        }
    }else if(a.value < b.value){
        return b;
    }else{
        return a;
    }
}
// 恒等写像
S e(){
    return {INT_MAX, 0, 0};
}
// 区間加算を下のノードに伝搬する
S mapping(ll f, S x){
    return {x.pos, x.value + f * x.size, x.size};
}
// 伝搬されていない処理のうえに更に加算クエリが来た時の処理
ll composition(ll f, ll g){
    return f + g;
}
// 恒等写像
ll id(){
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n, q; cin >> n >> q;
    lazy_segtree<S, op, e, ll, mapping, composition, id> seg(n);
    for(int i = 0; i < n; i++){
        // 全ての要素を (書かれた数字, 個数 = 1, 区間幅 = 1) で初期化する。
        seg.set(i, {i + 1, 1, 1});
    }

    query(q){
        int t, l, r; cin >> t >> l >> r;
        if(t == 1){
            // l, l+1, ..., r について、1 を加算する
            seg.apply(l - 1, r, 1);
        }else{
            // l, l+1, ..., r について、value が最大であるような要素の pos を出力する
            cout << seg.prod(l - 1, r).pos << endl;
        }
    }
}
```
