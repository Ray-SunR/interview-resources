//
//  observer.h
//  Observer Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Observer_Pattern__observer__
#define __Observer_Pattern__observer__

#include <iostream>

class Observer
{
public:
    virtual ~Observer();
    virtual void Notify() = 0;
};
#endif /* defined(__Observer_Pattern__observer__) */
