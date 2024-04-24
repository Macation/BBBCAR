/*
 * My_Control_Code.c
  *   ���ԭ���洢��CCU6�еĴ���
 *  Created on: 2024��4��21��
 *      Author: dduu
*/
#include "My_Control_Code.h"

extern key_t Key[];
extern pid_param_t Servo_Loc_PID;           //���λ��ʽPID��Ϻ������
extern pid_param_t Motor_Inc_PID1;          //���1�ٶȻ�PID
extern pid_param_t Motor_Inc_PID2;          //���2�ٶȻ�PID

uint8 cnt=0;
uint8 Mode=0;
char txt_a[30];                         //�ı�
float Motor1_IncPID=0;
float Motor2_IncPID=0;                  //����ٶȻ�
float Motor_DirPId=0;                   //���ת��
volatile sint16 Battery;                //��ص���ADC
volatile float Current_Speed1=0;        //��λm/s
volatile float Current_Speed2=0;
volatile sint16 LPulse;                 //�����������
volatile sint16 YPulse;                 //�ұ���������
int Servo_duty=Servo_Center_Mid;

void Motor_Control(void)
{
    cnt++;  //���ô��ڷ����ж�

    //���Ƶ��ͬ����5ms
    /* ��ȡ������ֵ */
    LPulse = -ENC_GetCounter(ENC4_InPut_P02_8); // ������С��ǰ��Ϊ��ֵ
    YPulse = ENC_GetCounter(ENC2_InPut_P33_7);  // �ҵ����С��ǰ��Ϊ��ֵ

    Current_Speed1=LPulse/1024.0*12.0576/100.0/0.01/1.357;        //��������תһȦ��С���ƶ�30/50*4.95*3.14=9.3258cm
    Current_Speed2=YPulse/1024.0*12.0576/100.0/0.01/1.357;        //

    //ת��PID
//    if(StraightWay_flag)
//    {
//        Motor_DirPId=(float)10*Servo_Loc_error;
//    }
//    else
//    {
//        Motor_DirPId=(float)0.4*Servo_Loc_error;
//    }

    //����
    Motor_DirPId=0.0;

    if(Motor_openFlag==1)
    {
        //�ٶȻ�PID
        Motor1_IncPID+=PidIncCtrl(&Motor_Inc_PID1,(float)(Target_Speed1-Current_Speed1));
        Motor2_IncPID+=PidIncCtrl(&Motor_Inc_PID2,(float)(Target_Speed2-Current_Speed2));
        //ȥ���������
//        if(Motor_duty1 > 0 && Motor_duty1 < 800) Motor_duty1 = 800;
//        if(Motor_duty1 < 0 && Motor_duty1 > -800) Motor_duty1 = -800;
//        if(Motor_duty2 > 0 && Motor_duty2 < 800) Motor_duty2 = 800;
//        if(Motor_duty2 < 0 && Motor_duty2 > -800) Motor_duty2 = -800;
    }
    else if(Motor_openFlag==0)
    {
        //�ٶȻ�PID
        Motor1_IncPID+=PidIncCtrl(&Motor_Inc_PID1,(float)(0-Current_Speed1));
        Motor2_IncPID+=PidIncCtrl(&Motor_Inc_PID2,(float)(0-Current_Speed2));
    }

    //����޷�
    if(Motor1_IncPID > 3000)Motor1_IncPID = 3000;else if(Motor1_IncPID < -3000)Motor1_IncPID = -3000;
    if(Motor_Inc_PID1.out > 3000)Motor_Inc_PID1.out = 3000;else if(Motor_Inc_PID1.out < -3000)Motor_Inc_PID1.out = -3000;

    if(Motor2_IncPID > 3000)Motor2_IncPID = 3000;else if(Motor2_IncPID < -3000)Motor2_IncPID = -3000;
    if(Motor_Inc_PID2.out > 3000)Motor_Inc_PID2.out = 3000;else if(Motor_Inc_PID2.out < -3000)Motor_Inc_PID2.out = -3000;

    //ת��͵�������ںϲ��޷�
    Motor_duty1=(int)Motor1_IncPID-(int)Motor_DirPId;
    Motor_duty2=(int)Motor2_IncPID+(int)Motor_DirPId;
    if(Motor_duty1 > 3000)Motor_duty1 = 3000;else if(Motor_duty1 < 0)Motor_duty1 = 0;
    if(Motor_duty2 > 3000)Motor_duty2 = 3000;else if(Motor_duty2 < 0)Motor_duty2 = 0;
    //�����PWM�ź�
    MotorCtrl(Motor_duty2,Motor_duty1);

    if(cnt>=10)    //ÿ20ms���ڷ���duty��ֵ
    {
        cnt=0;
//        sprintf(txt_a, "{Motor_duty12}%d,%d\r\n", Motor_duty1,Motor_duty2);
//        UART_PutStr(UART0, txt_a);
//        sprintf(txt_a, "{Servo_Loc_error}%d\r\n", Servo_Loc_error);
//        UART_PutStr(UART0, txt_a);
//        sprintf(txt_a, "{Motor_DirPId}%.2f\r\n", Motor_DirPId);
//        UART_PutStr(UART0, txt_a);
//        sprintf(txt_a, "{Cur_S1,Tar_S1}%.2f,%.2f\r\n", Current_Speed1,Target_Speed1);
//        UART_PutStr(UART0, txt_a);
//        sprintf(txt_a, "{Cur_S2,Tar_S2}%.2f,%.2f\r\n", Current_Speed2,Target_Speed2);
//        UART_PutStr(UART0, txt_a);
    }
}

