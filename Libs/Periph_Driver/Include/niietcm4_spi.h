/**
  ******************************************************************************
  * @file    niietcm4_spi.h
  *
  * @brief   Файл содержит все прототипы функций для SPI
  *
  * @author  Сергей С.Скляров (kirra), sergey.s.sklyarov@gmail.com
  * @date    17.02.2017
  *
  ******************************************************************************
  * @attention
  *
  * ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ ПРЕДОСТАВЛЯЕТСЯ «КАК ЕСТЬ», БЕЗ КАКИХ-ЛИБО
  * ГАРАНТИЙ, ЯВНО ВЫРАЖЕННЫХ ИЛИ ПОДРАЗУМЕВАЕМЫХ, ВКЛЮЧАЯ ГАРАНТИИ ТОВАРНОЙ
  * ПРИГОДНОСТИ, СООТВЕТСТВИЯ ПО ЕГО КОНКРЕТНОМУ НАЗНАЧЕНИЮ И ОТСУТСТВИЯ
  * НАРУШЕНИЙ, НО НЕ ОГРАНИЧИВАЯСЬ ИМИ. ДАННОЕ ПРОГРАММНОЕ ОБЕСПЕЧЕНИЕ
  * ПРЕДНАЗНАЧЕНО ДЛЯ ОЗНАКОМИТЕЛЬНЫХ ЦЕЛЕЙ И НАПРАВЛЕНО ТОЛЬКО НА
  * ПРЕДОСТАВЛЕНИЕ ДОПОЛНИТЕЛЬНОЙ ИНФОРМАЦИИ О ПРОДУКТЕ, С ЦЕЛЬЮ СОХРАНИТЬ ВРЕМЯ
  * ПОТРЕБИТЕЛЮ. НИ В КАКОМ СЛУЧАЕ АВТОРЫ ИЛИ ПРАВООБЛАДАТЕЛИ НЕ НЕСУТ
  * ОТВЕТСТВЕННОСТИ ПО КАКИМ-ЛИБО ИСКАМ, ЗА ПРЯМОЙ ИЛИ КОСВЕННЫЙ УЩЕРБ, ИЛИ
  * ПО ИНЫМ ТРЕБОВАНИЯМ, ВОЗНИКШИМ ИЗ-ЗА ИСПОЛЬЗОВАНИЯ ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ
  * ИЛИ ИНЫХ ДЕЙСТВИЙ С ПРОГРАММНЫМ ОБЕСПЕЧЕНИЕМ.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __NIIETCM4_SPI_H
#define __NIIETCM4_SPI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "niietcm4.h"

/** @addtogroup Peripheral
  * @{
  */

/** @addtogroup SPI
  * @{
  */

/** @defgroup SPI_Exported_Types Типы
  * @{
  */

/**
  * @brief  Выбор источника тактирования для SPI
  */

typedef enum
{
	SPI_Select_SystemClock, /*!< на модуль SPI подается системная частота. */
	SPI_Select_Osc,         /*!< на модуль SPI подается частота осцилятора. */
	SPI_Select_USBClock,    /*!< на модуль SPI подается частота контроллера USB (60 МГц). */
	SPI_Select_InputGPIO    /*!< вход GPIO */
} SPI_SelectSysClk_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref SPI_SysClk_TypeDef.
  */

#define IS_SPI_SYSCLK(CLK_SOURCE)           (((CLK_SOURCE) == SPI_Select_SystemClock) || \
                                             ((CLK_SOURCE) == SPI_Select_Osc)         || \
                                             ((CLK_SOURCE) == SPI_Select_USBClock)    || \
											 ((CLK_SOURCE) == SPI_Select_InputGPIO))

/**
  * @brief  Бит включения тактового сигнала
  */
typedef enum
{
	SPI_Clk_Disable,            /*!< Тактовый сигнал SPI выключен. */
	SPI_Clk_Enable              /*!< Тактовый сигнал SPI включен. */
} SPI_SysClkStatus_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref SPI_SysClkEn_TypeDef.
  */

#define IS_SPI_CLKEN(EN)                    (((EN) == SPI_Clk_Disable) || \
                                             ((EN) == SPI_Clk_Enable))

/**
  * @brief  Бит включения делителя
  */

