// a singleton button class
class CToggleButtons{
private:
	const int m_interruptID;
	static int m_value0;
	static int m_value1;

	// no direct construction
	CToggleButtons();
	// no copy construction
	CToggleButtons(const CToggleButtons &);
	// no direct construction with parameter
	CToggleButtons(int interruptID, int initValue);

	// interrupt function toggles value of button 0
	static void interruptFunction0();

	// interrupt function toggles value of button 1
	static void interruptFunction1();

public:
	// get instance for button with interrupt-ID 0 (PIN 2)
	static CToggleButtons &instance0(int initValue = 0);

	// get instance for button with interrupt-ID 1 (PIN 3)
	static CToggleButtons &instance1(int initValue = 0);

	// get the value of button 0
	int getValue();
};

