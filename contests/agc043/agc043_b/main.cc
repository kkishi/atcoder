#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define DBG(...)                \
  cerr << #__VA_ARGS__ << ": "; \
  debug(__VA_ARGS__);           \
  cerr << " (L" << __LINE__ << ")" << endl
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

template <typename T>
void setmax(T& a, const T& b) {
  if (a < b) a = b;
}

using namespace std;

template<class iter>
string conv(iter begin, iter end) {
  string s;
  for (; begin != end; ++begin) {
    if (s.empty() || s.back() < *begin) {
      s += *begin;
    }
  }
  return s;
}

string simulate(const string& s) {
  string ret;
  REP(i, s.size() - 1) {
    ret += '0' + abs(s[i] - s[i + 1]);
  }
  return ret;
}

string simplify(const string& s) {
  string ret;
  FOR(c, s) {
    if (ret.size() >= 2 && ret.back() == c && ret[ret.size() - 2] == c) {
      continue;
    }
    ret += c;
  }
  return ret;
}

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  string l = conv(ALL(S));
  string r = conv(S.rbegin(), S.rend());
  DBG(l, r);
  /*
  reverse(ALL(r));
  string s = l.substr(0, l.size() - 1) + r;
  DBG(l, r, s);
  */

  /*
  while (s.size() > 1) {
    s = simulate(s);
    DBG(s);
  }
  cout << s << endl;
  */
  char maximum = '0';
  FOR(c, S) setmax(maximum, c);
  DBG(maximum);
  int cnt = 0;
  FOR(c, S) if (c == maximum) ++cnt;

  reverse(ALL(r));

  string s;
  if (cnt & 1) {
    s = l.substr(0, l.size() - 1) + r;
  } else {
    s = l + r;
  }
  DBG(s);

  while (s.size() > 1) {
    s = simulate(s);
    DBG(s);
  }
  // cout << s << endl;

  string naive = S;
  while (naive.size() > 1) {
    naive = simulate(naive);
    DBG(naive);
  }
  if (s != naive) {
    DBG("FAIL");
  }

  string fast = S;
  while (fast.size() > 1) {
    fast = simulate(fast);
    DBG(fast);
    fast = simplify(fast);
    DBG(fast);
  }
  if (fast != naive) {
    DBG("FAIL");
  }
  cout << fast << endl;
}
