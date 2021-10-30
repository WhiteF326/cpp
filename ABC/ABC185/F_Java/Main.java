package ABC.ABC185.F_Java;

import java.util.*;

interface Monoid<T> {
  T e();

  T op(T a, T b);
}

class SegmentTree<T, U extends Monoid<T>> {
  private ArrayList<T> ary;
  private int n;
  U u;

  // e で初期化
  SegmentTree(int n, U u) {
    this.u = u;
    int b = (int) Math.ceil(Math.log(n) / Math.log(2));
    this.n = (int) Math.pow(2, b);
    ary.ensureCapacity(this.n * 2 - 1);
    for (int i = 0; i < n * 2 - 1; i++) {
      ary.add(u.e());
    }
  }

  // 値ありで初期化
  SegmentTree(T[] ary, U u) {
    this.u = u;
    this.ary.ensureCapacity(ary.length);
    for (T value : ary) {
      this.ary.add(value);
    }
  }

  // 更新
  void update(int p, T value) {
    p += n - 1;
    ary.set(p, value);
    while (p > 0) {
      p = (p - 1) / 2;
      ary.set(p, u.op(ary.get(p * 2 + 1), ary.get(p * 2 + 2)));
    }
  }

  // 全範囲を取得
  T getAll() {
    return ary.get(0);
  }

  // 一部範囲を取得
  T getRange(int l, int r){
    T sml = u.e();
    T smr = u.e();
    l += n - 1;
    r += n;
    
  }
}

// Range xor Tree
class xorOperator implements Monoid<Long> {
  @Override
  public Long e() {
    return 0L;
  }

  @Override
  public Long op(Long a, Long b) {
    return a ^ b;
  }
}

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = Integer.parseInt(sc.next());
    int q = Integer.parseInt(sc.next());

    sc.close();
  }
}