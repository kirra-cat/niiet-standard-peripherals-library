	.syntax	unified
	.arch	armv7e-m

	.section .stack
	.align	3
#ifdef __STACK_SIZE
	.equ	Stack_Size, __STACK_SIZE
#else
	.equ	Stack_Size, 0xc00
#endif
	.globl	__StackTop
	.globl	__StackLimit
__StackLimit:
	.space	Stack_Size
	.size	__StackLimit, . - __StackLimit
__StackTop:
	.size	__StackTop, . - __StackTop

	.section .heap
	.align	3
#ifdef __HEAP_SIZE
	.equ	Heap_Size, __HEAP_SIZE
#else
	.equ	Heap_Size, 0
#endif
	.globl	__HeapBase
	.globl	__HeapLimit
__HeapBase:
	.if	Heap_Size
	.space	Heap_Size
	.endif
	.size	__HeapBase, . - __HeapBase
__HeapLimit:
	.size	__HeapLimit, . - __HeapLimit

	.section .isr_vector
	.align	2
	.globl	__isr_vector
__isr_vector:
	.long	__StackTop            /* Top of Stack */
	.long	Reset_Handler         /* Reset Handler */
	.long	NMI_Handler           /* NMI Handler */
	.long	HardFault_Handler     /* Hard Fault Handler */
	.long	MemManage_Handler     /* MPU Fault Handler */
	.long	BusFault_Handler      /* Bus Fault Handler */
	.long	UsageFault_Handler    /* Usage Fault Handler */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	0                     /* Reserved */
	.long	SVC_Handler           /* SVCall Handler */
	.long	DebugMon_Handler      /* Debug Monitor Handler */
	.long	0                     /* Reserved */
	.long	PendSV_Handler        /* PendSV Handler */
	.long	SysTick_Handler       /* SysTick Handler */
	/* External interrupts */
	.long   WWDG_IRQHandler
    .long   I2C0_IRQHandler
    .long   I2C1_IRQHandler
    .long   TIM0_IRQHandler
    .long   TIM1_IRQHandler
    .long   TIM2_IRQHandler
    .long   DMA_Stream0_IRQHandler
    .long   DMA_Stream1_IRQHandler
    .long   DMA_Stream2_IRQHandler
    .long   DMA_Stream3_IRQHandler
    .long   DMA_Stream4_IRQHandler
    .long   DMA_Stream5_IRQHandler
    .long   DMA_Stream6_IRQHandler
    .long   DMA_Stream7_IRQHandler
    .long   DMA_Stream8_IRQHandler
    .long   DMA_Stream9_IRQHandler
    .long   DMA_Stream10_IRQHandler
    .long   DMA_Stream11_IRQHandler
    .long   DMA_Stream12_IRQHandler
    .long   DMA_Stream13_IRQHandler
    .long   DMA_Stream14_IRQHandler
    .long   DMA_Stream15_IRQHandler
    .long   DMA_Stream16_IRQHandler
    .long   DMA_Stream17_IRQHandler
    .long   DMA_Stream18_IRQHandler
    .long   DMA_Stream19_IRQHandler
    .long   DMA_Stream20_IRQHandler
    .long   DMA_Stream21_IRQHandler
    .long   DMA_Stream22_IRQHandler
    .long   DMA_Stream23_IRQHandler
    .long   USART0_MX_IRQHandler
    .long   USART0_RX_IRQHandler
    .long   USART0_TX_IRQHandler
    .long   USART0_RT_IRQHandler
    .long   USART0_E_IRQHandler
    .long   USART0_IRQHandler
    .long   USART1_MX_IRQHandler
    .long   USART1_RX_IRQHandler
    .long   USART1_TX_IRQHandler
    .long   USART1_RT_IRQHandler
    .long   USART1_E_IRQHandler
    .long   USART1_IRQHandler
    .long   USART2_MX_IRQHandler
    .long   USART2_RX_IRQHandler
    .long   USART2_TX_IRQHandler
    .long   USART2_RT_IRQHandler
    .long   USART2_E_IRQHandler
    .long   USART2_IRQHandler
    .long   USART3_MX_IRQHandler
    .long   USART3_RX_IRQHandler
    .long   USART3_TX_IRQHandler
    .long   USART3_RT_IRQHandler
    .long   USART3_E_IRQHandler
    .long   USART3_IRQHandler
    .long   PWM0_IRQHandler
    .long   PWM0_HD_IRQHandler
    .long   PWM0_TZ_IRQHandler
    .long   PWM1_IRQHandler
    .long   PWM1_HD_IRQHandler
    .long   PWM1_TZ_IRQHandler
    .long   PWM2_IRQHandler
    .long   PWM2_HD_IRQHandler
    .long   PWM2_TZ_IRQHandler
    .long   PWM3_IRQHandler
    .long   PWM3_HD_IRQHandler
    .long   PWM3_TZ_IRQHandler
    .long   PWM4_IRQHandler
    .long   PWM4_HD_IRQHandler
    .long   PWM4_TZ_IRQHandler
    .long   PWM5_IRQHandler
    .long   PWM5_HD_IRQHandler
    .long   PWM5_TZ_IRQHandler
    .long   PWM6_IRQHandler
    .long   PWM6_HD_IRQHandler
    .long   PWM6_TZ_IRQHandler
    .long   PWM7_IRQHandler
    .long   PWM7_HD_IRQHandler
    .long   PWM7_TZ_IRQHandler
    .long   PWM8_IRQHandler
    .long   PWM8_HD_IRQHandler
    .long   PWM8_TZ_IRQHandler
    .long   ADC_SEQ0_IRQHandler
    .long   ADC_SEQ1_IRQHandler
    .long   ADC_SEQ2_IRQHandler
    .long   ADC_SEQ3_IRQHandler
    .long   ADC_SEQ4_IRQHandler
    .long   ADC_SEQ5_IRQHandler
    .long   ADC_SEQ6_IRQHandler
    .long   ADC_SEQ7_IRQHandler
    .long   ADC_CompInt_IRQHandler
    .long   CAP0_IRQHandler
    .long   CAP1_IRQHandler
    .long   CAP2_IRQHandler
    .long   CAP3_IRQHandler
    .long   CAP4_IRQHandler
    .long   CAP5_IRQHandler
    .long   QEP0_IRQHandler
    .long   QEP1_IRQHandler
    .long   BootFlash_IRQHandler
    .long   CMP0_IRQHandler
    .long   CMP1_IRQHandler
    .long   CMP2_IRQHandler
    .long   SPI0_IRQHandler
    .long   SPI1_IRQHandler
    .long   SPI2_IRQHandler
    .long   SPI3_IRQHandler
    .long   UserFlash_IRQHandler
    .long   GPIOA_IRQHandler
    .long   GPIOB_IRQHandler
    .long   GPIOC_IRQHandler
    .long   GPIOD_IRQHandler
    .long   GPIOE_IRQHandler
    .long   GPIOF_IRQHandler
    .long   GPIOG_IRQHandler
    .long   GPIOH_IRQHandler
    .long   Ethernet_IRQHandler
    .long   CAN0_IRQHandler
    .long   CAN1_IRQHandler
    .long   CAN2_IRQHandler
    .long   CAN3_IRQHandler
    .long   CAN4_IRQHandler
    .long   CAN5_IRQHandler
    .long   CAN6_IRQHandler
    .long   CAN7_IRQHandler
    .long   CAN8_IRQHandler
    .long   CAN9_IRQHandler
    .long   CAN10_IRQHandler
    .long   CAN11_IRQHandler
    .long   CAN12_IRQHandler
    .long   CAN13_IRQHandler
    .long   CAN14_IRQHandler
    .long   CAN15_IRQHandler
    .long   RTC_IRQHandler
    .long   USBOTG_IRQHandler

	.size	__isr_vector, . - __isr_vector

	.text
	.thumb
	.thumb_func
	.align	2
	.globl	Reset_Handler
	.type	Reset_Handler, %function
