#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
class Empty {};
template<typename EventAction>class EventResponsor
{
	public:
		Empty * actor;
		EventAction * action;
		EventResponsor():actor(NULL),action(NULL) {}
		EventResponsor(Empty * actor,EventAction * action):actor(actor),action(action) {}
		friend bool operator==(const EventResponsor & er1,const EventResponsor & er2)
		{	return er1.actor == er2.actor && *er1.action == *er2.action; }
};
template<typename EventAction>class Event
{
	public:
		typedef vector<EventResponsor<EventAction>> EventResponsors;
		typedef typename vector<EventResponsor<EventAction>>::iterator EventIterator;
		virtual ~Event() 
		{
			for(EventIterator it = _ers.begin();it != _ers.end();++it) {
				delete _ers->action; _ers->action = NULL; 
			}
		}
		EventResponsors & GetResponsors() { return _ers; }
		template<typename Responsor,typename Action>
		void bind(Responsor * actor,Action action)
		{
			EventAction * act = new Action(action);
			EventResponsor<EventAction> er((Empty*)actor,(EventAction *)act);
			for(EventIterator it=_ers.begin(); it != _ers.end(); ++it) {
				if(er == *it) {
					delete er.action; er.action = NULL;
					return;
				}
			}
			_ers.push_back(er);
		}
		template<typename Responsor,typename Action>
		void unbind(Responsor * actor,Action action)
		{
			EventAction * act = new Action(action);
			EventResponsor<EventAction> er((Empty*)actor,(EventAction*)act);
			for(EventIterator it=_ers.begin();it != _ers.end();++it) {
				if(*it == er) {
					delete it->action;
					_ers.erase(er);
				}
			}
			delete er.action; er.action = NULL;
		}
	private:
		EventResponsors _ers;
};
