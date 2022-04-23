#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  bool u = false, l = false;
  each(e, s) {
    if (isupper(e)) u = true;
    if (islower(e)) l = true;
  }
  wt(u && l && (sz(s) == sz(set(all(s)))));
}
