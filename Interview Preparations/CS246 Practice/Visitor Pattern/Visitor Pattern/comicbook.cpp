//
//  comicbook.cpp
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include "comicbook.h"
#include "bookvisitor.h"

void ComicBook::accept(BookVisitor& bv)
{
    bv.visit(*this);
}