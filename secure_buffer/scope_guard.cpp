#include <utility>

#include "scope_guard.h"

using namespace Core::Runtime;

void Scope_Guard::exec(){
  if(callbk && !triggered){
    triggered=true;
    callbk();
  }
  return;
}

Scope_Guard::Scope_Guard(std::function<void()> _cb):triggered(false),callbk(std::move(_cb)){
  return;
}

Scope_Guard::~Scope_Guard(){
  exec();
  return;
}

void Scope_Guard::trigger(){
  exec();
  return;
}
