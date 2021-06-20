#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define fs(n) fixed << setprecision(n);
#define mp(a, b) make_pair(a, b);
using ll = long long;
using ld = long double;

#define ALL(a)  (a).begin(),(a).end()

int main() {

    //ソートする必要があるのじゃ…
    vector<int> a = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};

    //イテレータを返す
    auto Iter1 = upper_bound(ALL(a), 0);
    auto Iter2 = upper_bound(ALL(a), 6);
    auto Iter3 = upper_bound(ALL(a), 7);
    auto Iter4 = upper_bound(ALL(a), 19);
    auto Iter5 = upper_bound(ALL(a), 20);

    //値の表示
    cout << "----------value----------" << endl;
    cout << "Iter1 = " << *Iter1 << endl; //Iter1 = 7
    cout << "Iter2 = " << *Iter2 << endl; //Iter2 = 7
    cout << "Iter3 = " << *Iter3 << endl; //Iter3 = 8
    cout << "Iter4 = " << *Iter4 << endl; //Iter4 = 1326115891
    cout << "Iter5 = " << *Iter5 << endl; //Iter5 = 1326115891

    //先頭からの距離
    cout << "----------from----------" << endl;
    cout << "Iter1 = " << Iter1 - a.begin() << endl; //Iter1 = 3
    cout << "Iter2 = " << Iter2 - a.begin() << endl; //Iter2 = 3
    cout << "Iter3 = " << Iter3 - a.begin() << endl; //Iter3 = 5
    cout << "Iter4 = " << Iter4 - a.begin() << endl; //Iter4 = 10
    cout << "Iter5 = " << Iter5 - a.begin() << endl; //Iter5 = 10

    //末尾までの距離
    cout << "----------to----------" << endl;
    cout << "Iter1 = " << a.end() - Iter1 << endl; //Iter1 = 7
    cout << "Iter2 = " << a.end() - Iter2 << endl; //Iter2 = 7
    cout << "Iter3 = " << a.end() - Iter3 << endl; //Iter3 = 5
    cout << "Iter4 = " << a.end() - Iter4 << endl; //Iter4 = 0
    cout << "Iter5 = " << a.end() - Iter5 << endl; //Iter5 = 0

    return 0;
}
