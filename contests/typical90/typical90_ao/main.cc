#include <bits/stdc++.h>

#include "atcoder.h"

// http://www.prefield.com/algorithm/index.html

typedef complex<int> P;

namespace std {
bool operator<(const P& a, const P& b) {
  return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
}  // namespace std
int cross(const P& a, const P& b) { return imag(conj(a) * b); }
int dot(const P& a, const P& b) { return real(conj(a) * b); }

int ccw(P a, P b, P c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0) return +1;    // counter clockwise
  if (cross(b, c) < 0) return -1;    // clockwise
  if (dot(b, c) < 0) return +2;      // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line
  return 0;
}

vector<P> convex_hull(vector<P> ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  vector<P> ch(2 * n);
  for (int i = 0; i < n; ch[k++] = ps[i++])  // lower-hull
    while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])  // upper-hull
    while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
  ch.resize(k - 1);
  return ch;
}

using number = int;
using polygon = vector<P>;

#define curr(P, i) P[i]
#define next(P, i) P[(i + 1) % P.size()]

number area2(const polygon& P) {
  number A = 0;
  for (int i = 0; i < P.size(); ++i) A += cross(curr(P, i), next(P, i));
  return A;
}

void Main() {
  ints(n);
  V<P> v;
  rep(n) {
    ints(x, y);
    v.eb(x, y);
  }
  V<P> ch = convex_hull(v);
  int a2 = area2(ch);
  int b = 0;
  rep(i, sz(ch)) {
    P p = next(ch, i) - curr(ch, i);
    b += gcd(abs(p.real()), abs(p.imag()));
  }
  wt((a2 - b) / 2 + 1 + b - n);
}
