// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int MAXN = 5e5 + 5;
const int N = 2e5 + 5;

int arr[N];
int cnt[MAXN];
int nq;
int n;
vector < int > primes[MAXN];
bitset < N > used;

void sieve () {
  FOR(i, 2, MAXN) if (primes[i].empty()) {
    for (int j = i; j < MAXN; j += i) primes[j].eb(i); 
  }
}

lli query (int i) {
  lli ret = 0;
  int m = sz(primes[arr[i]]);
  FOR(mask, 1, 1 << m) {
    int c = 0;
    int p = 1;
    FOR(j, 0, m) {
      if (mask >> j & 1) {
        p *= primes[arr[i]][j];
        ++c;
      }
    }
    ret += (c & 1 ? 1 : -1) * cnt[p];
  }
  return ret;
}

void update (int i, int add) {
  int m = sz(primes[arr[i]]);
  FOR(mask, 1, 1 << m) {
    int p = 1;
    FOR(j, 0, m) {
      if (mask >> j & 1) {
        p *= primes[arr[i]][j];
      }
    }
    cnt[p] += add;
  }
}

int main () {
  sieve();
  scanf("%d %d", &n, &nq);
  FOR(i, 0, n) scanf("%d", arr + i);
  int c = 0;
  lli non = 0;
  while (nq--) {
    int x;
    scanf("%d", &x);
    --x;
    lli rem = 0;
    if (used[x]) {
      --c;
      update(x, -1);
      rem = -query(x);
      used[x] = 0;
    } else {
      ++c;
      rem = query(x);
      update(x, 1);
      used[x] = 1;
    }
    lli total = c * 1ll * (c - 1) >> 1ll;
    non += rem;
    printf("%lld\n", total - non);
  }
  return 0;
}
