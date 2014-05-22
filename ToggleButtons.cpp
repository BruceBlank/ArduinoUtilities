#include <Arduino.h>
#include "ToggleButtons.h"

// definition of the static values have to be done outside of the class
int CToggleButtons::m_value0 = 0;
int CToggleButtons::m_value1 = 0;

CToggleButtons::CToggleButtons(int interruptID, int initValue) : m_interruptID(interruptID)
	{
		if(m_interruptID == 0){
			m_value0 = initValue;
			pinMode(2, INPUT);
			attachInterrupt(0, CToggleButtons::interruptFunction0, FALLING);
		}else{
			m_value1 = initValue;
			pinMode(3, INPUT);
			attachInterrupt(1, CToggleButtons::interruptFunction1, FALLING);
		}
	}

	void CToggleButtons::interruptFunction0()
	{
		// increase value
		if(++m_value0 > 1){
			m_value0 = 0;
		}
	}

	void CToggleButtons::interruptFunction1()
	{
		// increase value
		if(++m_value1 > 1){
			m_value1 = 0;
		}
	}

	CToggleButtons &CToggleButtons::instance0(int initValue)
	{
		static CToggleButtons instance(0, initValue);
		return instance;
	}

	CToggleButtons &CToggleButtons::instance1(int initValue)
	{
		static CToggleButtons instance(1, initValue);
		return instance;
	}

	int CToggleButtons::getValue()
	{
		if(m_interruptID ==0)
			return m_value0;
		else
			return m_value1;
	}
