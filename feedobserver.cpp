#include "feedobserver.h"

#include "subject.h"
#include "feedsubject.h"

#include <iostream>

using std::cout;
using std::endl;

FeedObserver::FeedObserver() :
    m_state()
{

}

FeedObserver::~FeedObserver()
{
}

void FeedObserver::update(Subject *subject, string feedName = "")
{
    FeedSubject *observable = dynamic_cast<FeedSubject *>(subject);

    cout << subject << " " << this << " " << observable->state() << " " << feedName << endl;
    m_state = observable->state();
}