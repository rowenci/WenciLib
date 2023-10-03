#include "RTimer.h"

void RTimer::secondAdd(int count)
{
	if (count < 0)
		return;
	int dayCount = this->rClock.secondAdd(count);
	rDate += dayCount;
}

void RTimer::minuteAdd(int count)
{
	if (count < 0)
		return;
	this->rClock.minuteAdd(count);
	int dayCount = this->rClock.hourAdd(count);
	rDate += dayCount;
}

void RTimer::hourAdd(int count)
{
	if (count < 0)
		return;
	int dayCount = this->rClock.hourAdd(count);
	rDate += dayCount;
}

void RTimer::dayAdd(int count)
{
	if (count < 0)
		return;
	++this->rDate;
}

void RTimer::secondSub(int count)
{
	this->rClock.secondSub(count);
}

void RTimer::minuteSub(int count)
{
	this->rClock.minuteSub(count);
}

void RTimer::hourSub(int count)
{
	this->rClock.hourSub(count);
}

void RTimer::daySub(int count)
{
	--this->rDate;
}

// rtimer 代表时间在后
bool RTimer::before(const RTimer& rTimer)
{
	if (rDate.before(rTimer.rDate))
		return true;
	if (rDate.equal(rTimer.rDate))
		return this->rClock.before(rTimer.rClock);
	return false;
}

// rtimer 代表时间在前
bool RTimer::after(const RTimer& rTimer)
{
	if (rDate.after(rTimer.rDate))
		return true;
	if (rDate.equal(rTimer.rDate))
		return this->rClock.after(rTimer.rClock);
	return false;
}

bool RTimer::equal(const RTimer& rTimer)
{
	return rDate.equal(rTimer.rDate) && rClock.equal(rTimer.rClock);
}

void RTimer::setSecond(int second)
{
	this->rClock.setSecond(second);
}

void RTimer::setMinute(int minute)
{
	this->rClock.setMinute(minute);
}

void RTimer::setHour(int hour)
{
	this->rClock.setHour(hour);
}

void RTimer::setDay(int day)
{
	this->rDate.setDay(day);
}

void RTimer::setMonth(int month)
{
	this->rDate.setMonth(month);
}

void RTimer::setYear(int year)
{
	this->rDate.setYear(year);
}

void RTimer::resetCalender(int year, int month, int day, int hour, int minute, int second)
{
	this->rClock.setHour(hour);
	this->rClock.setMinute(minute);
	this->rClock.setSecond(second);

	this->rDate.setYear(year);
	this->rDate.setMonth(month);
	this->rDate.setDay(day);
}

int RTimer::getSecond()
{
	return rClock.getSecond();
}

int RTimer::getMinute()
{
	return rClock.getMinute();
}

int RTimer::getHour()
{
	return rClock.getHour();
}

int RTimer::getDay()
{
	return rDate.day;
}

int RTimer::getMonth()
{
	return rDate.month;
}

int RTimer::getYear()
{
	return rDate.year;
}

void RTimer::resetTimer()
{
	this->rDate.resetDate();
	this->rClock.resetClock();
}

std::string RTimer::toString()
{
	std::string timerStr;
	timerStr.append(this->rDate.toString());
	timerStr.append(" ");
	timerStr.append(this->rClock.toString());
	return timerStr;
}

std::ostream& operator<<(std::ostream& output, const RTimer& rTimer)
{
	output << rTimer.rDate;
	output << " ";
	output << rTimer.rClock;
	return output;
}
