#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  each(e, s) if (e == '6' || e == '9') e = '6' + '9' - e;
  reverse(s);
  wt(s);
}
