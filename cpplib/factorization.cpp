#include <vector>

using namespace std;

template<int S, int mod = 1000000007>
class Factorization{
public:
    Factorization(){
        fact.resize(S + 1, 1);
        for(int i = 1; i <= S; i++){
            fact[i] = (fact[i - 1] * i) % mod;
        }
    }

    long long get(int p){
        return fact[p];
    }

    long long & operator [] (int n) {
        return fact[n];
    }

private:
    vector<long long> fact;
};
