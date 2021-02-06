#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"
#include "segment_tree.h"

void Main() {
  ints(n, l);
  V<int> a(n);
  cin >> a;
  BinarySearch<int>(l, 0, [&](int x) {
    SegmentTree<int> t(n, [](int a, int b) { return max(a, b); });
    rep
                            
  
}
