#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

using ld = long double;

ld sq(ld x) { return x * x; }

void Main() {
  rd(ld, a, b);
  if (a > b) swap(a, b);
  wt(BinarySearch<ld>(a, sqrt(sq(a) + sq(b)), [&](ld x) -> bool {
    ld y = sqrt(sq(x) - sq(a));
    complex<ld> p(y, a);
    p /= polar(1.0, M_PI / 3);
    return 0 <= p.real() && p.real() <= b && 0 <= p.imag() && p.imag() <= a;
  }));
}
