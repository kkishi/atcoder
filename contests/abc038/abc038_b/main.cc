#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h1, w1, h2, w2);
  wt((h1 == h2 || h1 == w2 || w1 == h2 || w1 == w2) ? "YES" : "NO");
}
