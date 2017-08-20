//
// Created by joep on 8/20/17.
//
#include "ContextOperation.h"


class wrong;




template <class T>
 bool ContextOperation<T> ::init() {
        T t;
        Context::registerOperation(t);
        return true;
    }

    template<class T>
    bool ContextOperation<T>::reg = ContextOperation<T>::init();

