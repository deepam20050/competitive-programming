#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

template < class T > using min_heap = priority_queue < T, vector < T >, greater < T > >;
template < class T > using max_heap = priority_queue < T >;

void test_case() {
  int nq; cin >> nq;
  min_heap < int > pq;
  queue < int > q;
  while (nq--) {
    int op; cin >> op;
    if (op == 1) {
      int x; cin >> x;
      q.emplace(x);
    } else if (op == 2) {
      if (pq.empty()) {
        cout << q.front() << '\n';
        q.pop();
      } else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    } else {
      while (!q.empty()) {
        pq.emplace(q.front());
        q.pop();
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}