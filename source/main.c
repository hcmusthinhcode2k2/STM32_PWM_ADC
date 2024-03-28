#include <stm32f103c8t6.h>
#include <cortex_m3.h>
#include <gpio.h>
#include <bitband.h>

#ifndef BIT7
  #define BIT0          (0x01 << 0)
  #define BIT1          (0x01 << 1)
  #define BIT2          (0x01 << 2)
  #define BIT3          (0x01 << 3)
  #define BIT4          (0x01 << 4)
  #define BIT5          (0x01 << 5)
  #define BIT6          (0x01 << 6)
  #define BIT7          (0x01 << 7)
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef BIT15
  #define BIT8          (0x0001 << 8)
  #define BIT9          (0x0001 << 9)
  #define BIT10         (0x0001 << 10)
  #define BIT11         (0x0001 << 11)
  #define BIT12         (0x0001 << 12)
  #define BIT13         (0x0001 << 13)
  #define BIT14         (0x0001 << 14)
  #define BIT15         (0x0001 << 15)
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
#ifndef BIT31
  #define BIT16         (0x000001 << 16)
  #define BIT17         (0x000001 << 17)
  #define BIT18         (0x000001 << 18)
  #define BIT19         (0x000001 << 19)
  #define BIT20         (0x000001 << 20)
  #define BIT21         (0x000001 << 21)
  #define BIT22         (0x000001 << 22)
  #define BIT23         (0x000001 << 23)

  #define BIT24         (0x00000001 << 24)
  #define BIT25         (0x00000001 << 25)
  #define BIT26         (0x00000001 << 26)
  #define BIT27         (0x00000001 << 27)
  #define BIT28         (0x00000001 << 28)
  #define BIT29         (0x00000001 << 29)
  #define BIT30         (0x00000001 << 30)
  #define BIT31         (0x00000001 << 31)
#endif

struct
{
  unsigned char PWMvalue;  //3 bit low is used 
  unsigned char Index;
} Led={.PWMvalue=0x05,.Index=0};

void SysTick_Handler()
{ 
   if (Led.Index == 0)
   {
      GPIOB.ODR.BITS.b12 = !!(Led.PWMvalue & BIT0);
      STK.LOAD = 8000;   //1ms
      Led.Index = 1;
   }
   else if (Led.Index == 1)
   {
      GPIOB.ODR.BITS.b12 = !!(Led.PWMvalue & BIT1);
      STK.LOAD = 16000;   //2ms
      Led.Index = 2;
   }
   else if (Led.Index == 2)
   {
        GPIOB.ODR.BITS.b12 = !!(Led.PWMvalue & BIT2);
        STK.LOAD = 32000;  //4ms
        Led.Index = 0;
   }
   STK.CTRL.REG = BIT2 | BIT1;
   STK.VALUE = 0;
   STK.CTRL.REG = BIT2 | BIT1 | BIT0;
 
}
void main()
{
     *((unsigned long*)(0x40021000 + 0x18)) |= 0x08;
    GPIO_Mode(&GPIOB,BIT12,GPIO_MODE_OUTPUT_PUSHPULL_50MHz);

    STK.LOAD       = 8000  ; //1ms (clock 8M/1000)
    STK.VALUE      = 8000;
    STK.CTRL.REG = BIT2 | BIT1 | BIT0 ;
    while(1)
    {
        
    }
}