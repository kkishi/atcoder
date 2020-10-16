#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);

  string s[10];
  s[2] = s[4] = s[5] = s[7] = s[9] = "hon";
  s[0] = s[1] = s[6] = s[8] = "pon";
  s[3] = "bon";
  wt(s[N % 10]);
}
