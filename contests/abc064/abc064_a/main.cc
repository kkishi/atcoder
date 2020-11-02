#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(r, g, b);
  wt((r * 100 + g * 10 + b) % 4 == 0 ? "YES" : "NO");
}
