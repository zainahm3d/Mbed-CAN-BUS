#include "mbed.h"

CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);

#define RPM_ID 218099784

int main() {
  can1.frequency(250000);
  can1.mode(CAN::Normal);

  while (1) {
    CANMessage msg;
    if (can1.read(msg)) {
      led1 = !led1;

      if (msg.id == RPM_ID) {
        int lowByte = msg.data[0];
        int highByte = msg.data[1];
        double rpm = ((highByte * 256) + lowByte);
        printf("%f\n", rpm);
      }
      //
    }
  }
}
