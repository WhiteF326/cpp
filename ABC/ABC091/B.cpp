#include <bits/stdc++.h>
using namespace std;

int main(){
  unordered_map<string, int> cards;
  int a; cin >> a;
  for(int i = 0; i < a; i++){
    string name; cin >> name;
    cards[name]++;
  }
  cin >> a;
  for(int i = 0; i < a; i++){
    string name; cin >> name;
    cards[name]--;
  }
  int ans = -101;
  for(auto itr = cards.begin(); itr != cards.end(); ++itr){
    ans = max(ans, itr->second);
  }
  cout << (ans < 0 ? 0 : ans) << endl;
}