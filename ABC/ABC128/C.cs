using System;

String[] line = Console.ReadLine().Split(' ');
int n = int.Parse(line[0]), m = int.Parse(line[1]);

List<List<int>> sl = new List<List<int>>();
for(int i = 0; i < m; i++){
  sl.Add(new List<int>());
  String[] ksline = Console.ReadLine().Split(' ');
  int k = int.Parse(ksline[0]);

  for(int j = 0; j < k; j++){
    sl[i].Add(int.Parse(ksline[j + 1]) - 1);
  }
}

int[] p = new int[m];
String[] pline = Console.ReadLine().Split(' ');
for(int i = 0; i < m; i++) p[i] = int.Parse(pline[i]);

int ans = 0;
for(int i = 0; i < (1 << n); i++){
  int[] swlist = new int[n];
  for(int j = 0; j < n; j++){
    if((i & 1 << j) > 0) swlist[j] = 1;
    else swlist[j] = 0;
  }
  int light = 0;
  for(int j = 0; j < m; j++){
    int res = 0;
    foreach(int k in sl[j]) res += swlist[k];
    if(res % 2 == p[j]) light++;
  }
  if(light == m) ans++;
}

Console.WriteLine(ans);