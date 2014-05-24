// a singleton button class: it counts how often the button has been clicked.
// When a configurable maximum value will be reached, the counter will be reset to 0
class CCountingButtons{
private:
	const int m_interruptID;

	static unsigned int m_value0;
	static unsigned int m_value1;
	static unsigned int m_maxvalue0;
	static unsigned int m_maxvalue1;

	static const unsigned long clickTimeFrame = 250;

	// direct construction is private
	CCountingButtons();
	// copy construction is private
	CCountingButtons(const CCountingButtons &);
	// direct construction with parameter is private
	// interruptID is 0 (button on PIN2) or 1 (button on PIN3)
	CCountingButtons(int interruptID);

	// interrupt function increases value of button 0 up to a maximum value
	static void interruptFunction0();
	// interrupt function increases value of button 1 up to a maximum value
	static void interruptFunction1();

public:
	// define the initial and maximum value of the button 0
	// parameters have to be > 0 and maxValue >= initValue.
	// method sets parameters to a reasonable value
	void configButton(unsigned int initValue = 0, unsigned int maxValue = 1);

	// get instance for button with interrupt-ID 0 (PIN 2)
	static CCountingButtons &instance0();
	// get instance for button with interrupt-ID 1 (PIN 3)
	static CCountingButtons &instance1();

	// get the value of the current button instance
	unsigned int getValue();
};