typedef enum
{
	SPI_SysClkDiv_SysClk,         /*!< Частота тактового сигнала равна системной частоте */
	SPI_SysClkDiv_DIVSPI          /*!< Частота тактового сигнала определяется по формуле
	                             Fsys = Fosc/(2 *(DIV_SPI) + 1) */
} SPI_SysClkDiv_TypeDef;

/**
  * @brief Макрос проверки аргументов типа @ref SPI_SysClkDiv_TypeDef.
  */

#define IS_SPI_CLKDIV(DIV)                  (((DIV) == SPI_SysClkDiv_SysClk) || \
                                             ((DIV) == SPI_SysClkDiv_DIVSPI))

typedef struct
{
	SPI_SelectSysClk_TypeDef   SPI_SelectClk;     /* <!Выбор источника тактирования для SPI */
	SPI_SysClkDiv_TypeDef      SPI_ClkDiv;        /* <!Бит включения делителя */
	SPI_SysClkStatus_TypeDef   SPI_SysClkStatus;  /* <!Бит включения тактового сигнала */
	uint32_t                   SPI_DIV_SPI;       /* <!Коэффициент деления делителя системной частоты SPI */
} SPI_ClkInit_TypeDef;

/**
  * @brief Макрос проверки аргументов коэффициента деления делителя системной частоты SPI.
  */
#define IS_SPI_SYS_DIV(DIVIDER)       (((DIVIDER) <= 0x003F) && \
                                       ((DIVIDER) >= 0x0001))

/**
  * @brief  Режим работы SPI
  */

typedef enum
{
    SPI_ModeMaster,       /*!< модуль SPI в режиме Slave. */
    SPI_ModeSlave         /*!< модуль SPI в режиме Master. */
} SPI_Mode_Typedef;

/**
  * @brief Макрос проверки аргументов типа @ref SPI_Mode_Typedef.
  */

#define IS_SPI_MODE(MODE)                  (((MODE) == SPI_ModeMaster) || \
                                            ((MODE) == SPI_ModeSlave))


/**
  * @brief  Полярность тактового сигнала
  */

typedef enum
{
    SPI_SPO_Low,            /*!< линия SPI_CLK в низком уровне. */
    SPI_SPO_High            /*!< линия SPI_CLK в высоком уровне. */
} SPI_SPO_Typedef;

/**
  * @brief Макрос проверки аргументов типа @ref SPI_SPO_Typedef.
  */

#define IS_SPI_SPO(LEVEL)                   (((LEVEL) == SPI_SPO_Low) || \
                                             ((LEVEL) == SPI_SPO_High))

/**
  * @brief  Фаза тактового сигнала
  */

typedef enum
{
    SPI_SPH_1Edge,          /*!< выставление данных по переднему фронту SPI_CLK. */
    SPI_SPH_2Edge           /*!< выставление данных по заднему фронту SPI_CLK. */
} SPI_SPH_Typedef;

/**
  * @brief Макрос проверки аргументов типа @ref SPI_SPH_Typedef.
  */

#define IS_SPI_SPH(PHASE)                   (((PHASE) == SPI_SPH_1Edge) || \
                                             ((PHASE) == SPI_SPH_2Edge))

/**
  * @brief  Протокол обмена SPI
  */

typedef enum
{
    SPI_FRF_SPI_Motorola,   /*!< Протокол SPI Motorola. */
    SPI_FRF_SSI_TI,         /*!< Протокол SSI Texas Instruments. */
    SPI_FRF_Microwire       /*!< Протокол Microwire. */
} SPI_FRF_Typedef;

/**
  * @brief Макрос проверки аргументов типа @ref SPI_FRF_Typedef.
  */

#define IS_SPI_FRF(FORMAT)                  (((FORMAT) == SPI_FRF_SPI_Motorola) || \
                                             ((FORMAT) == SPI_FRF_SSI_TI)       || \
                                             ((FORMAT) == SPI_FRF_Microwire))

/**
  * @brief  Запрет на передачу данных в режиме slave
  */

typedef enum
{
    SPI_TX_Slave_Enable,    /*!< разрешена передача данных с вывода SPI_TXD в режиме slave. */
    SPI_TX_Slave_Disable,   /*!< запрет на передачу с вывода SPI_TXD в режиме slave. */
} SPI_TX_Slave_Typedef;

/**
  * @brief Макрос проверки аргументов типа @ref SPI_TX_Slave_Typedef.
  */

