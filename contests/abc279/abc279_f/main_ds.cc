#include <bits/stdc++.h>

#include "atcoder.h"
#include "disjoint_set.h"

void Main() {
  ints(n, q);
  V<int> ball_to_box(n + q);  // To which box does the ball GROUP belong?
  V<int> box_to_ball(n);      //  Which ball GROUP does the box i contain?
  DisjointSet ds(n + q);      // To which group does the ball i belong?
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
      int i = ds.Union(box_to_ball[x], box_to_ball[y]);
      ball_to_box[i] = x;
      box_to_ball[x] = i;
      // Put a placeholder ball GROUP to y.
      int j = --ball_idx_end;
      ball_to_box[j] = y;
      box_to_ball[y] = j;
    } else if (t == 2) {
      ints(x);
      --x;
      // Merge the new ball to the group in the box x. Note that the order of
      // the arguments is important (box_to_ball[x] to be the parent, so
      // box_to_ball[x] keeps pointing to the right group, thus we can skip
      // updating it).
      ds.Union(box_to_ball[x], ball_idx_begin++);
    } else {
      ints(x);
      --x;
      wt(ball_to_box[ds.Find(x)] + 1);
    }
  }
}
