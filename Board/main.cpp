/**
*File Name: proj3.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines 

*Assisted by and Assisted line numbers:
*Name: Kaveesha Siribaddana
*PSU user ID:  kps5662
*CMPSC465 Fall 2020
*Due Time: 11:59pm, Wednesday, October 7th, 2020
*Time of Last Modification: 11:00pm, Wednesday, October 7th, 2020
*Description: Replace all 'O's with 'X's if surrounded by 'X'
*/

#include<iostream> 
#include <fstream>
#include <vector>
using namespace std; 

void fill(vector<vector<char>&> m, int x, int y, char last, char next) 
{ 
	// Base cases 
	if (x < 0 || x >= m.size() || y < 0 || y >= m.size()) 
		return; 
	if (m[x][y] != last) 
		return; 
	
	m[x][y] = next; 
	 
	fill(size, m, x+1, y, last, next); 
	fill(size, m, x-1, y, last, next); 
	fill(size, m, x, y+1, last, next); 
	fill(size, m, x, y-1, last, next); 
} 
  
void replace(vector<vector<char>&> mtx) { 
 
  for (int i=0; i< mtx.size(); i++){
    for (int j=0; j<mtx.size(); j++) {
      if (mtx[i][j] == 'O') 
        mtx[i][j] = 'Z'; 
    }    
  }
   
  for (int i=0; i<mtx.size(); i++){
    if (mtx[i][0] == 'Z') {
      fill(mtx, i, 0, 'Z', 'O'); 
    }  
  }
  
  for (int i=0; i<mtx.size(); i++) {
    if (mtx[i][mtx.size()-1] == 'Z') 
      fill(mtx, i, mtx.size()-1, 'Z', 'O'); 
  }

  for (int i=0; i<mtx.size(); i++) {
    if (mtx[0][i] == 'Z') 
      fill(mtx, 0, i, 'Z', 'O'); 
  }
  for (int i=0; i<mtx.size(); i++) {
    if (mtx[mtx.size()-1][i] == 'Z') 
      fill(mtx, mtx.size()-1, i, 'Z', 'O'); 
  }
  
  for (int i=0; i<mtx.size(); i++) {
    for (int j=0; j<mtx.size(); j++) {
      if (mtx[i][j] == 'Z') 
        mtx[i][j] = 'X'; 
    }    
  }
} 

int main() { 
	ifstream f;
  f.open("input.txt");

  int size;
  f >> size;

  vector<vector<char>&> mx;
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      f >> mx[i][j];
    }  
  }

	replace(mx); 

	for (int i=0; i< mx.size(); i++) { 
    for (int j=0; j< mx.size(); j++) {
      cout << mx[i][j] << " "; 
    }
    cout << endl; 
	} 
	return 0; 
} 
