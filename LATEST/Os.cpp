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
class class_Os_Functionality{
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

class module_Os:
      public abstract_module
   ,  public infOs_EcuM
   ,  public class_Os_Functionality
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
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
      );
#endif
   }
   else{
#endif
      if(NULL_PTR == lptrCfgModule){
#if(STD_ON == Os_DevErrorDetect)
         Det_ReportError(
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
         );
#endif
      }
      else{
         if(STD_LOW){
// check lptrCfgModule for memory faults
            lptrCfg = lptrCfgModule;
         }
         else{
// use PBcfgCanIf as back-up configuration
            lptrCfg = &PBcfgOs;
         }
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
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
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
      0 //TBD: IdModule
   ,  0 //TBD: IdInstance
   ,  0 //TBD: IdApi
   ,  0 //TBD: IdError
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

FUNC(void, OS_CODE) class_Os_Functionality::GetResource(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::ReleaseResource(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::EnableAllInterrupts(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::DisableAllInterrupts(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetCurrentApplicationID(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetISRID(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::CallTrustedFunction(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::CheckISRMemoryAccess(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::CheckTaskMemoryAccess(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::CheckObjectAccess(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::CheckObjectOwnership(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::StartScheduleTableRel(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::StartScheduleTableAbs(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::StopScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::NextScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::StartScheduleTableSynchron(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::SyncScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::SetScheduleTableAsync(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetScheduleTableStatus(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::IncrementCounter(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetCounterValue(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetElapsedValue(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::TerminateApplication(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::AllowAccess(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetApplicationState(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetNumberOfActivatedCores(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetCoreId(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::StartCore(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::StartNonAutosarCore(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::GetSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::ReleaseSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::TryToGetSpinlock(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::ShutdownAllCores(void){
}

FUNC(void, OS_CODE) class_Os_Functionality::ControlIdle(void){
}

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

