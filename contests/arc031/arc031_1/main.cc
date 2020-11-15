#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  string t = s;
  reverse(all(t));
  wt(s == t ? "YES" : "NO");
}
