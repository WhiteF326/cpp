import java.util.ArrayList;

class SegTree<T>{
  private ArrayList<T> v = new ArrayList<>();
  private int n;
  private Monoid<T> monoid;

  SegTree(int n, Monoid<T> monoid){
    this.n = 1;
    while(this.n < n) this.n *= 2;
    v.ensureCapacity(this.n * 4);

    this.monoid = monoid;

    for(int i = 0; i < this.n * 4; i++){
      v.add(monoid.e());
    }
  }

  public void set(int p, T value){
    int np = p + this.n - 1;
    v.set(np, value);
    while(np > 0){
      np = (np - 1) / 2;
      v.set(np, monoid.op(v.get(np * 2 + 1), v.get(np * 2 + 2)));
    }
  }

  public T get(int p){
    return v.get(p + this.n - 1);
  }

  public T query(int l, int r){
    return subquery(l, r, 0, 0, this.n);
  }

  private T subquery(int a, int b, int k, int l, int r){
    if(r <= a || b <= l){
      return monoid.e();
    }else if(a <= l && r <= b){
      return v.get(k);
    }else{
      T vl = subquery(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = subquery(a, b, k * 2 + 2, (l + r) / 2, r);
      return monoid.op(vl, vr);
    }
  }

  ArrayList<T> retAry(){
    return v;
  }
}