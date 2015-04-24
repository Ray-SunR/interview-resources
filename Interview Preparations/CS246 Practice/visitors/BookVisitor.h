#ifndef __BOOKVISITOR_H__
#define __BOOKVISITOR_H__

#include "book.h"
#include "csbook.h"
#include "comicbook.h"


class BookVisitor {
  public:
    virtual void visit(Book &b) = 0;
    virtual void visit(CSBook &csb) = 0;
    virtual void visit(ComicBook &cb) = 0;
    virtual ~BookVisitor();
};

#endif
