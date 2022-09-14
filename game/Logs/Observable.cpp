#include "Observable.h"


void Observable::setObserver(SetLogger *ob) {
    this->obs = ob;
}

void Observable::notify(const std::string& str, Entity* obj){
    obs->update(str, obj);
}