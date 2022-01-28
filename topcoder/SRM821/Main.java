import java.util.*;

class Main{
  public static void main(String[] args) {
    ConnectTheWorld ctw = new ConnectTheWorld();
    String[] terminalA = {"Madrid"};
    String[] terminalB = {"Porto"};
    String[] isolated = {};
    System.out.println(Arrays.toString(ctw.connect(
      terminalA, terminalB, isolated
    )));
  }
}