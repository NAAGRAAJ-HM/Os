/******************************************************************************/
/* File   : Os.cpp                                                            */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "Module.hpp"
#include "infOs_EcuM.hpp"
#include "infOs_Dcm.hpp"
#include "infOs_SchM.hpp"

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
   ,  public infOs_EcuM
{
   public:
      module_Os(Std_TypeVersionInfo lVersionInfo) : abstract_module(lVersionInfo){
      }
      FUNC(void, OS_CODE) InitFunction(
         CONSTP2CONST(CfgModule_TypeAbstract, OS_CONFIG_DATA, OS_APPL_CONST) lptrCfgModule
      );
      FUNC(void, OS_CODE) DeInitFunction (void);
      FUNC(void, OS_CODE) MainFunction   (void);

      FUNC(void, OS_CODE) Start          (void);
      FUNC(void, OS_CODE) Shutdown       (void);
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
#include "CfgOs.hpp"

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
   if(E_OK == IsInitDone){
#if(STD_ON == Os_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Os_DevErrorDetect)
         Det_ReportError(
         );
#endif
      }
      else{
// check lptrCfgModule for memory faults
// use PBcfg_Os as back-up configuration
      }
      IsInitDone = E_OK;
#if(STD_ON == Os_InitCheck)
   }
#endif
}

FUNC(void, OS_CODE) module_Os::DeInitFunction(void){
#if(STD_ON == Os_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Os_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
      IsInitDone = E_NOT_OK;
#if(STD_ON == Os_InitCheck)
   }
#endif
}

FUNC(void, OS_CODE) module_Os::MainFunction(void){
#if(STD_ON == Os_InitCheck)
   if(E_OK != IsInitDone){
#if(STD_ON == Os_DevErrorDetect)
      Det_ReportError(
      );
#endif
   }
   else{
#endif
#if(STD_ON == Os_InitCheck)
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

class class_Os_Unused{
   public:
      FUNC(void, OS_CODE) Start                      (void);
      FUNC(void, OS_CODE) Shutdown                   (void);
      FUNC(void, OS_CODE) GetResource                (void);
      FUNC(void, OS_CODE) ReleaseResource            (void);
      FUNC(void, OS_CODE) DisableAllInterrupts       (void);
      FUNC(void, OS_CODE) EnableAllInterrupts        (void);
      FUNC(void, OS_CODE) GetApplicationID           (void);
      FUNC(void, OS_CODE) GetCurrentApplicationID    (void);
      FUNC(void, OS_CODE) GetISRID                   (void);
      FUNC(void, OS_CODE) CallTrustedFunction        (void);
      FUNC(void, OS_CODE) CheckISRMemoryAccess       (void);
      FUNC(void, OS_CODE) CheckTaskMemoryAccess      (void);
      FUNC(void, OS_CODE) CheckObjectAccess          (void);
      FUNC(void, OS_CODE) CheckObjectOwnership       (void);
      FUNC(void, OS_CODE) StartScheduleTableRel      (void);
      FUNC(void, OS_CODE) StartScheduleTableAbs      (void);
      FUNC(void, OS_CODE) StopScheduleTable          (void);
      FUNC(void, OS_CODE) NextScheduleTable          (void);
      FUNC(void, OS_CODE) StartScheduleTableSynchron (void);
      FUNC(void, OS_CODE) SyncScheduleTable          (void);
      FUNC(void, OS_CODE) SetScheduleTableAsync      (void);
      FUNC(void, OS_CODE) GetScheduleTableStatus     (void);
      FUNC(void, OS_CODE) IncrementCounter           (void);
      FUNC(void, OS_CODE) GetCounterValue            (void);
      FUNC(void, OS_CODE) GetElapsedValue            (void);
      FUNC(void, OS_CODE) TerminateApplication       (void);
      FUNC(void, OS_CODE) AllowAccess                (void);
      FUNC(void, OS_CODE) GetApplicationState        (void);
      FUNC(void, OS_CODE) GetNumberOfActivatedCores  (void);
      FUNC(void, OS_CODE) GetCoreId                  (void);
      FUNC(void, OS_CODE) StartCore                  (void);
      FUNC(void, OS_CODE) StartNonAutosarCore        (void);
      FUNC(void, OS_CODE) GetSpinlock                (void);
      FUNC(void, OS_CODE) ReleaseSpinlock            (void);
      FUNC(void, OS_CODE) TryToGetSpinlock           (void);
      FUNC(void, OS_CODE) ShutdownAllCores           (void);
      FUNC(void, OS_CODE) ControlIdle                (void);
};

FUNC(void, OS_CODE) class_Os_Unused::GetResource(void){
}

FUNC(void, OS_CODE) class_Os_Unused::ReleaseResource(void){
}

FUNC(void, OS_CODE) class_Os_Unused::EnableAllInterrupts(void){
}

FUNC(void, OS_CODE) class_Os_Unused::DisableAllInterrupts(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetCurrentApplicationID(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetISRID(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CallTrustedFunction(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CheckISRMemoryAccess(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CheckTaskMemoryAccess(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CheckObjectAccess(void){
}

FUNC(void, OS_CODE) class_Os_Unused::CheckObjectOwnership(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartScheduleTableRel(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartScheduleTableAbs(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StopScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Unused::NextScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartScheduleTableSynchron(void){
}

FUNC(void, OS_CODE) class_Os_Unused::SyncScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Unused::SetScheduleTableAsync(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetScheduleTableStatus(void){
}

FUNC(void, OS_CODE) class_Os_Unused::IncrementCounter(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetCounterValue(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetElapsedValue(void){
}

FUNC(void, OS_CODE) class_Os_Unused::TerminateApplication(void){
}

FUNC(void, OS_CODE) class_Os_Unused::AllowAccess(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetApplicationState(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetNumberOfActivatedCores(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetCoreId(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartCore(void){
}

FUNC(void, OS_CODE) class_Os_Unused::StartNonAutosarCore(void){
}

FUNC(void, OS_CODE) class_Os_Unused::GetSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Unused::ReleaseSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Unused::TryToGetSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Unused::ShutdownAllCores(void){
}

FUNC(void, OS_CODE) class_Os_Unused::ControlIdle(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

