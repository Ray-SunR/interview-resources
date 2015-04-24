//
//  catalogue.cpp
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//
#include "catalogue.h"
#include "comicbook.h"
#include "csbook.h"

void Catalogue::visit(ComicBook& cb)
{
    counter[cb.getHero()]++;
}

void Catalogue::visit(CSBook &csb)
{
    counter[csb.getLanguage()]++;
}