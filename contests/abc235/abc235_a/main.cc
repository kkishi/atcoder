#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  each(e, s) ans += 111 * (e - '0');
  wt(ans);
}
