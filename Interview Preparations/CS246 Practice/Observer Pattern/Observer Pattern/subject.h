//
//  subject.h
//  Observer Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Observer_Pattern__subject__
#define __Observer_Pattern__subject__

#include <iostream>
#include <vector>

class Observer;

class Subject
{
protected:
    std::vector<Observer*> vob;
public:
    Subject();
    void Notify();
    void Attach(Observer* ob);
    void Dettach(Observer* ob);
    virtual ~Subject() = 0;
};
#endif /* defined(__Observer_Pattern__subject__) */
