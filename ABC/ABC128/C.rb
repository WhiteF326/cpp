line = gets.split(' ')
n = line[0].to_i
m = line[1].to_i

sl = []
for i in 0...m do
  sl.push([])
  line = gets.split(' ').map(&:to_i)
  k = line[0]
  for j in 0...k do
    s = line[j + 1]
    sl[i].push(s - 1)
  end
end

p = gets.split(' ').map(&:to_i)

ans = 0
for i in 0...(1 << n) do
  swlist = []
  for j in 0...n do
    swlist.push(i & (1 << j) > 0 ? 1 : 0)
  end
  light = 0
  for j in 0...m do
    res = 0
    for k in sl[j] do
      res += swlist[k]
    end
    if res % 2 == p[j]
      light += 1
    end
  end
  if light == m
    ans += 1
  end
end

p ans