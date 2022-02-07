/*****************************************************/
/* File   : Os.cpp                                   */
/* Author : Naagraaj HM                              */
/*****************************************************/

/*****************************************************/
/* #INCLUDES                                         */
/*****************************************************/
#include "Os.h"

#include "Swc_Os.h"
#include "EcuM.h"

#include "Os_EcuM.h"

/*****************************************************/
/* #DEFINES                                          */
/*****************************************************/

/*****************************************************/
/* MACROS                                            */
/*****************************************************/

/*****************************************************/
/* TYPEDEFS                                          */
/*****************************************************/

/*****************************************************/
/* CONSTS                                            */
/*****************************************************/

/*****************************************************/
/* PARAMS                                            */
/*****************************************************/

/*****************************************************/
/* OBJECTS                                           */
/*****************************************************/
class_Os_EcuM Os_EcuM;
class_EcuM_Client *EcuM_Client_ptr_Os = &Os_EcuM;
class_Os Os;

/*****************************************************/
/* FUNCTIONS                                         */
/*****************************************************/
static FUNC(void, OS_CODE) Activate_Task(void){
   EcuM.StartupTwo();
}

FUNC(void, OS_CODE) class_Os::Start(void){
   Swc_Os.StartupHook();
   Activate_Task();

   while(1 /* TBD: State machine as per AUTOSAR */){
      Swc_Os.TASK_Idle();
   }
}

FUNC(void, OS_CODE) class_Os::Shutdown(void){
   Swc_Os.ShutdownHook();
}

FUNC(void, OS_CODE) class_Os::GetResource(void){
}

FUNC(void, OS_CODE) class_Os::ReleaseResource(void){
}

FUNC(void, OS_CODE) class_Os::EnableAllInterrupts(void){
}

FUNC(void, OS_CODE) class_Os::DisableAllInterrupts(void){
}

FUNC(void, OS_CODE) class_Os::GetCurrentApplicationID(void){
}

FUNC(void, OS_CODE) class_Os::GetISRID(void){
}

FUNC(void, OS_CODE) class_Os::CallTrustedFunction(void){
}

FUNC(void, OS_CODE) class_Os::CheckISRMemoryAccess(void){
}

FUNC(void, OS_CODE) class_Os::CheckTaskMemoryAccess(void){
}

FUNC(void, OS_CODE) class_Os::CheckObjectAccess(void){
}

FUNC(void, OS_CODE) class_Os::CheckObjectOwnership(void){
}

FUNC(void, OS_CODE) class_Os::StartScheduleTableRel(void){
}

FUNC(void, OS_CODE) class_Os::StartScheduleTableAbs(void){
}

FUNC(void, OS_CODE) class_Os::StopScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os::NextScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os::StartScheduleTableSynchron(void){
}

FUNC(void, OS_CODE) class_Os::SyncScheduleTable(void){
}

FUNC(void, OS_CODE) class_Os::SetScheduleTableAsync(void){
}

FUNC(void, OS_CODE) class_Os::GetScheduleTableStatus(void){
}

FUNC(void, OS_CODE) class_Os::IncrementCounter(void){
}

FUNC(void, OS_CODE) class_Os::GetCounterValue(void){
}

FUNC(void, OS_CODE) class_Os::GetElapsedValue(void){
}

FUNC(void, OS_CODE) class_Os::TerminateApplication(void){
}

FUNC(void, OS_CODE) class_Os::AllowAccess(void){
}

FUNC(void, OS_CODE) class_Os::GetApplicationState(void){
}

FUNC(void, OS_CODE) class_Os::GetNumberOfActivatedCores(void){
}

FUNC(void, OS_CODE) class_Os::GetCoreId(void){
}

FUNC(void, OS_CODE) class_Os::StartCore(void){
}

FUNC(void, OS_CODE) class_Os::StartNonAutosarCore(void){
}

FUNC(void, OS_CODE) class_Os::GetSpinlock(void){
}

FUNC(void, OS_CODE) class_Os::ReleaseSpinlock(void){
}

FUNC(void, OS_CODE) class_Os::TryToGetSpinlock(void){
}

FUNC(void, OS_CODE) class_Os::ShutdownAllCores(void){
}

FUNC(void, OS_CODE) class_Os::ControlIdle(void){
}

/*****************************************************/
/* EOF                                               */
/*****************************************************/

