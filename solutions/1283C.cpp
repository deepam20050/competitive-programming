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

const int N = 2e5 + 5;

int a[N];
bool indeg[N], outdeg[N];

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i]) {
      outdeg[i] = 1;
      indeg[a[i]] = 1;
    }
  }
  vector < int > toget, togive;
  vector < int > single;
  for (int i = 1; i <= n; ++i) {
    if (!indeg[i] && !outdeg[i]) {
      single.emplace_back(i);
      continue;
    }
    if (!indeg[i]) {
      toget.emplace_back(i);
    }
    if (!outdeg[i]) {
      togive.emplace_back(i);
    }
  }
  if (sz(single) > 1) {
    for (int i = 0; i < sz(single); ++i) {
      a[single[i]] = single[(i + 1) % sz(single)];
    }
  } else if (sz(single) == 1) {
    a[single[0]] = toget.back(); toget.pop_back();
    a[togive.back()] = single[0]; togive.pop_back();
  }
  for (int i = 0; i < sz(toget); ++i) {
    a[togive[i]] = toget[i];
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " \n"[i == n];
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
