
#include "Time.h"
#include "Utils.h"

namespace seneca
{
	Time::Time(unsigned int min)
	{
		minutes = min;
	}

	Time& Time::reset()
	{
		minutes = U.getTime();
		return *this;
	}

	ostream& Time::write(ostream& ostr) const
	{
		int hour = minutes / 60;
		int min = minutes % 60;
		ostr.width(2);
		ostr.fill('0');
		ostr << hour << ":";
		ostr.width(2);
		ostr << min;
		ostr.fill(' ');
		return ostr;
	}

	istream& Time::read(istream& istr)
	{
		int hours = 0, min = 0;
		char c;
		istr >> hours;
		c = istr.peek();
		if (c == ':')
		{
			istr >> c; //or c = istr.get();
			istr >> min;
			minutes = hours * 60 + min;
		}
		else
		{
			minutes = 0;
			istr.setstate(ios::failbit);
		}

		return istr;
	}

	//Time::operator unsigned int() const
	//{
	//	return minutes;
	//}
	//Time::operator int() const
	//{
	//	return minutes;
	//}

	Time& Time::operator*=(int val)
	{
		minutes *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		minutes = minutes - D.minutes;//unsigned int(D); //or minutes - D.minutes;
		//what about the difference between 1pm and 3pm it would be 2 hours, but by the algorithm provided it would be 22 hours.
		if (minutes < 0)
			minutes += 1440;
		return *this;
	}

	Time Time::operator-(const Time& T) const
	{
		Time temp;
		temp.minutes = minutes - T.minutes;
		if (temp.minutes < 0)
		{
			temp.minutes += 1440;
		}
		return temp;
	}


	/*ostream& operator<<(ostream& ostr, Time& t)
	{
		t.write(ostr);
		return ostr;
	}*/

	ostream& operator<<(ostream& ostr, Time t)
	{
		t.write(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Time& t)
	{
		t.read(istr);
		return istr;
	}

}