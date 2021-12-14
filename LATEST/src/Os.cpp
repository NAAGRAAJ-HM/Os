#include "Os.h"

#include "Swc_Os.h"
#include "EcuM.h"

class_Os Os;

static void Activate_Task(void){
   EcuM.StartupTwo();
}

void class_Os::Start(void){
   Swc_Os.StartupHook();
   Activate_Task();
}

void class_Os::Shutdown(void){
   Swc_Os.ShutdownHook();
}

void class_Os::GetResource(void){
}

void class_Os::ReleaseResource(void){
}

void class_Os::EnableAllInterrupts(void){
}

void class_Os::DisableAllInterrupts(void){
}

