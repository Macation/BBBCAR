/*
 * My_UART.c
 *
 *  Created on: 2024��1��15��
 *      Author: dduu
 */
#include "My_UART.h"

char Txt=0;

extern pid_param_t Servo_Loc_PID;
extern pid_param_t Motor_Inc_PID1;  //���1�ٶȻ�PID
extern pid_param_t Motor_Inc_PID2;  //���2�ٶȻ�PID
extern volatile float Target_Speed1; //����Ŀ���ٶ�
extern volatile float Target_Speed2; //�ҵ��Ŀ���ٶ�

void UART_hander(void)
{
    Txt=UART_GetChar(UART1);
    UART_PutChar(UART1, Txt);
    switch(Txt)
    {
        case 'P':Servo_Loc_PID.kp+=0.1;break;
        case 'p':Servo_Loc_PID.kp-=0.1;break;
        case 'I':Servo_Loc_PID.ki+=0.1;break;
        case 'i':Servo_Loc_PID.ki-=0.1;break;
        case 'D':Servo_Loc_PID.kd+=0.1;break;
        case 'd':Servo_Loc_PID.kd-=0.1;break;
        case 'A':Motor_Inc_PID1.kp+=0.1;break;
        case 'a':Motor_Inc_PID1.kp-=0.1;break;
        case 'B':Motor_Inc_PID1.ki+=0.1;break;
        case 'b':Motor_Inc_PID1.ki-=0.1;break;
        case 'C':Motor_Inc_PID1.kd+=0.1;break;
        case 'c':Motor_Inc_PID1.kd-=0.1;break;
        case 'E':Motor_Inc_PID2.kp+=0.1;break;
        case 'e':Motor_Inc_PID2.kp-=0.1;break;
        case 'F':Motor_Inc_PID2.ki+=0.1;break;
        case 'f':Motor_Inc_PID2.ki-=0.1;break;
        case 'G':Motor_Inc_PID2.kd+=0.1;break;
        case 'g':Motor_Inc_PID2.kd-=0.1;break;
        case 'T':Target_Speed1+=0.1;break;
        case 't':Target_Speed1-=0.1;break;
        case 'L':Target_Speed2+=0.1;break;
        case 'l':Target_Speed2-=0.1;break;
        default:break;
    }

}










