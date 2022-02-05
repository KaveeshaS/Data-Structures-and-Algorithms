/**
*File Name: proj6.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines 

*Assisted by and Assisted line numbers:
*Name: Kaveesha Siribaddana
*PSU user ID:  kps5662
*CMPSC465 Fall 2020
*Due Time: 11:59pm, Wednesday, November 11th, 2020
*Time of Last Modification: 6:10pm, Wednesday, November 11th, 2020
*Description: Outputs the size of the largest square containing all 1's in a given matrix
*/

#include <iostream>
#include <fstream>
using namespace std;

int min(int a, int b){
  if(a < b) 
    return a;
  else
    return b;
}

int main() {

  int **mx= NULL;
  int **dp = NULL;

  int x, y;

  ifstream file;
  file.open("input.txt");

  while(file >> x){
    if(x == 0) 
      break;
    
    file >> y;
   
    mx = new int*[x];
    dp = new int*[x];

    for(int i = 0; i < x; i++){
      mx[i] = new int[y];
      dp[i] = new int[y];
      for(int j = 0; j < y; j++)
        file >> mx[i][j];
   }

    int max = 0;

    for(int i = 0; i < x; i++) {
      for(int j = 0; j < y; j++) {
        if(i==0 || j==0){
          dp[i][j] = mx[i][j];
        } else{
          if(mx[i][j] == 1) 
            dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1])) + 1;
          else
            dp[i][j] = 0;
        }
          if(dp[i][j] > max) 
            max = dp[i][j];
      }
    }

    cout << max * max << endl;

    for(int i = 0; i< x; i++) {
      delete mx[i];
      delete dp[i];
    }
  
    delete mx;
    delete dp;
  }
  file.close();
  return 0;
}