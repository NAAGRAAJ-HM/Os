#pragma once
/******************************************************************************/
/* File   : ServiceOs_core.hpp                                                       */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_ServiceOs.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define SERVICEOS_CORE_FUNCTIONALITIES                                                \
              FUNC(void, SERVICEOS_CODE) Activate_Task              (void);           \
              FUNC(void, SERVICEOS_CODE) Start                      (void);           \
              FUNC(void, SERVICEOS_CODE) Shutdown                   (void);           \
              FUNC(void, SERVICEOS_CODE) GetResource                (void);           \
              FUNC(void, SERVICEOS_CODE) ReleaseResource            (void);           \
              FUNC(void, SERVICEOS_CODE) DisableAllInterrupts       (void);           \
              FUNC(void, SERVICEOS_CODE) EnableAllInterrupts        (void);           \
              FUNC(void, SERVICEOS_CODE) GetApplicationID           (void);           \
              FUNC(void, SERVICEOS_CODE) GetCurrentApplicationID    (void);           \
              FUNC(void, SERVICEOS_CODE) GetISRID                   (void);           \
              FUNC(void, SERVICEOS_CODE) CallTrustedFunction        (void);           \
              FUNC(void, SERVICEOS_CODE) CheckISRMemoryAccess       (void);           \
              FUNC(void, SERVICEOS_CODE) CheckTaskMemoryAccess      (void);           \
              FUNC(void, SERVICEOS_CODE) CheckObjectAccess          (void);           \
              FUNC(void, SERVICEOS_CODE) CheckObjectOwnership       (void);           \
              FUNC(void, SERVICEOS_CODE) StartScheduleTableRel      (void);           \
              FUNC(void, SERVICEOS_CODE) StartScheduleTableAbs      (void);           \
              FUNC(void, SERVICEOS_CODE) StopScheduleTable          (void);           \
              FUNC(void, SERVICEOS_CODE) NextScheduleTable          (void);           \
              FUNC(void, SERVICEOS_CODE) StartScheduleTableSynchron (void);           \
              FUNC(void, SERVICEOS_CODE) SyncScheduleTable          (void);           \
              FUNC(void, SERVICEOS_CODE) SetScheduleTableAsync      (void);           \
              FUNC(void, SERVICEOS_CODE) GetScheduleTableStatus     (void);           \
              FUNC(void, SERVICEOS_CODE) IncrementCounter           (void);           \
              FUNC(void, SERVICEOS_CODE) GetCounterValue            (void);           \
              FUNC(void, SERVICEOS_CODE) GetElapsedValue            (void);           \
              FUNC(void, SERVICEOS_CODE) TerminateApplication       (void);           \
              FUNC(void, SERVICEOS_CODE) AllowAccess                (void);           \
              FUNC(void, SERVICEOS_CODE) GetApplicationState        (void);           \
              FUNC(void, SERVICEOS_CODE) GetNumberOfActivatedCores  (void);           \
              FUNC(void, SERVICEOS_CODE) GetCoreId                  (void);           \
              FUNC(void, SERVICEOS_CODE) StartCore                  (void);           \
              FUNC(void, SERVICEOS_CODE) StartNonAutosarCore        (void);           \
              FUNC(void, SERVICEOS_CODE) GetMcalSpinlock                (void);           \
              FUNC(void, SERVICEOS_CODE) ReleaseMcalSpinlock            (void);           \
              FUNC(void, SERVICEOS_CODE) TryToGetMcalSpinlock           (void);           \
              FUNC(void, SERVICEOS_CODE) ShutdownAllCores           (void);           \
              FUNC(void, SERVICEOS_CODE) ControlIdle                (void);           \

#define SERVICEOS_CORE_FUNCTIONALITIES_VIRTUAL                                        \
      virtual FUNC(void, SERVICEOS_CODE) Activate_Task              (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) Start                      (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) Shutdown                   (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetResource                (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) ReleaseResource            (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) DisableAllInterrupts       (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) EnableAllInterrupts        (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetApplicationID           (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetCurrentApplicationID    (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetISRID                   (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) CallTrustedFunction        (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) CheckISRMemoryAccess       (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) CheckTaskMemoryAccess      (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) CheckObjectAccess          (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) CheckObjectOwnership       (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) StartScheduleTableRel      (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) StartScheduleTableAbs      (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) StopScheduleTable          (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) NextScheduleTable          (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) StartScheduleTableSynchron (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) SyncScheduleTable          (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) SetScheduleTableAsync      (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetScheduleTableStatus     (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) IncrementCounter           (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetCounterValue            (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetElapsedValue            (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) TerminateApplication       (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) AllowAccess                (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetApplicationState        (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetNumberOfActivatedCores  (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetCoreId                  (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) StartCore                  (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) StartNonAutosarCore        (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) GetMcalSpinlock                (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) ReleaseMcalSpinlock            (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) TryToGetMcalSpinlock           (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) ShutdownAllCores           (void) = 0;       \
      virtual FUNC(void, SERVICEOS_CODE) ControlIdle                (void) = 0;       \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_ServiceOs_Functionality{
   public:
      SERVICEOS_CORE_FUNCTIONALITIES_VIRTUAL
};

/******************************************************************************/
/* CONSTS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* PARAMS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* OBJECTS                                                                    */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/******************************************************************************/
/* EOF                                                                        */
/******************************************************************************/

