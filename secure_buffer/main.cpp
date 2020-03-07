#include <iostream>
#include <cstring>

#include <secubuff.h>

using namespace std;

void test(char* const key){
  char* ptr;
  {
    //Create Secure Buffer
    secubuff<char,100> sb;
    //Fill Buffer with random Data
    for(size_t ii=0; ii<sb.size(); ++ii){
      sb[ii] = char(65+(rand()%25));
    }

    //Get Pointer to Data
    ptr = sb.data();

    //Get Key from Secure Buffer
    memcpy(key,sb.data(),sb.size());

    sb.overwrite();
  }
  //Secure Buffer already has overwritten its data, but also it would do it right now as scope is left

  cout << "Memory from Secure Buffer: " << string(ptr,100) << "\n";
  return;
}

int main(){
  cout << "Hello Conquer MemSad!" << endl;

  array<char,100> key{}; //A buffer

  test(key.data());

  cout << "Key from Secure Buffer   : "<< string(key.data(),key.size()) << "\n";

  return 0;
}
