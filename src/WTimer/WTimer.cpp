#include "WTimer.h"

void WTimer::secondAdd(int count)
{
	if (count < 0)
		return;
	int dayCount = this->wClock.secondAdd(count);
	wDate += dayCount;
}

void WTimer::minuteAdd(int count)
{
	if (count < 0)
		return;
	this->wClock.minuteAdd(count);
	int dayCount = this->wClock.hourAdd(count);
	wDate += dayCount;
}

void WTimer::hourAdd(int count)
{
	if (count < 0)
		return;
	int dayCount = this->wClock.hourAdd(count);
	wDate += dayCount;
}

void WTimer::dayAdd(int count)
{
	if (count < 0)
		return;
	++this->wDate;
}

void WTimer::secondSub(int count)
{
	this->wClock.secondSub(count);
}

void WTimer::minuteSub(int count)
{
	this->wClock.minuteSub(count);
}

void WTimer::hourSub(int count)
{
	this->wClock.hourSub(count);
}

void WTimer::daySub(int count)
{
	--this->wDate;
}

// rtimer 代表时间在后
bool WTimer::before(const WTimer& wTimer)
{
	if (wDate.before(wTimer.wDate))
		return true;
	if (wDate.equal(wTimer.wDate))
		return this->wClock.before(wTimer.wClock);
	return false;
}

// rtimer 代表时间在前
bool WTimer::after(const WTimer& wTimer)
{
	if (wDate.after(wTimer.wDate))
		return true;
	if (wDate.equal(wTimer.wDate))
		return this->wClock.after(wTimer.wClock);
	return false;
}

bool WTimer::equal(const WTimer& wTimer)
{
	return wDate.equal(wTimer.wDate) && wClock.equal(wTimer.wClock);
}

void WTimer::setSecond(int second)
{
	this->wClock.setSecond(second);
}

void WTimer::setMinute(int minute)
{
	this->wClock.setMinute(minute);
}

void WTimer::setHour(int hour)
{
	this->wClock.setHour(hour);
}

void WTimer::setDay(int day)
{
	this->wDate.setDay(day);
}

void WTimer::setMonth(int month)
{
	this->wDate.setMonth(month);
}

void WTimer::setYear(int year)
{
	this->wDate.setYear(year);
}

void WTimer::resetCalender(int year, int month, int day, int hour, int minute, int second)
{
	this->wClock.setHour(hour);
	this->wClock.setMinute(minute);
	this->wClock.setSecond(second);

	this->wDate.setYear(year);
	this->wDate.setMonth(month);
	this->wDate.setDay(day);
}

int WTimer::getSecond()
{
	return wClock.getSecond();
}

int WTimer::getMinute()
{
	return wClock.getMinute();
}

int WTimer::getHour()
{
	return wClock.getHour();
}

int WTimer::getDay()
{
	return wDate.getDay();
}

int WTimer::getMonth()
{
	return wDate.getMonth();
}

int WTimer::getYear()
{
	return wDate.getYear();
}

void WTimer::resetTimer()
{
	this->wDate.resetDate();
	this->wClock.resetClock();
}

std::string WTimer::toString()
{
	std::string timerStr;
	timerStr.append(this->wDate.toString());
	timerStr.append(" ");
	timerStr.append(this->wClock.toString());
	return timerStr;
}

std::ostream& operator<<(std::ostream& output, const WTimer& wTimer)
{
	output << wTimer.wDate;
	output << " ";
	output << wTimer.wClock;
	return output;
}
