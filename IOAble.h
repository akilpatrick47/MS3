#ifndef IOALBE_H__
#define IOABLE_H__

#include <iostream>

using namespace std;

namespace seneca
{
	class IOAble
	{
	public:
		//IOAble();
		virtual ~IOAble() = default;
		virtual ostream& write(ostream& ostr) const = 0;
		virtual istream& read(istream& istr) = 0;
	};
	ostream& operator<<(ostream& ostr, const IOAble& parent);
	istream& operator>>(istream& istr, IOAble& parent);

}

#endif // !IOALBE_H__
