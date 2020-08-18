#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s, t);
  int n = s.size();
  bool ok = false;
  rep(i, n) if (s.substr(i, n - i) + s.substr(0, i) == t) ok = true;
  wt(ok);
}
