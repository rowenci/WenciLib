﻿#include "WDate.h"

#include <string>

//获取某月天数
int WDate::getMonthDay(int Year, int Month)
{
	static int monthDayArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (Month == 2 && isLeapYear(Year))
		return 29;
	return monthDayArray[Month];
}

bool WDate::before(const WDate& wDate)
{
	if (year < wDate.year ||
		year == wDate.year && month < wDate.month ||
		year == wDate.year && month == wDate.month && day < wDate.day)
		return true;
	return false;
}

bool WDate::after(const WDate& wDate)
{
	return !before(wDate) && !equal(wDate);
}

bool WDate::equal(const WDate& wDate)
{
	return year == wDate.year &&
		month == wDate.month &&
		day == wDate.day;
}

void WDate::setYear(int Year)
{
	if (Year < 0)
		return;
	this->year = Year;
}

void WDate::setMonth(int Month)
{
	if (Month < 1 || Month > 12)
		return;
	this->month = Month;
}

void WDate::setDay(int Day)
{
	if (Day < 0 || Day > getMonthDay(this->year, this->month))
		return;
	this->day = Day;
}

void WDate::yearAdd(int count)
{
	if (count < 0)
		return;
	this->year += count;
}

void WDate::dayAdd(int count)
{
	if (count < 0)
		return;
	day += count;
	while (day > getMonthDay(year, month))
	{
		day -= getMonthDay(year, month);
		month++;
		if (month == 13)
		{
			year++;
			month = 1;
		}
	}
}

void WDate::resetDate()
{
	this->year = 0;
	this->month = 1;
	this->day = 1;
}

std::string WDate::toString()
{
	std::string dateStr;
	if (this->year < 10)
		dateStr.append("000");
	else if (this->year < 100)
		dateStr.append("00");
	else if (this->year < 1000)
		dateStr.append("0");
	dateStr.append(std::to_string(year));
	dateStr.append("-");
	if (this->month < 10)
		dateStr.append("0");
	dateStr.append(std::to_string(month));
	dateStr.append("-");
	if (this->day < 10)
		dateStr.append("0");
	dateStr.append(std::to_string(day));
	return dateStr;
}

//构造函数
WDate::WDate(int Year, int Month, int Day)
{
	if (Year >= 1 && Month <= 12 && Month >= 1 && Day <= getMonthDay(Year, Month))
	{
		year = Year;
		month = Month;
		day = Day;
	}
	else
		std::cout << "日期非法" << std::endl;
}

// <运算符重载
bool WDate::operator<(const WDate& wDate) const //类外访问成员函数需要设定类域
{
	if (year < wDate.year ||
		year == wDate.year && month < wDate.month ||
		year == wDate.year && month == wDate.month && day < wDate.day)
		return true;
	return false;
}

// ==运算符重载
bool WDate::operator==(const WDate& wDate) const
{
	return year == wDate.year &&
		month == wDate.month &&
		day == wDate.day;
}

//日期 + 天数   d1 + 100  -->  d1.operator+(day)
WDate WDate::operator+(int Day) const
{
	//法二：复用日期 += 天数
	WDate ret(*this);
	ret += Day;
	return ret;
}

//日期 += 天数
WDate& WDate::operator+=(int Day)
{
	//法一：
	//如果day小于0，要单独处理
	if (Day < 0)
	{
		return *this -= -Day;
	}
	day += Day;
	while (day > getMonthDay(year, month))
	{
		day -= getMonthDay(year, month);
		month++;
		if (month == 13)
		{
			year++;
			month = 1;
		}
	}
	return *this;
}

//日期 -=天数  d1-=100
WDate& WDate::operator-=(int Day)
{
	//如果减去的天数是负数，要单独处理，直接调用+=
	if (Day < 0)
	{
		return *this += -Day;
	}
	day -= Day;
	while (day <= 0)
	{
		--month;
		if (month == 0)
		{
			month = 12;
			--year;
		}
		day += getMonthDay(year, month);
	}
	return *this;
}

//日期 - 天数
WDate WDate::operator-(int Day) const
{
	WDate ret(*this);
	ret -= Day;
	return ret;
}

//前置++
WDate& WDate::operator++() //无参的为前置
{
	*this += 1; //直接复用+=
	return *this;
}

//后置++
WDate WDate::operator++(int i) //有参数的为后置
{
	WDate tmp(*this);
	*this += 1;
	return tmp;
}

//前置--
WDate& WDate::operator--() //无参的为前置
{
	*this -= 1; //直接复用+=
	return *this;
}

//后置--
WDate WDate::operator--(int i) //有参数的为后置
{
	WDate tmp(*this);
	*this -= 1;
	return tmp;
}

//日期 - 日期
int WDate::operator-(const WDate& d) const
{
	int flag = 1;
	WDate max = *this;
	WDate min = d;
	if (*this < d)
	{
		min = *this;
		max = d;
		flag = -1;
	} //确保max是大的，min是小的
	int n = 0;
	while (min != max)
	{
		min++;
		n++;
	} //算出min和max之间绝对值差距
	return n * flag; //如果d1大，结果为正，d2大结果为负
}

std::ostream& operator<<(std::ostream& output, const WDate& wDate)
{
	if (wDate.year < 10)
		output << "000";
	if (wDate.year < 100)
		output << "00";
	if (wDate.year < 1000)
		output << "0";
	output << wDate.year << "-";
	if (wDate.month < 10)
		output << "0";
	output << wDate.month << "-";
	if (wDate.month < 10)
		output << "0";
	output << wDate.day;
	return output;
}
int WDate::getYear() const {
	return this->year;
}
int WDate::getMonth() const {
	return this->month;
}
int WDate::getDay() const {
	return this->day;
}
