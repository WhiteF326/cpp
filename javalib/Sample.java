import java.util.ArrayList;
import java.util.Collections;

class Pair implements selfComparable<Pair>{
  int l, r;

  Pair(int l, int r){
    this.l = l;
    this.r = r;
  }
  
  @Override
  public boolean compareTo(Pair obj){
    if(obj.l == this.l){
      return this.r > obj.r;
    }else{
      return this.l > obj.l;
    }
  }

  @Override
  public String toString(){
    return "{" + Integer.toString(l) + ", " + Integer.toString(r) + "}";
  }
}

class Sorter{
  static <T extends selfComparable<? super T>> void sort(ArrayList<T> list){
    for(int i = 0; i < list.size() - 1; i++){
      for(int j = i + 1; j < list.size(); j++){
        if(list.get(i).compareTo(list.get(j))){
          Collections.swap(list, i, j);
        }
      }
    }
  }
}

public class Sample {
  public static void main(String[] args){
    ArrayList<Pair> list = new ArrayList<Pair>();

    list.add(new Pair(3, 4));
    list.add(new Pair(4, 6));
    list.add(new Pair(4, 9));
    list.add(new Pair(1, 3));
    list.add(new Pair(7, 5));
    list.add(new Pair(2, 8));
    list.add(new Pair(2, 6));
    list.add(new Pair(2, 4));

    System.out.println(list.toString());
    
    Sorter.sort(list);

    System.out.println(list.toString());
  }
}
