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

using P = pair<int, int>;

struct Q {
  P lr;
  int bucket;
  int i;
  int kinds;
};

int main() {
  in(int, n, q);
  V<int> c(n);
  rep(i, n) cin >> c[i];

  auto bucket = [](int i) { return int(sqrt(i)); };

  V<Q> qs(q);
  rep(i, q) {
    cin >> qs[i].lr.first >> qs[i].lr.second;
    --qs[i].lr.first;
    --qs[i].lr.second;
    qs[i].i = i;
    qs[i].bucket = bucket(qs[i].lr.first);
  }
  sort(all(qs), [](const Q& l, const Q& r) {
    if (l.bucket != r.bucket) {
      return l.bucket < r.bucket;
    }
    return l.lr.second < r.lr.second;
  });

  vector<int> kinds(n + 1);
  int n_kinds = 0;
  auto add = [&](int i) {
    if (kinds[c[i]] == 0) {
      ++n_kinds;
    }
    ++kinds[c[i]];
  };
  auto del = [&](int i) {
    --kinds[c[i]];
    if (kinds[c[i]] == 0) {
      --n_kinds;
    }
  };
  rep(i, q) {
    auto [L, R] = qs[i].lr;
    if (i == 0 || qs[i].bucket != qs[i - 1].bucket) {
      n_kinds = 0;
      rep(i, n) kinds[i + 1] = 0;
      for (int j = L; j <= R; ++j) {
        add(j);
      }
    } else {
      auto [PL, PR] = qs[i - 1].lr;
      if (PL < L) {
        for (int j = PL; j < L; ++j) {
          del(j);
        }
      } else {
        for (int j = L; j < PL; ++j) {
          add(j);
        }
      }
      if (PR < R) {
        for (int j = R; j > PR; --j) {
          add(j);
        }
      } else {
        for (int j = PR; j > R; --j) {
          del(j);
        }
      }
    }
    qs[i].kinds = n_kinds;
  }
  sort(all(qs), [](const Q& l, const Q& r) { return l.i < r.i; });
  rep(i, q) { out(qs[i].kinds); }
}