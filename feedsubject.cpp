#include "feedsubject.h"

FeedSubject::FeedSubject() :
    m_subjectState("")
{
}

FeedSubject::~FeedSubject()
{
}

string FeedSubject::state() const
{
    return m_subjectState;
}

void FeedSubject::setState(const string &state, string feedName)
{
    m_subjectState = state;
    notify(feedName);
}