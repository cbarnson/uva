#include <bits/stdc++.h>
using namespace std;



int main() {


  while (cin.peek() != '#') {
    char arr[50];
    int count = 0;

    char c;
    while (cin.get(c) && c != '\n') {
      arr[count] = c;
      count++;      
    }
    
    if (next_permutation(arr, arr+count)) {
      string str(arr, arr+count);
      cout << str << endl;
    } else {
      cout << "No Successor" << endl;
    }

    
    // string presort(arr, arr+count);    
    // sort(arr, arr+count, greater<char>());
    // string postsort(arr, arr+count);

    // if (presort == postsort) {
    //   cout << "No Successor" << endl;
    // } else {
    //   cout << 
    // }
    
    // string str(arr, arr+count);
    // cout << "string is: " << str << endl;

    
    

  }
  
  


  return 0;
}
