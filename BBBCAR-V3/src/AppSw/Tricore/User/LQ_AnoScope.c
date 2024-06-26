/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
【平    台】北京龙邱智能科技TC264DA核心板
【编    写】chiusir
【E-mail】chiusir@163.com
【软件版本】V1.2 版权所有，单位使用请先联系授权
【最后更新】2023年6月6日
【相关信息参考下列地址】
【网    站】http://www.lqist.cn
【淘宝店铺】http://longqiu.taobao.com
------------------------------------------------
【dev.env.】AURIX Development Studio1.6版本
【Target 】 TC264DA/TC264D
【Crystal】 20.000Mhz
【SYS PLL】 200MHz
________________________________________________________________
使用匿名4.3上位机协议：ANO_TC匿名科创地面站v4.34.exe
如果能收到数据，但是不显示，可以这样设置：
第1步：右下角“打开链接”；
第2步：左上角第2个按钮“高级收码”：勾上帧，数据位置1，2，3。。。关闭“误码显示”
第3步：左上角第三个按钮“数据波形”-->右下角“设置”-->用户数据-->确定，
       返回波形页面-->左下角“开始显示”完毕！
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/

#include "../Driver/LQ_UART.h"

unsigned char data_to_send[50];


/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
【函数名】vvoid ANO_DT_send_int16(short data1,..., short data8 )
【功  能】匿名上位机用户协议，使用时占用MCU资源较大，跑车时不使用
【参数值】short data1,..., short data8, 待发送的数据
【返回值】无 
【作  者】L Q
【最后更新】2021年1月22日 
【软件版本】V1.0
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
void ANO_DT_send_int16byte16(short data1, short data2, short data3, short data4, short data5, short data6, short data7, short data8 )
{
  unsigned char  _cnt=0;
  unsigned char  sum = 0, i = 0;
  
  data_to_send[_cnt++] = 0xAA;      //匿名协议帧头  0xAAAA
  data_to_send[_cnt++] = 0xAA;
  data_to_send[_cnt++] = 0xF1;      //使用用户协议帧0xF1
  data_to_send[_cnt++] = 16;        //8个int16_t 长度 16个字节
  
  data_to_send[_cnt++]=(unsigned short)(data1>>8);
  data_to_send[_cnt++]=(unsigned char)(data1);
  
  data_to_send[_cnt++]=(unsigned short)(data2>>8);
  data_to_send[_cnt++]=(unsigned char)(data2);
  
  data_to_send[_cnt++]=(unsigned short)(data3>>8);
  data_to_send[_cnt++]=(unsigned char)(data3);
  
  data_to_send[_cnt++]=(unsigned short)(data4>>8);
  data_to_send[_cnt++]=(unsigned char)(data4);
  
  data_to_send[_cnt++]=(unsigned short)(data5>>8);
  data_to_send[_cnt++]=(unsigned char)(data5);
  
  data_to_send[_cnt++]=(unsigned short)(data6>>8);
  data_to_send[_cnt++]=(unsigned char)(data6);
  
  data_to_send[_cnt++]=(unsigned short)(data7>>8);
  data_to_send[_cnt++]=(unsigned char)(data7);
  
  data_to_send[_cnt++]=(unsigned short)(data8>>8);
  data_to_send[_cnt++]=(unsigned char)(data8);
  
  sum = 0;
  for(i=0;i<_cnt;i++)
    sum += data_to_send[i];
  data_to_send[_cnt++]=sum;
  
  UART_PutBuff(UART0, data_to_send, _cnt);     //可以修改不同的串口发送数据;
}

void ANO_DT_send_int16(short data1, short data2, short data3, short data4, short data5, short data6, short data7, short data8 )
{
  unsigned char  _cnt=0;
  unsigned char  sum = 0, i = 0;
  
  data_to_send[_cnt++] = 0xAA;      //匿名协议帧头  0xAAAA
  data_to_send[_cnt++] = 0xAA;
  data_to_send[_cnt++] = 0xF1;      //使用用户协议帧0xF1
  data_to_send[_cnt++] = 16;        //8个int16_t 长度 16个字节
  
  data_to_send[_cnt++]=(unsigned short)(data1>>8);
  data_to_send[_cnt++]=(unsigned char)(data1);
  
  data_to_send[_cnt++]=(unsigned short)(data2>>8);
  data_to_send[_cnt++]=(unsigned char)(data2);
  
  data_to_send[_cnt++]=(unsigned short)(data3>>8);
  data_to_send[_cnt++]=(unsigned char)(data3);
  
  data_to_send[_cnt++]=(unsigned short)(data4>>8);
  data_to_send[_cnt++]=(unsigned char)(data4);
  
  data_to_send[_cnt++]=(unsigned short)(data5>>8);
  data_to_send[_cnt++]=(unsigned char)(data5);
  
  data_to_send[_cnt++]=(unsigned short)(data6>>8);
  data_to_send[_cnt++]=(unsigned char)(data6);
  
  data_to_send[_cnt++]=(unsigned short)(data7>>8);
  data_to_send[_cnt++]=(unsigned char)(data7);
  
  data_to_send[_cnt++]=(unsigned short)(data8>>8);
  data_to_send[_cnt++]=(unsigned char)(data8);
  
  sum = 0;
  for(i=0;i<_cnt;i++)
    sum += data_to_send[i];
  data_to_send[_cnt++]=sum;
  
  UART_PutBuff(UART1, data_to_send, _cnt);     //可以修改不同的串口发送数据;
}
void ANO_DT_send_int16byte18(short data1, short data2, short data3, short data4, short data5, short data6, short data7, short data8, short data9 )
{
  unsigned char  _cnt=0;
  unsigned char  sum = 0, i = 0;
  
  data_to_send[_cnt++] = 0xAA;      //匿名协议帧头  0xAAAA
  data_to_send[_cnt++] = 0xAA;
  data_to_send[_cnt++] = 0xF1;      //使用用户协议帧0xF1
  data_to_send[_cnt++] = 18;        //9个int16_t 长度 18个字节
  
  data_to_send[_cnt++]=(unsigned short)(data1>>8);
  data_to_send[_cnt++]=(unsigned char)(data1);
  
  data_to_send[_cnt++]=(unsigned short)(data2>>8);
  data_to_send[_cnt++]=(unsigned char)(data2);
  
  data_to_send[_cnt++]=(unsigned short)(data3>>8);
  data_to_send[_cnt++]=(unsigned char)(data3);
  
  data_to_send[_cnt++]=(unsigned short)(data4>>8);
  data_to_send[_cnt++]=(unsigned char)(data4);
  
  data_to_send[_cnt++]=(unsigned short)(data5>>8);
  data_to_send[_cnt++]=(unsigned char)(data5);
  
  data_to_send[_cnt++]=(unsigned short)(data6>>8);
  data_to_send[_cnt++]=(unsigned char)(data6);
  
  data_to_send[_cnt++]=(unsigned short)(data7>>8);
  data_to_send[_cnt++]=(unsigned char)(data7);
  
  data_to_send[_cnt++]=(unsigned short)(data8>>8);
  data_to_send[_cnt++]=(unsigned char)(data8);
  
  data_to_send[_cnt++]=(unsigned short)(data9>>8);
  data_to_send[_cnt++]=(unsigned char)(data9);
  
  sum = 0;
  for(i=0;i<_cnt;i++)
    sum += data_to_send[i];
  data_to_send[_cnt++]=sum;
  
  UART_PutBuff(UART1, data_to_send, _cnt);     //可以修改不同的串口发送数据;
}
