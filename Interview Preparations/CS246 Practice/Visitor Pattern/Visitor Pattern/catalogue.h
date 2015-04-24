//
//  catalogue.h
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Visitor_Pattern__catalogue__
#define __Visitor_Pattern__catalogue__

#include <iostream>
#include <map>

#include "bookvisitor.h"

class ComicBook;
class CSBook;

class Catalogue:public BookVisitor
{
    std::map<std::string, int> counter;
public:
    Catalogue(){}
    std::map<std::string, int> getResult() const {return counter;}
    void visit(ComicBook& cb);
    void visit(CSBook& csb);
    ~Catalogue(){}
};
#endif /* defined(__Visitor_Pattern__catalogue__) */
