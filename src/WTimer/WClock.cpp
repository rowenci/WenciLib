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

bool WClock::before(const WClock& wClock) const
{
	// compare hour
	if (this->hour < wClock.hour)
		return true;
	if (this->hour > wClock.hour)
		return false;

	// compare minute
	if (this->minute < wClock.minute)
		return true;
	if (this->minute > wClock.minute)
		return false;

	// compare second
	if (this->second < wClock.second)
		return true;
	if (this->second > wClock.second)
		return false;
	return false;
}

bool WClock::after(const WClock& wClock) const
{
	return !before(wClock) && !equal(wClock);
}

bool WClock::equal(const WClock& wClock) const
{
	return this->hour == wClock.hour && this->minute == wClock.minute && this->second == wClock.second;
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

bool WClock::operator<(const WClock& wClock) const
{
	return before(wClock);
}

bool WClock::operator>(const WClock& wClock) const
{
	return after(wClock);
}

bool WClock::operator==(const WClock& wClock) const
{
	return equal(wClock);
}

bool WClock::operator!=(const WClock& wClock) const
{
	return !equal(wClock);
}

std::ostream& operator<<(std::ostream& output, const WClock& wClock)
{
	/*if (wClock.hour < 10)
		output << "0";
	output << wClock.hour << ":";
	if (wClock.minute < 10)
		output << "0";
	output << wClock.minute << ":";
	if (wClock.second < 10)
		output << "0";
	output << wClock.second;*/
	return output;
}

WClock& WClock::operator=(const WClock& wClock)
{
	this->hour = wClock.hour;
	this->minute = wClock.minute;
	this->second = wClock.second;
	return *this;
}
