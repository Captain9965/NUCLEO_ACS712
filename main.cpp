#include "mbed.h"

AnalogIn voltage(A0,5);     //V ref is 5V
float current_value, voltage_reading;
int offset_voltage= 2540;   // zero voltage average
int sensitivity=100;        // sensitivity im mV for the 20A ACS712 module

int main(void)
{
    while(1)
    {
      voltage_reading= voltage.read_voltage()*(0.660/0.666);  // correcting factor due to the ratio of resistors used.
      current_value=(((voltage_reading*1000)-offset_voltage)/sensitivity);

  
      printf("Voltage from module: %.2f\t\tCurrent reading: %.2f \n", voltage_reading,current_value);
      ThisThread::sleep_for(500ms);                         // sampling time
    }
}