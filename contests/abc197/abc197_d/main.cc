#include <bits/stdc++.h>

#include "atcoder.h"
// TODO: Use geometry.h.

using P = complex<double>;

void Main() {
  ints(n);
  rd(double, x0, y0, x1, y1);
  P a(x0, y0), b(x1, y1);
  P ab = b - a;
  P c = a + ab / 2.0;
  double pi = acos(-1);
  P d = c + (-(ab / 2.0) * polar(1.0, 2 * pi / n));
  wt(d.real(), d.imag());
}
