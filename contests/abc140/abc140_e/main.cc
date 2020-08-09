#include <bits/stdc++.h>

#include "macros.h"
#include "segment_tree.h"

using namespace std;

map<pair<ll, ll>, ll> cache;

ll Aggregate(const vector<ll>& p, const SegmentTree<ll>& tree, ll begin,
             ll end) {
  if (end == begin) return 0;
  if (end - begin == 1) return p[begin];
  if (end - begin == 2) return max(p[begin], p[begin + 1]);
  pair<ll, ll> k = {begin, end};
  ll& v = cache[k];
  if (v == 0) {
    v = tree.Aggregate(begin, end);
    dbg("not cached");
  } else {
    dbg("cached");
  }
  return v;
}

ll rec(ll begin, ll end, ll maximum, const vector<ll>& p,
       const SegmentTree<ll>& tree, map<ll, ll>& index) {
  if (end - begin < 2) return 0;
  if (maximum == 0) maximum = Aggregate(p, tree, begin, end);
  ll maximum_i = index[maximum];
  ll second_maximum = max(Aggregate(p, tree, begin, maximum_i),
                          Aggregate(p, tree, maximum_i + 1, end));
  ll second_maximum_i = index[second_maximum];
  ll left = min(maximum_i, second_maximum_i);
  ll right = max(maximum_i, second_maximum_i);
  dbg(begin, end, maximum, second_maximum);
  dbg(begin, end, left, right);
  return (left - begin + 1) * (end - right) * second_maximum +
         rec(begin, right, (left == maximum_i ? maximum : second_maximum), p,
             tree, index) +
         rec(left + 1, end, (right == maximum_i ? maximum : second_maximum), p,
             tree, index) -
         rec(left + 1, right, 0, p, tree, index);
}

int main() {
  rd(ll, n);
  SegmentTree<ll> tree(n, [](ll a, ll b) { return max(a, b); });
  map<ll, ll> index;
  vector<ll> p(n);
  rep(i, n) {
    cin >> p[i];
    tree.Set(i, p[i]);
    index[p[i]] = i;
  }
  wt(rec(0, n, n, p, tree, index));
}
