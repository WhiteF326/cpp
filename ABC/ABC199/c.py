# int main(){
#   int n; cin >> n;
#   string s; cin >> s;
#   int q; cin >> q;
#   for(int i = 0; i < q; i++){
#     int t, a, b; cin >> t >> a >> b;
#     if(t == 1){
#       swap(s[a - 1], s[b - 1]);
#     }else{
#       // t == 2
#       s = s.substr(n) + s.substr(0, n);
#     }
#   }
#   cout << s << endl;
# }

n = int(input())
s = input()
q = int(input())
l = n * 2
arr = list(range(l))
for i in range(q):
  t, a, b = map(int, input().split())
  if t == 1:
    arr[a - 1], arr[b - 1] = arr[b - 1], arr[a - 1]
  else:
    arr = arr[n:l] + arr[0:n]
for i in range(l):
  print(s[arr[i]], end="")
print()