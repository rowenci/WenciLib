#pragma once

#include "iostream"

class WDate {
public:
	//构造函数
	WDate(int Year = 1, int Month = 1, int Day = 1);
	
	bool isLeapYear(int Year) {
		//四年一润百年不润或四百年一润
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	
	//获取某月天数
	int getMonthDay(int year, int month);
	
	//打印
	void print() const {
		std::cout << year << "-" << month << "-" << day << std::endl;
	}
	
	bool before(const WDate& rDate);
	bool after(const WDate& rDate);
	bool equal(const WDate& rDate);
	
	void setYear(int Year);
	void setMonth(int Month);
	void setDay(int Day);
	
	void yearAdd(int count);
	void dayAdd(int count);
	
	void resetDate();
	
	std::string toString();
	
	// <运算符重载
	bool operator<(const WDate& rDate) const;
	// ==运算符重载
	bool operator==(const WDate& rDate) const;
	// <=运算符重载
	bool operator<=(const WDate& rDate) const {
		return *this < rDate || *this == rDate;
	}
	
	// >运算符重载
	bool operator>(const WDate& rDate) const {
		return !(*this <= rDate);
	}
	
	// >=运算符重载
	bool operator>=(const WDate& rDate) const {
		return !(*this < rDate);
	}
	
	// !=运算符重载
	bool operator!=(const WDate& rDate) const {
		return !(*this == rDate);
	}
	
	//日期 + 天数
	WDate operator+(int Day) const;
	//日期 += 天数
	WDate& operator+=(int Day);
	//日期 -= 天数
	WDate& operator-=(int Day);
	//日期 - 天数
	WDate operator-(int Day) const;
	//前置++
	WDate& operator++(); //无参的为前置
	//后置++
	WDate operator++(int i); //有参数的为后置
	//前置--
	WDate& operator--(); //无参的为前置
	//后置--
	WDate operator--(int i); //有参数的为后置
	//日期 - 日期
	int operator-(const WDate& d) const;
	friend std::ostream& operator<<(std::ostream& output, const WDate& rDate);

private:
	int year;
	int month; // 1 <= month <= 12
	int day; // 1 <= day <= 31
};