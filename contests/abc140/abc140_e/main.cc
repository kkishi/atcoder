#include <bits/stdc++.h>

#include "atcoder.h"
#include "segment_tree.h"

map<pair<int, int>, int> cache;

int Aggregate(const vector<int>& p, const SegmentTree<int>& tree, int begin,
              int end) {
  if (end == begin) return 0;
  if (end - begin == 1) return p[begin];
  if (end - begin == 2) return max(p[begin], p[begin + 1]);
  pair<int, int> k = {begin, end};
  int& v = cache[k];
  if (v == 0) {
    v = tree.Aggregate(begin, end);
    dbg("not cached");
  } else {
    dbg("cached");
  }
  return v;
}

int rec(int begin, int end, int maximum, const vector<int>& p,
        const SegmentTree<int>& tree, map<int, int>& index) {
  if (end - begin < 2) return 0;
  if (maximum == 0) maximum = Aggregate(p, tree, begin, end);
  int maximum_i = index[maximum];
  int second_maximum = max(Aggregate(p, tree, begin, maximum_i),
                           Aggregate(p, tree, maximum_i + 1, end));
  int second_maximum_i = index[second_maximum];
  int left = min(maximum_i, second_maximum_i);
  int right = max(maximum_i, second_maximum_i);
  dbg(begin, end, maximum, second_maximum);
  dbg(begin, end, left, right);
  return (left - begin + 1) * (end - right) * second_maximum +
         rec(begin, right, (left == maximum_i ? maximum : second_maximum), p,
             tree, index) +
         rec(left + 1, end, (right == maximum_i ? maximum : second_maximum), p,
             tree, index) -
         rec(left + 1, right, 0, p, tree, index);
}

void Main() {
  ints(n);
  SegmentTree<int> tree(n, [](int a, int b) { return max(a, b); });
  map<int, int> index;
  vector<int> p(n);
  rep(i, n) {
    cin >> p[i];
    tree.Set(i, p[i]);
    index[p[i]] = i;
  }
  wt(rec(0, n, n, p, tree, index));
}
