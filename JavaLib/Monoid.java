public interface Monoid<T> {
  public T op(T a, T b);
  public T e();
}
