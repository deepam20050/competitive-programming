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

const int N = 1e5 + 5;

lli pref[N];
int arr[N];
map < lli, int > freq_pref, freq_suf;
int n;

void rekt () {
  puts("NO");
  exit(0);
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
    pref[i] = pref[i - 1] + arr[i];
  }
  if (pref[n] & 1ll) {
    rekt();
  }
  lli req = pref[n] >> 1ll;
  for (int i = n; i >= 1; --i) {
    ++freq_suf[arr[i]];
  }
  FOR(i, 1, n) {
    --freq_suf[arr[i]];
    ++freq_pref[arr[i]];
    if (pref[i] == req) {
      puts("YES");
      exit(0);
    }
    lli t = pref[i] + arr[i + 1] - req;
    if (freq_pref[t]) {
      puts("YES");
      exit(0);
    }
    t = req + arr[i] - pref[i];
    if (freq_suf[t]) {
      puts("YES");
      exit(0);
    }
  }
  puts("NO");
  return 0;
}
