#pragma once
/******************************************************************************/
/* File   : Os_core.hpp                                                       */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/
#include "CompilerCfg_Os.hpp"

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/
#define OS_CORE_FUNCTIONALITIES                                                \
              FUNC(void, OS_CODE) Activate_Task              (void);           \
              FUNC(void, OS_CODE) Start                      (void);           \
              FUNC(void, OS_CODE) Shutdown                   (void);           \
              FUNC(void, OS_CODE) GetResource                (void);           \
              FUNC(void, OS_CODE) ReleaseResource            (void);           \
              FUNC(void, OS_CODE) DisableAllInterrupts       (void);           \
              FUNC(void, OS_CODE) EnableAllInterrupts        (void);           \
              FUNC(void, OS_CODE) GetApplicationID           (void);           \
              FUNC(void, OS_CODE) GetCurrentApplicationID    (void);           \
              FUNC(void, OS_CODE) GetISRID                   (void);           \
              FUNC(void, OS_CODE) CallTrustedFunction        (void);           \
              FUNC(void, OS_CODE) CheckISRMemoryAccess       (void);           \
              FUNC(void, OS_CODE) CheckTaskMemoryAccess      (void);           \
              FUNC(void, OS_CODE) CheckObjectAccess          (void);           \
              FUNC(void, OS_CODE) CheckObjectOwnership       (void);           \
              FUNC(void, OS_CODE) StartScheduleTableRel      (void);           \
              FUNC(void, OS_CODE) StartScheduleTableAbs      (void);           \
              FUNC(void, OS_CODE) StopScheduleTable          (void);           \
              FUNC(void, OS_CODE) NextScheduleTable          (void);           \
              FUNC(void, OS_CODE) StartScheduleTableSynchron (void);           \
              FUNC(void, OS_CODE) SyncScheduleTable          (void);           \
              FUNC(void, OS_CODE) SetScheduleTableAsync      (void);           \
              FUNC(void, OS_CODE) GetScheduleTableStatus     (void);           \
              FUNC(void, OS_CODE) IncrementCounter           (void);           \
              FUNC(void, OS_CODE) GetCounterValue            (void);           \
              FUNC(void, OS_CODE) GetElapsedValue            (void);           \
              FUNC(void, OS_CODE) TerminateApplication       (void);           \
              FUNC(void, OS_CODE) AllowAccess                (void);           \
              FUNC(void, OS_CODE) GetApplicationState        (void);           \
              FUNC(void, OS_CODE) GetNumberOfActivatedCores  (void);           \
              FUNC(void, OS_CODE) GetCoreId                  (void);           \
              FUNC(void, OS_CODE) StartCore                  (void);           \
              FUNC(void, OS_CODE) StartNonAutosarCore        (void);           \
              FUNC(void, OS_CODE) GetSpinlock                (void);           \
              FUNC(void, OS_CODE) ReleaseSpinlock            (void);           \
              FUNC(void, OS_CODE) TryToGetSpinlock           (void);           \
              FUNC(void, OS_CODE) ShutdownAllCores           (void);           \
              FUNC(void, OS_CODE) ControlIdle                (void);           \

#define OS_CORE_FUNCTIONALITIES_VIRTUAL                                        \
      virtual FUNC(void, OS_CODE) Activate_Task              (void) = 0;       \
      virtual FUNC(void, OS_CODE) Start                      (void) = 0;       \
      virtual FUNC(void, OS_CODE) Shutdown                   (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetResource                (void) = 0;       \
      virtual FUNC(void, OS_CODE) ReleaseResource            (void) = 0;       \
      virtual FUNC(void, OS_CODE) DisableAllInterrupts       (void) = 0;       \
      virtual FUNC(void, OS_CODE) EnableAllInterrupts        (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetApplicationID           (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetCurrentApplicationID    (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetISRID                   (void) = 0;       \
      virtual FUNC(void, OS_CODE) CallTrustedFunction        (void) = 0;       \
      virtual FUNC(void, OS_CODE) CheckISRMemoryAccess       (void) = 0;       \
      virtual FUNC(void, OS_CODE) CheckTaskMemoryAccess      (void) = 0;       \
      virtual FUNC(void, OS_CODE) CheckObjectAccess          (void) = 0;       \
      virtual FUNC(void, OS_CODE) CheckObjectOwnership       (void) = 0;       \
      virtual FUNC(void, OS_CODE) StartScheduleTableRel      (void) = 0;       \
      virtual FUNC(void, OS_CODE) StartScheduleTableAbs      (void) = 0;       \
      virtual FUNC(void, OS_CODE) StopScheduleTable          (void) = 0;       \
      virtual FUNC(void, OS_CODE) NextScheduleTable          (void) = 0;       \
      virtual FUNC(void, OS_CODE) StartScheduleTableSynchron (void) = 0;       \
      virtual FUNC(void, OS_CODE) SyncScheduleTable          (void) = 0;       \
      virtual FUNC(void, OS_CODE) SetScheduleTableAsync      (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetScheduleTableStatus     (void) = 0;       \
      virtual FUNC(void, OS_CODE) IncrementCounter           (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetCounterValue            (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetElapsedValue            (void) = 0;       \
      virtual FUNC(void, OS_CODE) TerminateApplication       (void) = 0;       \
      virtual FUNC(void, OS_CODE) AllowAccess                (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetApplicationState        (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetNumberOfActivatedCores  (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetCoreId                  (void) = 0;       \
      virtual FUNC(void, OS_CODE) StartCore                  (void) = 0;       \
      virtual FUNC(void, OS_CODE) StartNonAutosarCore        (void) = 0;       \
      virtual FUNC(void, OS_CODE) GetSpinlock                (void) = 0;       \
      virtual FUNC(void, OS_CODE) ReleaseSpinlock            (void) = 0;       \
      virtual FUNC(void, OS_CODE) TryToGetSpinlock           (void) = 0;       \
      virtual FUNC(void, OS_CODE) ShutdownAllCores           (void) = 0;       \
      virtual FUNC(void, OS_CODE) ControlIdle                (void) = 0;       \

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

/******************************************************************************/
/* TYPEDEFS                                                                   */
/******************************************************************************/
class class_Os_Functionality{
   public:
      OS_CORE_FUNCTIONALITIES_VIRTUAL
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

