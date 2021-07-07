using System;

string[] str = Console.ReadLine().Split(' ');

int a = 0, b = 0;
for(int i = 0; i < 3; i++){
  a += int.Parse(str[0].Substring(i, 1));
  b += int.Parse(str[1].Substring(i, 1));
}

Console.WriteLine(Math.Max(a, b));