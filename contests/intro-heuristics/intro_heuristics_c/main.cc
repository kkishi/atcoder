#include <bits/stdc++.h>

#include "atcoder.h"

struct Problem {
  int D;
  vector<int> c;
  vector<vector<int>> s;
};

class Solution {
 public:
  Solution(const Problem& p, const vector<int>& t)
      : problem_(p), types_(t), held_(26, {0, p.D + 1}), sat_(0) {
    rep(i, p.D) {
      sat_ += p.s[i][t[i]];
      held_[t[i]].insert(i + 1);
    }

    rep(i, 26) {
      const set<int>& h = held_[i];
      auto it = h.begin();
      ++it;
      for (; it != h.end(); ++it) {
        auto jt = it;
        --jt;
        int n = (*it - *jt - 1);
        sat_ -= p.c[i] * n * (n + 1) / 2;
      }
    }
  }
  void Change(int d, int q) {
    assert(d < types_.size());
    assert(types_[d] != q);

    auto change = [&](int date) {
      int t = types_[date];
      int ret = problem_.s[date][t];
      auto it = held_[t].find(date + 1);
      assert(it != held_[t].end());
      auto jt = it;
      --jt;
      int n = (*it - *jt);
      auto kt = it;
      ++kt;
      int m = (*kt - *it);
      ret += problem_.c[t] * m * n;
      return ret;
    };

    sat_ -= change(d);
    held_[types_[d]].erase(d + 1);
    types_[d] = q;
    assert(held_[types_[d]].count(d + 1) == 0);
    held_[types_[d]].insert(d + 1);
    sat_ += change(d);
  }
  int Sat() const { return sat_; }

 private:
  const Problem& problem_;
  vector<int> types_;
  vector<set<int>> held_;
  int sat_;
};

void Main() {
  Problem p;
  cin >> p.D;
  p.c.resize(26);
  cin >> p.c;
  p.s.resize(p.D);
  rep(i, p.D) {
    p.s[i].resize(26);
    rep(j, 26) cin >> p.s[i][j];
  }

  vector<int> t(p.D);
  rep(i, p.D) {
    cin >> t[i];
    --t[i];
  }

  Solution s(p, t);

  ints(m);
  while (m--) {
    ints(d, q);
    --d, --q;
    s.Change(d, q);
    wt(s.Sat());
  }
}
