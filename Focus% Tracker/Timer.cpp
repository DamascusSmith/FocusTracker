#include <Windows.h>
#include <thread>

class timer {
public: 
	void stopWatch(int/*hours*/, int/*minutes*/, int /*seconds*/, bool/*running*/);
};

void timer::stopWatch(int h, int m, int s, bool running)
{
	Sleep(s * 1000);
}
