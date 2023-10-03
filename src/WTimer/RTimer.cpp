#include "WTimer.h"

void WTimer::secondAdd(int count)
{
	if (count < 0)
		return;
	int dayCount = this->rClock.secondAdd(count);
	rDate += dayCount;
}

void WTimer::minuteAdd(int count)
{
	if (count < 0)
		return;
	this->rClock.minuteAdd(count);
	int dayCount = this->rClock.hourAdd(count);
	rDate += dayCount;
}

void WTimer::hourAdd(int count)
{
	if (count < 0)
		return;
	int dayCount = this->rClock.hourAdd(count);
	rDate += dayCount;
}

void WTimer::dayAdd(int count)
{
	if (count < 0)
		return;
	++this->rDate;
}

void WTimer::secondSub(int count)
{
	this->rClock.secondSub(count);
}

void WTimer::minuteSub(int count)
{
	this->rClock.minuteSub(count);
}

void WTimer::hourSub(int count)
{
	this->rClock.hourSub(count);
}

void WTimer::daySub(int count)
{
	--this->rDate;
}

// rtimer 代表时间在后
bool WTimer::before(const WTimer& rTimer)
{
	if (rDate.before(rTimer.rDate))
		return true;
	if (rDate.equal(rTimer.rDate))
		return this->rClock.before(rTimer.rClock);
	return false;
}

// rtimer 代表时间在前
bool WTimer::after(const WTimer& rTimer)
{
	if (rDate.after(rTimer.rDate))
		return true;
	if (rDate.equal(rTimer.rDate))
		return this->rClock.after(rTimer.rClock);
	return false;
}

bool WTimer::equal(const WTimer& rTimer)
{
	return rDate.equal(rTimer.rDate) && rClock.equal(rTimer.rClock);
}

void WTimer::setSecond(int second)
{
	this->rClock.setSecond(second);
}

void WTimer::setMinute(int minute)
{
	this->rClock.setMinute(minute);
}

void WTimer::setHour(int hour)
{
	this->rClock.setHour(hour);
}

void WTimer::setDay(int day)
{
	this->rDate.setDay(day);
}

void WTimer::setMonth(int month)
{
	this->rDate.setMonth(month);
}

void WTimer::setYear(int year)
{
	this->rDate.setYear(year);
}

void WTimer::resetCalender(int year, int month, int day, int hour, int minute, int second)
{
	this->rClock.setHour(hour);
	this->rClock.setMinute(minute);
	this->rClock.setSecond(second);

	this->rDate.setYear(year);
	this->rDate.setMonth(month);
	this->rDate.setDay(day);
}

int WTimer::getSecond()
{
	return rClock.getSecond();
}

int WTimer::getMinute()
{
	return rClock.getMinute();
}

int WTimer::getHour()
{
	return rClock.getHour();
}

int WTimer::getDay()
{
	return rDate.day;
}

int WTimer::getMonth()
{
	return rDate.month;
}

int WTimer::getYear()
{
	return rDate.year;
}

void WTimer::resetTimer()
{
	this->rDate.resetDate();
	this->rClock.resetClock();
}

std::string WTimer::toString()
{
	std::string timerStr;
	timerStr.append(this->rDate.toString());
	timerStr.append(" ");
	timerStr.append(this->rClock.toString());
	return timerStr;
}

std::ostream& operator<<(std::ostream& output, const WTimer& rTimer)
{
	output << rTimer.rDate;
	output << " ";
	output << rTimer.rClock;
	return output;
}
