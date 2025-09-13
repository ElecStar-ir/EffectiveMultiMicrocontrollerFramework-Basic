/**
 ******************************************************************************************
 * This file is part of EMF(Effective Multi Microcontroller Framework).
 *
 * @author  Ebrahim Rahmanian (elecstar.ir@gmail.com) (www.elecstar.ir)
 * @brief
 ******************************************************************************************
 * @attention
 *
 ******************************************************************************************
 * @RELEASE HISTORY
 *
 * DATE                     NAME           DESCRIPTION
 * v5.1_14040709            E.Rahmanian    Create
 ******************************************************************************************
 */
#if defined(CUBEIDE__HAL)
#ifndef EMF_INIT_CUBEIDE__HAL_H
#define EMF_INIT_CUBEIDE__HAL_H

// namespace EMF::Init {

/**
* @code
#include "EMF.h"
#include "main.h"

int main(void){

  EMF_init();

}
* @endcode
*/

#define EMF_init() HAL_Init()

// }  // namespace EMF::Init
// using namespace EMF::Init;
#endif
#endif
