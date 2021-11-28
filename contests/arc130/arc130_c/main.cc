#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(a, b);
  bool swp = false;
  if (sz(a) < sz(b)) {
    swap(a, b);
    swp = true;
  }
  map<int, int> A, B;
  each(e, a)++ A[e - '0'];
  each(e, b)++ B[e - '0'];
  int ans = big;
  string ans_a = a, ans_b = b;
  const int d = sz(a) - sz(b);
  const int D = sz(b);
  rep(ax, 1, 10) {
    if (A[ax] == 0) continue;
    rep(bx, 10 - ax, 10) {
      if (B[bx] == 0) continue;
      map<int, int> a = A, b = B;
      --a[ax];
      --b[bx];
      deque<int> aL, aR, bR;
      aR.push_back(ax);
      bR.push_back(bx);
      while (sz(aL) < d && a[9] > 0) {
        --a[9];
        aL.push_back(9);
      }
      rrep(x, 1, 10) {
        while (a[x] > 0) {
          bool ok = false;
          rep(y, 9 - x, 10) {
            if (b[y] == 0) continue;
            ok = true;
            --a[x];
            --b[y];
            aR.push_front(x);
            bR.push_front(y);
            break;
          }
          if (!ok) break;
        }
      }
      each(k, v, a) {
        rep(v) {
          if (sz(aR) < D) {
            aR.push_back(k);
          } else {
            aL.push_front(k);
          }
        }
      }
      each(k, v, b) {
        rep(v) { bR.push_back(k); }
      }
      string sa, sb;
      each(e, aL) sa += '0' + e;
      each(e, aR) sa += '0' + e;
      each(e, bR) sb += '0' + e;
      string SA = "0" + sa;
      string SB = "0" + string(d, '0') + sb;
      int sum = 0;
      int carry = 0;
      rrep(i, sz(SA)) {
        int x = carry + (SA[i] - '0') + (SB[i] - '0');
        sum += x % 10;
        carry = x / 10;
      }
      if (carry) ++sum;
      if (chmin(ans, sum)) {
        ans_a = sa;
        ans_b = sb;
      }
    }
  }
  if (swp) {
    swap(ans_a, ans_b);
  }
  wt(ans_a);
  wt(ans_b);
}
