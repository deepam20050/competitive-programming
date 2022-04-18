#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const lli LIMIT = 1e13;
const int N = 3e6;

int idx;
lli v[N];

void gen (lli x) {
  if (x > LIMIT) return;
  if (x > 0) {
    v[idx++] = x;
  }
  gen(x * 10ll + 1);
  gen(x * 10ll + 2);
  gen(x * 10ll + 3);
}

inline int solve (lli x) {
  int d = 0;
  int c[] = {0, 0, 0};
  while (x > 0) {
    ++c[x % 10 - 1];
    x /= 10;
    ++d;
  }
  int ans = 0;
  FOR(i, 0, 3) {
    FOR(j, i + 1, 3) {
      ans += abs(c[i] - c[j]);
    }
  }
  return ans + d;
}

int main () {
  gen(0);
  sort(v, v + idx);
  lli n;
  scanf("%lld", &n);
  lli ans_val = -1;
  int score = 2e9;
  FOR(i, 0, idx) {
    lli e = v[i];
    if (e >= n) {
      auto x = solve(e);
      if (x < score) {
        ans_val = e;
        score = x;
      }
    }
  }
  printf("%lld\n", ans_val);
  return 0;
}
