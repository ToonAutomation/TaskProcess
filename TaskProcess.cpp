#include "TaskProcess.h"

#define Arduino

#ifdef Arduino
#define TimeCurrent millis()
#endif // 

#ifdef Windows
#include "Windows.h"
#define TimeCurrent millis()

WORD millis()
{
	SYSTEMTIME t;
	GetSystemTime(&t);
	return (t.wSecond * 1000) + t.wMilliseconds;
}

#endif // Windows




void TaskProcess::init(unsigned long interval_ms,callback function)
{
	
	jobprocess = function;
	Tinterval = interval_ms;
	TStart = TimeCurrent + Tinterval;
	RunState = true;
}

bool TaskProcess::Run()
{
	unsigned long TCurrent = TimeCurrent;
	if ((TCurrent >= TStart)&&(RunState))
	{
		jobprocess();
		TStart = TCurrent + Tinterval;
		return true;
	}
	return false;
}




