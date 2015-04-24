//
//  csbook.cpp
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include "csbook.h"
#include "bookvisitor.h"

void CSBook::accept(BookVisitor& bv)
{
    bv.visit(*this);
}