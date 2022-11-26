#include <bits/stdc++.h>

#include "atcoder.h"

// DisjointSet with path compression only. This is convenient for this problem,
// because Union(x, y) doesn't change the value of Find(x).
class DisjointSet {
 public:
  DisjointSet(int size) : parent_(size), size_(size, 1) {
    for (int i = 0; i < size; ++i) {
      parent_[i] = i;
    }
  }
  int Find(int x) {
    int& p = parent_[x];
    if (p != x) p = Find(p);
    return p;
  }
  // Add y to x.
  bool Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return false;
    parent_[y] = parent_[x];
    return true;
  }

 private:
  std::vector<int> parent_, size_;
};

void Main() {
  ints(n, q);
  V<int> ball_to_box(n + q);
  V<int> box_to_ball(n);
  DisjointSet ds(n + q);
  rep(i, n) {
    ball_to_box[i] = i;
    box_to_ball[i] = i;
  }
  int idx_begin = n;
  int idx_end = n + q;
  rep(q) {
    ints(t);
    if (t == 1) {
      ints(x, y);
      --x, --y;
      ds.Union(box_to_ball[x], box_to_ball[y]);
      int i = --idx_end;
      ball_to_box[i] = y;
      box_to_ball[y] = i;
    } else if (t == 2) {
      ints(x);
      --x;
      int i = idx_begin++;
      ds.Union(box_to_ball[x], i);
    } else {
      ints(x);
      --x;
      wt(ball_to_box[ds.Find(x)] + 1);
    }
  }
}
