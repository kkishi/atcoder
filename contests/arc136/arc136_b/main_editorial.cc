#include <bits/stdc++.h>

#include "atcoder.h"
#include "inversion_number.h"

void Main() {
  wt([] {
    ints(n);
    V<int> a(n), b(n);
    cin >> a >> b;
    map<int, int> A, B;
    each(e, a)++ A[e];
    each(e, b)++ B[e];
    if (A != B) return false;
    each(_, e, A) if (e >= 2) return true;
    return even(InversionNumber(a)) == even(InversionNumber(b));
  }());
}
