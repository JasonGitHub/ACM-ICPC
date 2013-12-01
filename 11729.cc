#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
  int b, j;
  bool operator>(const Job &that) const {
    return j > that.j;
  }
};

int Solve(vector<Job> &v) {
  sort(v.begin(), v.end(), greater<Job>());
  int start = 0;
  int end = 0;
  for (int i = 0; i < v.size(); ++i) {
    start += v[i].b;
    end = max(end, start + v[i].j);
  }
  return end;
}

int main() {
  int n, t = 1;
  while (cin >> n && n != 0) {
    vector<Job> v;
    for (int i = 0; i < n; ++i) {
      Job j;
      cin >> j.b >> j.j;
      v.push_back(j);
    }
    cout << "Case " << t << ": " << Solve(v) << endl;
    ++t;
  }
  return 0;
}
