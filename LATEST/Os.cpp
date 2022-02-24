/*****************************************************/
/* File   : Os.cpp                                   */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "module.h"
#include "Os_EcuM.h"
#include "Os_SchM.h"
#include "Os_EcuM.h"
#include "Os_Unused.h"

#include "SwcServiceOs_Os.h"
#include "EcuM_Os.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/
class module_Os:
      public abstract_module
   ,  public interface_Os_EcuM
   ,  public interface_Os_SchM
//   ,  public interface_Os_EcuM
{
   public:
      FUNC(void, OS_CODE) InitFunction   (void);
      FUNC(void, OS_CODE) DeInitFunction (void);
      FUNC(void, OS_CODE) MainFunction   (void);
      FUNC(void, OS_CODE) Start          (void);
      FUNC(void, OS_CODE) Shutdown       (void);
};

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
module_Os Os;

interface_Os_EcuM *EcuM_Client_ptr_Os = &Os;
interface_Os_SchM *SchM_Client_ptr_Os = &Os;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
static FUNC(void, OS_CODE) Activate_Task(void){
//TBD: <generic service> arguement must contain reference to Task

//TBD: make scope and accessibility to global

//TBD: create task for EcuM startup two operations
   Os_Client_ptr_EcuM->StartupTwo();
}

FUNC(void, OS_CODE) module_Os::InitFunction(void){
}

FUNC(void, OS_CODE) module_Os::DeInitFunction(void){
}

FUNC(void, OS_CODE) module_Os::MainFunction(void){
}

FUNC(void, OS_CODE) module_Os::Start(void){
   Os_Client_ptr_SwcServiceOs_Os->StartupHook();
   Activate_Task();

   while(1 /* TBD: State machine as per AUTOSAR */){
      Os_Client_ptr_SwcServiceOs_Os->TASK_Idle();
   }
}

FUNC(void, OS_CODE) module_Os::Shutdown(void){
   Os_Client_ptr_SwcServiceOs_Os->ShutdownHook();
}

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

/*****************************************************/
/* EOF                                               */
/*****************************************************/

