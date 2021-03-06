# 目標
$ax + by = c$ の特殊解を求める。

# 手順

まず、$gcd(a, b) \cdot v = c$ であるような整数 $v$ が存在するものとする。
でなければ、$ax + by = c$ に整数解はない。

以下は整数解があるものとして進める。

まず、$v=1$ つまり $ax + by = \mathrm{gcd}(a, b)$ として解く。

## ax + by = gcd(a, b) の特殊解

便宜上、$\mathrm{gcd}(a, b) = c$ とする。

$a > b$ とする。$a$ を $b$ で割ることを考える。
商を $q$ とし余りは $r$ であるとすると、
$a = qb + r$ となる。

これを $ax + by = c$ に代入すると、$(qb + r)x + by = c$ となる。
$$\begin{align}
(qb + r)x + by &= c \\
qbx + rx + by &= c \\
b(qx + y) + rx &= c
\end{align}$$と変形できる。

$a, b$ は実際には問題上で与えられる値であることに注意されたい。
よって、ここで $q, r$ は数値として求められる値である。

$qx + y = x_1, x = y_1$ とすると、
$bx_1 + ry_1 = c$ となり、これは $ax + by = c$ と同様にしてまた変形できる。
また、$b = a_1, r = b_1$ とおいて、式変形を一般化すると

$$\begin{align}
ax + by &= c \\
a_1 x_1 + b_1 y_1 &= c \\
a_2 x_2 + b_2 y_2 &= c \\
\vdots
\end{align}$$となる。

この手順はユークリッドの互除法とまったく一致している。
そこで、ユークリッドの互除法に従って $a, b$ の $\mathrm{gcd}$ を求めると、最終的にどこかで割り切れるが、
その一手前の計算で出たあまりが $\mathrm{gcd}$ となる。

ここで、$\mathrm{gcd}(a, b) = c$ である。すなわちユークリッドの互除法における割り切れる一手前の計算が $s_n x_n + t_n y_n = c$ だったとすると、

$y_n = x_{n-1}$ であることから、$x_n = a_n(q_n x_{n-1} + y_{n-1})$ より $y_{n-1}$ の値が分かる。これを繰り返すことで、最終的に $x, y$ の値をひとつ求めることができた。

## 一般化

ここで、$c = \mathrm{gcd}(a, b) \cdot v$ であることから、
$ax + by = c$ であるとき、何らかの整数解 $d, e$ があって、$ad + be = \mathrm{gcd}(a, b)$ であるとする。
このとき両辺を $v$ 倍すると

$$\begin{align}
adv + bev = \mathrm{gcd}(a, b) \cdot v \\
adv + bev = c
\end{align}$$と変形できる。

よって、$a, b$ を $v$ で割ることで $c = \mathrm{gcd}(a, b)$ である場合に帰着できる。
よってこの問題を解けた。
