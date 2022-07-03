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

const int N = 1e6 + 5;
const int M = 3e5 + 5;

int t[N];

void add (int idx) {
  while (idx < N) {
    ++t[idx];
    idx += idx & -idx;
  }
}

int query (int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += t[idx];
    idx -= idx & -idx;
  }
  return ret;
}

vector < int > seg[N];
vector < pii > queries[N];
int ans[M];
int pos[M];

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 0; i < n; ++i) {
    int l, r; cin >> l >> r;
    seg[r].emplace_back(l);
  }
  for (int i = 0; i < nq; ++i) {
    int c; cin >> c;
    for (int j = 0; j < c; ++j) {
      cin >> pos[j];
    }
    queries[pos[0]].emplace_back(i, 0);
    queries[N - 1].emplace_back(i, pos[c - 1]);
    for (int j = 1; j < c; ++j) {
      queries[pos[j]].emplace_back(i, pos[j - 1]);
    }
  }
  for (int i = 1; i < N; ++i) {
    for (auto &[id, l] : queries[i]) {
      ans[id] -= query(i) - query(l);
    }
    for (auto &l : seg[i]) {
      add(l);
    }
  }
  for (int i = 0; i < nq; ++i) {
    cout << n + ans[i] << '\n';
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}