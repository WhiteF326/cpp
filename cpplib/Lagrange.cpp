#include <vector>

using namespace std;

namespace shiroha{
    namespace math{
        /*
            与えられる点の x 座標が初項 a, 公差 d の等差数列である時、
            加えて y 座標を与えて、ラグランジュ補間を行い、x = t における y の値を求める。
        */
        template<typename T>
        T lagrange(T a, T d, vector<T> y, T t){
            const int n = y.size() - 1;
            T ret = 0, ft = 1;
            for(int i = 0; i <= n; i++) ft *= t - (a + d * i);
            T f = 1;
            for(int i = 1; i <= n; i++) f *= -1 * i * d;
            ret += y[0] / f * ft / (t - a);
            for(int i = 0; i < n; i++){
                f *= d * (i + 1) / (d * (i - n));
                ret += y[i + 1] / f * ft / (t - a - d * (i + 1));
            }
            return ret;
        }
    }
}