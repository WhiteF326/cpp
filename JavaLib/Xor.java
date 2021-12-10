public class Xor implements Monoid<Long>{
  @Override
  public Long op(Long a, Long b){
    return a ^ b;
  }

  @Override
  public Long e(){
    return 0L;
  }
}
