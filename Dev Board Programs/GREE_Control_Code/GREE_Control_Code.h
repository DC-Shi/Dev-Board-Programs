#pragma once

/// Code definition from http://wenku.baidu.com/view/2197b3400b4e767f5bcfce34.html
/// Might be wrong.

class GREE_Control_Code
{
	typedef unsigned char BYTE;

	enum enum_Mode : BYTE
	{
		Auto = 0b000,
		Cool = 0b100,
		Fan = 0b110,
		Dry = 0b010,
		Heat = 0b001
	};

	enum enum_FanSpeed : BYTE
	{
		LvAuto = 0b00,
		Lv1 = 0b10,
		Lv2 = 0b01,
		Lv3 = 0b11
	};

private:
	// ģʽ��־
	enum_Mode mode;
	// ����
	bool powerOn;

	// ����
	enum_FanSpeed fanSpeed;

	// ɨ��
	bool swipe;

	// ˯��
	bool sleep;

	// �¶�����
	int temperature;

	// ��ʱ����
		/// We do not implement this.


	// ��ǿ
	bool strong;

	// �ƹ�
	bool light;

	// ����
	bool healthy;

	// ����
	bool dry;

	// ����
	bool airExchange;

	// ����ɨ��
	bool swipeUpDown;

	// ����ɨ��
	bool swipeLeftRight;

	// �¶���ʾ
	bool tempDisplay;

	// ����
	bool energySaving;

public:
	GREE_Control_Code();
	~GREE_Control_Code();
	void SendAllData();
	void SendMultipleBits(int bit, int lenght);
	void SendOneBit(bool bit);
	void Send1();
	void Send0Zero();
	void SendStartcodeS();
	void SendMiddlecodeC();
	void SendLvHigh();
	void SendLvLow();
	void WaitMicroSecond(int muSec);
};

