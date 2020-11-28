#include <bits/stdc++.h>

#include "atcoder.h"

int Solve() {
  ints(ax, ay, bx, by, cx, cy);

  // Think of the 3 points to be one entity that occupies a square of area 1.
  // The entity has orientations alongside x-axis and y-axis. For example, the
  // initial state occupies (0, 0), (1, 1) and has negative x-axis orientation
  // and negative y-axis orientation. The entity can perform the following
  // actions:
  //
  // * Move to an adjacent cell, if the entity is oriented towards the cell.
  // After the move, the orientation of the axis used for the movement is
  // flipped, and the orientation of the other axis can be chosen arbitrary.
  // * Change the orientation of either x-axis or y-axis.
  //
  // With that, it can be proved that zig-zag movement is optimal.
  bool left = true;
  bool down = true;
  int x = min({ax, bx, cx});
  int y = min({ay, by, cy});

  set<pair<int, int>> p{{ax, ay}, {bx, by}, {cx, cy}};
  bool left2 = true;
  bool down2 = true;
  rep(i, 2) rep(j, 2) if (!p.count({x + i, y + j})) {
    if (i == 0) left2 = false;
    if (j == 0) down2 = false;
  }

  // Normalize.
  if (x < 0) {
    left = !left;
    left2 = !left2;
    x = -x;
  }
  if (y < 0) {
    down = !down;
    down2 = !down2;
    y = -y;
  }

  if (x == 0 && y == 0) {
    return (left == left2 && down == down2) ? 0 : 1;
  }

  if (y == 0) {
    swap(left, down);
    swap(left2, down2);
    swap(x, y);
  }
  if (x == 0) {
    assert(y != 0);
    int ans = 0;
    if (!down) {
      --y;
      ++ans;
    }
    ans += y * 2;
    if (!down2) ++ans;
    return ans;
  }

  auto f = [](bool l, bool d2, bool l2, int x, int y) {
    int cnt = 0;
    // Do a zig-zag move starting from right, then up, right, ...
    int z = min(x, y);
    assert(z > 0);
    if (l) ++cnt;
    cnt += z * 2;

    if (x == y) {
      if (!d2) ++cnt;
    } else if (y > z) {
      cnt += (y - z) * 2;
      if (!d2) ++cnt;
    } else {
      ++cnt;
      --x;
      cnt += (x - z) * 2;
      if (!l2) ++cnt;
    }
    return cnt;
  };
  return min(f(left, down2, left2, x, y), f(down, left2, down2, y, x));
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
