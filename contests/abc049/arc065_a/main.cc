#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  reverse(all(s));
  V<string> v{"dream", "dreamer", "erase", "eraser"};
  for (auto& vi : v) reverse(all(vi));
  while (!s.empty()) {
    bool changed = false;
    for (const auto& vi : v) {
      if (s.substr(0, vi.size()) == vi) {
        s = s.substr(vi.size());
        changed = true;
        break;
      }
    }
    if (!changed) break;
  }
  wt(s.empty() ? "YES" : "NO");
}
