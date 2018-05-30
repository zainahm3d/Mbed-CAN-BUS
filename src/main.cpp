#include "mbed.h"
CAN can1(PA_11, PA_12);
DigitalOut led1(LED1);
char counter = 0;
int main() {
  printf("start\n");

  can1.frequency(250000);
  can1.mode(CAN::Normal);

  CANMessage msg;

  while (1) {
    // if (can1.write(CANMessage(1337, &counter, 1))) {
    //   printf("sent\n");
    // } else {
    //   printf("error\n");
    // }
    // counter++;
    // led1 = !led1;

    if (can1.read(msg)) {
      led1 = !led1;
      printf("%s", "ID ");
      printf("%d", msg.id);
      printf("     ");
      for (int i = 0; i < 8; i++) {
        printf("%d ", msg.data[i]);
      }
      printf("\n");
    }
  }
}
