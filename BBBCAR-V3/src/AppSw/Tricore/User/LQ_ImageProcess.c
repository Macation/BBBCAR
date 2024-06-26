/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
【平    台】北京龙邱智能科技TC264DA核心板
【编    写】zyf/chiusir
【E-mail  】chiusir@163.com
【软件版本】V1.0
【最后更新】2020年4月10日
【相关信息参考下列地址】
【网    站】http://www.lqist.cn
【淘宝店铺】http://longqiu.taobao.com
------------------------------------------------
【dev.env.】Hightec4.9.3/Tasking6.3及以上版本
【Target 】 TC264DA
【Crystal】 20.000Mhz
【SYS PLL】 200MHz
基于iLLD_1_0_1_11_0底层程序
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
#include <LQ_CAMERA.h>
#include <LQ_DMA.h>
#include <LQ_GPIO_LED.h>
#include <LQ_TFT18.h>
#include <LQ_MotorServo.h>
#include <IfxCpu.h>
#include <LQ_ADC.h>
#include <LQ_CCU6.h>
#include <LQ_STM.h>
#include <LQ_TFT18.h>
#include <Main.h>
#include <Platform_Types.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <LQ_GPIO_KEY.h>
#include <LQ_MotorServo.h>
#include <LQ_GPIO_LED.h>
#include <LQ_Inductor.h>
#include <LQ_GPT12_ENC.h>
#include "LQ_MT9V034.h"
#include "LQ_ImageProcess.h"

/**  @brief    使用起始行  */
#define ROAD_START_ROW     119

/**  @brief    使用结束行  */
#define ROAD_END_ROW       0

uint8 ImageSide[LCDH][2];         //左右边线数组
uint8 ImageSide_last[LCDH][2];    //上张图片左右边线数组
uint8 UpdowmSide[2][LCDW];        //上下边线数组
uint8 Roadwide[LCDH];             //赛道宽度

volatile sint16 ECPULSE1 = 0;          // 速度全局变量
volatile sint16 ECPULSE2 = 0;          // 速度全局变量
volatile sint32 RAllPulse = 0;         // 速度全局变量

/*************************************************************************
 *  函数名称：void TFT_Show_Camera_Info(void)
 *  功能说明：显示各种所需信息
 *  参数说明：无
 *  函数返回：无
 *  修改时间：2020年11月18日
 *  备    注：
 *************************************************************************/
void TFT_Show_Camera_Info (void)
{
    char txt[16] = "X:";
    TFTSPI_Init(0);               //TFT1.8初始化0:横屏  1：竖屏
    TFTSPI_CLS(u16BLUE);          //清屏
    sint16 mps = 0, dmm = 0;    // 速度：m/s,毫米数值
    sint16 pulse100 = 0;
    uint16 bat = 0;

    dmm = (sint16) (RAllPulse * 100 / 579);         // 龙邱512带方向编码器1米5790个脉冲，数值太大，除以100
    pulse100 = (sint16) (RAllPulse / 100);
    sprintf(txt, "AP:%05d00", pulse100);           //
    TFTSPI_P8X16Str(3, 4, txt, u16RED, u16BLUE);   // 显示赛道偏差参数

    NowTime = (STM_GetNowUs(STM0) - NowTime) / 1000;  // 获取STM0 当前时间，得到毫秒
    mps = (sint16) (dmm / (NowTime / 1000));          // 计算速度mm/s
    TFTSPI_Road(18, 0, LCDH, LCDW, (unsigned char *)Image_Use); // TFT1.8动态显示摄像头灰度图像
    //TFTSPI_BinRoad(0, 0, LCDH, LCDW, (unsigned char *) Bin_Image);
    sprintf(txt, "%04d,%04d,%04d", OFFSET0, OFFSET1, OFFSET2);
    TFTSPI_P8X16Str(0, 5, txt, u16RED, u16BLUE);       // 显示赛道偏差参数
    BatVolt       = ADC_Read(ADC7);  // 刷新电池电压
    bat = BatVolt * 11 / 25;  // x/4095*3.3*100*5.7
    sprintf(txt, "B:%d.%02dV %d.%02dm/s", bat / 100, bat % 100, mps / 1000, (mps / 10) % 100);  // *3.3/4095*3
    TFTSPI_P8X16Str(0, 6, txt, u16WHITE, u16BLUE);   // 字符串显示
    // 电机和舵机参数显示
    sprintf(txt, "Sv:%04d Rno:%d", ServoDuty, CircleNumber);
    TFTSPI_P8X16Str(1, 7, txt, u16RED, u16BLUE);     // 显示舵机，电机1，编码器1数值
    sprintf(txt, "M1:%04d, M2:%04d ", MotorDuty1, MotorDuty2);
    TFTSPI_P8X16Str(0, 8, txt, u16RED, u16BLUE);     // 电机1-2数值
    sprintf(txt, "E1:%04d, E2:%04d ", ECPULSE1, ECPULSE2);
    TFTSPI_P8X16Str(0, 9, txt, u16RED, u16BLUE);     // 编码器1-2数值
    /*
    sprintf(txt, "Ring num: %d ", CircleNumber);
    TFTSPI_P8X16Str(2, 6, txt, u16GREEN, u16BLACK);
    sprintf(txt, "M:%03d Q:%d J:%d ", MagneticField, TangentPoint, EnterCircle);
    TFTSPI_P8X16Str(0, 7, txt, u16WHITE, u16BLACK);
    */
}
/*************************************************************************
 *  函数名称：void CameraCar(void)
 *  功能说明：电磁车双电机差速控制
 -->1.入门算法：简单的分段比例控制算法，教学演示控制算法；
 2.进阶算法：PID典型应用控制算法，教学演示控制算法；
 3.高端算法：改进粒子群协同控制算法；
 *  参数说明：无
 *  函数返回：无
 *  修改时间：2020年10月28日
 *  备    注：驱动2个电机
 *************************************************************************/
