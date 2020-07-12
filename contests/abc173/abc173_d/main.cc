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
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

struct Pair {
  ll l, r;
  ll Min() const { return min(l, r); }
  bool operator<(const Pair& p) const { return Min() < p.Min(); }
};

int main() {
  in(ll, n);
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(all(a), greater());

  ll ans = a[0];
  priority_queue<Pair> que;
  que.push({a[0], a[1]});
  que.push({a[1], a[0]});
  for (int i = 2; i < n; ++i) {
    Pair p = que.top();
    dbg(i, ans, p.l, p.r, p.Min());
    que.pop();
    ans += p.Min();
    que.push({p.l, a[i]});
    que.push({a[i], p.r});
  }
  out(ans);
}
