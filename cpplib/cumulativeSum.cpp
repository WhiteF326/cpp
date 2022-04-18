namespace shiroha{
    namespace datastructure{
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
        template<typename T>
        class RangeSum2D{
        public:
            RangeSum2D(vector<vector<T>> &v){
                int h = v.size();
                int w = v[0].size();

                d.assign(h + 1, vector<T>(w + 1, T()));
                for(int i = 0; i < h; i++){
                    for(int j = 0; j < w; j++){
                        d[i + 1][j + 1] = v[i][j];
                    }
                }
                for(int i = 0; i < h; i++){
                    for(int j = 0; j < w; j++){
                        d[i + 1][j + 1] += d[i + 1][j];
                    }
                }
                for(int i = 0; i < h; i++){
                    for(int j = 0; j < w; j++){
                        d[i + 1][j + 1] += d[i][j + 1];
                    }
                }
            };

            // get sum of [(l1, r1) : (l2 : r2))
            T get(int l1, int r1, int l2, int r2){
                return d[l2][r2] - d[l1][r2] - d[l2][r1] + d[l1][r1];
            }

        private:
            vector<vector<T>> d;
        };
    }
}