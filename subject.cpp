#include <algorithm>

#include "subject.h"
#include "iobserver.h"

Subject::Subject() :
    m_observers(new list<IObserver *>),
    m_feedCategories(new multimap<string, IObserver *>)
{

}

Subject::~Subject()
{
    delete m_observers;
    delete m_feedCategories;
}

void Subject::attach(IObserver *observer, string feedName)
{
    if(!feedName.empty())
        m_feedCategories->insert(make_pair(feedName, observer));
    else
		m_observers->push_back(observer);

}

void Subject::detach(IObserver *observer, string feedName)
{
	if(m_feedCategories->find(feedName) != m_feedCategories->end())
	{
		typedef multimap<string, IObserver *>::iterator iterator;
		std::pair<iterator, iterator> iterpair = m_feedCategories->equal_range(feedName);

		iterator it = iterpair.first;
		for (; it != iterpair.second; ++it)
		{
			if (it->second == observer)
			{ 
				m_feedCategories->erase(it);
				break;
			}
		}
	}
	else
	{
		auto iter = std::find(m_observers->begin(), m_observers->end(), observer);
		m_observers->erase(iter);
	}

    
}

void Subject::notify(string feedName)
{
    if(!feedName.empty())
    {
        auto iter = m_feedCategories->find(feedName);
		while (iter != m_feedCategories->end() && iter->first == feedName)
        {
			iter++->second->update(this, feedName);
        }
	}
    
	std::for_each(m_observers->begin(), m_observers->end(), [&] (IObserver *observer)
	{
		observer->update(this, feedName);
	});
}