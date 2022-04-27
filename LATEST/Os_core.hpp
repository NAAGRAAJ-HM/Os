#pragma once
/******************************************************************************/
/* File   : Os_core.hpp                                                       */
/* Author : NAGARAJA HM (c) since 1982. All rights reserved.                  */
/******************************************************************************/

/******************************************************************************/
/* #INCLUDES                                                                  */
/******************************************************************************/

/******************************************************************************/
/* #DEFINES                                                                   */
/******************************************************************************/

/******************************************************************************/
/* MACROS                                                                     */
/******************************************************************************/

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

