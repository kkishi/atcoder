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
  void Swap(int a, int b) {
    int ta = types_[a];
    int tb = types_[b];
    Change(a, tb);
    Change(b, ta);
  }
  int Sat() const { return sat_; }
  const vector<int>& Types() { return types_; }

 private:
  const Problem& problem_;
  vector<int> types_;
  vector<set<int>> held_;
  int sat_;
};

inline int Now() {
  return chrono::duration_cast<chrono::milliseconds>(
             chrono::system_clock::now().time_since_epoch())
      .count();
}

void Improve(const Problem& p, Solution& sol, int start) {
  while (true) {
    bool improved = false;
    rep(i, p.D) {
      for (int j = i + 1; j < p.D; ++j) {
        if (Now() - start > 1900) return;

        int ti = sol.Types()[i];
        int tj = sol.Types()[j];
        if (ti == tj) continue;

        int s = sol.Sat();
        sol.Swap(i, j);
        if (sol.Sat() > s) {
          improved = true;
        } else {
          sol.Swap(i, j);
        }
      }
    }
    if (!improved) {
      dbg("swap1 not improved");
      break;
    }
  }
  while (true) {
    bool improved = false;
    rep(i, p.D) {
      for (int j = i + 1; j < p.D; ++j) {
        for (int k = j + 1; k < p.D; ++k) {
          if (Now() - start > 1900) return;

          int ti = sol.Types()[i];
          int tj = sol.Types()[j];
          int tk = sol.Types()[k];
          if (ti == tj || tj == tk || tk == ti) continue;

          int s = sol.Sat();
          sol.Swap(i, j);
          sol.Swap(j, k);
          if (sol.Sat() > s) {
            improved = true;
          } else {
            sol.Swap(j, k);
            sol.Swap(i, j);
          }
        }
      }
    }
    if (!improved) {
      dbg("swap2 not improved");
      break;
    }
  }
}

void Main() {
  int start = Now();

  Problem p;
  cin >> p.D;
  p.c.resize(26);
  rep(i, 26) cin >> p.c[i];
  p.s.resize(p.D);
  rep(i, p.D) {
    p.s[i].resize(26);
    rep(j, 26) cin >> p.s[i][j];
  }

  vector<int> t;

  vector<int> last(26);
  rep(i, p.D) {
    int d = i + 1;
    int maxi = -big;
    int chosen;
    rep(j, 26) {
      int change = p.s[i][j];
      rep(k, 26) {
        int last_day = k == j ? d : last[k];
        change -= p.c[k] * (d - last_day);
      }
      // HACK
      change += (d - last[j]) * p.c[j] * 6;
      if (chmax(maxi, change)) {
        chosen = j;
      }
    }
    last[chosen] = d;
    t.pb(chosen);
  }

  Solution sol(p, t);
  Improve(p, sol, start);
  rep(i, p.D) wt(sol.Types()[i] + 1);
}
