#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;
#include "segment_tree.h"

using namespace std;

struct Robot {
  int X, D;
  int Destination() const { return X + D; }
  bool operator<(const Robot& r) const { return X < r.X; }
};

Robot robot[200000];
mint dp[200001];

int Max(int a, int b) { return max(a, b); }

int main() {
  int N;
  cin >> N;

  rep(i, N) cin >> robot[i].X >> robot[i].D;
  sort(robot, robot + N);

  SegmentTree<int> tree(N, Max);
  rep(i, N) tree.Set(i, i);

  dp[N] = 1;
  for (int i = N - 1; i >= 0; --i) {
    Robot r = {robot[i].Destination(), 0};
    int n = lower_bound(robot, robot + N, r) - robot;
    int m = tree.Aggregate(i, n);
    tree.Set(i, m);

    dp[i] = dp[i + 1] + dp[m + 1];
  }
  cout << dp[0] << endl;
}
