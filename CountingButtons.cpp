#include <Arduino.h>
#include "CountingButtons.h"

// definition of the static values have to be done outside of the class
unsigned int CCountingButtons::m_value0 = 0;
unsigned int CCountingButtons::m_value1 = 0;
unsigned int CCountingButtons::m_maxvalue0 = 1;
unsigned int CCountingButtons::m_maxvalue1 = 1;

CCountingButtons::CCountingButtons(int interruptID) : m_interruptID(interruptID)
{
	if(m_interruptID == 0){
		pinMode(2, INPUT);
		attachInterrupt(0, CCountingButtons::interruptFunction0, FALLING);
	}else{
		pinMode(3, INPUT);
		attachInterrupt(1, CCountingButtons::interruptFunction1, FALLING);
	}
}

void CCountingButtons::interruptFunction0()
{
	// collect interrupts within a certain time frame
	static unsigned long lasttime = 0;
	if(millis()-lasttime < clickTimeFrame)
		return;
	lasttime = millis();

	// increase value
	if(++m_value0 > m_maxvalue0){
		m_value0 = 0;
	}
}

void CCountingButtons::interruptFunction1()
{
	// collect interrupts within a certain time frame
	static unsigned long lasttime = 0;
	if(millis()-lasttime < clickTimeFrame)
		return;
	lasttime = millis();

	// increase value
	if(++m_value1 > m_maxvalue1){
		m_value1 = 0;
	}
}

void CCountingButtons::configButton(unsigned int initValue, unsigned int maxValue)
{
	// set the static values, catching errors
	if(m_interruptID == 0){
		m_maxvalue0 = (maxValue>0) ? maxValue : 1;
		m_value0 = (initValue<=m_maxvalue0) ? initValue : 0 ;
	}else{
		m_maxvalue1 = (maxValue>0) ? maxValue : 1;
		m_value1 = (initValue<=m_maxvalue1) ? initValue : 0 ;
	}
}

CCountingButtons &CCountingButtons::instance0()
{
	static CCountingButtons instance(0);
	return instance;
}

CCountingButtons &CCountingButtons::instance1()
{
	static CCountingButtons instance(1);
	return instance;
}

unsigned int CCountingButtons::getValue()
{
	if(m_interruptID ==0)
		return m_value0;
	else
		return m_value1;
}





