#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
  usage : sieve(s)
  s = max value you want to use -> Ο(sqrt s)
  
  method isprime(v) returns 1 if v is prime or else returns 0
*/

struct sieve{
  vector<bool> s;
  int size;

  sieve(int size){
    s.resize(size + 1, true);
    this->size = size;

    s[0] = false;
    s[1] = false;

    for(int i = 2; i * i <= size; i++){
      if(s[i]){
        for(int j = 2; i * j <= size; j++){
          s[i * j] = false;
        }
      }
    }
  }

  bool isprime(int v){
    assert(v <= this->size);
    return s[v];
  }
};