#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
 
using mint = modint998244353;

vector<mint> ten(211000),one(211000);

struct S{
  mint sum;
  int len;
};

S op(S a,S b){
  return {a.sum*ten[b.len]+b.sum,a.len+b.len};
}

S e(){
  return {0,0};
}

using F = int;

S mapping(F f,S s){
  if(f==0) return s;
  return {f*one[s.len],s.len};
}

F composition(F f,F g){
  if(f==0) return g;
  return f;
}

F id(){
  return 0;
}

int main(){
  
  //ten[i] := 100...0 (mod998244353)
  //one[i] := 111...1 (mod998244353)
  ten[0]=1,one[0]=0;
  for(int i=0;i<210000;i++){
    ten[i+1]=ten[i]*10;
    one[i+1]=one[i]+ten[i];
  }
 
  int n,q;
  cin>>n>>q;
 
  //初期状態
  vector<S> initial(n,{1,1});
 
  lazy_segtree<S,op,e,F,mapping,composition,id> seg(initial);
 
  while(q--){
    int l,r,d;
    cin>>l>>r>>d;

    //要素は0から始まる
    l--;
 
    //l番目からr-1番目までをdに更新
    seg.apply(l,r,d);
    
    //出力
    cout<<seg.all_prod().sum.val()<<endl;
  }
}
