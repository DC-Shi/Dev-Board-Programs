#include "GREE_Control_Code.h"



GREE_Control_Code::GREE_Control_Code()
{
}


GREE_Control_Code::~GREE_Control_Code()
{
}

void GREE_Control_Code::SendAllData() 
{
	int checksum = mode - 1 + temperature - 16 + 5 + swipeLeftRight + airExchange + energySaving;
	int revCheckSum = checksum & 0xF;

	SendStartcodeS();
	// ------------------

	SendMultipleBits(mode, 3);

	SendOneBit(powerOn);

	SendMultipleBits(fanSpeed, 2);

	SendOneBit(swipe);
	SendOneBit(sleep);
	
	SendMultipleBits(temperature, 4);
	SendMultipleBits(0, 8);

	SendOneBit(strong);
	SendOneBit(light);
	SendOneBit(healthy);
	SendOneBit(dry);
	SendOneBit(airExchange);

	SendMultipleBits(0b0001010010, 10);

	// ------------------
	SendMiddlecodeC();
	// ------------------

	SendOneBit(swipeUpDown);
	SendMultipleBits(0b000, 3);
	SendOneBit(swipeLeftRight);
	SendMultipleBits(0b000, 3);

	SendMultipleBits(0, 2);
	SendMultipleBits(0b000100, 6);

	SendMultipleBits(0, 8);

	SendMultipleBits(0, 2);
	SendOneBit(energySaving);
	SendOneBit(0);
	SendMultipleBits(revCheckSum, 4);
}

void GREE_Control_Code::SendMultipleBits(int bit, int lenght)
{
	int i = 0;
	for (i = lenght - 1; i >= 0; i--)
	{
		SendOneBit((bit >> i) & 1);
	}
}

void GREE_Control_Code::SendOneBit(bool bit)
{
	if (bit == 0) Send0Zero();
	if (bit == 1) Send1();
}

void GREE_Control_Code::Send1()
{
	SendLvLow();
	WaitMicroSecond(600);
	SendLvHigh();
	WaitMicroSecond(600);
}

void GREE_Control_Code::Send0Zero()
{
	SendLvLow();
	WaitMicroSecond(600);
	SendLvHigh();
	WaitMicroSecond(1600);
}

void GREE_Control_Code::SendStartcodeS()
{
	SendLvLow();
	WaitMicroSecond(9000);
	SendLvHigh();
	WaitMicroSecond(4500);
}

void GREE_Control_Code::SendMiddlecodeC()
{
	SendLvLow();
	WaitMicroSecond(600);
	SendLvHigh();
	WaitMicroSecond(20000);
}

void GREE_Control_Code::SendLvHigh()
{
}

void GREE_Control_Code::SendLvLow()
{
}

void GREE_Control_Code::WaitMicroSecond(int muSec)
{
}