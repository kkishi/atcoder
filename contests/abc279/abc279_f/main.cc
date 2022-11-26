#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, q);
  V<set<int>> box(n);
  V<int> ball_to_int_box_idx(n + q);
  V<int> int_box_to_ext_box(2 * n);
  V<int> ext_box_to_int_box(2 * n);
  rep(i, n) {
    box[i].insert(i);
    ball_to_int_box_idx[i] = i;
    int_box_to_ext_box[i] = i;
    ext_box_to_int_box[i] = i;
  }
  int num_balls = n;
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(x, y);
      --x, --y;
      int X = ext_box_to_int_box[x];
      int Y = ext_box_to_int_box[y];
      // Balls added to X
      if (sz(box[X]) < sz(box[Y])) {
        swap(X, Y);
      }
      each(e, box[Y]) {
        box[X].insert(e);
        ball_to_int_box_idx[e] = X;
      }
      box[Y].clear();
      int_box_to_ext_box[X] = x;
      int_box_to_ext_box[Y] = y;
      ext_box_to_int_box[x] = X;
      ext_box_to_int_box[y] = Y;
    } else if (t == 2) {
      ints(x);
      --x;
      int X = ext_box_to_int_box[x];
      int i = num_balls++;
      ball_to_int_box_idx[i] = X;
      box[X].insert(i);
    } else {
      ints(x);
      --x;
      wt(int_box_to_ext_box[ball_to_int_box_idx[x]] + 1);
    }
  }
}
