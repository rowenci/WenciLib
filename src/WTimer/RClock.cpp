//
// Created by Rowenci on 2023/6/2.
//

#include "WClock.h"

#include <string>

int WClock::secondAdd(int count)
{
	if (count < 0)
		return 0;
	int secondSum = this->second + count;
	int minutes = secondSum / 60;
	this->second = secondSum % 60;

	int minuteSum = this->minute + minutes;
	int hours = minuteSum / 60;
	this->minute = minuteSum % 60;

	int hoursSum = this->hour + hours;
	int days = hoursSum / 24;
	this->hour = hoursSum % 24;

	return days;
}

int WClock::minuteAdd(int count)
{
	if (count < 0)
		return 0;
	int minuteSum = this->minute + count;
	int hours = minuteSum / 60;
	this->minute = minuteSum % 60;

	int hoursSum = this->hour + hours;
	int days = hoursSum / 24;
	this->hour = hoursSum % 24;

	return days;
}

int WClock::hourAdd(int count)
{
	if (count < 0)
		return 0;
	int hoursSum = this->hour + count;
	int days = hoursSum / 24;
	this->hour = hoursSum % 24;

	return days;
}

int WClock::secondSub(int count)
{
	if (count < 0)
		return 0;
	this->second -= count;
	if (this->second < 0)
	{
		minuteSub(1);
		this->second += 60;
		return 1;
	}
	return 0;
}

int WClock::minuteSub(int count)
{
	if (count < 0)
		return 0;
	this->minute -= count;
	if (this->minute < 0)
	{
		hourSub(1);
		this->minute += 60;
		return 1;
	}
	return 0;
}

int WClock::hourSub(int count)
{
	if (count < 0)
		return 0;
	this->hour -= count;
	if (this->hour < 0)
	{
		this->hour += 24;
		return 1;
	}
	return 0;
}

int WClock::getSecond() const
{
	return this->second;
}

int WClock::getMinute() const
{
	return this->minute;
}

int WClock::getHour() const
{
	return this->hour;
}

bool WClock::before(const WClock& rClock) const
{
	// compare hour
	if (this->hour < rClock.hour)
		return true;
	if (this->hour > rClock.hour)
		return false;

	// compare minute
	if (this->minute < rClock.minute)
		return true;
	if (this->minute > rClock.minute)
		return false;

	// compare second
	if (this->second < rClock.second)
		return true;
	if (this->second > rClock.second)
		return false;
	return false;
}

bool WClock::after(const WClock& rClock) const
{
	return !before(rClock) && !equal(rClock);
}

bool WClock::equal(const WClock& rClock) const
{
	return this->hour == rClock.hour && this->minute == rClock.minute && this->second == rClock.second;
}

std::string WClock::toString() const
{
	std::string clockStr = "";
	if (this->hour < 10)
		clockStr.append("0");
	clockStr.append(std::to_string(this->hour));
	clockStr.append(":");

	if (this->minute < 10)
		clockStr.append("0");
	clockStr.append(std::to_string(this->minute));
	clockStr.append(":");

	if (this->second < 10)
		clockStr.append("0");
	clockStr.append(std::to_string(this->second));

	return clockStr;
}

void WClock::resetClock()
{
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

void WClock::setHour(int Hour)
{
	if (Hour < 0 || Hour > 23)
		return;
	Hour %= 24;
	this->hour = Hour;
}

void WClock::setMinute(int Minute)
{
	if (Minute < 0 || Minute > 59)
		return;
	Minute %= 60;
	this->minute = Minute;
}

void WClock::setSecond(int Second)
{
	if (Second < 0 || Second > 59)
		return;
	Second %= 60;
	this->second = Second;
}

bool WClock::operator<(const WClock& rClock) const
{
	return before(rClock);
}

bool WClock::operator>(const WClock& rClock) const
{
	return after(rClock);
}

bool WClock::operator==(const WClock& rClock) const
{
	return equal(rClock);
}

bool WClock::operator!=(const WClock& rClock) const
{
	return !equal(rClock);
}

std::ostream& operator<<(std::ostream& output, const WClock& rClock)
{
	if (rClock.hour < 10)
		output << "0";
	output << rClock.hour << ":";
	if (rClock.minute < 10)
		output << "0";
	output << rClock.minute << ":";
	if (rClock.second < 10)
		output << "0";
	output << rClock.second;
	return output;
}

WClock& WClock::operator=(const WClock& rClock)
{
	this->hour = rClock.hour;
	this->minute = rClock.minute;
	this->second = rClock.second;
	return *this;
}
