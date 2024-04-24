/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
锟斤拷平    台锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟杰科硷拷TC264DA锟斤拷锟侥帮拷
锟斤拷锟斤拷    写锟斤拷chiusir
锟斤拷E-mail  锟斤拷chiusir@163.com
锟斤拷锟斤拷锟斤拷姹撅拷锟絍1.0
锟斤拷锟斤拷锟斤拷锟铰★拷2020锟斤拷4锟斤拷10锟斤拷
锟斤拷锟斤拷锟斤拷锟较拷慰锟斤拷锟斤拷械锟街凤拷锟�
锟斤拷锟斤拷    站锟斤拷http://www.lqist.cn
锟斤拷锟皆憋拷锟斤拷锟教★拷http://longqiu.taobao.com
------------------------------------------------
锟斤拷dev.env.锟斤拷Hightec4.9.3/Tasking6.3锟斤拷锟斤拷锟较版本
锟斤拷Target 锟斤拷 TC264DA
锟斤拷Crystal锟斤拷 20.000Mhz
锟斤拷SYS PLL锟斤拷 200MHz
锟斤拷锟斤拷iLLD_1_0_1_11_0锟阶诧拷锟斤拷锟�
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
#ifndef SRC_APPSW_TRICORE_MAIN_MAIN_H_
#define SRC_APPSW_TRICORE_MAIN_MAIN_H_

#include <include.h>//锟斤拷锟斤拷模锟斤拷锟酵凤拷募锟�
#include <stdio.h>
#include <stdint.h>
#include <LQ_ADC.h>
#include <IfxCpu.h>
#include <IfxStm.h>
#include <LQ_UART.h>
#include <LQ_CCU6.h>
#include <LQ_TFT18.h>
#include <LQ_CAMERA.h>
#include <IfxScuCcu.h>
#include <IfxScuWdt.h>
#include <LQ_SOFTI2C.h>
#include <IfxStm_reg.h>
#include <LQ_IIC_Gyro.h>
#include <LQ_I2C_VL53.h>
#include <LQ_GPIO_LED.h>
#include <LQ_Inductor.h>
#include <LQ_MotorServo.h>
#include <Platform_Types.h>

#include "image1.h"
#include "My_Key.h"
#include "My_menu.h"
#include "Image_Handle.h"
#include "LQ_ImageProcess.h"
#include "My_Image_Handle.h"

extern App_Cpu0 g_AppCpu0; // brief CPU 0 global data
extern IfxCpu_mutexLock mutexCpu0InitIsOk;   /** CPU0 锟斤拷始锟斤拷锟斤拷杀锟街疚�  */
extern volatile char mutexCpu0TFTIsOk;       /** TFT18使锟矫憋拷志位  */
/**
 * 锟斤拷时锟斤拷 5ms锟斤拷50ms锟斤拷志位
 */
extern volatile uint8 cpu1Flage5ms;
extern volatile uint8 cpu1Flage50ms;

/* 锟斤拷锟斤拷锟劫讹拷  */
extern volatile sint16 targetSpeed;

/* 锟斤拷锟较憋拷志位 */
extern volatile uint8 evadibleFlage;

int core0_main(void);
void Init_System(void);

#endif /* SRC_APPSW_TRICORE_MAIN_MAIN_H_ */
