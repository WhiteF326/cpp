import java.util.*;

public class fastComb{
  ArrayList<Long> f;
  long modv;
  int size;

  fastComb(int size, long modv){
    f.ensureCapacity(size + 1);
    this.modv = modv;
    this.size = size;
    f.set(0, 1L);
    for(int i = 1; i < this.size + 1; i++) f.set(i, (f.get(i - 1) * i) % modv);
  }

  private long inv(long x){
    long res = 1, k = this.modv - 2, y = x;
    while(k != 0){
      if((k & 1) != 0) res = (res * y) % modv;
      y = y * y % modv;
      k /= 2;
    }
    return res;
  }

  public long cal(int n, int r){
    long a = this.f.get(n);
    long b = this.f.get(n - r);
    long c = this.f.get(r);

    long bc = (b * c) % modv;
    
    return (a * inv(bc)) % modv;
  }
}