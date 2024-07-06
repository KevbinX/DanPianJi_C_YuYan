/************************************************************************
				KevbinX 北辰青菁
*************************************************************************
程序功能：该程序通过两个延时函数的不同效果，关于不同函数类型的数据间差异提供一感性认识。
				下载程序后，会发现八位发光二极管被点亮的时间很短，而熄灭的时间很长。
************************************************************************/

#include<reg52.h>
typedef unsigned int u16;
typedef unsigned char u8;
void DelayChar()
{
	u8 m,n;	   
	for(m=255;m>0;m--)	   //unsigned char型的变量，最大值可以取到255
		for(n=10;n>0;n--); //故这种变量延时不会太长
}

void DelayInt()
{
	u8 n;
	u16 m;
	for(m=65535;m>0;m--)  //unsigned int型的变量，最大值可以取到65535
		for(n=10;n>0;n--);//故这种变量，延时的长度会比前者大。
}

void main()
{
	while(1)
	{
		P1=0X00;	 //当函数运行到此处时，八个二极管被点亮。
		DelayChar(); //这是点亮持续的时间。
		P1=0xff;	 //当函数运行到此处时，八个二极管被熄灭。
		DelayInt();	 //这是熄灭的持续时间。
	}
}
//编程时，关于某变量数值类型的选择，一边参照它可能取得的最大数值。
//能定义为char型的变量，就不要定义成int型，因为当定义为int型时，
//程序就会在单片机的存储区中腾出两个字节的位置来存储此变量，而单片机的
//存储空间毕竟是比较有限的。故一般不要随便浪费空间。
