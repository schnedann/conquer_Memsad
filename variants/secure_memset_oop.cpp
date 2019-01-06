#include <iostream>
#include <cstring>

#include <cstdint>
#include <array>

using namespace std;

template<typename T, size_t N> class secubuff
{
private:
    volatile T buff[N];
public:
    secubuff()=default;

    T volatile& operator[](std::size_t idx){
            return buff[idx];
    }
    const T& operator[](std::size_t idx) const{
            return buff[idx];
    }

    ~secubuff(){
        for(size_t ii=0; ii<N; ++ii){
            buff[ii]=0;
        }
    }

    T* data(){
        return const_cast<T*>(buff);
    }

    size_t size(){
        return N;
    }
};

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