void CameraCar (void)
{
    // 摄像头初始化
    CAMERA_Init(50);
    TFTSPI_P8X16Str(2, 3, "LQ 9V034 Car", u16RED, u16GREEN);
    TFTSPI_P8X16Str(1, 5, "K2 Show Video", u16RED, u16GREEN);
    delayms(500);

    // 切记CPU0,CPU1...不可以同时开启屏幕显示，否则冲突不显示
    mutexCpu0TFTIsOk = 0;             // CPU1： 0占用/1释放 TFT
    //CircleNumber = 2;    // 设置需要进入圆环的个数；

    // 。根据需要设置出入库，出库是固定执行，
    // 。入库需要干簧管和外部中断配合实现
    // 。本例程中，干簧管在通过圆环后开启，不会出现起跑触发的可能性
   // OutInGarage(OUT_GARAGE, ReadOutInGarageMode()); // 测试出库，拨码在上左侧出入库，反之右侧出入库
    //OutInGarage(IN_GARAGE,ReadOutInGarageMode());  // 测试入库

    TFTSPI_CLS(u16BLUE);            // 清屏
    // 切记CPU0,CPU1...不可以同时开启屏幕显示，否则冲突不显示
    mutexCpu0TFTIsOk = 1;             // CPU1： 0占用/1释放 TFT

    RAllPulse = 0;                  // 全局变量，脉冲计数总数
    NowTime = STM_GetNowUs(STM0);   // 获取STM0 当前时间
    while (1)
    {
        LED_Ctrl(LED1, RVS);     // LED闪烁 指示程序运行状态
        if (Camera_Flag == 2)
        {
            Camera_Flag = 0;     // 清除摄像头采集完成标志位  如果不清除，则不会再次采集数据
            Get_Use_Image();     // 取出赛道及显示所需图像数据
            Get_Bin_Image(2);    // 转换为01格式数据，0、1原图；2、3边沿提取
            Bin_Image_Filter();  // 滤波，三面被围的数据将被修改为同一数值
            Seek_Road();         // 通过黑白区域面积差计算赛道偏差值

            // 计算赛道偏差值，系数越大打角越早，数值跟舵机的范围有关，此处为±160左右，默认为7，
            ServoDuty = Servo_Center_Mid - (OFFSET1 + OFFSET2 + OFFSET2) * 1/7;

            // 圆环处理，如果面积为负数，数值越大说明越偏左边；
            if((OFFSET2 < -300)||(OFFSET2 > 300))
                ServoDuty = Servo_Center_Mid - OFFSET2 / 7;

            ServoCtrl(ServoDuty);     // 舵机PWM输出，转向

            // SPEED正负标识方向，负数为正向
            MotorDuty1 = MtTargetDuty + ECPULSE1 * 4 - (OFFSET1 + OFFSET2 + OFFSET2) / 10;        // 电机PWM
            MotorDuty2 = MtTargetDuty - ECPULSE2 * 4 + (OFFSET1 + OFFSET2 + OFFSET2) / 10;        // 双电机差分，需要去掉abs

            MotorCtrl(MotorDuty1, MotorDuty2);        // 四轮电机驱动
            // MotorCtrl(2500, 2500); // 电机PWM固定功率输出
        }
        if(RAllPulse>10000)
            Reed_Init();            // 干簧管GPIO及中断初始化函数,为停车入库做准备
        if (Game_Over)
        {
            OutInGarage(IN_GARAGE, ReadOutInGarageMode());
        }

    }
}

