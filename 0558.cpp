//include
//------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n)  FOR(i,0,n)

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const int INF = -1;

typedef pair<int, int> P;
const int MAX_H = 1001;
const int MAX_W = 1001;

char maze[MAX_H][MAX_W];
int h,w;
int sx, sy;
int gx, gy;
int d[MAX_H][MAX_W];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int bfs() {
  queue<P> que;
  REP(i,h) {
    REP(j,w) {
      d[i][j] = INF;
    }
  }
  que.push(P(sx,sy));
  d[sx][sy] = 0;

  while (que.size()) {
    P p = que.front();
    que.pop();
    if(p.first == gx && p.second == gy) break;
    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i];
      int ny = p.second + dy[i];

      if(0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF) {
        que.push(P(nx,ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);



  return 0;
}
