#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(double, xa, ya, xb, yb, xc, yc);
  wt(abs(((xa - xc) * (yb - yc) - (xb - xc) * (ya - yc)) / 2));
}
