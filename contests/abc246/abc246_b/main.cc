#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(a, b);
  complex<double> c(a, b);
  c /= abs(c);
  wt(c.real(), c.imag());
}
