#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"
#include "segment_tree.h"

using mint = ModInt<>;

using namespace std;

struct Robot {
  int X, D;
  int Destination() const { return X + D; }
  bool operator<(const Robot& r) const { return X < r.X; }
};

mint dp[200001];

int main() {
  rd(int, N);

  V<Robot> robot(N);
  rep(i, N) cin >> robot[i].X >> robot[i].D;
  sort(all(robot));

  SegmentTree<int> tree(N, [](int a, int b) { return max(a, b); });
  rep(i, N) tree.Set(i, i);

  dp[N] = 1;
  rrep(i, N) {
    Robot r = {robot[i].Destination(), 0};
    int n = lower_bound(all(robot), r) - robot.begin();
    int m = tree.Aggregate(i, n);
    tree.Set(i, m);

    dp[i] = dp[i + 1] + dp[m + 1];
  }
  wt(dp[0]);
}
