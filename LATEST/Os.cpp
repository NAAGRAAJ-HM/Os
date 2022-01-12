#include "Os.h"

#include "Swc_Os.h"
#include "EcuM.h"

class_Os Os;

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

