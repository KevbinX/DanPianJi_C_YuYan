/****************************************************************************
					KevbinX 北辰青菁
*****************************************************************************
程序功能：	该函数通过for语句控制蜂鸣器的鸣响次数来说明for语句的功能。
****************************************************************************/
#include <reg52.h>
#define uint unsigned int
sbit beep=P2^3;
sbit led=P1^0;

void DelayMs(uint c)
{
	uint a,b;
	for(a=c;a>0;a--)
			for(b=115;b>0;b--);
}

void main()
{
	char cishu;
	for(cishu=0;cishu<10;cishu++)	//第一个表达式为给变量赋初值，第二个为判断标准
																//若为真，则执行下面的指令，否则将跳过大括弧中的指令
																//第三句为更改变量值的指令。
	{
		beep=~beep;	  //每执行一次，beep与led所代表的管脚电平都会取反。
		led=~led;	  	//由于共取了十次反，故蜂鸣器会响五下，led会闪五次
		DelayMs(100);
		beep=~beep;	  //每执行一次，beep与led所代表的管脚电平都会取反。
		led=~led;	  	//由于共取了十次反，故蜂鸣器会响五下，led会闪五次
		DelayMs(50);
		beep=~beep;	  //每执行一次，beep与led所代表的管脚电平都会取反。
		led=~led;	  	//由于共取了十次反，故蜂鸣器会响五下，led会闪五次
		DelayMs(100);
		beep=~beep;	  //每执行一次，beep与led所代表的管脚电平都会取反。
		led=~led;	  	//由于共取了十次反，故蜂鸣器会响五下，led会闪五次
		DelayMs(50);
	}
	while(1);
}