void Servo_Control(void)
{
    //���ƶ��
    float Servo_LocPid;  //�������PID

    Servo_Loc_error=(int)Err_Sum();

//    if(Servo_Loc_error>=10 && Servo_Loc_error<=-10)
//    {
//        Servo_Loc_PID.kp=40;
//    }
//    else
//    {
//        Servo_Loc_PID.kp=20;
//    }

    Servo_LocPid=PidLocCtrl(&Servo_Loc_PID,(float)Servo_Loc_error);   //ʹ��PС��PID
//    Servo_LocPid=PidLocCtrl(&Servo_Loc_PID,(float)Servo_Loc_error)+EKP*Servo_QZ_ERR;

    Servo_duty=(int)(Servo_Center_Mid + Servo_LocPid);

    if (Servo_duty >= Servo_Left_Max)                  //���Ʒ�ֵ
        Servo_duty = Servo_Left_Max;
    else if (Servo_duty <= Servo_Right_Min)            //���Ʒ�ֵ
        Servo_duty = Servo_Right_Min;

    if(Servo_openFlag==1)
    {
        ATOM_PWM_InitConfig(ATOMSERVO1, Servo_duty, 100);  //���Ƶ��Ϊ100HZ����ʼֵΪ1.5ms��ֵ
    }
    else
    {
        ATOM_PWM_InitConfig(ATOMSERVO1, Servo_Center_Mid, 100);  //���Ƶ��Ϊ100HZ����ʼֵΪ1.5ms��ֵ
    }
}

void Camera_Control(void)
{
//    if(++LED1_Time == 50)   //10*50 = 500ms
//    {
//        LED1_Time = 0;
//        LED_Ctrl(LED1,RVS);     // LED��˸ ָʾ��������״̬
//    }

        Cross_Detect();
    //    Right_Down_Find=Find_Right_Down_Point(LCDH-1,0);
    //    if(Right_Down_Find!=0)
    //    {
    //        Mon_change_Right_Line=Monotonicity_Change_Right(Right_Down_Find-5,0);
    //    }
    //    else
    //    {
    //        Mon_change_Right_Line=Monotonicity_Change_Right(LCDH-1,0);
    //    }

        Island_Detect();

        for(int i=LCDH-1;i>=0;i--)
        {
            Middle_Line[i]=(Right_Line[i]+Left_Line[i])/2;
            Bin_Image[i][Left_Line[i]]=0;
            Bin_Image[i][Middle_Line[i]]=0;
            Bin_Image[i][Right_Line[i]]=0;
        }
}

void Key_Control(void)
{
    Key_Check(0,Key,KEY0_Pin);
    Key_Check(1,Key,KEY1_Pin);
    Key_Check(2,Key,KEY2_Pin);

    if(Key[0].keyFlag==1)
    {
        Key[0].keyFlag=0;
        Mode=1;
    }
    else if(Key[1].keyFlag==1)
    {
        Key[1].keyFlag=0;
        Mode=2;
    }
    else if(Key[2].keyFlag==1)
    {
        Key[2].keyFlag=0;
        Mode=3;
    }
}