#define IS_SPI_TX_SLAVE(DISABLE_DATA)        (((DISABLE_DATA) == SPI_TX_Slave_Enable) || \
                                              ((DISABLE_DATA) == SPI_TX_Slave_Disable))

typedef struct
{
   uint32_t SPI_SCR;                        /*!< Коэффициент деления второго делителя.
                                                 Может принимать значения 00h до FFh.*/
   uint32_t SPI_CPSDVSR;                    /*!< Коэффициент деления первого делителя.
                                                 Может принимать четные значения от 02h до FEh */
   SPI_Mode_Typedef SPI_Mode;               /*!< Бит выбора режима работы (Master или Slave). */
   uint32_t SPI_WordLength;                 /*!< Размер слова данных */
   SPI_SPH_Typedef SPI_SPH;                 /*!< Фаза сигнала SSPCLKOUT (только для протокола обмена SPI) */
   SPI_SPO_Typedef SPI_SPO;                 /*!< Полярность сигнала SSPCLKOUT (только для протокола обмена SPI) */
   SPI_FRF_Typedef SPI_FRF;                 /*!< Поле выбора протокола обмена информацией */
   SPI_TX_Slave_Typedef SPI_TX_Slave;       /*!< Бит запрета передачи данных.
                                                 В режиме мастера значение бита игнорируется */
} SPI_Init_TypeDef;

/**
  * @brief Макрос проверки аргументов коэффициента деления первого делителя.
  */

#define IS_SPI_SPEED_DIVIDER(DIVIDER)      (((DIVIDER) <= 0x00FE) && \
                                            ((DIVIDER) >= 0x0002) && \
                                            (((DIVIDER) & 0x0001) == 0))

/**
  * @brief Макрос проверки аргументов коэффициента деления второго делителя.
  */

#define IS_SPI_SPEED_FACTOR(DIVIDER)       ((DIVIDER) <= 0x00FF)

#define SPI_WordLength4b                   ((uint32_t)0x00000003)
#define SPI_WordLength5b                   ((uint32_t)0x00000004)
#define SPI_WordLength6b                   ((uint32_t)0x00000005)
#define SPI_WordLength7b                   ((uint32_t)0x00000006)
#define SPI_WordLength8b                   ((uint32_t)0x00000007)
#define SPI_WordLength9b                   ((uint32_t)0x00000008)
#define SPI_WordLength10b                  ((uint32_t)0x00000009)
#define SPI_WordLength11b                  ((uint32_t)0x0000000A)
#define SPI_WordLength12b                  ((uint32_t)0x0000000B)
#define SPI_WordLength13b                  ((uint32_t)0x0000000C)
#define SPI_WordLength14b                  ((uint32_t)0x0000000D)
#define SPI_WordLength15b                  ((uint32_t)0x0000000E)
#define SPI_WordLength16b                  ((uint32_t)0x0000000F)

/**
  * @brief Макрос проверки размера слова данных.
  */

#define IS_SPI_WORD_LENGTH(LENGTH)         (((LENGTH) == SPI_WordLength4b)  || \
                                            ((LENGTH) == SPI_WordLength5b)  || \
                                            ((LENGTH) == SPI_WordLength6b)  || \
                                            ((LENGTH) == SPI_WordLength7b)  || \
                                            ((LENGTH) == SPI_WordLength8b)  || \
                                            ((LENGTH) == SPI_WordLength9b)  || \
                                            ((LENGTH) == SPI_WordLength10b) || \
                                            ((LENGTH) == SPI_WordLength11b) || \
                                            ((LENGTH) == SPI_WordLength12b) || \
                                            ((LENGTH) == SPI_WordLength13b) || \
                                            ((LENGTH) == SPI_WordLength14b) || \
                                            ((LENGTH) == SPI_WordLength15b) || \
                                            ((LENGTH) == SPI_WordLength16b))

/**
  * @}
  */

/** @defgroup SPI_Exported_Constants Константы
  * @{
  */

/** @defgroup SPI_Exported_Constants_Flag Флаги работы SPI
  * @{
  */

