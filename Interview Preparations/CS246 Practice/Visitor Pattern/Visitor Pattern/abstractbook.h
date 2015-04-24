//
//  abstractbook.h
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Visitor_Pattern__abstractbook__
#define __Visitor_Pattern__abstractbook__

#include <iostream>

class BookVisitor;

class AbstractBook
{
protected:
    std::string name, author;
    int numPages;
public:
    AbstractBook(std::string name, std::string author, int numPages):name(name), author(author), numPages(numPages){}
    virtual void accept(BookVisitor& bv) = 0;
    virtual ~AbstractBook() = 0;
};
#endif /* defined(__Visitor_Pattern__abstractbook__) */
