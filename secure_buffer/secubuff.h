#ifndef SECUBUFF_H
#define SECUBUFF_H

#include <cstdint>
#include <array>

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

#endif // SECUBUFF_H
