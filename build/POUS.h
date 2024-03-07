#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
__DECLARE_STRUCT_TYPE(S_FA_STATUS,
  BOOL BART_HAND;
    BOOL BART_AUTO;
    BOOL STOERUNG;
    BOOL STOER_QUIT;
    BOOL NOTHALT;
    BOOL TAKT;
  )
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// FUNCTION_BLOCK AKT_5_2_MV
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,HAND_P1)
  __DECLARE_VAR(BOOL,HAND_P2)
  __DECLARE_VAR(BOOL,S_MV_P2_FF)

  // FB private variables - TEMP, private and located variables
  SR SR0;
  __DECLARE_VAR(BOOL,DEBUGBOOLEAN)

} AKT_5_2_MV;

void AKT_5_2_MV_init__(AKT_5_2_MV *data__, BOOL retain);
// Code part
void AKT_5_2_MV_body__(AKT_5_2_MV *data__);
// FUNCTION
BOOL FA_SERV(
  BOOL EN, 
  BOOL *__ENO, 
  S_FA_STATUS STATUS, 
  BOOL BART_HAND, 
  BOOL BART_AUTO, 
  BOOL STOERUNG, 
  BOOL STOER_QUIT, 
  BOOL NOTHALT);
// PROGRAM PROGRAM0_POU
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,FA_START_T_HMI)
  __DECLARE_VAR(BOOL,FA_INIT_T_HMI)
  __DECLARE_VAR(BOOL,FA_SONDER_T_HMI)
  __DECLARE_VAR(BOOL,FA_STOP_T_HMI)
  __DECLARE_VAR(BOOL,FA_BART_HAND_T_HMI)
  __DECLARE_VAR(BOOL,FA_BART_AUTO_T_HMI)
  __DECLARE_VAR(BOOL,FA_BART_AUTO_EINZEL_T_HMI)
  __DECLARE_VAR(BOOL,FA_STOERUNG_T_HMI)
  __DECLARE_VAR(BOOL,FA_STOER_QUIT_T_HMI)
  __DECLARE_VAR(BOOL,FA_NOTHALT_T_HMI)
  __DECLARE_VAR(BOOL,DEBUGBOOLEAN)
  __DECLARE_VAR(S_FA_STATUS,FA_STATUS)
  __DECLARE_EXTERNAL(S_FA_STATUS,GLOBAL_STATUS)
  AKT_5_2_MV AKT_5_2_MV0;
  __DECLARE_VAR(BOOL,ZYL1_T_P1_HMI)
  __DECLARE_VAR(BOOL,ZYL1_T_P2_HMI)
  __DECLARE_VAR(BOOL,S_MV_P2_FF)
  __DECLARE_VAR(BOOL,_TMP_FA_SERV1_OUT)

} PROGRAM0_POU;

void PROGRAM0_POU_init__(PROGRAM0_POU *data__, BOOL retain);
// Code part
void PROGRAM0_POU_body__(PROGRAM0_POU *data__);
// FUNCTION_BLOCK FA
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(S_FA_STATUS,STATUS)

} FA;

void FA_init__(FA *data__, BOOL retain);
// Code part
void FA_body__(FA *data__);
#endif //__POUS_H
