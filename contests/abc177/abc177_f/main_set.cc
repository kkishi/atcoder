#include <bits/stdc++.h>

#include "atcoder.h"

struct S {
  int begin, end;
  optional<int> value;
  bool flat;
  bool operator<(const S& s) const { return begin < s.begin; }
};

ostream& operator<<(ostream& os, const S& s) {
  os << "{" << s.begin << "," << s.end << ","
     << (s.value ? to_string(*s.value) : "{}") << "," << s.flat << "}";
  return os;
}

void Main() {
  ints(h, w);
  V<int> a(h), b(h);
  rep(i, h) {
    cin >> a[i] >> b[i];
    --a[i];  // [a, b)
  }

  set<S> s{{0, w, {0}, true}};
  multiset<int> ms{0};

  rep(i, h) {
    auto it = s.lower_bound(S{a[i], 0, 0, false});
    auto lt = it;
    if (lt == s.end() || lt->begin > a[i]) --lt;
    assert(lt->begin <= a[i] && a[i] < lt->end);
    auto rt = s.lower_bound(S{b[i], 0, 0, false});
    if (rt == s.end()) --rt;
    if (rt->begin >= b[i]) --rt;
    if (rt->end < b[i]) ++rt;
    dbg(a[i], b[i]);
    dbg(*rt);
    assert(rt->begin < b[i] && b[i] <= rt->end);

    V<S> todo;
    if (lt->begin < a[i]) {
      S s = *lt;
      s.end = a[i];
      todo.pb(s);
    }
    if (b[i] < rt->end) {
      S s = *rt;
      if (s.value) {
        if (!s.flat) {
          *s.value += b[i] - s.begin;
        }
      }
      s.begin = b[i];
      todo.pb(s);
    }
    for (auto it = lt; it != next(rt); ++it) {
      if (it->value) {
        ms.erase(ms.find(*it->value));
      }
    }
    s.erase(lt, next(rt));
    for (auto& t : todo) {
      s.insert(t);
      if (t.value) {
        ms.insert(*t.value);
      }
    }
    auto [nt, ok] = s.insert(S{a[i], b[i], nullopt, false});
    assert(ok);
    if (nt != s.begin()) {
      auto pt = prev(nt);
      if (pt->value) {
        const_cast<S&>(*nt).value =
            *pt->value + (pt->flat ? 1 : (pt->end - pt->begin));
        ms.insert(*nt->value);
      }
    }
    dbg(s);
    dbg(ms);
    if (ms.empty()) {
      wt(-1);
    } else {
      wt(*ms.begin() + i + 1);
    }
  }
}
