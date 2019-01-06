#include <iostream>
#include <cstring>

#include <secubuff.h>

using namespace std;

void test(char* key){
  secubuff<char,100> sb;

  for(size_t ii=0; ii<sb.size(); ++ii){
    sb[ii] = char(65+(rand()%25));
  }

  memcpy(key,sb.data(),sb.size());

  return;
}



int main()
{
  cout << "Hello World!" << endl;

  array<char,100> key;
  test(key.data());

  cout << string(key.data(),key.size()) << "\n";

  return 0;
}
