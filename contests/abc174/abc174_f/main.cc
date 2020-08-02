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

struct Query {
  int begin, end, index;
};

template <typename T>
class Mo {
 public:
  using F = std::function<void(int)>;
  using G = std::function<T()>;
  Mo(F add, F del, G get)
      : add_(add), del_(del), get_(get), index_(0), prev_(-1) {}
  std::pair<int, T> ProcessQuery() {
    if (prev_ == -1) {
      sort(queries_.begin(), queries_.end(),
           [](const Query& a, const Query& b) {
             int ba = sqrt(a.begin), bb = sqrt(b.begin);
             if (ba != bb) return ba < bb;
             return a.end < b.end;
           });
      prev_ = 0;
      const Query& q = queries_[0];
      Add(q.begin, q.end);
      return {q.index, get_()};
    }
    const Query& p = queries_[prev_];
    const Query& c = queries_[prev_ + 1];
    ++prev_;
    Add(c.begin, p.begin);
    Delete(p.begin, c.begin);
    Add(p.end, c.end);
    Delete(c.end, p.end);
    return {c.index, get_()};
  }
  void AddQuery(int begin, int end) {
    queries_.push_back({begin, end, index_++});
  }

 private:
  void Add(int begin, int end) {
    for (int i = begin; i < end; ++i) {
      add_(i);
    }
  }
  void Delete(int begin, int end) {
    for (int i = begin; i < end; ++i) {
      del_(i);
    }
  }
  const F add_, del_;
  const G get_;
  int index_, prev_;
  std::vector<Query> queries_;
};

using namespace std;

int main() {
  in(int, n, q);
  V<int> c(n);
  rep(i, n) cin >> c[i];

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
  auto get = [&]() { return n_kinds; };
  Mo<int> mo(add, del, get);
  rep(i, q) {
    in(int, l, r);
    mo.AddQuery(l - 1, r);
  }

  vector<int> ans(q);
  rep(i, q) {
    auto [idx, x] = mo.ProcessQuery();
    ans[idx] = x;
  }
  rep(i, q) out(ans[i]);
}