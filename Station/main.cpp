/**
*File Name: proj1.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines 

*Assisted by and Assisted line numbers:
*Name: Kaveesha Siribaddana
*PSU user ID:  kps5662
*CMPSC465 Fall 2020
*Due Time: 11:59pm, Wednesday, September 2, 2020
*Time of Last Modification: 2:30pm, Tuesday, September 1st, 2020
*Description: Determines whether you can marshal the coaches from track A to track B using the station
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  ifstream read; // input file
  ofstream write; // output file

  read.open("lab1in.txt"); // opens input file
  write.open("lab1out.txt"); // opens output file

  int n; // Number of coaches

  while(true){ // Loops until program terminates
    
    read >> n;

    if(n == 0){break;}

    int trA[n]; // Track A

    while (true){

      read >> trA[0];

      if (trA[0] == 0){break;} // Terminates block
      
      for(int x = 1; x < n; x++){read >> trA[x];} // Loads incoming train order 
      
      vector<int> trB; // Track B 
      stack<int> station; // stack represents the train station
      int front = 0;

      int y = 1;
      while (y <= n) {
        if (!station.empty() && (station.top() == trA[front])){
          trB.push_back(station.top());
          station.pop();
          front++;
        } else {
          station.push(y);
          y++;
        }
      }

      while(!station.empty()){ // Loads trains into Track B
        trB.push_back(station.top());
        station.pop();
      }

      bool order = true;

      for(int i = 0; i < n; i++){ // Checks if the order works
        if(trA[i] != trB[i]){
          order = false;
          break;
        }
      }

      if(order == true){
        write << "Yes\n";
      } else {
        write << "No\n";
      }

    }

    write << "\n";

  }
  
  read.close(); // close input file
  write.close(); // close output file
}