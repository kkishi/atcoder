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

template <typename T>
struct Edge {
  int from, to;
  T weight;
};

template <typename T>
class Graph {
 public:
  Graph(int n) : edges_(n) {}
  void AddEdge(int from, int to, T weight) {
    edges_[from].push_back({from, to, weight});
  }
  std::vector<Edge<T>>& Edges(int from) { return edges_[from]; }
  const std::vector<Edge<T>>& Edges(int from) const { return edges_[from]; }
  int NumVertices() const { return edges_.size(); }

 private:
  std::vector<std::vector<Edge<T>>> edges_;
};

template <typename T>
bool BellmanFord(const Graph<T>& graph, int start, std::vector<T>& dist) {
  std::size_t n = graph.NumVertices();

  dist.resize(n);
  T inf = std::numeric_limits<T>::max();
  fill(dist.begin(), dist.end(), inf);
  dist[start] = 0;

  for (std::size_t iter = 0; iter < n; ++iter) {
    for (std::size_t i = 0; i < n; ++i) {
      if (dist[i] == inf) continue;
      for (const Edge<T>& e : graph.Edges(i)) {
        if (T d = dist[i] + e.weight; dist[e.to] > d) {
          if (iter == n - 1) return false;
          dist[e.to] = d;
        }
      }
    }
  }
  return true;
}

int main() {
  in(ll, n, m, p);
  Graph<ll> g(n);
  Graph<ll> bg(n);
  rep(i, m) {
    in(int, a, b, c);
    --a, --b;
    g.AddEdge(a, b, p - c);
    bg.AddEdge(b, a, 0);
  }

  vector<ll> bgd;
  BellmanFord(bg, n - 1, bgd);
  rep(i, n) if (bgd[i] != 0) {
    g.Edges(i).clear();
  }

  vector<ll> d;
  if (BellmanFord(g, 0, d)) {
    out(max(-d[n - 1], 0LL));
  } else {
    out(-1);
  }
}
