//
//  bookvisitor.h
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Visitor_Pattern__bookvisitor__
#define __Visitor_Pattern__bookvisitor__

#include <iostream>

class ComicBook;
class CSBook;

class BookVisitor
{
public:
    virtual void visit(ComicBook& cb) = 0;
    virtual void visit(CSBook& csb) = 0;
    virtual ~BookVisitor(){}
};
#endif /* defined(__Visitor_Pattern__bookvisitor__) */
