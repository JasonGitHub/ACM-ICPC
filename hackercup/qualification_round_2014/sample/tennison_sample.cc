#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

const double eps = 1e-11;

#define MAXK 105

bool lt(double a, double b) { return a + eps < b; }
bool gt(double a, double b) { return lt(b, a); }
bool eq(double a, double b) { return !lt(a, b) && !gt(a, b); }
bool lte(double a, double b) { return lt(a, b) || eq(a, b); }
bool gte(double a, double b) { return gt(a, b) || eq(a, b); }

int T, K;
double ps, pr, pi, pu, pw, pd, pl;
double p[2][3][MAXK][MAXK][MAXK];

double fcps(int q, int u, int d) {
  double cpi = (q == 2) ? pi : q;
  return min(1.0, max(0.0, cpi + u * pu - d * pd));
}

int fq(int q, int u, int d) {
  double cps = fcps(q, u, d);
  if (lte(cps, 0.0)) return 0;
  if (gte(cps, 1.0)) return 1;
  return q;
}

int fu(int q, int u, int d) {
  double cps = fcps(q, u, d);
  if (lte(cps, 0.0) || gte(cps, 1.0)) return 0;
  return u;
}

int fd(int q, int u, int d) {
  double cps = fcps(q, u, d);
  if (lte(cps, 0.0) || gte(cps, 1.0)) return 0;
  return d;
}

int main(void) {
  scanf("%d", &T);

  for (int tc = 1; tc <= T; ++tc) {
    scanf("%d%lf%lf%lf%lf%lf%lf%lf", &K, &ps, &pr, &pi, &pu, &pw, &pd, &pl);

    for (int sets = 0; sets <= 2 * K - 1; ++sets) {
      int S = (sets & 1);
      for (int q = 0; q <= 2; ++q) {
        for (int won = 0; won <= K; ++won) {
          for (int u = 0; u <= K; ++u) {
            for (int d = 0; d <= K; ++d) {
              int ewon = 2 * K - 1 - sets - won;
              if (ewon < 0 || ewon >= K || u > won || d > ewon) {
                p[S][q][won][u][d] = 0.0;
                continue;
              }
              if (won >= K) {
                p[S][q][won][u][d] = 1.0;
                continue;
              }

              double pW = pw * p[S ^ 1][fq(q, u + 1, d)][won + 1][fu(q, u + 1, d)][fd(q, u + 1, d)] 
                + (1.0 - pw) * p[S ^ 1][q][won + 1][u][d];

              double pL = pl * p[S ^ 1][fq(q, u, d + 1)][won][fu(q, u, d + 1)][fd(q, u, d + 1)]
                + (1.0 - pl) * p[S ^ 1][q][won][u][d];

              double cps = fcps(q, u, d);
              p[S][q][won][u][d] = cps * (ps * pW + (1.0 - ps) * pL) + (1.0 - cps) * (pr * pW + (1.0 - pr) * pL);
            }
          }
        }
      }
    }

    printf("Case #%d: %.6lf\n", tc, p[1][2][0][0][0]);
  }

  return 0;
}
