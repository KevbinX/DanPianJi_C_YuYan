#include<reg52.h> // 导入单片机寄存器库

#define u8 unsigned char // 定义无符号字符型

sbit LED1=P1^0; // 将LED1设置为P1口的第0位
sbit LED2=P1^1; // 将LED2设置为P1口的第1位
sbit LED3=P1^2; // 将LED3设置为P1口的第2位
sbit LED4=P1^3; // 将LED4设置为P1口的第3位

u8 LedShuZhu[]={0,1,2,3,4,5,6,7,8,9}; // 定义一个无符号字符数组，用于存储 LED 的状态

void main() // 主函数
{
    while(1) // 无限循环
    {
        u8 x,y,i,j; // 声明变量x、y、i、j
        j=0; // 初始化j为0
        x=LedShuZhu[0]; // 使用索引来访问数组元素
        if(x==0) // 如果x等于0
        {
            LED1=0; // 将LED1置低电平
        }
        LedShuZhu[1]=10; // 将值赋给数组元素
        y=LedShuZhu[1]; // 将数组元素值赋给y
        if(y==10) // 如果y等于10
        {
            LED2=0; // 将LED2置低电平
        }    
        for(i=0;i<5;i++) // 循环5次
        {
            if(LedShuZhu[i]==3) // 如果数组元素等于3
            {
                LED3=0; // 将LED3置低电平
            }
        }
        while(j<10) // 循环10次
        {
            if(LedShuZhu[j]==7) // 如果数组元素等于7
            {
                LED4=0; // 将LED4置低电平
            }
            j++; // j自增1
        }
    }
}
