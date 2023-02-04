#pragma once
/******************************************************************************/
/* File   : infServiceOs_ServiceNvM_Types.hpp                                 */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "infServiceEcuM_ServiceOs.hpp"
#include "infServiceSwcOs_ServiceOs.hpp"

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class NvM_BlocksRom_ServiceOs_Type:
      public ConstModule_TypeAbstract
{
   public:
      infServiceEcuM_ServiceOs*  ptrinfServiceEcuM_ServiceOs;
      infServiceSwcOs_ServiceOs* ptrinfServiceSwcOs_ServiceOs;
};

class NvM_BlocksNv_ServiceOs_Type:
      public CfgModule_TypeAbstract
{
};

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

