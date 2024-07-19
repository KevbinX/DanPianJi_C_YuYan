#include <reg52.h>
 
int LedYiLing = 0; // 用于记录是否已点亮LED灯的标志位

// 定义函数原型，用于初始化LED灯
void LedChuShiHua(void);

// 定义LED灯对应的端口和脚标号
sbit LED1 = P2^0;
sbit LED2 = P2^1;
 
// 定义控制程序逻辑的函数
void LuoJiYu(void);

// 主函数
void main()
{
	while(1)
	{
		LedChuShiHua(); // 初始化LED灯，将其初始状态置灭
		// 调用LuoJiYu函数，实现LED灯的闪烁效果
		LuoJiYu();
	}
}

// 控制LED灯闪烁逻辑的函数
void LuoJiYu(void)
{	
	int JiShu=0; // 定义计数器用于记录LED灯亮的时间间隔

	// 利用无限循环控制LED灯的闪烁时间，并且记录亮灯的时间间隔
    while( LedYiLing && JiShu < 3) // 如果LED已点亮且计数器小于3，循环继续
	{
		JiShu++; // 在每个闪烁间隔内，增加计数器
	}

	// 根据计数器的值判断闪烁周期是否到期，改变LED灯的状态
	if(JiShu >= 3) // 如果计数器等于或大于3，关闭LED2灯，打开LED1灯
	{
		LED1=0;// 将LED灯置低电平
		LED2=1;
		LedYiLing = 0;//将标志位置低，表示LED1灯已点亮
	}
	else // 否则，关闭LED1灯，打开LED2灯
	{
		LED1=1;// 将LED灯置高电平
		LED2=0; 
		LedYiLing = 1;		//将标志位置高，表示LED2灯已点亮
	}
}

// 初始化LED灯
void LedChuShiHua(void)
{
	LED1=1;
	LED2=1; 
}
