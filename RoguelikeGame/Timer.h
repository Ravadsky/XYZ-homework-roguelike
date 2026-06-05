#pragma once
namespace Arcanoid
{
	class Timer
	{
	private:
		float ElapsedTime = 0.f;

	protected:
		float TimerTime = 1.f;

	public:
		bool isCompleted = false;

		virtual void TimerCompleted() = 0;

		float getTimerTime();
		float getElapsedTime();
		void UpdateElapsedTime(float addedTime);

		bool isTimerFinished();
	};

}


