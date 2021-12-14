#pragma once

class class_Os{
   public:
      void Start                (void);
      void Shutdown             (void);
      void GetResource          (void);
      void ReleaseResource      (void);
      void EnableAllInterrupts  (void);
      void DisableAllInterrupts (void);
};

extern class_Os Os;

