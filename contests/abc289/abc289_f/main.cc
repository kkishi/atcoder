#include <bits/stdc++.h>

#include "atcoder.h"

void Move(int& s, int a) { s = 2 * a - s; }

pair<V<int>, bool> Solve(int s, int t, int a) {
  if (!even(abs(s - t))) return {{}, false};
  V<int> ret;
  while (s != t) {
    int nd = big;
    V<int> nm;
    auto check = [&](const V<int>& moves) {
      int ns = s;
      each(e, moves) Move(ns, e);
      if (chmin(nd, abs(t - ns))) nm = moves;
    };
    check({a, a + 1});
    check({a + 1, a});
    each(e, nm) {
      ret.eb(e);
      Move(s, e);
    }
  }
  return {ret, true};
}

void Main() {
  ints(sx, sy, tx, ty, a, b, c, d);
  if (sx == tx && sy == ty) {
    wt("Yes");
    return;
  }
  // If both the width and the height have size 1, there's only one possible
  // move, so check it.
  if (a == b && c == d) {
    Move(sx, a);
    Move(sy, c);
    if (sx == tx && sy == ty) {
      wt("Yes");
      wt(a, c);
    } else {
      wt("No");
    }
    return;
  }
  // If either the width or the height has size 1, it might necessiate the total
  // number of moves to be odd. Handle such cases.
  V<pair<int, int>> extra;
  if (a == b && sx != tx) {
    extra.eb(a, c);
    Move(sx, a);
    Move(sy, c);
    if (sx != tx) {
      wt("No");
      return;
    }
  }
  if (c == d && sy != ty) {
    extra.eb(a, c);
    Move(sx, a);
    Move(sy, c);
    if (sy != ty) {
      wt("No");
      return;
    }
  }
  // From here, we can restrict the number of moves to be even, so we can solve
  // x and y independently.
  auto [x, xok] = Solve(sx, tx, a);
  auto [y, yok] = Solve(sy, ty, c);
  if (!xok || !yok) {
    wt("No");
    return;
  }
  wt("Yes");
  each(x, y, extra) wt(x, y);
  each(e, x) wt(e, c);
  each(e, y) wt(a, e);
}
