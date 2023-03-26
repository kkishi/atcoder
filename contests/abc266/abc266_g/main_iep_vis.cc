#include <bits/stdc++.h>

#include "atcoder.h"

void Solve(int r, int g, int b, int k) {
  // Solve naively.
  {
    string s = string(r, 'R') + string(g, 'G') + string(b, 'B');
    sort(s);
    int ans = 0;
    do {
      string ox;
      int cnt = 0;
      rep(i, sz(s) - 1) {
        if (s[i] == 'R' && s[i + 1] == 'G') {
          ++cnt;
          ox += 'o';
        } else {
          ox += 'x';
        }
      }
      dbg(s, ox, cnt);
      if (cnt == k) ++ans;
    } while (next_permutation(all(s)));
    dbg("naive", ans);
  }
  // Visualize how inclusion-exclusion principle works.
  {
    string s = string(r - k, 'R') + string(g - k, 'G') + string(b, 'B') +
               string(k, 'X');
    sort(s);

    int cnt_all = 0;
    int N = sz(s) - 1;
    VV<string> a(N);
    do {
      string ox;
      int cnt = 0;
      rep(i, N) {
        if (s[i] == 'R' && s[i + 1] == 'G') {
          ++cnt;
          ox += 'o';
          a[i].eb(s);
        } else {
          ox += 'x';
        }
      }
      dbg(s, ox, cnt);
      ++cnt_all;
    } while (next_permutation(all(s)));
    dbg(cnt_all);

    int ng = 0;
    V<int> seq;
    rep(i, 1, N + 1) {
      V<int> use(N);
      rep(j, i) use[j] = 1;
      int sum = 0;
      do {
        V<int> idx;
        rep(j, sz(a)) if (use[j]) idx.eb(j);
        set<string> st(all(a[idx[0]]));
        rep(j, 1, sz(idx)) {
          set<string> nst;
          each(e, a[idx[j]]) if (st.count(e)) nst.insert(e);
          swap(st, nst);
        }
        dbg(idx, st);
        sum += sz(st);
      } while (next_permutation(use.rbegin(), use.rend()));
      if (even(i)) sum = -sum;
      dbg(i, sum);
      ng += sum;
      seq.eb(sum);
    }
    dbg(seq, ng);

    dbg("iep", cnt_all - ng);
  }
  // Check how the fast inclusion-exclusion principle solution works.
  {
    int x = k;
    int r2 = r -= k;
    int g2 = g -= k;
    V<int> seq;
    int ans = 0;
    rep(i, 0, min(r2, g2) + 1) {
      int y = i;
      int r3 = r2 - i;
      int g3 = g2 - i;
      auto f = [](int x) {
        int ret = 1;
        rep(i, x) ret *= i + 1;
        return ret;
      };
      int cnt = f(r3 + g3 + b + x + y) / (f(r3) * f(g3) * f(b) * f(x) * f(y));
      if (!even(i)) cnt = -cnt;
      ans += cnt;
      seq.eb(cnt);
    }
    dbg(seq, ans);
    wt(ans);
  }
}

void Main() {
  ints(r, g, b, k);
  Solve(r, g, b, k);
}
