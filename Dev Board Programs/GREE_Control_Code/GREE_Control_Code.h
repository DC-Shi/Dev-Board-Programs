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
	// 模式标志
	enum_Mode mode;
	// 开关
	bool powerOn;

	// 风速
	enum_FanSpeed fanSpeed;

	// 扫风
	bool swipe;

	// 睡眠
	bool sleep;

	// 温度数据
	int temperature;

	// 定时数据
		/// We do not implement this.


	// 超强
	bool strong;

	// 灯光
	bool light;

	// 健康
	bool healthy;

	// 干燥
	bool dry;

	// 换气
	bool airExchange;

	// 上下扫风
	bool swipeUpDown;

	// 左右扫风
	bool swipeLeftRight;

	// 温度显示
	bool tempDisplay;

	// 节能
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

