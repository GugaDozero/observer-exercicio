#ifndef FEEDOBSERVER_H
#define FEEDOBSERVER_H

#include "iobserver.h"

#include <string>

class Subject;

class FeedObserver : public IObserver
{
public:
    FeedObserver();
    ~FeedObserver();

    virtual void update(Subject *subject, string feedName);

private:
    string m_state;
};

#endif // FEEDOBSERVER_H