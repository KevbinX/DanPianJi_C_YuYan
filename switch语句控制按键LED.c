/****************************************************************************
					KevbinX 北辰青菁
*****************************************************************************
程序功能：	通过实例说明switch语句的功能。特别注意switch语句的格式，在此很容易犯错。	
****************************************************************************/
#include <reg52.h> //包含了reg52.h头文件，该文件定义了常用的寄存器和指令，方便在单片机程序中使用

sbit s2=P3^4;//定义了四个按键对应的IO口，分别为P3的第4、5、6、7位。
sbit s3=P3^5;
sbit s4=P3^6;
sbit s5=P3^7;

void main()//主函数的定义，程序从这里开始执行。
{
	char anjian;//定义了一个字符型变量anjian，用于存储按键的值。
	while(1)    //无条件永远执行大循环
	{
		if(!s2)		//检测按键是否按下，如果按下则给anjian变量赋予相应的值。
			anjian=1;//!用于判断按键S2被按下，由于按键在按下时对应的IO口会被拉低（逻辑0），
		if(!s3)	   //所以当按键被按下，S2的IO口值为0，取反后变为逻辑1，触发if条件成立。
			anjian=2;
		if(!s4)
			anjian=3;
		if(!s5)
			anjian=4;

		switch(anjian)	//当按键的值为几，程序就跳转到case几执行指令，让然后跳出
		{//这个大括弧一定不可少
			case 1: P1=0X0F; break;//break语句用于跳出switch语句块，防止继续执行后续的case语句,00001111
			case 2: P1=0Xf0; break;//根据按键值的不同，点亮不同的LED灯。11110000
			case 3: P1=0X55; break;//01010101
			case 4: P1=0Xaa; break;//10101010
			default:P1=0X00; break;//这个为当anjian取值为其他值时的结果（注意关键字为default）。
		}						   //又由于在刚定义变量anjian时，变量的值为初始值0，而0不属于上面的数值，
								   //故此时default项即被选中，故刚开机时，为8个LED均亮。
	}
}
