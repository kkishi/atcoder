#include <bits/stdc++.h>

#include "binary_search.h"
#include "macros.h"
#include "segment_tree.h"

using namespace std;

int main() {
  ints(n, m);
  vector<pair<int, int>> job(n);
  rep(i, n) cin >> job[i].second >> job[i].first;
  sort(all(job), greater());

  int ans = 0;
  SegmentTree<bool> tree(
      n, [](bool a, bool b) { return a && b; }, true);
  rep(i, n) tree.Set(i, false);
  for (const auto& p : job) {
    if (p.second > m) continue;
    int i = BinarySearch<int>(0, m - p.second + 1, [&](int x) {
      return !tree.Aggregate(x, m - p.second + 1);
    });
    dbg(p.first, p.second, i);
    if (i == 0 && tree.Get(0)) continue;
    ans += p.first;
    tree.Set(i, true);
    dbg(tree.Get(0));
  }
  wt(ans);
}
