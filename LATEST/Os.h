#pragma once

#include "Std_Types.h"
#include "Compiler_Cfg_Os.h"

class class_Os{
   public:
      FUNC(void, OS_CODE) Start                (void);
      FUNC(void, OS_CODE) Shutdown             (void);
      FUNC(void, OS_CODE) GetResource          (void);
      FUNC(void, OS_CODE) ReleaseResource      (void);
      FUNC(void, OS_CODE) EnableAllInterrupts  (void);
      FUNC(void, OS_CODE) DisableAllInterrupts (void);
};

extern class_Os Os;

