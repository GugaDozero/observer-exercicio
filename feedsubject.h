#ifndef FEEDSUBJECT_H
#define FEEDSUBJECT_H

#include "subject.h"

class FeedSubject : public Subject
{
public:
    FeedSubject();
    ~FeedSubject();

    string state() const;
    void setState(const string &state, string feedName = "");

private:
   string m_subjectState;
};

#endif // FEEDSUBJECT_H