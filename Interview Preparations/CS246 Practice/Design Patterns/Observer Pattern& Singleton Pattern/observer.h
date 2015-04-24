//
//  observer.h
//  
//
//  Created by Sun Renchen on 2013-08-06.
//
//

#ifndef ____observer__
#define ____observer__

#include <iostream>

class Observer
{
public:
    virtual ~Observer();
    virtual void Notify() = 0;
};

#endif /* defined(____observer__) */
