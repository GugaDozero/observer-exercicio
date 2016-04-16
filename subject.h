#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <map>
#include <list>
#include <utility>
#include <string>

using namespace std;

class IObserver;

class Subject
{
public:
    Subject();
    virtual ~Subject();
    void attach(IObserver *observer, string feedName = "");
    void detach(IObserver *observer, string feedName = "");
    void notify(string feedName = "");

private:
    list<IObserver *> *m_observers;
    multimap<string, IObserver *> *m_feedCategories;
};

#endif // SUBJECT_H