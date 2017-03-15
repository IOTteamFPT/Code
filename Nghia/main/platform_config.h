/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H


/* Define the STM32F10x hardware depending on the used evaluation board */

  #define SPIz                   SPI1
  #define SPIz_CLK               RCC_APB2Periph_SPI1
  #define SPIz_GPIO              GPIOA
  #define SPIz_GPIO_CLK          RCC_APB2Periph_GPIOA  
  #define SPIz_PIN_SCK           GPIO_Pin_13
  #define SPIz_PIN_MISO          GPIO_Pin_14
  #define SPIz_PIN_MOSI          GPIO_Pin_15
/*
  #define SPI                    SPI2
  #define SPIz_CLK                RCC_APB1Periph_SPI2
  #define SPIz_GPIO               GPIOB
  #define SPIz_GPIO_CLK           RCC_APB2Periph_GPIOB 
  #define SPIz_PIN_SCK            GPIO_Pin_13
  #define SPIz_PIN_MISO           GPIO_Pin_14
  #define SPIz_PIN_MOSI           GPIO_Pin_15 

*/

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */
