// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int MAXP = 1e5 + 5;

int sp[MAXP];
bitset < MAXP > vis_prime;

// Credits : https://codeforces.com/blog/entry/7262
inline void sieve () {
  for (int i = 3; i < MAXP; i += 2) 
    if (!vis_prime[i]) {
      sp[i] = i;
      for (int j = i; j * 1ll * i < 1ll * MAXP; j += 2) {
        if (!vis_prime[j * i]) vis_prime[j * i] = 1, sp[j * i] = i;
      }
    }
}

inline bool check_prime (int x) {
	for (int i = 2; 1ll * i * i <= x; ++i) {
		if (x % i == 0) return 0;
	}
	return 1;
}

int main () {
	sieve();
  int n;
	scanf("%d", &n);
	bool ok = 1;
	if (check_prime(n)) {
		printf("1\n%d\n", n);
		return 0;
	}
	n -= 3;
	vector < int > v;
	v.eb(3);
	FOR(i, 2, MAXP) {
		if (!vis_prime[i] && check_prime(n - i)) {
			v.eb(i);
			if (n != i) v.eb(n - i);
			break;
		}
	}
	printf("%d\n", sz(v));
	for (auto &p : v) printf("%d ", p);
	return 0;
}
