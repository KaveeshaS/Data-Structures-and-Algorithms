/**
*File Name: proj2.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines 

*Assisted by and Assisted line numbers:
*Name: Kaveesha Siribaddana
*PSU user ID:  kps5662
*CMPSC465 Fall 2020
*Due Time: 11:59pm, Wednesday, September 23, 2020
*Time of Last Modification: 8:00pm, Tuesday, September 22st, 2020
*Description: Generates all combinations of n pairs of parantheses
*/

#include<iostream>
#include<vector>
using namespace std;


void combination(vector<string> &combo, string temp, int left, int right) {

  if( left == 0 && right == 0) {
    combo.push_back(temp);
    return;
  }

  if(left > 0) 
    combination(combo, temp + "(", left -1, right +1); 
  
  if(right > 0)  
    combination(combo, temp + ")", left, right - 1);   
}

vector<string> generate(int n) {
  vector<string> str;

  combination(str, "", n, 0);    
  return str;
}

int main() {
    
  vector<string> sol;

  int n;
  cin >> n;

  sol = generate(n);

  for (int x = 0; x < sol.size(); x++){
    cout << sol[x] << endl;
  }  

}

/* Outputs

2
(())
()()

3
((()))
(()())
(())()
()(())
()()()

4
(((())))
((()()))
((())())
((()))()
(()(()))
(()()())
(()())()
(())(())
(())()()
()((()))
()(()())
()(())()
()()(())
()()()()
*/