#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n);
  V<double> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  double s = accumulate(all(a), double(0));
  double x = BinarySearch<double>(0, big, [&](double x) {
    double l = 0;
    {
      double t = x;
      rep(i, n) {
        double T = a[i] / b[i];
        if (T < t) {
          t -= T;
          l += a[i];
        } else {
          l += t * b[i];
          break;
        }
      }
    }
    double r = 0;
    {
      double t = x;
      rrep(i, n) {
        double T = a[i] / b[i];
        if (T < t) {
          t -= T;
          r += a[i];
        } else {
          r += t * b[i];
          break;
        }
      }
    }
    return l + r < s;
  });
  double l = 0;
  {
    double t = x;
    rep(i, n) {
      double T = a[i] / b[i];
      if (T < t) {
        t -= T;
        l += a[i];
      } else {
        l += t * b[i];
        break;
      }
    }
  }
  wt(l);
}
