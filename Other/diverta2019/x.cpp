#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
#define repo(i,n) for(int i=1;i<=(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define rrepo(i,n) for(int i=(n);i>=1;i--)
#define rep2(i,s,n) for(int i=(s);i<(n);i++)
#define repr2(i,s,n) for(int i=(n)-1;i>=(s);i--)
#define vrep(v,V) for(auto &v:V)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define allc(x) (x).cbegin(),(x).cend()

template <typename T>
bool chmax(T& a,const T& b){if(a<b){a=b;return true;}else{return false;}}
template <typename T>
bool chmin(T& a,const T& b){if(a>b){a=b;return true;}else{return false;}}
template <typename T>
bool chmax2(T& a,T& b,T& c){if(a<=c){b=a;a=c;return true;}else if(b<c){b=c;return true;}else{return false;}}
template <typename T>
bool chmin2(T& a,T& b,T& c){if(a>=c){b=a;a=c;return true;}else if(b>c){b=c;return true;}else{return false;}}


int main(){
  ll N,m=1LL,S=0LL,l;
  cin>>N;
  while(m*m<=N){
    if(N%m==0){
      l=N/m;
      if(m>1LL && N/(m-1LL)==N%(m-1LL)) S+=m-1LL;
      if(m!=l && N/(l-1LL)==N%(l-1LL)) S+=l-1LL;
    }
    m++;
  }
  cout<<S<<endl;
}