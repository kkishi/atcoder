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
  std::cout << value << '\n';
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

template <typename T, class DS>
class Mo {
 public:
  Mo(DS& ds) : ds_(ds), index_(0), prev_(-1) {}
  std::pair<int, T> ProcessQuery() {
    if (prev_ == -1) {
      int bin = sqrt(index_);
      sort(queries_.begin(), queries_.end(),
           [&bin](const Query& a, const Query& b) {
             int ba = a.begin / bin, bb = b.begin / bin;
             if (ba != bb) return ba < bb;
             if (ba % 2 == 0) {
               return a.end < b.end;
             }
             return a.end > b.end;
           });
      prev_ = 0;
      const Query& q = queries_[0];
      Add(q.begin, q.end);
      return {q.index, ds_.Get()};
    }
    const Query& p = queries_[prev_];
    const Query& c = queries_[prev_ + 1];
    ++prev_;
    Add(c.begin, p.begin);
    Del(p.begin, c.begin);
    Add(p.end, c.end);
    Del(c.end, p.end);
    return {c.index, ds_.Get()};
  }
  void AddQuery(int begin, int end) {
    queries_.push_back({begin, end, index_++});
  }

 private:
  struct Query {
    int begin, end, index;
  };
  void Add(int begin, int end) {
    for (int i = begin; i < end; ++i) {
      ds_.Add(i);
    }
  }
  void Del(int begin, int end) {
    for (int i = begin; i < end; ++i) {
      ds_.Del(i);
    }
  }
  DS& ds_;
  int index_, prev_;
  std::vector<Query> queries_;
};

using namespace std;

struct DS {
  DS(int n) : c(n), kinds(n), unique_kinds(0) {}
  void Add(int i) {
    if (kinds[c[i] - 1]++ == 0) {
      ++unique_kinds;
    }
  }
  void Del(int i) {
    if (--kinds[c[i] - 1] == 0) {
      --unique_kinds;
    }
  }
  int Get() const { return unique_kinds; }
  V<int> c;
  V<int> kinds;
  int unique_kinds;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  in(int, n, q);
  DS ds(n);
  rep(i, n) cin >> ds.c[i];

  Mo<int, DS> mo(ds);
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
