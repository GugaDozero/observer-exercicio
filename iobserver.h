#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

using std::string;

class Subject;

class IObserver
{
public:
    IObserver() {}
    virtual ~IObserver() {}

    virtual void update(Subject *subject, string feedName = "") = 0;
};

#endif // OBSERVER_H