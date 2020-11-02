#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  ints(x, y);

  V<int> fs;
  int f = 0;
  for (char c : s) {
    if (c == 'F') {
      ++f;
    } else {
      fs.push_back(f);
      f = 0;
    }
  }
  fs.push_back(f);

  auto get = [&s](V<bool>& v, int i) { return v[sz(s) + i]; };
  auto set = [&s](V<bool>& v, int i) { v[sz(s) + i] = true; };
  const int dpsize = sz(s) * 2 + 3;

  V<bool> dpx(dpsize);
  for (int i = 0; i < sz(fs); i += 2) {
    if (i == 0) {
      set(dpx, fs[0]);
    } else {
      V<bool> ndp(dpsize);
      rep(j, -sz(s), sz(s) + 1) {
        if (get(dpx, j)) {
          set(ndp, j - fs[i]);
          set(ndp, j + fs[i]);
        }
      }
      swap(ndp, dpx);
    }
  }

  V<bool> dpy(dpsize);
  set(dpy, 0);
  for (int i = 1; i < sz(fs); i += 2) {
    V<bool> ndp(dpsize);
    rep(j, -sz(s), sz(s) + 1) {
      if (get(dpy, j)) {
        set(ndp, j - fs[i]);
        set(ndp, j + fs[i]);
      }
    }
    swap(ndp, dpy);
  }

  wt(get(dpx, x) && get(dpy, y));
}
