#include "IOAble.h"

using namespace seneca;

//ostream& operator<<(ostream& ostr, IOAble* parent)
//{
//	return ostr;
//}

ostream& seneca::operator<<(ostream& ostr, const IOAble& parent)
{
	parent.write(ostr);
	return ostr;
}

istream& seneca::operator>>(istream& istr, IOAble& parent)
{
	parent.read(istr);
	return istr;
}

//ostream& operator<<(ostream& ostr, IOAble* parent)
//{
//	// TODO: insert return statement here
//}
