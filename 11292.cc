#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, m;
  int A[20005], B[20005];
  while (cin >> n >> m && n && m) {
    int curr = 0, cost = 0;
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < m; ++i) cin >> B[i];
    sort(A, A + n); 
    sort(B, B + m); 
    for (int i = 0; i < m; ++i) {
      if (B[i] >= A[curr]) {
        cost += B[i];
        if (++curr == n) break;
      }   
    }   
    if (curr < n) cout << "Loowater is doomed!" << endl;
    else cout << cost << endl;
  }
  return 0;
}
