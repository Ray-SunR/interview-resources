//
//  stackexception.h
//  mstack
//
//  Created by Sun Renchen on 2013-10-07.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __mstack__stackexception__
#define __mstack__stackexception__

#include <iostream>

class StackException
{
private:
    std::string name;
public:
    StackException(std::string name):name(name){}
    void What() { std::cout << name << std::endl;}
};
#endif /* defined(__mstack__stackexception__) */