/*!
  * @brief    获取左右边线
  *
  * @param    imageInput ： 二值图像信息
  * @param    imageOut   ： 边线数组
  * @param    imageOut_last   ： 上一张图片边线数组
  * @return   是否丢线
  *
  * @note     思路：从距离车头较近的行开始从中间向两边搜线
  *
  * @see
  *
  * @date     2020/6/23 星期二
  */
uint8 ImageGetSide(uint8 imageInput[LCDH][LCDW], uint8 imageOut[LCDH][2])
{
    uint8 i = 0, j = 0;

    //RoadIsNoSide(imageInput, imageOut, ROAD_START_ROW);

    /* 离车头近的40行 寻找边线 */
    imageOut[119][0] = 0;
    imageOut[119][1] = 159;

    for(i = 118; i >= 0; i--)
    {
        imageOut[i][0] = 0;
        imageOut[i][1] = 159;

        /* 根据边界连续特性 寻找边界 */
        for(j = imageOut[i+1][0] + 20; j > 0; j--)
        {
            if(!imageInput[i][j])
            {
                imageOut[i][0] = j ;
                break;
            }
        }
        for(j = imageOut[i+1][1] - 20; j < 160; j++)
        {
            if(!imageInput[i][j])
            {
                imageOut[i][1] = j;
                break;
            }
        }
        /* 如果左边界 即将超出中线 则检查是否右丢线 */
//        if(imageOut[i][0] > (LCDW/2 - 10) && imageOut[i][1] >  (LCDW - 5))
//        {
//            /* 右丢线处理  即让右边线为最有边界159，左边线为*/
//            RoadNoSideProcess(imageInput, imageOut, 2, i);
//
//            if(i > 70)
//            {
//                imageOut[i][0] += 50;
//            }
//            return 1;
//        }
//
//        /* 如果右边界 即将超出中线 则检查是否左丢线 */
//        if(imageOut[i][1] < (LCDW/2 + 10) && imageOut[i][0] <  (5))
//        {
//            /* 左丢线处理 */
//            RoadNoSideProcess(imageInput, imageOut, 1, i);
//
//            if(i > 70)
//            {
//                imageOut[i][1] -= 50;
//            }
//            return 2;
//
//        }
        /*边线数组发生突变*/
//        if((imageOut_last[110][0] - imageOut[110][0]) > 20 && (imageOut_last[110][0] - imageOut[110][0]) < -20)
//        {
//            for(i = 0;i < LCDH;i++)
//            {
//                imageOut[i][0] = imageOut_last[i][0];
//                imageOut[i][1] = 158;
//            }
//        }
//        if(imageOut_last[110][1] - imageOut[110][1] > 20 && imageOut_last[110][1] - imageOut[110][1] < -20)
//        {
//            for(i = 0;i <= LCDH;i++)
//            {
//                imageOut[i][1] = imageOut_last[i][1];
//                imageOut[i][0] = 1;
//            }
//        }
    }
    return 0;
}

/*!
  * @brief    获取上下边线
  *
  * @param    imageInput ： 二值图像信息
  * @param    imageOut   ： 边线数组
  *
  * @return   是否丢线
  *
  * @note     思路：从距离车头较近的行开始从中间向两边搜线
  *
  * @see
  *
  * @date     2021/11/30 星期二
  */
uint8 UpdownSideGet(uint8 imageInput[LCDH][LCDW], uint8 imageOut[2][LCDW])
{
    uint8 i = 0, j = 0;
    uint8 last = 60;

    imageOut[0][159] = 0;
    imageOut[1][159] = 119;
    /* 用中线比较近的行 判断是否丢线 */
    for(i = last; i >= 0; i--)
    {
        if(!imageInput[i][80])
        {
            imageOut[0][80] = i;
            break;
        }
    }

    for(i = last; i < 120; i++)
    {
        if(!imageInput[i][80])
        {
            imageOut[1][80] = i;
            break;
        }
    }

    /* 中线往左 寻找边线 */
    for(i = 80-1; i > 0; i--)
    {
        imageOut[0][i] = 0;
        imageOut[1][i] = 119;

        /* 根据边界连续特性 寻找边界 */
        for(j = imageOut[0][i+1] + 10; j > 0; j--)
        {
            if(!imageInput[j][i])
            {
                imageOut[0][i] = j;
                break;
            }
        }
        for(j = imageOut[1][i+1] - 10; j < 120; j++)
        {
            if(!imageInput[j][i])
            {
                imageOut[1][i] = j;
                break;
            }
        }
    }
    /*中线往右 寻找边线*/
    for(i = 80+1; i < 159; i++)
        {
            imageOut[0][i] = 0;
            imageOut[1][i] = 119;

            /* 根据边界连续特性 寻找边界 */
            for(j = imageOut[0][i-1] + 10; j > 0; j--)
            {
                if(!imageInput[j][i])
                {
                    imageOut[0][i] = j;
                    break;
                }
            }
            for(j = imageOut[1][i-1] - 10; j < 120; j++)
            {
                if(!imageInput[j][i])
                {
                    imageOut[1][i] = j;
                    break;
                }
            }
        }
    return 0;
}


