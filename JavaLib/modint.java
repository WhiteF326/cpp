package JavaLib;

public class modint {
  long modv = 0;
  long val = 0;

  // if mod specified
  public modint(long val, long modv){
    this.val = val;
    this.modv = modv;
  }
  // if mod did not specified
  public modint(long val){
    this.val = val;
    this.modv = 1000000007;
  }

  // get
  public long get(){
    return val;
  }

  // four basic action
  public void plus(long b){
    val = (val + b) % modv;
  }
  public void minus(long b){
    val = (val - b + modv) % modv;
  }
  public void multiple(long b){
    b = b % modv;
    val = (val * b) % modv;
  }
  public void division(long b){
    val = (val * modinv(b)) % modv;
  }

  // power
  public void power(long b){
    long res = 1;
    while(b > 0){
      if((b & 1) > 0) res = (res * val) % modv;
      val = val * val % modv;
      b >>= 1;
    }
  }

  // inner methods
  private long modinv(long v){
    long res = 1, k = this.modv - 2, y = v;
    while(k > 0){
      if((k & 1) > 0) res = (res * y) % modv;
      y = y * y % modv;
      k /= 2;
    }
    return res;
  }
}
