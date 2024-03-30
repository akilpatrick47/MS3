#ifndef TIME_H__
#define TIME_H__
#include <iostream>

using namespace std;

namespace seneca
{
	class Time
	{
	public:
		Time(unsigned int min = 0u); //what is the 'u' for
		virtual ~Time() {};

		Time& reset();

		ostream& write(ostream& ostr = cout) const;
		istream& read(istream& istr = cin);
		//operator unsigned int()const;
		//operator int() const;
		Time& operator*= (int val);
		Time& operator-= (const Time& D);
		Time operator-(const Time& T) const;


	private:
		int minutes;
	};
	//ostream& operator<<(ostream& ostr, Time& t);
	ostream& operator<<(ostream& ostr, Time t);
	istream& operator>>(istream& istr, Time& t);
}

#endif // !TIME_H__
