#include <iostream>
#include <cstring>

#include <secubuff.h>

using namespace std;

void test(char* const key){
  char* ptr;
  {
    secubuff<char,100> sb;

    for(size_t ii=0; ii<sb.size(); ++ii){
      sb[ii] = char(65+(rand()%25));
    }

    ptr = sb.data();

    memcpy(key,sb.data(),sb.size());
  }

  cout << string(ptr,100) << "\n";
  return;
}


int main(){
  cout << "Hello Conquer MemSad!" << endl;

  array<char,100> key{}; //A buffer

  test(key.data());

  cout << string(key.data(),key.size()) << "\n";

  return 0;
}
