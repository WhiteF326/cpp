package ABC.ABC045.C_Java;

import java.util.*;

class Main {
  static double log2(double x) {
    return Math.log10(x) / Math.log10(2);
  }

  static int[] Dec2Bin(int x, int len) {
    String l = Integer.toBinaryString(x);
    int[] ret = new int[len];
    for (int i = 0; i < l.length(); i++) {
      ret[len - l.length() + i] = Integer.parseInt(l.substring(i, i + 1));
    }
    return ret;
  }

  static long sum(int[] arr) {
    long ans = 0;
    for (int i = 0; i < arr.length; i++) {
      ans += arr[i];
    }
    return ans;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    long ans = 0;

    String s = sc.next();

    if (s.length() == 1) {
      System.out.println(s);
    } else {
      for (int i = 0; i < (1 << (s.length() - 1)); i++) {
        int[] ret = Dec2Bin(i, s.length() - 1);
        String t = "";
        for (int j = 0; j < s.length() - 1; j++) {
          t += s.substring(j, j + 1);
          if (ret[j] == 1)
            t += " ";
        }
        t += s.substring(s.length() - 1);
        String[] cls = t.split(" ");
        for (int j = 0; j < cls.length; j++) {
          ans += Long.parseLong(cls[j]);
        }
      }

      System.out.println(ans);
    }

    sc.close();
  }
}