/*!
  * @brief    获取赛道宽度
  *
  * @param    imageInput ： 左右边线数组
  * @param    imageOut   ： 赛道宽度边线数组
  *
  * @return   是否丢线
  *
  * @note     思路：右边线数组减去左边线数组
  *
  * @see
  *
  * @date     2022/11/29 星期二
  */
uint8 GetRoadWide(uint8 imageInput[LCDH][2] ,uint8 imageOut[LCDH])
{
    uint8 i = 0;
    for(i = 10;i <= LCDH - 5; i++)
    {
        imageOut[i] = 0;
        if(imageInput[i][1] > imageInput[i][0])
        {
            imageOut[i] = imageInput[i][1] - imageInput[i][0];
        }
        else
        {
            imageOut[i] = 160;
        }
    }
    return 0;
}


/*!
  * @brief    判断是否丢线
  *
  * @param    imageInput ： 二值图像信息
  * @param    imageOut   ： 边线数组
  * @param    lineIndex  ： 行
  *
  * @return   0：没有丢线   1:左边丢线  2：右边丢线  3： 左右都丢线   4：错误
  *
  * @note
  *
  * @see
  *
  * @date     2020/6/24 星期三
  */
uint8 RoadIsNoSide(uint8 imageInput[LCDH][LCDW], uint8 imageOut[LCDH][2], uint8 lineIndex)
{
    uint8 state = 0;
    uint8 i = 0;
    static uint8 last = 78;
    imageOut[lineIndex][0] = 0;
    imageOut[lineIndex][1] = 159;
    /* 用距离小车比较近的行 判断是否丢线 */
    for(i = last; i > 1; i--)
    {
        if(!imageInput[lineIndex][i])
        {
            imageOut[lineIndex][0] = i;
            break;
        }
    }
    if(i == 1)
    {
        /* 左边界丢线 */
        state = 1;
    }

    for(i = last; i < 159; i++)
    {
        if(!imageInput[lineIndex][i])
        {
            imageOut[lineIndex][1] = i;
            break;
        }
    }
    if(i == 159)
    {
        /* 左右边界丢线 */
        if(state == 1)
        {
            state = 3;
        }
        /* 右边界丢线 */
        else
        {
            state = 2;
        }
    }
    if(imageOut[lineIndex][1] <= imageOut[lineIndex][0])
    {
        state = 4;
    }
    return state;
}

/*!
  * @brief    丢线处理
  *
  * @param    imageInput ： 二值图像信息
  * @param    imageOut   ： 边线数组
  * @param    mode       ： 那边丢线？   1：左边丢线  2：右边丢线
  * @param    lineIndex  ： 丢线行数
  *
  * @return
  *
  * @note
  *
  * @see
  *
  * @date     2020/6/24 星期三
  */
void RoadNoSideProcess(uint8 imageInput[LCDH][LCDW], uint8 imageOut[LCDH][2], uint8 mode, uint8 lineIndex)
{
    uint8 i = 0, j = 0, count = 0;
    switch(mode)
    {
      case 1:
        for(i = imageOut[lineIndex][1]; i > 1; i--)
        {
            count++;
            for(j = lineIndex; j > ROAD_END_ROW && lineIndex > count; j--)
            {
                if(!imageInput[j][i])
                {
                    imageOut[lineIndex - count][0] = 0;
                    imageOut[lineIndex - count][1] = i;
                    break;
                }
            }
        }
        break;
      case 2:
        for(i = imageOut[lineIndex][0]; i < 159; i++)
        {
            count++;
            for(j = lineIndex; j > ROAD_END_ROW && lineIndex > count; j--)
            {
                if(!imageInput[j][i])
                {
                    imageOut[lineIndex - count][0] = i;
                    imageOut[lineIndex - count][1] = 159;
                    break;
                }
            }
        }
        break;

    }
}
