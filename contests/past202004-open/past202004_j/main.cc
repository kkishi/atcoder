#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  auto f = [&](int begin, int end) { return s.substr(begin, end - begin); };
  wt(Fix([&](auto rec, int begin, int end) -> pair<string, int> {
       string ret;
       int b = begin;
       while (b < end) {
         int i = b;
         while (i < end && isalpha(s[i])) ++i;
         if (i == end) return {ret + f(b, end), end};
         if (s[i] == ')') return {ret + f(b, i), i + 1};
         assert(s[i] == '(');
         auto [res, pos] = rec(i + 1, end);
         string ser = res;
         reverse(ser);
         ret += f(b, i) + res + ser;
         b = pos;
       }
       return {ret, end};
     })(0, sz(s))
         .first);
}
