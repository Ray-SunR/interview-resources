#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class Subject
{
protected:
    std::vector<Observer*> vob;
public:
    void Attach(Observer* ob);
    void Detach(Observer* ob);
    void NotifyAll();
    virtual ~Subject() = 0;
};

#endif