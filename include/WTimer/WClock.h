#pragma once

#include <string>

class WClock {
public:
	WClock() = default;
	
	WClock(int Hour, int Minute, int Second) : hour(Hour), minute(Minute), second(Second) {
	}
	
	int getSecond() const;
	int getMinute() const;
	int getHour() const;
	
	void setHour(int Hour);
	void setMinute(int Minute);
	void setSecond(int Second);
	
	int secondAdd(int count);
	int minuteAdd(int count);
	int hourAdd(int count);
	
	int secondSub(int count);
	int minuteSub(int count);
	int hourSub(int count);
	
	bool before(const WClock& wClock) const;
	bool after(const WClock& wClock) const;
	bool equal(const WClock& wClock) const;
	
	std::string toString() const;
	
	void resetClock();
	
	bool operator<(const WClock& wClock) const;
	bool operator>(const WClock& wClock) const;
	bool operator==(const WClock& wClock) const;
	bool operator!=(const WClock& wClock) const;
	friend std::ostream& operator<<(std::ostream& output, const WClock& wClock);
	WClock& operator=(const WClock& wClock);

private:
	int hour = 0; // 时 0 ~ 23
	int minute = 0; // 分 0 ~ 59
	int second = 0; // 秒 0 ~ 59
};