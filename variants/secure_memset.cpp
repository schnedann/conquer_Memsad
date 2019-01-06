#include <cstring>
#include <cstdlib>

void memset_s(volatile char* target, char x, size_t len){
    for(int ii=0;ii<len;++ii){
        target[ii] = x;
    }
    return;
}
	
void test(char* key){
    volatile char k[100];
    for(int ii=0;ii<100;++ii){
        k[ii] = rand();
    }
    memcpy(key,const_cast<char const*>(k),100);
    memset_s(k,0,100);
    return;
}