#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  string ict = "ict";
  int i = 0;
  each(e, s) if (i < 3 && tolower(e) == ict[i])++ i;
  wt(i == 3 ? "YES" : "NO");
}
