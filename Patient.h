#ifndef PATIENT_H__
#define PATIENT_H__

#include "Ticket.h"

namespace seneca {

	class Patient : public IOAble
	{
	public:
		Patient(int ticketNum);
		Patient(Patient& RS);
		Patient& operator=(Patient& RS);

		virtual ~Patient();

		virtual char type() const = 0;
		bool operator==(char type) const;
		bool operator==(const Patient& p2) const;
		void setArrivalTime();
		Time time() const; //reference or not?
		int number() const;
		operator bool() const; //what does it mean for a patient to be in a valid state?
		operator const char* () const;
		ostream& write(ostream& ostr) const;
		istream& read(istream& istr);
	private:
		char* m_name{}; //50chars max
		int m_OHIPnum;
		Ticket m_ticket;
	};
}

#endif // !PATIENT_H__
