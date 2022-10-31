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

const int N = 3e6 + 5;

int sp[N];
bitset < N > vis_prime;
int x_prime[N];
int freq[N];

// Credits : https://codeforces.com/blog/entry/7262
inline void sieve () {
  for (int i = 2; i < N; i += 2) { 
    sp[i] = 2;
    if (i == 2) continue;
    vis_prime[i] = 1;
  }
  for (int i = 3; i < N; i += 2) 
    if (!vis_prime[i]) {
      sp[i] = i;
      for (int j = i; j * 1ll * i < 1ll * N; j += 2) {
        if (!vis_prime[j * i]) vis_prime[j * i] = 1, sp[j * i] = i;
      }
    }
  int which = 0;
  FOR(i, 2, N) {
    if (!vis_prime[i]) {
      x_prime[i] = ++which;
    }
  }
}

int main () {
  sieve();
  int n;
  scanf("%d", &n);
  n += n;
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    ++freq[x];
  }
  vector < int > ans;
  for (int i = N - 1; i > 0; --i) {
    while (freq[i]) {
      if (sp[i] == i) {
        int who = x_prime[i];
        ans.eb(who);
        --freq[who];
      } else {
        int req = i / sp[i];
        ans.eb(i);
        --freq[req];
      }
      --freq[i];
    }
  }
  for (auto &e : ans) printf("%d ", e);
  return 0;
}
