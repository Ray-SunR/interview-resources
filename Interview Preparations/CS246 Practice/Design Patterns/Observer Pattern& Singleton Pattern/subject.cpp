
#include "subject.h"
#include "observer.h"

void Subject::Attach(Observer* ob)
{
    vob.push_back(ob);
}

void Subject::Detach(Observer* ob)
{
    for (int i = 0; i < vob.size(); i++)
    {
        if (vob[i] == ob)
        {
            vob.erase(vob.begin() + i);
            return;
        }
    }
}

void Subject::NotifyAll()
{
    for (int i = 0; i < vob.size(); i++)
        vob[i]->Notify();
}

Subject::~Subject() {}
