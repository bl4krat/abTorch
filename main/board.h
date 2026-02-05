// Board supported: Generic "Yellow Header" ESP32 + Wifi + BLE
// Module on-board:  ESP32-WROOM-32
//
// Maps PCB PIN names to module pin names.
//
// This dev board provides the following:
//
// * EN button   - press to reset the MCU
// * BOOT button - press & hold. Press and release EN, then release BOOT to put MCU in download mode (?? Joint download mode, supporting SDIO and UART)
// * Red LED     - Indicates power on 3V3
// * Blue LED    - On PIN_IO2 - External 1k pullup - lights when PIN_IO2 is low
// * AMS1117     - 1A 3.3v linear regulator to power the module from 5v USB connector
// * CP2104      - USB to UART bridge. GPIO lines are not connected to PIN_IO0 or PIN_IO2, so no boot mode control. TX/RX to PIN_RXD/PIN_TXD respectively

#ifndef __BOARD_H	// include guard
#define __BOARD_H


//	    -----------------------------//-----------|---------------------------------|----------------------------------------------------------------------------------------------------------
//      BoardName		IDF_REF   	 // BoardPin# | ModulePin#	ModuleName			| ESP32Pin# ESP32PinName Function
//	    -----------------------------//-----------|---------------------------------|----------------------------------------------------------------------------------------------------------
//  	3V3 			    		 //  1		  |  2 		 	3V3					|  1		VDDA		 Analog power supply (2.3 V ∼ 3.6 V)
//					    			 // 		  | --			[PCB Ant]			|  2		LNA_IN		 RF input and output
//		3V3 			    		 //  1		  |  2 		 	3V3					|  3		VDD3P3		 Analog power supply (2.3 V ∼ 3.6 V)
//		3V3 			    		 //  1		  |  2 		 	3V3					|  4		VDD3P3		 Analog power supply (2.3 V ∼ 3.6 V)
#define	PIN_SVP			GPIO_NUM_36	 //  3		  |  4			SENSOR_VP			|  5		SENSOR_VP	 GPIO36, ADC1_CH0, RTC_GPIO0
//		 	    					 // 		  | --			[cap to 4]			|  6		SENSOR_CAPP	 GPIO37, ADC1_CH1, RTC_GPIO1
//		 	    					 // 		  | --			[cap to 5]			|  7		SENSOR_CAPN	 GPIO38, ADC1_CH2, RTC_GPIO2
#define	PIN_SVN			GPIO_NUM_39	 //  4		  |  5 		 	SENSOR_VN			|  8		SENSOR_VN	 GPIO39, ADC1_CH3, RTC_GPIO3
//      RST				    		 //  2		  |  3 		 	EN					|  9		CHIP_PU		 High: On; enables the chip. Low: Off; the chip shuts down
#define	PIN_IO34	 	GPIO_NUM_34  //  5		  |  6			IO34				| 10		VDET_1		 GPIO34, ADC1_CH6, RTC_GPIO4
#define	PIN_IO35	 	GPIO_NUM_35  //  6		  |  7			IO35				| 11		VDET_2		 GPIO35, ADC1_CH7, RTC_GPIO5
#define	PIN_IO32	 	GPIO_NUM_32  //  7		  |  8			IO32				| 12		32K_XP		 GPIO32, ADC1_CH4, RTC_GPIO9, TOUCH9, 32K_XP (32.768 kHz crystal oscillator input)
#define	PIN_IO33	 	GPIO_NUM_33  //  8		  |  9			IO33				| 13		32K_XN		 GPIO33, ADC1_CH5, RTC_GPIO8, TOUCH8, 32K_XN (32.768 kHz crystal oscillator output)
#define	PIN_IO25	 	GPIO_NUM_25  //  9		  | 10			IO25				| 14		GPIO25		 GPIO25, ADC2_CH8, RTC_GPIO6, DAC_1, EMAC_RXD0
#define	PIN_IO26	 	GPIO_NUM_26  // 10		  | 11			IO26				| 15		GPIO26		 GPIO26, ADC2_CH9, RTC_GPIO7, DAC_2, EMAC_RXD1
#define	PIN_IO27	 	GPIO_NUM_27  // 11		  | 12			IO27				| 16		GPIO27		 GPIO27, ADC2_CH7, RTC_GPIO17, TOUCH7, EMAC_RX_DV
#define	PIN_IO14	 	GPIO_NUM_14  // 12		  | 13			IO14				| 17		MTMS 		 GPIO14, ADC2_CH6, RTC_GPIO16, TOUCH6, EMAC_TXD2, HSPICLK, HS2_CLK, SD_CLK, MTMS
#define	PIN_IO12	 	GPIO_NUM_12  // 13		  | 14			IO12				| 18		MTDI 		 GPIO12, ADC2_CH5, RTC_GPIO15, TOUCH5, EMAC_TXD3, HSPIQ, HS2_DATA2, SD_DATA2, MTDI
//		3V3 	 					 //  1		  |  2 			3V3					| 19		VDD3P3_RTC	 Input power supply for RTC IO (2.3 V ∼ 3.6 V)
#define	PIN_IO13	 	GPIO_NUM_13  // 15		  | 16			IO13 				| 20		MTCK		 GPIO13, ADC2_CH4, RTC_GPIO14, TOUCH4, EMAC_RX_ER, HSPID, HS2_DATA3, SD_DATA3, MTCK
#define	PIN_IO15	 	GPIO_NUM_15  // 35		  | 23			IO15 				| 21		MTDO		 GPIO15, ADC2_CH3, RTC_GPIO13, TOUCH3, EMAC_RXD3, HSPICS0, HS2_CMD, SD_CMD, MTDO
#define	PIN_IO2			GPIO_NUM_2   // 34		  | 24			IO2					| 22		GPIO2		 GPIO2, ADC2_CH2, RTC_GPIO12, TOUCH2, HSPIWP, HS2_DATA0, SD_DATA0
#define	PIN_IO0			GPIO_NUM_0   // 33		  | 25			IO0					| 23		GPIO0		 GPIO0, ADC2_CH1, RTC_GPIO11, TOUCH1, EMAC_TX_CLK, CLK_OUT1,
#define	PIN_IO4			GPIO_NUM_4   // 32		  | 26			IO4					| 24		GPIO4		 GPIO4, ADC2_CH0, RTC_GPIO10, TOUCH0, EMAC_TX_ER, HSPIHD, HS2_DATA1, SD_DATA1
#define	PIN_IO16	 	GPIO_NUM_16  // 31		  | 27			IO16 				| 25		GPIO16		 GPIO16, HS1_DATA4, U2RXD, EMAC_CLK_OUT
//									 // 		  | --			[Flash Vdd]			| 26		VDD_SDIO	 Output power supply: 1.8 V or the same voltage as VDD3P3_RTC
#define	PIN_IO17	 	GPIO_NUM_17  // 30		  | 28			IO17 				| 27		GPIO17 		 GPIO17, HS1_DATA5, U2TXD, EMAC_CLK_OUT_180
#define	PIN_SD2 		GPIO_NUM_9	 // 16		  | 17 			SD2 [& flash_|hold] | 28		SD_DATA_2	 GPIO9, HS1_DATA2, U1RXD, SD_DATA2, SPIHD
#define	PIN_SD3 		GPIO_NUM_10	 // 17		  | 18 			SD3 [& flash_|WP]	| 29		SD_DATA_3	 GPIO10, HS1_DATA3, U1TXD, SD_DATA3, SPIWP
#define	PIN_CMD 		GPIO_NUM_11	 // 18		  | 19			CMD [& flash_|CS]	| 30		SD_CMD 		 GPIO11, HS1_CMD, U1RTS, SD_CMD, SPICS0
#define	PIN_SCK 		GPIO_NUM_6   // 38		  | 20			CLK [& flash_CLK]	| 31		SD_CLK 		 GPIO6, HS1_CLK, U1CTS, SD_CLK, SPICLK
#define	PIN_SD0 		GPIO_NUM_7   // 36		  | 21			SD0 [& flash_D0]	| 32		SD_DATA_0	 GPIO7, HS1_DATA0, U2RTS, SD_DATA0, SPIQ
#define	PIN_SD1 		GPIO_NUM_8	 // 37		  | 22			SD1 [& flash_DI]	| 33		SD_DATA_1	 GPIO8, HS1_DATA1, U2CTS, SD_DATA1, SPID
#define	PIN_IO5 	 	GPIO_NUM_5   // 29		  | 29		 	IO5 				| 34		GPIO5 		 GPIO5, HS1_DATA6, VSPICS0, EMAC_RX_CLK
#define	PIN_IO18	 	GPIO_NUM_18  // 28		  | 30		 	IO18				| 35		GPIO18		 GPIO18, HS1_DATA7, VSPICLK
#define	PIN_IO23	 	GPIO_NUM_23  // 21		  | 37		 	IO23				| 36		GPIO23		 GPIO23, HS1_STROBE, VSPID
//		3V3 	 					 //  1		  |  2 			3V3 				| 37		VDD3P3_CPU	 Input power supply for CPU IO (1.8 V ∼ 3.6 V)
#define	PIN_IO19	 	GPIO_NUM_19  // 27		  | 31		 	IO19				| 38		GPIO19		 GPIO19, U0CTS, VSPIQ, EMAC_TXD0
#define	PIN_IO22	 	GPIO_NUM_22  // 22		  | 36		  	IO22				| 39		GPIO22		 GPIO22, U0RTS, VSPIWP, EMAC_TXD1
#define	PIN_RXD 		GPIO_NUM_3	 // 24		  | 34			RXD0				| 40		U0RXD		 GPIO3, U0RXD, CLK_OUT2
#define	PIN_TXD 		GPIO_NUM_1	 // 23		  | 35			TXD0				| 41		U0TXD		 GPIO1, U0TXD, CLK_OUT3, EMAC_RXD2
#define	PIN_IO21 		GPIO_NUM_21	 // 25		  | 33			IO21				| 42		GPIO21		 GPIO21, VSPIHD, EMAC_TX_EN
//		3V3 	 					 //  1		  |  2 			3V3 				| 43		VDDA		 Analog power supply (2.3 V ∼ 3.6 V)
//		 	     					 // 		  | --			[crystal output]	| 44		XTAL_N		 External crystal output
//		 	     					 // 		  | --			[crystal input]		| 45		XTAL_P		 External crystal input
//		3V3 	 					 //  1		  |  2 			3V3 				| 46		VDDA		 Analog power supply (2.3 V ∼ 3.6 V)
//		 	     					 // 		  | --			[parallel c & r]	| 47		CAP2		 Connects to a 3.3 nF (10%) capacitor and 20 kΩ resistor in parallel to CAP1
//		 	     					 // 		  | --			[cap to ground]		| 48		CAP1		 Connects to a 10 nF series capacitor to ground
//		GND 	 					 // 14,20,26  |  1,15,38,39	GND					| 49		GND			 Ground
//		 	     					 // 		  | 32			N/C 				|
//      5V							 // 19        |									|
//	    -----------------------------//-----------|---------------------------------|----------------------------------------------------------------------------------------------------------
								
#endif