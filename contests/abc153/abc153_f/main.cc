#include <bits/stdc++.h>

#include "atcoder.h"
#include "dual_segment_tree.h"

struct Monster {
  int X, H;
  bool operator<(const Monster& m) const { return X < m.X; }
};

Monster monster[200000];

int Add(int a, int b) { return a + b; }

void Main() {
  ints(N, D, A);
  rep(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  DualSegmentTree<int> tree(N, Add);
  rep(i, N) tree.Update(i, i + 1, monster[i].H);

  int ans = 0;
  int mi = 0;
  while (mi < N) {
    int h = tree.Get(mi);
    if (h <= 0) {
      ++mi;
      continue;
    }
    Monster max_m = {monster[mi].X + D * 2, 0};
    int ub = upper_bound(monster, monster + N, max_m) - monster;
    int cnt = div_ceil(h, A);
    tree.Update(mi, ub, -cnt * A);
    ans += cnt;
  }
  wt(ans);
}
