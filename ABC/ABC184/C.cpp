#include <bits/stdc++.h>
using namespace std;

#define fs(n) fixed << setprecision(n)
using ll = long long;

vector<int> AllDivs(int d){
	vector<int> resDivs(0);
	for(int i = 1; i < (int)sqrt(d); i++){
		if(d % i == 0){
			resDivs.push_back(i);
			resDivs.push_back(d / i);
		}
	}
	sort(resDivs.begin(), resDivs.end());
	return resDivs;
}

bool IsPrime(int num){
	bool ans = true;
	if(num < 2) return false;
	else if (num == 2) return true;
	else{
		for(int i = 2; i <= (int)sqrt(num); i++){
			if(num % i == 0){
					ans = false;
			}
		}
	}
	return ans;
}

int NextPrime(int d){
	int ans = d;
	while(true){
		ans++;
		if(IsPrime(ans)) break;
	}
	return ans;
}

vector<int> Dec2Bin(int x, int len){
	vector<int> res(len, 0);
	int d = 1, pt = len - 1;
	while(d <= x){
		res[pt] = (x & d ? 1 : 0);
		d *= 2; pt--;
	}
	return res;
}

int avg(int a, int b){
  return (a + b) / 2;
}
 
int main(){
  int sr, sc, er, ec; cin >> sr >> sc >> er >> ec;
  int t = 0;
  er -= sr; ec -= sc; sr = 0; sc = 0;
  int der = er, dec = ec, dsr = sr, dsc = sc;
  
  if(er == sr && ec == sc){cout << 0 << endl; return 0;}
  if((abs(er - sr) + abs(ec - sc)) <= 3){cout << 1 << endl; return 0;}
	
	int ans = 0;
  while(true){
    int tmp = avg(abs(er), abs(ec)); t++;
    if(er < 0){er += tmp;}else{er -= tmp;}
    if(ec < 0){ec += tmp;}else{ec -= tmp;}
    if(er == sr && ec == sc){
      //直接ヒットした場合
      ans = t;
      break;
    }else if(abs(er) == abs(ec)){
      //斜め線上にある場合
      ans = t + 1;
      break;
    }else if((abs(er - sr) + abs(ec - sc)) <= 3){
      //縦横の差が合計3に収まる場合
      ans = t + 1;
      break;
    }
  }
	if((abs(der - dsr) + abs(dec - dsc)) <= 6){cout << min(ans, 2) << endl; return 0;}
  else cout << ans << endl;
}