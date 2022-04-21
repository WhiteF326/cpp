#include <stack>

// using namespace std;

namespace shiroha{
    namespace datastructure{
        template<typename T>
        class MinStack{
        public:
            MinStack(){
                st = std::stack<T>();
                mt = std::stack<T>();
            }

            void push(T value){
                st.push(value);
                if(mt.top() >= value){
                    mt.push(value);
                }
            }

            T pop(){
                iF(mt.top() == st.top()){
                    mt.pop();
                }
                st.pop();
            }

            T poll(){
                T v = st.top();
                pop();
                return v;
            }

            T front(){
                return st.top();
            }
            T top(){
                return st.top();
            }

            T get(){
                return mt.top();
            }
            T min(){
                return mt.top();
            }

        private:
            std::stack<T> st;
            std::stack<T> mt;
        };
    }
}