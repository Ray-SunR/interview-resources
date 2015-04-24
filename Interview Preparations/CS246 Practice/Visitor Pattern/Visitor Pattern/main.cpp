//
//  main.cpp
//  Visitor Pattern
//
//  Created by Sun Renchen on 2013-08-03.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include "comicbook.h"
#include "csbook.h"
#include "catalogue.h"
#include "abstractbook.h"

using namespace std;

int main(int argc, const char * argv[])
{
    vector<AbstractBook*> vbook;
    vbook.push_back(new ComicBook("ComicBook", "Renchen Sun", 23, "Ray"));
    vbook.push_back(new ComicBook("ComicBook1", "Renchen Sun", 25, "Ray"));
    vbook.push_back(new ComicBook("ComicBook2", "Renchen Sun", 30, "Ray1"));
    vbook.push_back(new ComicBook("ComicBook2", "Renchen Sun", 30, "Ray2"));
    vbook.push_back(new CSBook("CSBook1", "Yuchen Liu", 30, "C++"));
    vbook.push_back(new CSBook("CSBook2", "Yuchen Liu", 33, "Scheme"));
    vbook.push_back(new CSBook("CSBook3", "Yuchen Liu", 33, "C++"));
    vector<AbstractBook*>::iterator i;
    Catalogue* ctlg = new Catalogue();
    for (i = vbook.begin(); i != vbook.end(); i++)
        (*i)->accept(*ctlg);
    map<string, int> result = ctlg->getResult();
    for (map<string, int>::iterator i = result.begin(); i != result.end(); i++)
        cout << "First: " << i->first << " Second: " << i->second << endl;
    for (i = vbook.begin(); i != vbook.end(); i++)
        delete (*i);
    return 0;
}

