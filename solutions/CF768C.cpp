// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1100;

int freq[N];

int main () {
  int n, k, x;
  scanf("%d %d %d", &n, &k, &x);
  vector < int > freq(N);
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    ++freq[x];
  }
  FOR(i, 0, k) {
    auto tmp = freq;
    int cnt = 0;
    FOR(j, 0, N) {
      if (freq[j]) {
        int curr = j ^ x;
        int change = freq[j] >> 1;
        if (cnt == 0) {
          change += freq[j] & 1;
        }
        tmp[j] -= change;
        tmp[curr] += change;
        cnt ^= freq[j] & 1;
      }
    }
    freq = tmp;
  }
  int mx = -1, mi = 2e9;
  FOR(i, 0, N) {
    if (freq[i]) {
      mx = max(i, mx);
      mi = min(i, mi);
    }
  }
  printf("%d %d\n", mx, mi);
  return 0;
}
