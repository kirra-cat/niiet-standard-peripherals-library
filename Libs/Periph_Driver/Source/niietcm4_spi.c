/**
  ******************************************************************************
  * @file    niietcm4_spi.c
  *
  * @brief   Файл содержит реализацию всех функции для работы с модулями SPI
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

#include "niietcm4_spi.h"

void SPI_DeInit(NT_SPI_TypeDef* SPIx)
{
    RCC_PeriphRst_TypeDef SpiRst;
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    if (SPIx == NT_SPI0)
    {
        SpiRst = RCC_PeriphRst_SPI0;
    }
    else if (SPIx == NT_SPI1)
    {
        SpiRst = RCC_PeriphRst_SPI1;
    }
    else if (SPIx == NT_SPI2)
    {
        SpiRst = RCC_PeriphRst_SPI2;
    }
    else
    {
        SpiRst = RCC_PeriphRst_SPI3;
    }

    SPIx->SPI_ICR = SPI_IT_ROR | SPI_IT_RT;

    RCC_PeriphRstCmd(SpiRst, DISABLE);
    RCC_PeriphRstCmd(SpiRst, ENABLE);
}

void SPI_Init(NT_SPI_TypeDef* SPIx, const SPI_Init_TypeDef* SPI_InitStruct)
{
    assert_param(IS_SPI_SPEED_DIVIDER(SPI_InitStruct->SPI_CPSDVSR));
    assert_param(IS_SPI_SPEED_FACTOR(SPI_InitStruct->SPI_SCR));
    assert_param(IS_SPI_MODE(SPI_InitStruct->SPI_Mode));
    assert_param(IS_SPI_WORD_LENGTH(SPI_InitStruct->SPI_WordLength));
    assert_param(IS_SPI_SPH(SPI_InitStruct->SPI_SPH));
    assert_param(IS_SPI_SPO(SPI_InitStruct->SPI_SPO));
    assert_param(IS_SPI_TX_SLAVE(SPI_InitStruct->SPI_TX_Slave));

    SPIx->SPI_CPSR = (uint32_t)SPI_InitStruct->SPI_CPSDVSR;

    SPIx->SPI_CR0_bit.DSS = (uint32_t)SPI_InitStruct->SPI_WordLength;
    SPIx->SPI_CR0_bit.FRF = (uint32_t)SPI_InitStruct->SPI_FRF;
    SPIx->SPI_CR0_bit.SPH = (uint32_t)SPI_InitStruct->SPI_SPH;
    SPIx->SPI_CR0_bit.SPO = (uint32_t)SPI_InitStruct->SPI_SPO;

    SPIx->SPI_CR1_bit.MS = SPI_InitStruct->SPI_Mode;
    SPIx->SPI_CR1_bit.SOD = SPI_InitStruct->SPI_TX_Slave;
}

void SPI_StructInit(SPI_Init_TypeDef* SPI_InitStruct)
{
    SPI_InitStruct->SPI_CPSDVSR = 2;
    SPI_InitStruct->SPI_SCR = 0;
    SPI_InitStruct->SPI_Mode = SPI_ModeMaster;
    SPI_InitStruct->SPI_WordLength = SPI_WordLength8b;
    SPI_InitStruct->SPI_SPH = SPI_SPH_1Edge;
    SPI_InitStruct->SPI_SPO = SPI_SPO_Low;
    SPI_InitStruct->SPI_FRF = SPI_FRF_SPI_Motorola;
}

void SPI_Cmd(NT_SPI_TypeDef* SPIx, FunctionalState NewState)
{
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        SPIx->SPI_CR1_bit.SSE = 1;
    }
    else
    {
        SPIx->SPI_CR1_bit.SSE = 0;
    }
}

void SPI_ITConfig(NT_SPI_TypeDef* SPIx, uint32_t SPI_IT, FunctionalState NewState)
{
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_CONFIG_IT(SPI_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        SPIx->SPI_IMSC |= SPI_IT;
    }
    else
    {
        SPIx->SPI_IMSC &= ~SPI_IT;
    }
}

FlagStatus SPI_GetITStatus(NT_SPI_TypeDef* SPIx, uint32_t SPI_IT)
{
    FlagStatus flag_status;

    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_CONFIG_IT(SPI_IT));

    if ((SPIx->SPI_RIS & SPI_IT) == SPI_IT)
    {
        flag_status = Flag_SET;
    }
    else
    {
        flag_status = Flag_CLEAR;
    }

    return (flag_status);

}

FlagStatus SPI_GetITStatusMasked(NT_SPI_TypeDef* SPIx, uint32_t SPI_IT)
{
    FlagStatus flag_status;

    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_CONFIG_IT(SPI_IT));

    if ((SPIx->SPI_MIS & SPI_IT) == SPI_IT)
    {
        flag_status = Flag_SET;
    }
    else
    {
        flag_status = Flag_CLEAR;
    }

    return (flag_status);
}

void SPI_ClearITPendingBit(NT_SPI_TypeDef* SPIx, uint32_t SPI_IT)
{
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_RESET_IT(SPI_IT));

    SPIx->SPI_ICR |= SPI_IT;
}

void SPI_SendData(NT_SPI_TypeDef* SPIx, uint32_t Data)
{
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    SPIx->SPI_DR = Data;
}

uint16_t SPI_ReceiveData(NT_SPI_TypeDef* SPIx)
{
    assert_param(IS_SPI_ALL_PERIPH(SPIx));

    return ((uint16_t) (SPIx->SPI_DR));
}

void SPI_DMACmd(NT_SPI_TypeDef* SPIx, uint32_t SPI_DMAReq, FunctionalState NewState)
{
    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_DMAREQ(SPI_DMAReq));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE)
    {
        SPIx->SPI_DMACR |= SPI_DMAReq;
    }
    else
    {
        SPIx->SPI_DMACR &= (uint16_t)~SPI_DMAReq;
    }
}

FlagStatus SPI_GetFlagStatus(NT_SPI_TypeDef* SPIx, uint32_t SPI_FLAG)
{
    FlagStatus flag_status;

    assert_param(IS_SPI_ALL_PERIPH(SPIx));
    assert_param(IS_SPI_FLAG(SPI_FLAG));

    if ((SPIx->SPI_SR & SPI_FLAG) == SPI_FLAG)
    {
        flag_status = Flag_SET;
    }
    else
    {
        flag_status = Flag_CLEAR;
    }

    return (flag_status);
}

/******************* END OF FILE *******************/
