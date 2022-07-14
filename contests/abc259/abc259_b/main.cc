#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(double, a, b, d);
  complex<double> c = {a, b};
  c *= polar(1.0, d / 360 * 2 * 3.14159265358979);
  wt(c.real(), c.imag());
}
