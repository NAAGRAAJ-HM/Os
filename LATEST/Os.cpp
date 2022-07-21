/******************************************************************************/
/* File   : Os.cpp                                                            */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "Os.hpp"
#include "infOs_Imp.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define OS_AR_RELEASE_VERSION_MAJOR                                            4
#define OS_AR_RELEASE_VERSION_MINOR                                            3

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/
#if(OS_AR_RELEASE_VERSION_MAJOR != STD_AR_RELEASE_VERSION_MAJOR)
   #error "Incompatible OS_AR_RELEASE_VERSION_MAJOR!"
#endif

#if(OS_AR_RELEASE_VERSION_MINOR != STD_AR_RELEASE_VERSION_MINOR)
   #error "Incompatible OS_AR_RELEASE_VERSION_MINOR!"
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
VAR(module_Os, OS_VAR) Os;

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
FUNC(void, OS_CODE) module_Os::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, OS_CONFIG_DATA, OS_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Os_InitCheck)
   if(
         E_OK
      != IsInitDone
   ){
#endif
      if(NULL_PTR != lptrCfgModule){
         lptrCfg = lptrCfgModule;
      }
      else{
#if(STD_ON == Os_DevErrorDetect)
         Det_ReportError(
               0 //TBD: IdModule
            ,  0 //TBD: IdInstance
            ,  0 //TBD: IdApi
            ,  0 //TBD: IdError
         );
#endif
      }
#if(STD_ON == Os_InitCheck)
      IsInitDone = E_OK;
   }
   else{
#if(STD_ON == Os_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  OS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, OS_CODE) module_Os::DeInitFunction(
   void
){
#if(STD_ON == Os_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Os_InitCheck)
      IsInitDone = E_NOT_OK;
   }
   else{
#if(STD_ON == Os_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  OS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, OS_CODE) module_Os::MainFunction(
   void
){
#if(STD_ON == Os_InitCheck)
   if(
         E_OK
      == IsInitDone
   ){
#endif
#if(STD_ON == Os_InitCheck)
   }
   else{
#if(STD_ON == Os_DevErrorDetect)
      Det_ReportError(
            0 //TBD: IdModule
         ,  0 //TBD: IdInstance
         ,  0 //TBD: IdApi
         ,  OS_E_UNINIT
      );
#endif
   }
#endif
}

FUNC(void, OS_CODE) module_Os::Activate_Task(
   void
){
//TBD: <generic service> arguement must contain reference to Task

//TBD: make scope and accessibility to global

//TBD: create task for EcuM startup two operations
   ((CfgOs_Type*)lptrCfg)->ptrinfEcuM_Os->StartupTwo();
}

FUNC(void, OS_CODE) module_Os::Start(
   void
){
   ((CfgOs_Type*)lptrCfg)->ptrinfSwcServiceOs_Os->StartupHook();
   Activate_Task();

   while(1 /* TBD: State machine as per AUTOSAR */){
      ((CfgOs_Type*)lptrCfg)->ptrinfSwcServiceOs_Os->TASK_Idle();
   }
}

FUNC(void, OS_CODE) module_Os::Shutdown(
   void
){
   ((CfgOs_Type*)lptrCfg)->ptrinfSwcServiceOs_Os->ShutdownHook();
}

FUNC(void, OS_CODE) module_Os::GetResource(
   void
){
}

FUNC(void, OS_CODE) module_Os::ReleaseResource(
   void
){
}

FUNC(void, OS_CODE) module_Os::EnableAllInterrupts(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetApplicationID(
   void
){
}

FUNC(void, OS_CODE) module_Os::DisableAllInterrupts(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetCurrentApplicationID(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetISRID(
   void
){
}

FUNC(void, OS_CODE) module_Os::CallTrustedFunction(
   void
){
}

FUNC(void, OS_CODE) module_Os::CheckISRMemoryAccess(
   void
){
}

FUNC(void, OS_CODE) module_Os::CheckTaskMemoryAccess(
   void
){
}

FUNC(void, OS_CODE) module_Os::CheckObjectAccess(
   void
){
}

FUNC(void, OS_CODE) module_Os::CheckObjectOwnership(
   void
){
}

FUNC(void, OS_CODE) module_Os::StartScheduleTableRel(
   void
){
}

FUNC(void, OS_CODE) module_Os::StartScheduleTableAbs(
   void
){
}

FUNC(void, OS_CODE) module_Os::StopScheduleTable(
   void
){
}

FUNC(void, OS_CODE) module_Os::NextScheduleTable(
   void
){
}

FUNC(void, OS_CODE) module_Os::StartScheduleTableSynchron(
   void
){
}

FUNC(void, OS_CODE) module_Os::SyncScheduleTable(
   void
){
}

FUNC(void, OS_CODE) module_Os::SetScheduleTableAsync(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetScheduleTableStatus(
   void
){
}

FUNC(void, OS_CODE) module_Os::IncrementCounter(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetCounterValue(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetElapsedValue(
   void
){
}

FUNC(void, OS_CODE) module_Os::TerminateApplication(
   void
){
}

FUNC(void, OS_CODE) module_Os::AllowAccess(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetApplicationState(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetNumberOfActivatedCores(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetCoreId(
   void
){
}

FUNC(void, OS_CODE) module_Os::StartCore(
   void
){
}

FUNC(void, OS_CODE) module_Os::StartNonAutosarCore(
   void
){
}

FUNC(void, OS_CODE) module_Os::GetSpinlock(
   void
){
}

FUNC(void, OS_CODE) module_Os::ReleaseSpinlock(
   void
){
}

FUNC(void, OS_CODE) module_Os::TryToGetSpinlock(
   void
){
}

FUNC(void, OS_CODE) module_Os::ShutdownAllCores(
   void
){
}

FUNC(void, OS_CODE) module_Os::ControlIdle(
   void
){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

