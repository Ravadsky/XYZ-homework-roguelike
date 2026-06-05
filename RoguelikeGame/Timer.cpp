#include "Timer.h"


float Arcanoid::Timer::getTimerTime()
{
	return TimerTime;
}

float Arcanoid::Timer::getElapsedTime()
{
	return ElapsedTime;
}
void Arcanoid::Timer::UpdateElapsedTime(float addedTime)
{
	ElapsedTime += addedTime;
}

bool Arcanoid::Timer::isTimerFinished()
{
	return ElapsedTime >= TimerTime;
}
