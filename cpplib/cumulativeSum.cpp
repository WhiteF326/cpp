// 1D_Sum

template<class T>
struct CumulativeSum{
public:
    CumulativeSum(const vector<T>& v) : n(int(v.size())){
        cv = vector<T>(n + 1, 0);

        for(int i = 0; i < n; i++){
            cv[i + 1] += cv[i];
            cv[i + 1] += v[i];
        }
    }

    T sum(int l, int r){
        return cv[r] - cv[l - 1];
    }

private:
    int n;
    vector<T> cv;
};

// 1D_any
template<class T, T (*op)(T&, T), T (*rop)(T, T)>
struct CumulativeProd{
public:
    CumulativeProd(const vector<T>& v) : n(int(v.size())){
        cv = vector<T>(n + 1, 0);

        for(int i = 0; i < n; i++){
            op(cv[i + 1], cv[i]);
            op(cv[i + 1], v[i]);
        }

        T product(int l, int r){
            return rop(cv[r] - cv[l - 1]);
        }
    }

private:
    int n;
    vector<T> cv;
};

// 2D
