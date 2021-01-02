#include <bits/stdc++.h>

#include "atcoder.h"

int Dfs(int l, int mult, int node, vector<tuple<int, int, int>>& v) {
  if (l == 1) {
    return node;
  }
  if (even(l)) {
    v.push_back({node, node + 1, 0});
    v.push_back({node, node + 1, mult});
    return Dfs(l / 2, mult * 2, node + 1, v);
  }
  int n = Dfs(l - 1, mult, node, v);
  v.push_back({node, n, (l - 1) * mult});
  return n;
}

void Main() {
  rd(int, l);
  vector<tuple<int, int, int>> v;
  int n = Dfs(l, 1, 0, v);
  wt(n + 1, v.size());
  for (auto [a, b, c] : v) {
    wt(a + 1, b + 1, c);
  }
}
