#include <bits/stdc++.h>

#include "atcoder.h"

struct S {
  int lowest, change;
  bool operator<(const S& s) const { return lowest > s.lowest; }
};

void Main() {
  ints(n);
  vector<string> s(n);
  cin >> s;
  vector<S> left, right;
  for (const string& si : s) {
    int lowest = 0, change = 0;
    for (char c : si) {
      change += c == '(' ? 1 : -1;
      chmin(lowest, change);
    }
    if (change >= 0) {
      left.pb({lowest, change});
      continue;
    }
    lowest = 0, change = 0;
    rrep(i, si.size()) {
      change += si[i] == ')' ? 1 : -1;
      chmin(lowest, change);
    }
    right.pb({lowest, change});
  }
  sort(left);
  sort(right);
  auto height = [&](const vector<S>& v) -> optional<int> {
    int curr = 0;
    for (const auto& s : v) {
      if (curr + s.lowest < 0) {
        return nullopt;
      }
      curr += s.change;
    }
    return curr;
  };
  optional<int> l = height(left), r = height(right);
  wt(l && r && *l == *r);
}
