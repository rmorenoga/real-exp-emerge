/*******************************************************************************
* File Name: Multiplexor.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_Multiplexor_H)
#define CY_AMUX_Multiplexor_H

#include "cyfitter.h"
#include "cyfitter_cfg.h"

#if ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC4) || \
         (CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC5))    
    #include "cytypes.h"
#else
    #include "syslib/cy_syslib.h"
#endif /* ((CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3) */


/***************************************
*        Function Prototypes
***************************************/

void Multiplexor_Start(void) ;
#define Multiplexor_Init() Multiplexor_Start()
void Multiplexor_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Multiplexor_Stop(void); */
/* void Multiplexor_Select(uint8 channel); */
/* void Multiplexor_Connect(uint8 channel); */
/* void Multiplexor_Disconnect(uint8 channel); */
/* void Multiplexor_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Multiplexor_CHANNELS  3u
#define Multiplexor_MUXTYPE   1
#define Multiplexor_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Multiplexor_NULL_CHANNEL 0xFFu
#define Multiplexor_MUX_SINGLE   1
#define Multiplexor_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Multiplexor_MUXTYPE == Multiplexor_MUX_SINGLE
# if !Multiplexor_ATMOSTONE
#  define Multiplexor_Connect(channel) Multiplexor_Set(channel)
# endif
# define Multiplexor_Disconnect(channel) Multiplexor_Unset(channel)
#else
# if !Multiplexor_ATMOSTONE
void Multiplexor_Connect(uint8 channel) ;
# endif
void Multiplexor_Disconnect(uint8 channel) ;
#endif

#if Multiplexor_ATMOSTONE
# define Multiplexor_Stop() Multiplexor_DisconnectAll()
# define Multiplexor_Select(channel) Multiplexor_FastSelect(channel)
void Multiplexor_DisconnectAll(void) ;
#else
# define Multiplexor_Stop() Multiplexor_Start()
void Multiplexor_Select(uint8 channel) ;
# define Multiplexor_DisconnectAll() Multiplexor_Start()
#endif

#endif /* CY_AMUX_Multiplexor_H */


/* [] END OF FILE */
