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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  lli a = 2, b = 2;
  set < lli > s = {1};
  queue < lli > q;
  q.emplace(1);
  for (int i = 0; i < 100; ++i) {
    auto x = q.front();
    q.pop();
    if (s.find(x * a) == s.end()) {
      s.emplace(x * a);
      q.emplace(x * a);
    }
    if (s.find(x + b) == s.end()) {
      s.emplace(x + b);
      q.emplace(x + b);
    }
  }
  debug(s);
  return 0;
}