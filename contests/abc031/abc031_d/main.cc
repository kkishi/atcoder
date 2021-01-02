#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k, n);
  VV<int> v(n);
  V<string> w(n);
  rep(i, n) {
    int vi;
    cin >> vi >> w[i];
    while (vi) {
      v[i].pb(vi % 10);
      vi /= 10;
    }
    reverse(all(v[i]));
  }
  V<optional<string>> m(10);
  // Run a DFS with backtracking.
  assert(Fix([&](auto rec, int row, int col, int i) -> bool {
    if (row == n) return true;
    if (col == sz(v[row])) return i == sz(w[row]) && rec(row + 1, 0, 0);
    int vi = v[row][col];
    if (const auto& mi = m[vi]; mi) {
      int l = sz(*mi);
      return i + l <= sz(w[row]) && w[row].substr(i, l) == mi &&
             rec(row, col + 1, i + l);
    }
    if (col == v[row].size()) {
      if (sz(w[row]) - i > 3) return false;
      m[vi] = w[row].substr(i);
      if (rec(row + 1, 0, 0)) return true;
      m[vi] = nullopt;
    } else {
      for (int l = 1; i + l <= sz(w[row]) && l <= 3; ++l) {
        m[vi] = w[row].substr(i, l);
        if (rec(row, col + 1, i + l)) return true;
      }
      m[vi] = nullopt;
    }
    return false;
  })(0, 0, 0));
  rep(i, k) wt(*m[i + 1]);

#if DEBUG
  // Verify the answer.
  rep(i, n) {
    string x;
    for (int vi : v[i]) {
      int s = sz(*m[vi]);
      assert(1 <= s && s <= 3);
      x += *m[vi];
    }
    assert(x == w[i]);
  }
#endif
}
