//
//  csbook.h
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Visitor_Pattern__csbook__
#define __Visitor_Pattern__csbook__

#include <iostream>
#include "abstractbook.h"

class CSBook: public AbstractBook
{
    std::string language;
public:
    CSBook(std::string name, std::string author, int numPages, std::string language):AbstractBook(name, author, numPages), language(language){}
    std::string getLanguage() const {return language;}
    void accept(BookVisitor& bv);
    ~CSBook(){}
};
#endif /* defined(__Visitor_Pattern__csbook__) */
