#pragma once
/******************************************************************************/
/* File   : infServiceOs_ServiceNvM.hpp                                       */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceEcuM_ServiceOs.hpp"
#include "infServiceSwcOs_ServiceOs.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define CONSTSERVICEOS_AR_RELEASE_VERSION_MAJOR                                4
#define CONSTSERVICEOS_AR_RELEASE_VERSION_MINOR                                3

#define Const_DefaultInit_ConstServiceOs                                                                                   \
   ,  {                                                                                                                    \
            {CONSTSERVICEOS_AR_RELEASE_VERSION_MAJOR, CONSTSERVICEOS_AR_RELEASE_VERSION_MINOR, 0x00,0xFF,0x01,'0','1','0'} \
         ,  &ServiceEcuM                                                                                                   \
         ,  &ServiceSwcOs                                                                                                  \
      }                                                                                                                    \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(CONSTSERVICEOS_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible CONSTSERVICEOS_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(CONSTSERVICEOS_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible CONSTSERVICEOS_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

