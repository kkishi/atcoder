#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  wt((count(all(s), 'o') + 15 - sz(s) >= 8) ? "YES" : "NO");
}
