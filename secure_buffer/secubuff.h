#ifndef SECUBUFF_H
#define SECUBUFF_H

#include <cstdint>
#include <array>

#include "scope_guard.h"

template<typename T, size_t N> class secubuff
{
private:
  volatile T buff[N];
  Core::Runtime::Scope_Guard sg;
public:
  //Utilizing the Scopeguard guarantees execution even if code is disrupted by e.g. an exception
  secubuff():sg([this](){
    for(size_t ii=0; ii<N; ++ii){
      this->buff[ii]='0';
    }
  }){};

  ~secubuff()=default;

  T volatile& operator[](std::size_t idx){
    return buff[idx%N];
  }
  const T& operator[](std::size_t idx) const{
    return buff[idx%N];
  }

  T* data(){
    return const_cast<T*>(buff);
  }

  size_t size(){
    return N;
  }
};

#endif // SECUBUFF_H