#define SPI_Flag_TFE                        ((uint32_t)0x00000001)      /** !< Флаг пустоты буфера FIFO передатчика */
#define SPI_Flag_TNF                        ((uint32_t)0x00000002)      /** !< Индикатор того, что буфера FIFO передатчика не заполнен */
#define SPI_Flag_RNE                        ((uint32_t)0x00000004)      /** !< Индикатор того, что буфер FIFO приемника не пуст */
#define SPI_Flag_RFF                        ((uint32_t)0x00000008)      /** !< Флаг заполнения буфера FIFO приемника */
#define SPI_Flag_BSY                        ((uint32_t)0x00000010)      /** !< Флаг активности */
#define SPI_Flag_All                        ((uint32_t)0x0000001F)      /** !< Все флаги выбраны*/

/**
  * @brief Макрос проверки флагов работы SPI.
  */

#define IS_SPI_FLAG(FLAG)                   (((FLAG) == SPI_FLAG_TFE) || \
                                             ((FLAG) == SPI_FLAG_TNF) || \
                                             ((FLAG) == SPI_FLAG_RNE) || \
                                             ((FLAG) == SPI_FLAG_RFF) || \
                                             ((FLAG) == SPI_FLAG_BSY) || \
                                             ((FLAG) == SPI_Flag_All))

/**
  * @}
  */

/** @defgroup SPI_Exported_Constants_ITSource Источники прерываний SPI
  * @{
  */

#define SPI_IT_ROR                          ((uint32_t)0x00000001)  /** <! Переполнение буфера приемника */
#define SPI_IT_RT                           ((uint32_t)0x00000002)  /** <! Таймаут приема данных */
#define SPI_IT_RX                           ((uint32_t)0x00000004)  /** <! Буфер приемника заполнен наполовину */
#define SPI_IT_TX                           ((uint32_t)0x00000008)  /** <! Буфер передатчика опустошен наполовину*/

#define SPI_IT_MASK                          (SPI_IT_ROR | SPI_IT_RT |\
                                              SPI_IT_RX | SPI_IT_TX)

#define IS_SPI_CONFIG_IT(IT)                 ((IT) & (~SPI_IT_MASK) == 0)

#define IS_SPI_RESET_IT(IT)                 (((IT) == SPI_IT_RT) || \
                                             ((IT) == SPI_IT_ROR))
/**
  * @}
  */

#define SPI_DMA_RXE                         ((uint32_t)0x00000000)
#define SPI_DMA_TXE                         ((uint32_t)0x00000001)

#define IS_SPI_DMAREQ(DMAREQ)               (((DMAREQ) == SPI_DMA_RXE) || \
                                             ((DMAREQ) == SPI_DMA_TXE))

/**
  * @}
  */

/** @defgroup SPI_Exported_Functions Функции
  * @{
  */
void SPI_ClkInit(NT_SPI_TypeDef* SPIx, const SPI_ClkInit_TypeDef* SPI_ClkInitStruct);
void SPI_StructClkInit(SPI_ClkInit_TypeDef* SPI_ClkInitStruct);

void SPI_DeInit(NT_SPI_TypeDef* SPIx);
void SPI_Init(NT_SPI_TypeDef* SPIx, const SPI_Init_TypeDef* SPI_InitStruct);
void SPI_StructInit(SPI_Init_TypeDef* SPI_InitStruct);
void SPI_Cmd(NT_SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_ITConfig(NT_SPI_TypeDef* SPIx, uint32_t SPI_IT, FunctionalState NewState);
FlagStatus SPI_GetITStatus(NT_SPI_TypeDef* SPIx, uint32_t SPI_IT);
FlagStatus SPI_GetITStatusMasked(NT_SPI_TypeDef* SPIx, uint32_t SPI_IT);
void SPI_ClearITPendingBit(NT_SPI_TypeDef* SPIx, uint32_t SPI_IT);

void SPI_SendData(NT_SPI_TypeDef* SPIx, uint32_t Data);
uint16_t SPI_ReceiveData(NT_SPI_TypeDef* SPIx);

void SPI_DMACmd(NT_SPI_TypeDef* SPIx, uint32_t SPI_DMAReq, FunctionalState NewState);

FlagStatus SPI_GetFlagStatus(NT_SPI_TypeDef* SPIx, uint32_t SPI_FLAG);

/** @} */ /* End of group SPI_Exported_Functions */


#ifdef __cplusplus
}
#endif

#endif /* __NIIETCM4_SPI_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ END OF FILE ************************/
