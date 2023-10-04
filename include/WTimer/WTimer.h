#pragma once

#include "WClock.h"
#include "WDate.h"

class WTimer {
public:
	WTimer() {
	}
	
	WTimer(int Year, int Month, int Day, int Hour, int Minute, int Second) {
		this->wDate.setYear(Year);
		this->wDate.setMonth(Month);
		this->wDate.setDay(Day);
		
		this->wClock.setHour(Hour);
		this->wClock.setMinute(Minute);
		this->wClock.setSecond(Second);
	}
	
	WTimer(std::string fromTimeString, bool shortType) {
		if (!shortType) {
			int Year = std::stoi(fromTimeString.substr(0, 4));
			int Month = std::stoi(fromTimeString.substr(5, 2));
			int Day = std::stoi(fromTimeString.substr(8, 2));
			
			int Hour = std::stoi(fromTimeString.substr(11, 2));
			int Minute = std::stoi(fromTimeString.substr(14, 2));
			int Second = std::stoi(fromTimeString.substr(17, 2));
			
			this->wDate.setYear(Year);
			this->wDate.setMonth(Month);
			this->wDate.setDay(Day);
			
			this->wClock.setHour(Hour);
			this->wClock.setMinute(Minute);
			this->wClock.setSecond(Second);
		} else {
			int Hour = std::stoi(fromTimeString.substr(0, 2));
			int Minute = std::stoi(fromTimeString.substr(3, 2));
			this->wDate.setYear(0);
			this->wDate.setMonth(1);
			this->wDate.setDay(1);
			
			this->wClock.setHour(Hour);
			this->wClock.setMinute(Minute);
			this->wClock.setSecond(0);
		}
	}
	
	virtual ~WTimer() {
	}
	
	void secondAdd(int count);
	void minuteAdd(int count);
	void hourAdd(int count);
	void dayAdd(int count);
	
	void secondSub(int count);
	void minuteSub(int count);
	void hourSub(int count);
	void daySub(int count);
	
	bool before(const WTimer& wTimer);
	bool after(const WTimer& wTimer);
	bool equal(const WTimer& wTimer);
	
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
	
	friend std::ostream& operator<<(std::ostream& output, const WTimer& wTimer);
	
	std::string toTimeString() {
		std::string str;
		std::string hour;
		if (wClock.getHour() < 10) {
			str.append("0");
		}
		str.append(std::to_string(wClock.getHour()));
		if (wClock.getMinute() < 10) {
			str.append("0");
		}
		str.append(std::to_string(wClock.getMinute()));
		return str;
	}

private:
	WClock wClock;
	WDate wDate;
};
