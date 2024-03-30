#define _CRT_SECURE_NO_WARNINGS
#include "Patient.h"
#include <cstring>

using namespace seneca;

Patient::Patient(int ticketNum) : m_ticket(ticketNum)
{
	m_OHIPnum = 0;
	//Ticket temp(ticketNum);
	//m_ticket = temp;

}

Patient::Patient(Patient& RS) : m_ticket(RS.m_ticket)
{
	m_OHIPnum = RS.m_OHIPnum;
	delete[] m_name;
	m_name = new char[strlen(RS.m_name) + 1];
	strcpy(m_name, RS.m_name);
}

Patient& Patient::operator=(Patient& RS)
{
	if (this != &RS)
	{
		m_OHIPnum = RS.m_OHIPnum;
		delete[] m_name;
		m_name = new char[strlen(RS.m_name) + 1];
		strcpy(m_name, RS.m_name);
		m_ticket = RS.m_ticket;
	}
	return *this;
}

Patient::~Patient()
{
	delete[] m_name;
	m_name = nullptr;
}

bool Patient::operator==(char Otype) const
{
	return (this->type() == Otype);
}

bool Patient::operator==(const Patient& p2) const
{
	return (this->type() == p2.type());
}

void Patient::setArrivalTime()
{
	m_ticket.resetTime();
}

Time Patient::time() const
{
	return m_ticket.time();
}

int Patient::number() const
{
	return m_ticket.number();
}

Patient::operator bool() const
{
	return m_name && m_name[0] != 0 && (m_OHIPnum >= 100000000 && m_OHIPnum <= 999999999);
}

Patient::operator const char* () const
{
	return m_name;
}

ostream& Patient::write(ostream& ostr) const
{

	if (&ostr == &clog)
	{
		if (!bool(*this))
		{
			ostr << "Invalid Patient Record" << endl;
		}
		else
		{
			ostr.width(53);
			ostr.fill('.');
			ostr.setf(ios::left);
			ostr << m_name;
			ostr.fill(' ');
			ostr.unsetf(ios::left);
			ostr << m_OHIPnum;
			ostr.width(5);
			ostr.setf(ios::right);
			ostr << m_ticket.number() << " ";
			ostr.unsetf(ios::right);
			ostr << m_ticket.time();
		}
	}
	else if (&ostr == &cout)
	{
		if (!bool(*this))
		{
			ostr << "Invalid Patient Record" << endl;
		}
		else
		{
			m_ticket.write(ostr) << endl;
			ostr << m_name << ", OHIP: " << m_OHIPnum << endl;
		}
	}
	else
	{
		ostr << this->type() << "," << m_name << "," << m_OHIPnum << ",";
		m_ticket.write(ostr) << endl;
	}

	return ostr;
}

istream& Patient::read(istream& istr)
{
	if (&istr == &cin)
	{
		char tempName[51];
		cout << "Name: ";
		istr.getline(tempName, 50, '\n');
		delete[] m_name;
		m_name = new char[strlen(tempName) + 1];
		strcpy(m_name, tempName);
		if (strlen(tempName) >= 50)
		{
			istr.ignore(10000, '\n');
		}
		bool done = false;
		cout << "OHIP: ";
		do {
			istr >> m_OHIPnum;
			if (istr) {
				if (m_OHIPnum >= 100000000 && m_OHIPnum <= 999999999)
				{
					done = true;
				}
				else
				{
					cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
				}
			}
			else {
				
				istr.clear();
				istr.ignore(10000, '\n'); 
				cout << "Bad integer value, try again: ";
			}
		} while (!done);

	}
	else
	{
		//char c;
		//int num;
		char tempName[51];
		//c = istr.peek();
		//cout << c;
		istr.getline(tempName, 51, ',');
		istr.clear();
		//c = istr.peek();
		//cout << c;
		delete[] m_name;
		m_name = new char[strlen(tempName) + 1];
		strcpy(m_name, tempName);
		if (strlen(tempName) >= 50)
		{
			istr.ignore(10000, ',');
		}
		istr >> m_OHIPnum;
		istr.ignore();
		//istr >> num;
		m_ticket.read(istr);
	}

	return istr;
}
