#pragma once
class GREE_Control_Code
{
	typedef unsigned char BYTE;

	enum Mode : BYTE
	{
		Auto = 0b000,
		Cool = 0b100,
		Fan = 0b110,
		Dry = 0b010,
		Heat = 0b001
	};

	enum FanSpeed : BYTE
	{
		Auto = 0b00,
		Lv1 = 0b10,
		Lv2 = 0b01,
		Lv3 = 0b11
	};

	// ģʽ��־
	void SetMode(Mode m)
	{
		/// Clear the mode flag.
		First35[0] &= 0b00011111;
		/// Fill the data.
		First35[0] |= m << 5;
	}

	// ����
	void SetOnOff(bool isOn)
	{
		/// Clear the mode flag.
		First35[0] &= 0b11101111;
		/// Fill the data.
		First35[0] |= (isOn ? 1 : 0) << 4;
	}

	// ����
	void SetFanSpeed(FanSpeed fs)
	{
		/// Clear the mode flag.
		First35[0] &= 0b11110011;
		/// Fill the data.
		First35[0] |= fs << 2;
	}

	// ɨ��
	void SetSwipe(bool swipe)
	{
		/// Clear the mode flag.
		First35[0] &= 0b11111101;
		/// Fill the data.
		First35[0] |= (swipe ? 1 : 0) << 1;
	}

	// ˯��
	void SetSleep(bool sleep)
	{
		/// Clear the mode flag.
		First35[0] &= 0b11111110;
		/// Fill the data.
		First35[0] |= (sleep ? 1 : 0) << 1;
	}

	// �¶�����
	void SetTemp(int temperature)
	{
		int revTemp = temperature - 16;
		/// Clear the mode flag.
		First35[1] &= 0b00001111;
		/// Fill the data.
		First35[1] |= revTemp << 4;
	}

	// ��ʱ����
	void SetTimer(int time)
	{
		/// We do not implement this.
	}

	// ��ǿ
	void SetStrong(bool strong)
	{
		/// Clear the mode flag.
		First35[1] &= 0b11110111;
		/// Fill the data.
		First35[1] |= (strong ? 1 : 0) << 3;
	}

	// �ƹ�
	void SetLight(bool light)
	{
		/// Clear the mode flag.
		First35[1] &= 0b11111011;
		/// Fill the data.
		First35[1] |= (light ? 1 : 0) << 2;
	}

	// ����
	void SetHealthy(bool healthy)
	{
		/// Clear the mode flag.
		First35[1] &= 0b11111101;
		/// Fill the data.
		First35[1] |= (healthy ? 1 : 0) << 1;
	}

	// ����
	void SetDry(bool dry)
	{
		/// Clear the mode flag.
		First35[1] &= 0b11111110;
		/// Fill the data.
		First35[1] |= (dry ? 1 : 0);
	}

	// ����
	void SetAirExchange(bool airExchange)
	{
		/// Clear the mode flag.
		First35[2] &= 0b01111111;
		/// Fill the data.
		First35[2] |= (airExchange ? 1 : 0) << 7;
	}

	// ����ɨ��
	void SetSwipe(bool swipe)
	{
		/// Clear the mode flag.
		First35[0] &= 0b11111101;
		/// Fill the data.
		First35[0] |= (swipe ? 1 : 0) << 1;
	}

	// ����ɨ��
	void SetSwipe(bool swipe)
	{
		/// Clear the mode flag.
		First35[0] &= 0b11111101;
		/// Fill the data.
		First35[0] |= (swipe ? 1 : 0) << 1;
	}

	// �¶���ʾ
	void SetSwipe(bool swipe)
	{
		/// Clear the mode flag.
		First35[0] &= 0b11111101;
		/// Fill the data.
		First35[0] |= (swipe ? 1 : 0) << 1;
	}

	// ����
	void SetSwipe(bool swipe)
	{
		/// Clear the mode flag.
		First35[0] &= 0b11111101;
		/// Fill the data.
		First35[0] |= (swipe ? 1 : 0) << 1;
	}
public:
	GREE_Control_Code();
	~GREE_Control_Code();
};

