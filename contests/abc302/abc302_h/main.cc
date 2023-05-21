#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"

class DisjointSet {
 public:
  DisjointSet(int n) : parent_(n), size_(n), num_edges_(n) {
    rep(i, n) parent_[i] = i, size_[i] = 1;
  }
  int Find(int i) const {
    while (true) {
      int p = parent_[i];
      if (p == i) break;
      i = p;
    }
    return i;
  }
  int Union(int i, int j) {
    i = Find(i);
    j = Find(j);
    if (size_[i] < size_[j]) swap(i, j);
    parent_hist_.eb(j, parent_[j]);
    size_hist_.eb(i, size_[i]);
    num_edges_hist_.eb(i, num_edges_[i]);
    if (i != j) {
      parent_[j] = i;
      size_[i] += size_[j];
      num_edges_[i] += num_edges_[j];
    }
    ++num_edges_[i];
    return i;
  }
  void Undo() {
    auto [i, p] = parent_hist_.back();
    parent_hist_.pop_back();
    parent_[i] = p;
    auto [j, s] = size_hist_.back();
    size_hist_.pop_back();
    size_[j] = s;
    auto [k, n] = num_edges_hist_.back();
    num_edges_hist_.pop_back();
    num_edges_[k] = n;
  }
  int Size(int i) const { return size_[i]; }
  int NumEdges(int i) const { return num_edges_[i]; }

 private:
  V<int> parent_;
  V<pair<int, int>> parent_hist_;
  V<int> size_;
  V<pair<int, int>> size_hist_;
  V<int> num_edges_;
  V<pair<int, int>> num_edges_hist_;
};

void Main() {
  ints(n);
  V<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  Graph g(n);
  g.Read();

  DisjointSet ds(n);

  map<int, int> mp;  // Holds values for each connected component.
  int curr = 0;      // Current value of the answer.

  // Delete a connected component.
  V<pair<int, int>> del_hist;
  auto del = [&](int i) {
    auto it = mp.find(i);
    if (it != mp.end()) {
      del_hist.eb(*it);
      curr -= it->second;
      mp.erase(it);
    } else {
      del_hist.eb(-1, -1);
    }
  };
  auto undo_del = [&] {
    auto [k, v] = del_hist.back();
    del_hist.pop_back();
    if (k != -1) {
      mp[k] = v;
      curr += v;
    }
  };

  // Insert a connected component.
  V<int> ins_hist;
  auto ins = [&](int i) {
    assert(mp.count(i) == 0);
    int x = min(ds.Size(i), ds.NumEdges(i));
    curr += x;
    mp[i] = x;
    ins_hist.eb(i);
  };
  auto undo_ins = [&] {
    int i = ins_hist.back();
    ins_hist.pop_back();
    curr -= mp[i];
    mp.erase(i);
  };

  V<int> ans(n - 1);
  Fix([&](auto rec, int node, int parent) -> void {
    int A = ds.Find(a[node]);
    int B = ds.Find(b[node]);
    del(A);
    del(B);
    ins(ds.Union(A, B));
    if (node > 0) ans[node - 1] = curr;
    each(child, g[node]) {
      if (child == parent) continue;
      rec(child, node);
    }
    ds.Undo();
    undo_ins();
    undo_del();
    undo_del();
  })(0, -1);
  wt(ans);
}
