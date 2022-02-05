/**
*File Name: proj4.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines 

*Assisted by and Assisted line numbers:
*Name: Kaveesha Siribaddana
*PSU user ID:  kps5662
*CMPSC465 Fall 2020
*Due Time: 11:59pm, Wednesday, October 21st, 2020
*Time of Last Modification: 9:00pm, Wednesday, October 21st, 2020
*Description: Determine the shortest route a knight has to take to get from x to y
*/

#include <bits/stdc++.h>
using namespace std;

struct cell {
  int x, y;
  int d;

  cell() {}
  cell(int x, int y, int d) : x(x), y(y), d(d) {}
};

bool valid(int x, int y) {
  if (x >= 1 && x <= 8 && y >= 1 && y <= 8)
    return true;
  else
    return false;
}

int steps(int knightPos[], int targetPos[]) {

  int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
  int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

  queue<cell> q;
  q.push(cell(knightPos[0], knightPos[1], 0));

  cell t;
  int x, y;
  bool visit[9][9];

  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      visit[i][j] = false;

  visit[knightPos[0]][knightPos[1]] = true;

  while (!q.empty()) {

    t = q.front();
    q.pop();

    visit[t.x][t.y] = true;

    if (t.x == targetPos[0] && t.y == targetPos[1])
      return t.d;
  
    for (int i = 0; i < 8; i++) {

      x = t.x + dx[i];
      y = t.y + dy[i];

      if (valid(x, y) && !visit[x][y])
        q.push(cell(x, y, t.d + 1));
    }
  }
}

int main(){

  ifstream obj("input.txt");
  string line;

  int x1,y1,x2,y2;

  while(getline(obj,line)){

    x1=line[0]-'a'+1;
    y1=line[1]-'0';

    x2=line[3]-'a'+1;
    y2=line[4]-'0';

    int knightPos[] = {x1,y1};
    int targetPos[] = {x2,y2};

    cout <<"To get from "<< line[0] << line[1] <<" to "<< line[3] << line[4] <<
            " takes "<< steps(knightPos, targetPos)<<" knight moves."<<endl;

  }
  return 0;
}