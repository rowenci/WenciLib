﻿#pragma once

#include "RClock.h"
#include "RDate.h"

class RTimer
{
public:
	RTimer()
	{
	}

	RTimer(int Year, int Month, int Day, int Hour, int Minute, int Second)
	{
		this->rDate.setYear(Year);
		this->rDate.setMonth(Month);
		this->rDate.setDay(Day);

		this->rClock.setHour(Hour);
		this->rClock.setMinute(Minute);
		this->rClock.setSecond(Second);
	}

	RTimer(std::string fromTimeString, bool shortType)
	{
		if (!shortType)
		{
			int Year = std::stoi(fromTimeString.substr(0, 4));
			int Month = std::stoi(fromTimeString.substr(5, 2));
			int Day = std::stoi(fromTimeString.substr(8, 2));

			int Hour = std::stoi(fromTimeString.substr(11, 2));
			int Minute = std::stoi(fromTimeString.substr(14, 2));
			int Second = std::stoi(fromTimeString.substr(17, 2));

			this->rDate.setYear(Year);
			this->rDate.setMonth(Month);
			this->rDate.setDay(Day);

			this->rClock.setHour(Hour);
			this->rClock.setMinute(Minute);
			this->rClock.setSecond(Second);
		}
		else
		{
			int Hour = std::stoi(fromTimeString.substr(0, 2));
			int Minute = std::stoi(fromTimeString.substr(3, 2));
			this->rDate.setYear(0);
			this->rDate.setMonth(1);
			this->rDate.setDay(1);

			this->rClock.setHour(Hour);
			this->rClock.setMinute(Minute);
			this->rClock.setSecond(0);
		}
	}

	virtual ~RTimer()
	{
	}

	void secondAdd(int count);
	void minuteAdd(int count);
	void hourAdd(int count);
	void dayAdd(int count);

	void secondSub(int count);
	void minuteSub(int count);
	void hourSub(int count);
	void daySub(int count);

	bool before(const RTimer& rTimer);
	bool after(const RTimer& rTimer);
	bool equal(const RTimer& rTimer);

	void setSecond(int second);
	void setMinute(int minute);
	void setHour(int hour);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void resetCalender(int year, int month, int day, int hour, int minute, int second);

	int getSecond();
	int getMinute();
	int getHour();
	int getDay();
	int getMonth();
	int getYear();

	void resetTimer();

	std::string toString();

	friend std::ostream& operator<<(std::ostream& output, const RTimer& rTimer);

	std::string toTimeString()
	{
		std::string str;
		std::string hour;
		if (rClock.getHour() < 10)
		{
			str.append("0");
		}
		str.append(std::to_string(rClock.getHour()));
		if (rClock.getMinute() < 10)
		{
			str.append("0");
		}
		str.append(std::to_string(rClock.getMinute()));
		return str;
	}

	RClock rClock;
	RDate rDate;
};