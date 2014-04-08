//	 Start of the Copyright Notice
//	****************************************************************************
// 	* Copyright Itron SAS.                                                     *
//	* This computer program includes confidential proprietary information and  *
//	* is a trade secret of Itron. All use, disclosures and/or reproduction 	   *
//	* is prohibited unless authorized in writing.          					   *
//	* All Rights Reserved                                                      *
//	****************************************************************************
//	 End of the Copyright Notice

/*************************************************************************//**
 * @file 	encoder.h
 * @brief	xx
 * @author	boutboutnico
 * @date	25 juil. 2012
 * @company	Itron
 * @site	Chasseneuil
 * @product	xx
 * @module	xx
 *****************************************************************************/

#ifndef ENCODER_H_
#define ENCODER_H_

/*****************************************************************************
 * DEFINITION
 *****************************************************************************/
#include "Arduino.h"

//#include "define.h"

/*****************************************************************************
 * INCLUDE
 *****************************************************************************/
typedef void (*pfunc)(void);
/*****************************************************************************
 * CLASS
 *****************************************************************************/
/**
 * @class 	xx
 * @brief	xx
 * @author	boutboutnico
 * @date	25 juil. 2012
 */
class Encoder
{
	public:
		Encoder(uint8_t pin_A, uint8_t int_pin_A, uint8_t pin_B, pfunc interrupt, bool isCCW);

		void begin();
		void update();
		uint32_t getCount();

	private:
		uint8_t pin_A;
		uint8_t int_pin_A;
		uint8_t pin_B;
		pfunc interrupt;

		uint32_t cpt_encoder;
		bool b_CCW;

};

#endif /* ENCODER_H_ */
/*****************************************************************************
 * END OF FILE
 *****************************************************************************/
