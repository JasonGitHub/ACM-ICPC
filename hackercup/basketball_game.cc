#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <iterator>

using namespace std;

struct Player {
  string name;
  int pct;
  int height;
  bool operator<(const Player &p) const {return pct != p.pct ? pct < p.pct : height < p.height;}
  bool operator>(const Player &p) const {return p < *this;}
};

// initialized the p players on field
void Init(deque<Player> &on, queue<Player> &off, int p) {
  for (int i = 0; i < p; ++i) {
    Player tmp = off.front();
    off.pop();
    on.push_front(tmp);  // arrange elements in reverse order, so that player with higher draft number pop out first
  }
}

// rotate the players
void Rotate(deque<Player> &on, queue<Player> &off, int m) {
  for (int i = 0; i < m; ++i) {
    Player tmp = on.front();  // player out
    on.pop_front();
    off.push(tmp);
    tmp = off.front();  // player in
    off.pop();
    on.push_back(tmp);
  }
}

vector<Player> Solve(vector<Player> &players, int n, int m, int p) {
  vector<Player> ret;
  deque<Player> t1on, t2on;
  queue<Player> t1off, t2off;
  sort(players.begin(), players.end(), greater<Player>());

  for (int i = 0; i < players.size(); ++i) {
    if (i % 2 == 0) t1off.push(players[i]);
    else t2off.push(players[i]);
  }

  Init(t1on, t1off, p);
  Init(t2on, t2off, p);
  Rotate(t1on, t1off, m);
  Rotate(t2on, t2off, m);

  copy(t1on.begin(), t1on.end(), back_inserter(ret));
  copy(t2on.begin(), t2on.end(), back_inserter(ret));
  sort(ret.begin(), ret.end(), [](Player a, Player b){return a.name < b.name;});
  return ret;
}

int main() {
  int t, n, m, p;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> m >> p;
    vector<Player> players;
    for (int j = 0; j < n; ++j) {
      Player player;
      cin >> player.name >> player.pct >> player.height;
      players.push_back(player);
    }
    vector<Player> ret = Solve(players, n, m, p);
    cout << "Case #" << i + 1 << ": ";
    for (auto &item : ret) cout << item.name << " ";
    cout << endl;
  }
  return 0;
}
