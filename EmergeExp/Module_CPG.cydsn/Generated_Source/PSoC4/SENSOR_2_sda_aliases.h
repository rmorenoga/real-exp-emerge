/*******************************************************************************
* File Name: SENSOR_2_sda.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SENSOR_2_sda_ALIASES_H) /* Pins SENSOR_2_sda_ALIASES_H */
#define CY_PINS_SENSOR_2_sda_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SENSOR_2_sda_0			(SENSOR_2_sda__0__PC)
#define SENSOR_2_sda_0_PS		(SENSOR_2_sda__0__PS)
#define SENSOR_2_sda_0_PC		(SENSOR_2_sda__0__PC)
#define SENSOR_2_sda_0_DR		(SENSOR_2_sda__0__DR)
#define SENSOR_2_sda_0_SHIFT	(SENSOR_2_sda__0__SHIFT)
#define SENSOR_2_sda_0_INTR	((uint16)((uint16)0x0003u << (SENSOR_2_sda__0__SHIFT*2u)))

#define SENSOR_2_sda_INTR_ALL	 ((uint16)(SENSOR_2_sda_0_INTR))


#endif /* End Pins SENSOR_2_sda_ALIASES_H */


/* [] END OF FILE */
