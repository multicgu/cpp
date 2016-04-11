#include<stdio.h>
#include<iostream>
using namespace std;
typedef Empty EventDelegator;
typedef void (EventDelegator::ValueChanged)(int value,void * tag);

class Trigger
{
	pubilc:
		Trigger():_value(0) {}
		void SetValue(int value,void * tag);
		int GetValue() {return _value;}
		Event<ValueChanged> value_changed;
	private:
		int _value;
};
void Trigger::SetValue(int value,void * tag)
{
	if(_value == value) return;
	_value = value;
	Event<ValueChanged>::EventResponsors ers = this->value_changed.GetResponsors();
	if(!ers.empty()) {
		Event<ValueChanged>::EventIterator it;
		for(it = ers.begin(); it != ers.end(); ++it) {
			((it->actor)->*(*(it->action)))(vallue,tag);
		}
	}
}

class Actor
{
	public:
		void Listen(Trigger * trigger)
		{ trigger->value_changed.bind(this,&Actor::OnValueChanged); }
		void Unlisten(Trigger * trigger)
		{ trigger->value_changed.unbind(this,&Actor::OnValueChanged); }
		void OnValueChanged(int value,void * tag)
		{ cout << reinterpret_cast<char *>(tag) << value << "." << endl; }
};

int main()
{
	const char * s = "Now the value is";
	Trigger t;
	Actor a1,a2;
	a1.Listen(&t);
	a2.Listen(&t);
	cout << "Listening..." << endl;
	t.SetValue(10,reinterpret_cast<void *>(const_cast(s)));

	a2.Unlisten(&t);
	cout << "Listening again..."<< endl;
	t.SetValue(20,reinterpret_cast<void *>(const_cast<char*>(s)));
	
	return 0;
}
