using System;
using System.Collections.Generic;

namespace p6921{
  class Program{
    static void Main(string[] args){
      int n = int.Parse(Console.ReadLine());
      if (n % 4 == 0){
        Console.WriteLine("Yes");
      }else{
        Console.WriteLine("No");
      }
    }
  }
}