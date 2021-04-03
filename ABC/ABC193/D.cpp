#include <bits/stdc++.h>
using namespace std;

int main(){
  int k; cin >> k;
  vector<int> ta(9, 1), ao(9, 1);
  string ts, tt; cin >> ts >> tt;
  char s[6], t[6]; strcpy(s, ts.c_str()); strcpy(t, tt.c_str());
  for(int i = 0; i < 4; i++){
    ta[s[i] - '0' - 1]++; ao[t[i] - '0' - 1]++;
  }
  int w = 0, v = 0;
  for(int i = 1; i <= 9; i++){
    ta[i - 1]++;
    for(int j = 1; j <= 9; j++){
      ao[j - 1]++; v++;
      vector<int> tas(k + 1, 0), aos(k + 1, 0);
      for(int l = 0; l < 9; l++){
        tas[ta[l]] += l + 1;
        aos[ao[l]] += l + 1;
      }
      for(int l = k; l >= 0; l--){
        if(tas[l] > aos[l]){w++; break;}
        else if(tas[l] < aos[l]){break;}
      }
      ao[j - 1]--;
    }
    ta[i - 1]--;
  }
  cout << fixed << setprecision(15) << (w / (double)v) << endl;
}