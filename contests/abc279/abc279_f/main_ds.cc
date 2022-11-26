#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  V<int> ball_to_box(n + q);
  V<int> box_to_ball(n);
  DisjointSet ds(n + q);
  rep(i, n) {
    ball_to_box[i] = i;
    box_to_ball[i] = i;
  }
  int ball_idx_begin = n;
  int ball_idx_end = n + q;
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(x, y);
      --x, --y;
      int i = box_to_ball[x];
      int j = box_to_ball[y];
      ds.Union(i, j);
      int I = ds.Find(i);
      ball_to_box[I] = x;
      box_to_ball[x] = I;
      int J = --ball_idx_end;
      ball_to_box[J] = y;
      box_to_ball[y] = J;
    } else if (t == 2) {
      ints(x);
      --x;
      int i = ball_idx_begin++;
      int j = box_to_ball[x];
      ds.Union(i, j);
      int I = ds.Find(i);
      ball_to_box[I] = x;
      box_to_ball[x] = I;
    } else {
      ints(x);
      --x;
      wt(ball_to_box[ds.Find(x)] + 1);
    }
  }
}
