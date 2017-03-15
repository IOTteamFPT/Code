#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "stm32f10x_rcc.h"
#include "sys_cfg.h"
#include "system.h"
#include "stm32f10x_spi.h"
#include "stm32f10x_gpio.h"
#include "RF24.h"
#include "platform_config.h"

/* Private define ------------------------------------------------------------*/
#define BufferSize 32
#define SEND_LIMIT 3

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
const uint64_t pipe = 0xE8E8F0F0E1LL
int val;
const char mess[] = "Hello Raspberry Pi"
SPI_InitTypeDef   SPI_InitStructure;

uint8_t SPIz_Buffer_Tx[BufferSize] = {0x1, 0x2, 0x4, 0x54, 0x55, 0x56, 0x57,
                                      0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E,
                                      0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65,
                                      0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C,
                                      0x6D, 0x6E, 0x6F, 0x70};

__IO uint8_t TxIdx = 0, RxIdx = 0, k = 0;

/* Private functions ---------------------------------------------------------*/
void RCC_Configuration(void);
void SPIx_Init();
void setup_gpio();
RF24 radio(GPIO_Pin_13,GPIO_Pin_14);


int main(void)
{
		  /* System clocks configuration ---------------------------------------------*/
		  RCC_Configuration();
		  /* SPI & GPIO configuration  ---------------------------------------------*/
		  SPIx_Init();
	          setup_gpio();

	//===========================Module NRF24============================
    // setup
	  radio.begin();                                 
	  radio.setPALevel(busdn_PA_MAX);      // Dung lượng tối đa
	  radio.setChannel(0x76);    
	  radio.enableDynamicPayloads(); 
	  radio.powerUp(); 
	  radio.openWritingPipe(0xF0F0F0F0E1LL);      // Địa chỉ phát phải giống với địa chỉ thu của Raspberry
	  radio.openReadingPipe(1, pipe); 
	  radio.startListening();      // Bắt đầu thu

		  while (1)
		  {
		  
		 char receivedMessage[32] = {0};
		if (radio.available()){
		radio.read(receivedMessage, sizeof(receivedMessage));
		if(receivedMessage==1)
		{
		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_SET);
		}
                else
		{
    		GPIO_WriteBit(GPIOC,GPIO_Pin_13,Bit_RESET);
		}
    		
		radio.stopListening();
		radio.write(mess, sizeof(mess));
		radio.startListening();
		delay(1000);
		  }



}
}
void setup_gpio(){
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
	  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_All ;
	  GPIO_Init(GPIOC, &GPIO_InitStructure);
}
void RCC_Configuration(void)
{
  /* PCLK2 = HCLK/2 */
  RCC_PCLK2Config(RCC_HCLK_Div2);

  /* Enable GPIO clock for SPIz */
  RCC_APB2PeriphClockCmd(SPIz_GPIO_CLK | RCC_APB2Periph_AFIO, ENABLE);

  /* Enable SPIz Periph clock */
  RCC_APB1PeriphClockCmd(SPIz_CLK, ENABLE);
}


void SPIx_Init()
{
      


      /* SPIy Config -------------------------------------------------------------*/
      SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
      SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
      SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
      SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
      SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
      SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
      SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64;
      SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
      SPI_InitStructure.SPI_CRCPolynomial = 7;
      SPI_Init(SPIz, &SPI_InitStructure);

      /* Enable SPIz */
      SPI_Cmd(SPIz, ENABLE);

      /* Transfer procedure */
      while (TxIdx < SEND_LIMIT)
      {
        /* Wait for SPIy Tx buffer empty */
        while (SPI_I2S_GetFlagStatus(SPIz, SPI_I2S_FLAG_TXE) == RESET);
        /* Send SPIz data */
        SPI_I2S_SendData(SPIz, SPIz_Buffer_Tx[TxIdx++]);

      }
	   /* GPIO configuration ------------------------------------------------------*/

      GPIO_InitTypeDef GPIO_InitStructure;

      /* Configure SPIz pins: SCK, MISO and MOSI ---------------------------------*/
      GPIO_InitStructure.GPIO_Pin = SPIz_PIN_SCK | SPIz_PIN_MOSI;
      /* Configure SCK and MOSI pins as Alternate Function Push Pull */
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;

      /**** ADDED THIS TO WORK ****/
      GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
      **/**** ADDED THIS TO WORK ****/**


      GPIO_Init(SPIz_GPIO, &GPIO_InitStructure);


      GPIO_InitStructure.GPIO_Pin = SPIz_PIN_MISO;
      /* Configure MISO pin as Input Floating  */
      GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
      GPIO_Init(SPIz_GPIO, &GPIO_InitStructure);

}
