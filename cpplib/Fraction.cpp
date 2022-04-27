#include <cassert>

namespace shiroha{
    namespace math{
        long long gcd(long long a, long long b){
            if(a < 0) a = -a;
            if(b < 0) b = -b;
            if(a == 0) return b;
            if(b == 0) return a;
            if(a == 1 || b == 1) return 1;
            if(a == b) return a;
            return gcd(b, a % b);
        }
        class Fraction{
        public:
            Fraction(){
                Fraction(0, 1);
            }
            Fraction(long long n, long long d){
                assert(d != 0);
                if(d < 0){
                    n = -n;
                    d = -d;
                }
                long long g = gcd(n, d);
                this->n = n / g;
                this->d = d / g;
            }

            long long n;
            long long d;
        };

        Fraction operator+(const Fraction& lhs, const Fraction& rhs){
            return Fraction(lhs.n * rhs.d + rhs.n * lhs.d, lhs.d * rhs.d);
        }
        Fraction operator-(const Fraction& lhs, const Fraction& rhs){
            return Fraction(lhs.n * rhs.d - rhs.n * lhs.d, lhs.d * rhs.d);
        }
        Fraction operator*(const Fraction& lhs, const Fraction& rhs){
            return Fraction(lhs.n * rhs.n, lhs.d * rhs.d);
        }
        Fraction operator/(const Fraction& lhs, const Fraction& rhs){
            return Fraction(lhs.n * rhs.d, lhs.d * rhs.n);
        }
        bool operator==(const Fraction& lhs, const Fraction& rhs){
            return lhs.n == rhs.n && lhs.d == rhs.d;
        }
        bool operator!=(const Fraction& lhs, const Fraction& rhs){
            return !(lhs == rhs);
        }
        bool operator<(const Fraction& lhs, const Fraction& rhs){
            return lhs.n * rhs.d < rhs.n * lhs.d;
        }
        bool operator>(const Fraction& lhs, const Fraction& rhs){
            return rhs < lhs;
        }
        bool operator<=(const Fraction& lhs, const Fraction& rhs){
            return !(lhs > rhs);
        }
        bool operator>=(const Fraction& lhs, const Fraction& rhs){
            return !(lhs < rhs);
        }
        Fraction operator-(const Fraction& rhs){
            return Fraction(-rhs.n, rhs.d);
        }
        Fraction operator+(const Fraction& rhs){
            return rhs;
        }
        Fraction operator++(Fraction& lhs){
            return lhs = Fraction(lhs.n + lhs.d, lhs.d);
        }
        Fraction operator--(Fraction& lhs){
            return lhs = Fraction(lhs.n - lhs.d, lhs.d);
        }
        Fraction operator++(Fraction& lhs, int){
            Fraction ret = lhs;
            lhs = Fraction(lhs.n + lhs.d, lhs.d);
            return ret;
        }
        Fraction operator--(Fraction& lhs, int){
            Fraction ret = lhs;
            lhs = Fraction(lhs.n - lhs.d, lhs.d);
            return ret;
        }
    }
}