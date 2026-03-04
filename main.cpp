#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>

//#define PI 3.141592653

//Declarations for encoders & motors
DigitalEncoder TEST_ENC(FEHIO::Pin8);
FEHMotor TEST_MOT(FEHMotor::Motor0,9.0);

void ERCMain()
{
    int x,y;
    LCD.Write("Touch Screen");
    while(!LCD.Touch(&x,&y));
    while(LCD.Touch(&x,&y));
    LCD.Clear();
    while(1)
    {
    TEST_ENC.ResetCounts();
    TEST_MOT.SetPercent(25);
    while(TEST_ENC.Counts() < 312); //318 is expected amount for 1 turn
    
    TEST_MOT.Stop();

    LCD.WriteLine(TEST_ENC.Counts());
    
    Sleep(2.0);
    LCD.Write("Touch to go again");
    while(!LCD.Touch(&x,&y)){};
    }
}