#include <bits/stdc++.h>

#include "macros.h"
#include "segment_tree.h"

using namespace std;

int Union(int a, int b) { return a | b; }

int main() {
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
