/******************************************************************************/
/* File   : Os.cpp                                                            */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "CfgOs.hpp"
#include "Os_core.hpp"
#include "infOs.hpp"

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
class module_Os:
      public abstract_module
      //TBD: move to infOs.hpp ?
   ,  public infOs_EcuM
   ,  public class_Os_Functionality
{
   private:
/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
            Std_TypeReturn          IsInitDone{E_NOT_OK};
      const CfgModule_TypeAbstract* lptrCfg{(CfgModule_TypeAbstract*)NULL_PTR};

   public:
      module_Os(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, OS_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, OS_CONFIG_DATA, OS_APPL_CONST) lptrCfgModule
      );
      FUNC(void, OS_CODE) DeInitFunction (void);
      FUNC(void, OS_CODE) MainFunction   (void);
      OS_CORE_FUNCTIONALITIES
};

extern VAR(module_Os, OS_VAR) Os;

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/
CONSTP2VAR(infEcuMClient, OS_VAR, OS_CONST) gptrinfEcuMClient_Os = &Os;
CONSTP2VAR(infDcmClient,  OS_VAR, OS_CONST) gptrinfDcmClient_Os  = &Os;
CONSTP2VAR(infSchMClient, OS_VAR, OS_CONST) gptrinfSchMClient_Os = &Os;
CONSTP2VAR(infOs_EcuM,    OS_VAR, OS_CONST) gptrinfOs_EcuM       = &Os;

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/
VAR(module_Os, OS_VAR) Os(
   {
         OS_AR_RELEASE_VERSION_MAJOR
      ,  OS_AR_RELEASE_VERSION_MINOR
      ,  0x00
      ,  0xFF
      ,  0x01
      ,  '0'
      ,  '1'
      ,  '0'
   }
);

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/
#include "infSwcServiceOs_Os.hpp"
#include "infEcuM_Os.hpp"

static FUNC(void, OS_CODE) Activate_Task(void){
//TBD: <generic service> arguement must contain reference to Task

//TBD: make scope and accessibility to global

//TBD: create task for EcuM startup two operations
   gptrinfEcuM_Os->StartupTwo();
}

FUNC(void, OS_CODE) module_Os::InitFunction(
   CONSTP2CONST(CfgModule_TypeAbstract, OS_CONFIG_DATA, OS_APPL_CONST) lptrCfgModule
){
#if(STD_ON == Os_InitCheck)
   if(E_OK != IsInitDone){
#endif
      if(NULL_PTR != lptrCfgModule){
         if(STD_HIGH){
            lptrCfg = lptrCfgModule;
         }
         else{
            lptrCfg = &PBcfgOs;
         }
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

FUNC(void, OS_CODE) module_Os::DeInitFunction(void){
#if(STD_ON == Os_InitCheck)
   if(E_OK == IsInitDone){
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

FUNC(void, OS_CODE) module_Os::MainFunction(void){
#if(STD_ON == Os_InitCheck)
   if(E_OK == IsInitDone){
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

FUNC(void, OS_CODE) module_Os::Start(void){
   gptrinfSwcServiceOs_Os->StartupHook();
   Activate_Task();

   while(1 /* TBD: State machine as per AUTOSAR */){
      gptrinfSwcServiceOs_Os->TASK_Idle();
   }
}

FUNC(void, OS_CODE) module_Os::Shutdown(void){
   gptrinfSwcServiceOs_Os->ShutdownHook();
}

FUNC(void, OS_CODE) module_Os::GetResource(void){
}

FUNC(void, OS_CODE) module_Os::ReleaseResource(void){
}

FUNC(void, OS_CODE) module_Os::EnableAllInterrupts(void){
}

FUNC(void, OS_CODE) module_Os::GetApplicationID(void){
}

FUNC(void, OS_CODE) module_Os::DisableAllInterrupts(void){
}

FUNC(void, OS_CODE) module_Os::GetCurrentApplicationID(void){
}

FUNC(void, OS_CODE) module_Os::GetISRID(void){
}

FUNC(void, OS_CODE) module_Os::CallTrustedFunction(void){
}

FUNC(void, OS_CODE) module_Os::CheckISRMemoryAccess(void){
}

FUNC(void, OS_CODE) module_Os::CheckTaskMemoryAccess(void){
}

FUNC(void, OS_CODE) module_Os::CheckObjectAccess(void){
}

FUNC(void, OS_CODE) module_Os::CheckObjectOwnership(void){
}

FUNC(void, OS_CODE) module_Os::StartScheduleTableRel(void){
}

FUNC(void, OS_CODE) module_Os::StartScheduleTableAbs(void){
}

FUNC(void, OS_CODE) module_Os::StopScheduleTable(void){
}

FUNC(void, OS_CODE) module_Os::NextScheduleTable(void){
}

FUNC(void, OS_CODE) module_Os::StartScheduleTableSynchron(void){
}

FUNC(void, OS_CODE) module_Os::SyncScheduleTable(void){
}

FUNC(void, OS_CODE) module_Os::SetScheduleTableAsync(void){
}

FUNC(void, OS_CODE) module_Os::GetScheduleTableStatus(void){
}

FUNC(void, OS_CODE) module_Os::IncrementCounter(void){
}

FUNC(void, OS_CODE) module_Os::GetCounterValue(void){
}

FUNC(void, OS_CODE) module_Os::GetElapsedValue(void){
}

FUNC(void, OS_CODE) module_Os::TerminateApplication(void){
}

FUNC(void, OS_CODE) module_Os::AllowAccess(void){
}

FUNC(void, OS_CODE) module_Os::GetApplicationState(void){
}

FUNC(void, OS_CODE) module_Os::GetNumberOfActivatedCores(void){
}

FUNC(void, OS_CODE) module_Os::GetCoreId(void){
}

FUNC(void, OS_CODE) module_Os::StartCore(void){
}

FUNC(void, OS_CODE) module_Os::StartNonAutosarCore(void){
}

FUNC(void, OS_CODE) module_Os::GetSpinlock(void){
}

FUNC(void, OS_CODE) module_Os::ReleaseSpinlock(void){
}

FUNC(void, OS_CODE) module_Os::TryToGetSpinlock(void){
}

FUNC(void, OS_CODE) module_Os::ShutdownAllCores(void){
}

FUNC(void, OS_CODE) module_Os::ControlIdle(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

