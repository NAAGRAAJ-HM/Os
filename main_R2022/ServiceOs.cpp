/******************************************************************************/
/* File   : ServiceOs.cpp                                                     */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "ServiceOs.hpp"
#include "infServiceOs_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICEOS_AR_RELEASE_VERSION_MAJOR                                     4
#define SERVICEOS_AR_RELEASE_VERSION_MINOR                                     3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(SERVICEOS_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible SERVICEOS_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(SERVICEOS_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible SERVICEOS_AR_RELEASE_VERSION_MINOR!"
#endif

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_ServiceOs, SERVICEOS_VAR) ServiceOs;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, SERVICEOS_CODE) module_ServiceOs::InitFunction(
      CONSTP2CONST(ConstModule_TypeAbstract, SERVICEOS_CONST,       SERVICEOS_APPL_CONST) lptrConstModule
   ,  CONSTP2CONST(CfgModule_TypeAbstract,   SERVICEOS_CONFIG_DATA, SERVICEOS_APPL_CONST) lptrCfgModule
){
#if(STD_ON == ServiceOs_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(
            (NULL_PTR != lptrConstModule)
         && (NULL_PTR != lptrCfgModule)
      ){
         lptrConst = (const ConstServiceOs_Type*)lptrConstModule;
         lptrCfg   = lptrCfgModule;
      }
      else{
#if(STD_ON == ServiceOs_DevErrorDetect)
         ServiceDet_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == ServiceOs_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == ServiceOs_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICEOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::DeInitFunction(
   void
){
#if(STD_ON == ServiceOs_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceOs_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == ServiceOs_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICEOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::MainFunction(
   void
){
#if(STD_ON == ServiceOs_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == ServiceOs_InitCheck)
   }
   else{
#if(STD_ON == ServiceOs_DevErrorDetect)
      ServiceDet_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  SERVICEOS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::Activate_Task(
   void
){
//TBD: <generic service> arguement must contain reference to Task

//TBD: make scope and accessibility to global

//TBD: create task for ServiceEcuM startup two operations
   lptrConst->ptrinfServiceEcuM_ServiceOs->StartupTwo();
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::Start(
   void
){
   lptrConst->ptrinfServiceSwcOs_ServiceOs->StartupHook();
   Activate_Task();

   while(1 /* TBD: State machine as per AUTSERVICEOSAR */){
      lptrConst->ptrinfServiceSwcOs_ServiceOs->TASK_Idle();
   }
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::Shutdown(
   void
){
   lptrConst->ptrinfServiceSwcOs_ServiceOs->ShutdownHook();
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetResource(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::ReleaseResource(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::EnableAllInterrupts(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetApplicationID(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::DisableAllInterrupts(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetCurrentApplicationID(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetISRID(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::CallTrustedFunction(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::CheckISRMemoryAccess(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::CheckTaskMemoryAccess(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::CheckObjectAccess(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::CheckObjectOwnership(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::StartScheduleTableRel(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::StartScheduleTableAbs(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::StopScheduleTable(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::NextScheduleTable(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::StartScheduleTableSynchron(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::SyncScheduleTable(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::SetScheduleTableAsync(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetScheduleTableStatus(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::IncrementCounter(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetCounterValue(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetElapsedValue(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::TerminateApplication(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::AllowAccess(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetApplicationState(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetNumberOfActivatedCores(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetCoreId(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::StartCore(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::StartNonAutosarCore(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::GetMcalSpinlock(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::ReleaseMcalSpinlock(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::TryToGetMcalSpinlock(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::ShutdownAllCores(
   void
){
}

FUNC(void, SERVICEOS_CODE) module_ServiceOs::ControlIdle(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/
