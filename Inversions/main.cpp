/**
*File Name: proj5.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines 

*Assisted by and Assisted line numbers:
*Name: Kaveesha Siribaddana
*PSU user ID:  kps5662
*CMPSC465 Fall 2020
*Due Time: 11:59pm, Wednesday, November 4th, 2020
*Time of Last Modification: 6:00pm, Wednesday, November 4th, 2020
*Description: Outputs the number of inversions in a sequence of numbers
*/

#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream> 
#include <fstream>
using namespace std;

#include <boost/algorithm/string.hpp> 

int merge(int arr[], int left, int mid, int right) {
  int i, j, k;
  int count = 0;
  int temp[right+1];
 
  i = k = left; 
  j = mid; 

  while ((i <= mid - 1) && (j <= right)) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      count = count + (mid - i);
    }
  }
 
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
  
  for (i = left; i <= right; i++)
    arr[i] = temp[i];
 
  return count;
}

int mergeSort(int arr[], int left, int right) {
  int mid, count = 0;
  if (right > left) {
    mid = (right + left) / 2;
    count += mergeSort(arr, left, mid);
    count += mergeSort(arr, mid + 1, right); 
    count += merge(arr, left, mid + 1, right);
  }
  return count;
}

int main() {

  string line;
  ifstream file;

  file.open("input.txt");

  getline(file, line);
  while(getline(file, line)){
    vector<string> temp; 
    // Used the vector 'temp' to make spliting values easy
    boost::split(temp, line, boost::is_any_of(" "));
    
    int seq[temp.size()];
    for(int x = 0; x < temp.size(); x++) // Loaded temp vector into array 'seq'      
      seq[x] = stoi(temp.at(x));

    int n = sizeof(seq) / sizeof(seq[0]);
	  cout << "The sequence has " << mergeSort(seq, 0, n-1) << " inversions." << endl;
  }	
	return 0;
}

