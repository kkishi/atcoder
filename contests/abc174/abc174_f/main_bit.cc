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

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

using namespace std;

template <typename T>
class BIT {
 public:
  BIT(int n) : v_(n) {}
  T Sum(int i) const {
    T ret = 0;
    while (i >= 0) {
      ret += v_[i];
      i = (i & (i + 1)) - 1;
    }
    return ret;
  }
  T Get(int i) const { return Sum(i) - Sum(i - 1); }
  void Add(int i, T v) {
    while (i < v_.size()) {
      v_[i] += v;
      i |= i + 1;
    }
  }

 private:
  std::vector<T> v_;
};

struct Q {
  int l, r, i, v;
};

int main() {
  in(int, n, q);
  V<int> c(n);
  rep(i, n) cin >> c[i];
  V<Q> qs;
  rep(i, q) {
    in(int, l, r);
    --l, --r;
    qs.push_back({l, r, i, 0});
  }
  sort(all(qs), [](const Q& a, const Q& b) { return a.r < b.r; });
  V<int> seen(n, -1);
  int seen_cnt = 0;
  BIT<int> bit(n);
  auto qit = qs.begin();
  V<int> ans(q);
  rep(i, n) {
    int& s = seen[c[i] - 1];
    if (s == -1) {
      ++seen_cnt;
    } else {
      bit.Add(s, -1);
    }
    s = i;
    bit.Add(i, 1);
    while (qit != qs.end() && qit->r == i) {
      ans[qit->i] = seen_cnt - bit.Sum(qit->l - 1);
      ++qit;
    }
  }
  rep(i, q) out(ans[i]);
}