class StackEmpty ; 
class StackFull;
/*{
	private:
		int value;
	public:
		StackFull(int v):value(v) {}
		int getvalue()const { return value; }
};*/
/*class JuStack
{
	private:
		int * stk;
		int _cap,_cnt,_top;
	public:
		JuStack(int cap):stk(new int[cap]),_cap(cap),_top(0) {}
		int pop() throw(StackEmpty);
		void push(int value) throw(StackFull);
		bool IsEmpty() const { return _cnt==0; }
		bool IsFull() const { return _cnt == _cap; }
		int GetCapacity() const { return _cap; }
		int GetCount() const { return _cnt; }
		virtual ~JuStack() { delete []stk; stk == NULL; }
};*/
class JuStack;
