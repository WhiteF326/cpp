#include <bits/stdc++.h>
using namespace std;

int fact(int x) { return x <= 1 ? 1 : x * fact(x - 1); }

int main() {
    vector<int> n(5);
    for(int i = 0; i < 5; i++) cin >> n[i];
    vector<int> answers(0);
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            for(int k = j + 1; k < 5; k++){
                answers.push_back(n[i] + n[j] + n[k]);
            }
        }
    }
    sort(answers.begin(), answers.end(), greater<int>());
    answers.erase(unique(answers.begin(), answers.end()), answers.end());
    cout << answers[2] << endl;
}