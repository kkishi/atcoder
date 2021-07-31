#include <bits/stdc++.h>

#include "atcoder.h"

bool Weak(string x) {
  bool weak = true;
  rep(i, 4) if (x[i] != x[0]) weak = false;
  if (weak) return true;
  weak = true;
  rep(i, 3) if (x[i + 1] != (x[i] == '9' ? '0' : (x[i] + 1))) weak = false;
  return weak;
}

void Main() {
  strings(x);
  wt(Weak(x) ? "Weak" : "Strong");
}
