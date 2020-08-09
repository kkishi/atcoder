#include <bits/stdc++.h>

#include "macros.h"
#include "segment_tree.h"

using namespace std;

int Union(int a, int b) { return a | b; }

int main() {
  int N;
  cin >> N;
  SegmentTree<int> tree(N, Union);
  string S;
  cin >> S;
  rep(i, N) tree.Set(i, 1 << (S[i] - 'a'));
  rep(i, N) dbg(i, tree.Get(i));
  int Q;
  cin >> Q;
  rep(q, Q) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      char c;
      cin >> i >> c;
      tree.Set(i - 1, 1 << (c - 'a'));
    } else {
      int l, r;
      cin >> l >> r;
      cout << __builtin_popcount(tree.Aggregate(l - 1, r)) << endl;
    }
  }
}
