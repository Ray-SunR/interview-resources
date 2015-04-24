//
//  subject.cpp
//  Observer Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>

#include "subject.h"
#include "observer.h"

using namespace std;

Subject::Subject(){}
Subject::~Subject(){}

void Subject::Attach(Observer* ob)
{
    vob.push_back(ob);
}

void Subject::Dettach(Observer* ob)
{
    for (int i = 0; i < vob.size(); i++)
    {
        if (vob[i] == ob)
        {
            vob.erase(vob.begin() + i);
            return;
        }
    }
}

void Subject::Notify()
{
    for (int i = 0; i < vob.size(); i++)
        vob[i]->Notify();
}