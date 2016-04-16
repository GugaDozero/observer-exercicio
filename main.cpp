#include "subject.h"
#include "feedobserver.h"
#include "feedsubject.h"
#include "iobserver.h"

#include <iostream>

int main()
{
    FeedSubject *s1 = new FeedSubject;
    FeedSubject *s2 = new FeedSubject;

    IObserver *o1 = new FeedObserver;
    IObserver *o2 = new FeedObserver;
    IObserver *o3 = new FeedObserver;
    IObserver *o4 = new FeedObserver;

    s1->attach(o1, "esportes");
    s1->attach(o2, "esportes");

    s2->attach(o1, "esportes");
    s2->attach(o2, "esportes");
    s2->attach(o2, "musica");
    s2->attach(o3);
    s2->attach(o4);

    s1->setState("2", "esportes");
    s2->setState("3","musica");
    s2->setState("99");

	return 0;
}
