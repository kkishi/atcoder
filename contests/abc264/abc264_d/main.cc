#include <bits/stdc++.h>

#include "atcoder.h"
#include "inversion_number.h"

void Main() {
  strings(s);
  string t = "atcoder";
  V<int> idx;
  each(e, s) rep(i, sz(t)) if (e == t[i]) idx.eb(i);
  wt(InversionNumber(idx));
}
