#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

int Union(int a, int b) { return a | b; }

void Main() {
  ints(N);
  SegmentTree<int> tree(N, Union);
  strings(S);
  rep(i, N) tree.Set(i, 1 << (S[i] - 'a'));
  ints(Q);
  rep(Q) {
    ints(t);
    if (t == 1) {
      ints(i);
      char c;
      cin >> c;
      tree.Set(i - 1, 1 << (c - 'a'));
    } else {
      ints(l, r);
      wt(popcount(tree.Aggregate(l - 1, r)));
    }
  }
}
