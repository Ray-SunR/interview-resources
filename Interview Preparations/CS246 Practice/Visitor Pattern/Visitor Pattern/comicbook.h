//
//  comicbook.h
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#ifndef __Visitor_Pattern__comicbook__
#define __Visitor_Pattern__comicbook__

#include <iostream>
#include "abstractbook.h"

class ComicBook: public AbstractBook
{
    std::string hero;
public:
    ComicBook(std::string name, std::string author, int numPages, std::string hero):AbstractBook(name, author, numPages), hero(hero){}
    std::string getHero() const {return hero;}
    void accept(BookVisitor& bv);
    ~ComicBook(){}
};
#endif /* defined(__Visitor_Pattern__comicbook__) */
