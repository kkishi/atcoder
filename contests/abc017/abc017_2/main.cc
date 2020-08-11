#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, x);
  reverse(all(x));
  while (!x.empty()) {
    if (set{'o', 'k', 'u'}.count(x[0])) {
      x = x.substr(1);
      continue;
    }
    if (x.substr(0, 2) == "hc") {
      x = x.substr(2);
      continue;
    }
    break;
  }
  wt(x.empty() ? "YES" : "NO");
}
