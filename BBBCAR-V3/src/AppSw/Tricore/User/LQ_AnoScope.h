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
=================================================================
程序配套视频地址：https://space.bilibili.com/95313236
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
#ifndef SRC_APPSW_TRICORE_USER_ANO_DT_H_
#define SRC_APPSW_TRICORE_USER_ANO_DT_H_

#include "stdint.h"

void ANO_DT_send_int16(short data1, short data2, short data3, short data4, short data5, short data6, short data7, short data8 );
void ANO_DT_send_int16byte16(short data1, short data2, short data3, short data4, short data5, short data6, short data7, short data8 );
void ANO_DT_send_int16byte18(short data1, short data2, short data3, short data4, short data5, short data6, short data7, short data8, short data9 );


#endif /* SRC_APPSW_TRICORE_USER_ANO_DT_H_ */