Reset_Handler:
/*  Firstly it copies data from read only memory to RAM. There are two schemes
 *  to copy. One can copy more than one sections. Another can only copy
 *  one section.  The former scheme needs more instructions and read-only
 *  data to implement than the latter.
 *  Macro __STARTUP_COPY_MULTIPLE is used to choose between two schemes.  */

#ifdef __STARTUP_COPY_MULTIPLE
/*  Multiple sections scheme.
 *
 *  Between symbol address __copy_table_start__ and __copy_table_end__,
 *  there are array of triplets, each of which specify:
 *    offset 0: LMA of start of a section to copy from
 *    offset 4: VMA of start of a section to copy to
 *    offset 8: size of the section to copy. Must be multiply of 4
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
	ldr	r4, =__copy_table_start__
	ldr	r5, =__copy_table_end__

.L_loop0:
	cmp	r4, r5
	bge	.L_loop0_done
	ldr	r1, [r4]
	ldr	r2, [r4, #4]
	ldr	r3, [r4, #8]

.L_loop0_0:
	subs	r3, #4
	ittt	ge
	ldrge	r0, [r1, r3]
	strge	r0, [r2, r3]
	bge	.L_loop0_0

	adds	r4, #12
	b	.L_loop0

.L_loop0_done:
#else
/*  Single section scheme.
 *
 *  The ranges of copy from/to are specified by following symbols
 *    __etext: LMA of start of the section to copy from. Usually end of text
 *    __data_start__: VMA of start of the section to copy to
 *    __data_end__: VMA of end of the section to copy to
 *
 *  All addresses must be aligned to 4 bytes boundary.
 */
	ldr	r1, =__etext
	ldr	r2, =__data_start__
	ldr	r3, =__data_end__

