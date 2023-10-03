#include "RDate.h"

#include <string>

//获取某月天数
int RDate::getMonthDay(int Year, int Month)
{
	static int monthDayArray[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (Month == 2 && isLeapYear(Year))
		return 29;
	return monthDayArray[Month];
}

bool RDate::before(const RDate& rDate)
{
	if (year < rDate.year ||
		year == rDate.year && month < rDate.month ||
		year == rDate.year && month == rDate.month && day < rDate.day)
		return true;
	return false;
}

bool RDate::after(const RDate& rDate)
{
	return !before(rDate) && !equal(rDate);
}

bool RDate::equal(const RDate& rDate)
{
	return year == rDate.year &&
		month == rDate.month &&
		day == rDate.day;
}

void RDate::setYear(int Year)
{
	if (Year < 0)
		return;
	this->year = Year;
}

void RDate::setMonth(int Month)
{
	if (Month < 1 || Month > 12)
		return;
	this->month = Month;
}

void RDate::setDay(int Day)
{
	if (Day < 0 || Day > getMonthDay(this->year, this->month))
		return;
	this->day = Day;
}

void RDate::yearAdd(int count)
{
	if (count < 0)
		return;
	this->year += count;
}

void RDate::dayAdd(int count)
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

void RDate::resetDate()
{
	this->year = 0;
	this->month = 1;
	this->day = 1;
}

std::string RDate::toString()
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
RDate::RDate(int Year, int Month, int Day)
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
bool RDate::operator<(const RDate& rDate) const //类外访问成员函数需要设定类域
{
	if (year < rDate.year ||
		year == rDate.year && month < rDate.month ||
		year == rDate.year && month == rDate.month && day < rDate.day)
		return true;
	return false;
}

// ==运算符重载
bool RDate::operator==(const RDate& rDate) const
{
	return year == rDate.year &&
		month == rDate.month &&
		day == rDate.day;
}

//日期 + 天数   d1 + 100  -->  d1.operator+(day)
RDate RDate::operator+(int Day) const
{
	//法二：复用日期 += 天数
	RDate ret(*this);
	ret += Day;
	return ret;
}

//日期 += 天数
RDate& RDate::operator+=(int Day)
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
RDate& RDate::operator-=(int Day)
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
RDate RDate::operator-(int Day) const
{
	RDate ret(*this);
	ret -= Day;
	return ret;
}

//前置++
RDate& RDate::operator++() //无参的为前置
{
	*this += 1; //直接复用+=
	return *this;
}

//后置++
RDate RDate::operator++(int i) //有参数的为后置
{
	RDate tmp(*this);
	*this += 1;
	return tmp;
}

//前置--
RDate& RDate::operator--() //无参的为前置
{
	*this -= 1; //直接复用+=
	return *this;
}

//后置--
RDate RDate::operator--(int i) //有参数的为后置
{
	RDate tmp(*this);
	*this -= 1;
	return tmp;
}

//日期 - 日期
int RDate::operator-(const RDate& d) const
{
	int flag = 1;
	RDate max = *this;
	RDate min = d;
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

std::ostream& operator<<(std::ostream& output, const RDate& rDate)
{
	if (rDate.year < 10)
		output << "000";
	if (rDate.year < 100)
		output << "00";
	if (rDate.year < 1000)
		output << "0";
	output << rDate.year << "-";
	if (rDate.month < 10)
		output << "0";
	output << rDate.month << "-";
	if (rDate.month < 10)
		output << "0";
	output << rDate.day;
	return output;
}
