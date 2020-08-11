#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  rd(int, k);
  V<string> sub;
  rep(i, s.size()) rep(j, 5) if (i + j < s.size()) {
    sub.push_back(s.substr(i, j + 1));
  }
  sort(all(sub));
  unique(all(sub));
  wt(sub[k - 1]);
}
