// from geshi_crep23, edited code

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin>>H>>W;
  vector<string>S(H, string(W, ' '));
  // vector<string>S(H);
  // cout << S[0].capacity() << endl;
  vector<vector<int>>bomb(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>S[i][j];
      if(S[i][j]=='#'){
        if(j-1>=0){
          bomb[i][j-1]++;
        }
        if(j+1<=W-1){
          bomb[i][j+1]++;
        }
        if(i-1>=0){
          bomb[i-1][j]++;
          if(j-1>=0){
            bomb[i-1][j-1]++;
          }
          if(j+1<=W-1){
            bomb[i-1][j+1]++;
          }
        }
        if(i+1<=H-1){
          bomb[i+1][j]++;
          if(j-1>=0){
            bomb[i+1][j-1]++;
          }
          if(j+1<=W-1){
            bomb[i+1][j+1]++;
          }
        }
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(S[i][j]=='#'){
        cout<<S[i][j];
      }
      else{
        cout<<bomb[i][j];
      }
      if(j==W-1){
        cout<<endl;
      }
    }
  }
}