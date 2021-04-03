#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }
int sign(int x){
    return (x > 0) - (x < 0);
}

int main() {
    unordered_map<string, string> nextWeather;
    nextWeather["Sunny"] = "Cloudy";
    nextWeather["Cloudy"] = "Rainy";
    nextWeather["Rainy"] = "Sunny";
    string s; cin >> s;
    cout << nextWeather[s] << endl;
}