.L_loop1:
	cmp	r2, r3
	ittt	lt
	ldrlt	r0, [r1], #4
	strlt	r0, [r2], #4
	blt	.L_loop1
#endif /*__STARTUP_COPY_MULTIPLE */

/*  This part of work usually is done in C library startup code. Otherwise,
 *  define this macro to enable it in this startup.
 *
 *  There are two schemes too. One can clear multiple BSS sections. Another
 *  can only clear one section. The former is more size expensive than the
 *  latter.
 *
 *  Define macro __STARTUP_CLEAR_BSS_MULTIPLE to choose the former.
 *  Otherwise efine macro __STARTUP_CLEAR_BSS to choose the later.
 */
#ifdef __STARTUP_CLEAR_BSS_MULTIPLE
/*  Multiple sections scheme.
 *
 *  Between symbol address __copy_table_start__ and __copy_table_end__,
 *  there are array of tuples specifying:
 *    offset 0: Start of a BSS section
 *    offset 4: Size of this BSS section. Must be multiply of 4
 */
	ldr	r3, =__zero_table_start__
	ldr	r4, =__zero_table_end__

.L_loop2:
	cmp	r3, r4
	bge	.L_loop2_done
	ldr	r1, [r3]
	ldr	r2, [r3, #4]
	movs	r0, 0

.L_loop2_0:
	subs	r2, #4
	itt	ge
	strge	r0, [r1, r2]
	bge	.L_loop2_0

	adds	r3, #8
	b	.L_loop2
.L_loop2_done:
#elif defined (__STARTUP_CLEAR_BSS)
/*  Single BSS section scheme.
 *
 *  The BSS section is specified by following symbols
 *    __bss_start__: start of the BSS section.
 *    __bss_end__: end of the BSS section.
 *
 *  Both addresses must be aligned to 4 bytes boundary.
 */
	ldr	r1, =__bss_start__
	ldr	r2, =__bss_end__

	movs	r0, 0
.L_loop3:
	cmp	r1, r2
	itt	lt
	strlt	r0, [r1], #4
	blt	.L_loop3
#endif /* __STARTUP_CLEAR_BSS_MULTIPLE || __STARTUP_CLEAR_BSS */

#ifndef __NO_SYSTEM_INIT
	bl	SystemInit
#endif

#ifndef __START
#define __START _start
#endif
	bl	__START

	.pool
	.size	Reset_Handler, . - Reset_Handler

	.align	1
	.thumb_func
	.weak	Default_Handler
	.type	Default_Handler, %function
Default_Handler:
	b	.
	.size	Default_Handler, . - Default_Handler

/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
	.macro	def_irq_handler	handler_name
	.weak	\handler_name
	.set	\handler_name, Default_Handler
	.endm

	def_irq_handler	NMI_Handler
	def_irq_handler	HardFault_Handler
	def_irq_handler	MemManage_Handler
	def_irq_handler	BusFault_Handler
	def_irq_handler	UsageFault_Handler
	def_irq_handler	SVC_Handler
	def_irq_handler	DebugMon_Handler
	def_irq_handler	PendSV_Handler
	def_irq_handler	SysTick_Handler
 /* Interrupt Handlers */
    def_irq_handler WWDG_IRQHandler
    def_irq_handler I2C0_IRQHandler
    def_irq_handler I2C1_IRQHandler
    def_irq_handler TIM0_IRQHandler
    def_irq_handler TIM1_IRQHandler
    def_irq_handler TIM2_IRQHandler
    def_irq_handler DMA_Stream0_IRQHandler
    def_irq_handler DMA_Stream1_IRQHandler
    def_irq_handler DMA_Stream2_IRQHandler
    def_irq_handler DMA_Stream3_IRQHandler
    def_irq_handler DMA_Stream4_IRQHandler
    def_irq_handler DMA_Stream5_IRQHandler
    def_irq_handler DMA_Stream6_IRQHandler
    def_irq_handler DMA_Stream7_IRQHandler
    def_irq_handler DMA_Stream8_IRQHandler
    def_irq_handler DMA_Stream9_IRQHandler
    def_irq_handler DMA_Stream10_IRQHandler
    def_irq_handler DMA_Stream11_IRQHandler
    def_irq_handler DMA_Stream12_IRQHandler
    def_irq_handler DMA_Stream13_IRQHandler
    def_irq_handler DMA_Stream14_IRQHandler
    def_irq_handler DMA_Stream15_IRQHandler
    def_irq_handler DMA_Stream16_IRQHandler
    def_irq_handler DMA_Stream17_IRQHandler
    def_irq_handler DMA_Stream18_IRQHandler
    def_irq_handler DMA_Stream19_IRQHandler
    def_irq_handler DMA_Stream20_IRQHandler
    def_irq_handler DMA_Stream21_IRQHandler
    def_irq_handler DMA_Stream22_IRQHandler
    def_irq_handler DMA_Stream23_IRQHandler
    def_irq_handler USART0_MX_IRQHandler
    def_irq_handler USART0_RX_IRQHandler
    def_irq_handler USART0_TX_IRQHandler
    def_irq_handler USART0_RT_IRQHandler
    def_irq_handler USART0_E_IRQHandler
    def_irq_handler USART0_IRQHandler
    def_irq_handler USART1_MX_IRQHandler
    def_irq_handler USART1_RX_IRQHandler
    def_irq_handler USART1_TX_IRQHandler
    def_irq_handler USART1_RT_IRQHandler
    def_irq_handler USART1_E_IRQHandler
    def_irq_handler USART1_IRQHandler
    def_irq_handler USART2_MX_IRQHandler
    def_irq_handler USART2_RX_IRQHandler
    def_irq_handler USART2_TX_IRQHandler
    def_irq_handler USART2_RT_IRQHandler
    def_irq_handler USART2_E_IRQHandler
    def_irq_handler USART2_IRQHandler
    def_irq_handler USART3_MX_IRQHandler
    def_irq_handler USART3_RX_IRQHandler
    def_irq_handler USART3_TX_IRQHandler
    def_irq_handler USART3_RT_IRQHandler
    def_irq_handler USART3_E_IRQHandler
    def_irq_handler USART3_IRQHandler
    def_irq_handler PWM0_IRQHandler
    def_irq_handler PWM0_HD_IRQHandler
    def_irq_handler PWM0_TZ_IRQHandler
    def_irq_handler PWM1_IRQHandler
    def_irq_handler PWM1_HD_IRQHandler
    def_irq_handler PWM1_TZ_IRQHandler
    def_irq_handler PWM2_IRQHandler
    def_irq_handler PWM2_HD_IRQHandler
    def_irq_handler PWM2_TZ_IRQHandler
    def_irq_handler PWM3_IRQHandler
    def_irq_handler PWM3_HD_IRQHandler
    def_irq_handler PWM3_TZ_IRQHandler
    def_irq_handler PWM4_IRQHandler
    def_irq_handler PWM4_HD_IRQHandler
    def_irq_handler PWM4_TZ_IRQHandler
    def_irq_handler PWM5_IRQHandler
    def_irq_handler PWM5_HD_IRQHandler
    def_irq_handler PWM5_TZ_IRQHandler
    def_irq_handler PWM6_IRQHandler
    def_irq_handler PWM6_HD_IRQHandler
    def_irq_handler PWM6_TZ_IRQHandler
    def_irq_handler PWM7_IRQHandler
    def_irq_handler PWM7_HD_IRQHandler
    def_irq_handler PWM7_TZ_IRQHandler
    def_irq_handler PWM8_IRQHandler
    def_irq_handler PWM8_HD_IRQHandler
    def_irq_handler PWM8_TZ_IRQHandler
    def_irq_handler ADC_SEQ0_IRQHandler
    def_irq_handler ADC_SEQ1_IRQHandler
    def_irq_handler ADC_SEQ2_IRQHandler
    def_irq_handler ADC_SEQ3_IRQHandler
    def_irq_handler ADC_SEQ4_IRQHandler
    def_irq_handler ADC_SEQ5_IRQHandler
    def_irq_handler ADC_SEQ6_IRQHandler
    def_irq_handler ADC_SEQ7_IRQHandler
    def_irq_handler ADC_CompInt_IRQHandler
    def_irq_handler CAP0_IRQHandler
    def_irq_handler CAP1_IRQHandler
    def_irq_handler CAP2_IRQHandler
    def_irq_handler CAP3_IRQHandler
    def_irq_handler CAP4_IRQHandler
    def_irq_handler CAP5_IRQHandler
    def_irq_handler QEP0_IRQHandler
    def_irq_handler QEP1_IRQHandler
    def_irq_handler BootFlash_IRQHandler
    def_irq_handler CMP0_IRQHandler
    def_irq_handler CMP1_IRQHandler
    def_irq_handler CMP2_IRQHandler
    def_irq_handler SPI0_IRQHandler
    def_irq_handler SPI1_IRQHandler
    def_irq_handler SPI2_IRQHandler
    def_irq_handler SPI3_IRQHandler
    def_irq_handler UserFlash_IRQHandler
    def_irq_handler GPIOA_IRQHandler
    def_irq_handler GPIOB_IRQHandler
    def_irq_handler GPIOC_IRQHandler
    def_irq_handler GPIOD_IRQHandler
    def_irq_handler GPIOE_IRQHandler
    def_irq_handler GPIOF_IRQHandler
    def_irq_handler GPIOG_IRQHandler
    def_irq_handler GPIOH_IRQHandler
    def_irq_handler Ethernet_IRQHandler
    def_irq_handler CAN0_IRQHandler
    def_irq_handler CAN1_IRQHandler
    def_irq_handler CAN2_IRQHandler
    def_irq_handler CAN3_IRQHandler
    def_irq_handler CAN4_IRQHandler
    def_irq_handler CAN5_IRQHandler
    def_irq_handler CAN6_IRQHandler
    def_irq_handler CAN7_IRQHandler
    def_irq_handler CAN8_IRQHandler
    def_irq_handler CAN9_IRQHandler
    def_irq_handler CAN10_IRQHandler
    def_irq_handler CAN11_IRQHandler
    def_irq_handler CAN12_IRQHandler
    def_irq_handler CAN13_IRQHandler
    def_irq_handler CAN14_IRQHandler
    def_irq_handler CAN15_IRQHandler
    def_irq_handler RTC_IRQHandler
    def_irq_handler USBOTG_IRQHandler

	.end

