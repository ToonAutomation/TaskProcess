
class TaskProcess
{
public:
		typedef void(*callback)(void);
		void init(unsigned long interval_ms,callback function);		
virtual	        bool Run();
		bool Enable(bool State) { RunState = State; return RunState; };
		void SetInterval(unsigned long interval) { Tinterval = interval; };
		unsigned long GetInterval() { return Tinterval; };
	    
private:
		
		unsigned long TStart, Tinterval;		
		callback  jobprocess;
		bool RunState = false;
};
