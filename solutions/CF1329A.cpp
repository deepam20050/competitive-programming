#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  FOR(i, 0, n) {
    scanf("%d", l + i);
    if (i + l[i] - 1 > n) {
      puts("-1");
      return 0;
    }
  }
  for (int i = n - 1; i >= 0; --i) suff[i] = suff[i + 1] + l[i];
  if (suff[i] < n) {
    puts("-1");
    return 0;
  }
  
  return 0;
}