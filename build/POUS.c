void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void AKT_5_2_MV_init__(AKT_5_2_MV *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const S_FA_STATUS temp = {__BOOL_LITERAL(TRUE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE)};
    __SET_VAR(data__->,STATUS,,temp);
  }
  __INIT_VAR(data__->HAND_P1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->HAND_P2,__BOOL_LITERAL(FALSE),retain)
  SR_init__(&data__->SR0,retain);
  __INIT_VAR(data__->S_MV_P2_FF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DEBUGBOOLEAN,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->CONST_T_LAUFZEIT_P2,__time_to_timespec(1, 0, 10, 0, 0, 0),retain)
  __INIT_VAR(data__->SEN_P1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEN_P2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND6_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND9_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND15_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void AKT_5_2_MV_body__(AKT_5_2_MV *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_AND6_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->STATUS,.BART_HAND),
    (BOOL)__GET_VAR(data__->HAND_P2,)));
  __SET_VAR(data__->,_TMP_AND9_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->STATUS,.BART_HAND),
    (BOOL)__GET_VAR(data__->HAND_P1,)));
  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->_TMP_AND6_OUT,));
  __SET_VAR(data__->SR0.,R,,__GET_VAR(data__->_TMP_AND9_OUT,));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,S_MV_P2_FF,,__GET_VAR(data__->SR0.Q1,));
  __SET_VAR(data__->,_TMP_NOT17_OUT,,!(__GET_VAR(data__->SEN_P2,)));
  __SET_VAR(data__->,_TMP_AND15_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_NOT17_OUT,),
    (BOOL)__GET_VAR(data__->HAND_P2,)));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->_TMP_AND15_OUT,));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->CONST_T_LAUFZEIT_P2,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,DEBUGBOOLEAN,,__GET_VAR(data__->TON0.Q,));

  goto __end;

__end:
  return;
} // AKT_5_2_MV_body__() 





// FUNCTION
BOOL FA_SERV(
  BOOL EN, 
  BOOL *__ENO, 
  S_FA_STATUS STATUS, 
  BOOL BART_HAND, 
  BOOL BART_AUTO, 
  BOOL STOERUNG, 
  BOOL STOER_QUIT, 
  BOOL NOTHALT)
{
  BOOL ENO = __BOOL_LITERAL(TRUE);
  BOOL FA_SERV = __BOOL_LITERAL(FALSE);

  // Control execution
  if (!EN) {
    if (__ENO != NULL) {
      *__ENO = __BOOL_LITERAL(FALSE);
    }
    return FA_SERV;
  }
  STATUS.BART_HAND = BART_HAND;
  FA_SERV = STATUS.BART_HAND;
  STATUS.BART_AUTO = BART_AUTO;
  STATUS.STOERUNG = STOERUNG;
  STATUS.STOER_QUIT = STOER_QUIT;
  STATUS.NOTHALT = NOTHALT;

  goto __end;

__end:
  if (__ENO != NULL) {
    *__ENO = ENO;
  }
  return FA_SERV;
}


void PROGRAM0_POU_init__(PROGRAM0_POU *data__, BOOL retain) {
  __INIT_VAR(data__->FA_START_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_INIT_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_SONDER_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_STOP_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_BART_HAND_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_BART_AUTO_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_BART_AUTO_EINZEL_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_STOERUNG_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_STOER_QUIT_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FA_NOTHALT_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DEBUGBOOLEAN,__BOOL_LITERAL(FALSE),retain)
  {
    static const S_FA_STATUS temp = {__BOOL_LITERAL(TRUE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE)};
    __SET_VAR(data__->,FA_STATUS,,temp);
  }
  __INIT_EXTERNAL(S_FA_STATUS,GLOBAL_STATUS,data__->GLOBAL_STATUS,retain)
  AKT_5_2_MV_init__(&data__->AKT_5_2_MV0,retain);
  __INIT_VAR(data__->ZYL1_T_P1_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ZYL1_T_P2_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->S_MV_P2_FF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEN_P1_T_HMI,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->SEN_P2_T_HMI,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_FA_SERV1_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_POU_body__(PROGRAM0_POU *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,FA_STATUS,.BART_HAND,__GET_VAR(data__->FA_START_T_HMI,));
  __SET_EXTERNAL(data__->,GLOBAL_STATUS,.BART_HAND,__GET_VAR(data__->FA_START_T_HMI,));
  __SET_VAR(data__->,_TMP_FA_SERV1_OUT,,FA_SERV(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (S_FA_STATUS)__GET_EXTERNAL(data__->GLOBAL_STATUS,),
    (BOOL)__GET_VAR(data__->FA_BART_HAND_T_HMI,),
    (BOOL)__GET_VAR(data__->FA_BART_AUTO_T_HMI,),
    (BOOL)__GET_VAR(data__->FA_STOERUNG_T_HMI,),
    (BOOL)__GET_VAR(data__->FA_STOER_QUIT_T_HMI,),
    (BOOL)__GET_VAR(data__->FA_NOTHALT_T_HMI,)));
  __SET_VAR(data__->,DEBUGBOOLEAN,,__GET_VAR(data__->_TMP_FA_SERV1_OUT,));
  __SET_VAR(data__->AKT_5_2_MV0.,STATUS,,__GET_EXTERNAL(data__->GLOBAL_STATUS,));
  __SET_VAR(data__->AKT_5_2_MV0.,HAND_P1,,__GET_VAR(data__->ZYL1_T_P1_HMI,));
  __SET_VAR(data__->AKT_5_2_MV0.,HAND_P2,,__GET_VAR(data__->ZYL1_T_P2_HMI,));
  __SET_VAR(data__->AKT_5_2_MV0.,SEN_P1,,__GET_VAR(data__->SEN_P1_T_HMI,));
  __SET_VAR(data__->AKT_5_2_MV0.,SEN_P2,,__GET_VAR(data__->SEN_P2_T_HMI,));
  AKT_5_2_MV_body__(&data__->AKT_5_2_MV0);
  __SET_VAR(data__->,S_MV_P2_FF,,__GET_VAR(data__->AKT_5_2_MV0.S_MV_P2_FF,));

  goto __end;

__end:
  return;
} // PROGRAM0_POU_body__() 





void FA_init__(FA *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  {
    static const S_FA_STATUS temp = {__BOOL_LITERAL(TRUE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE)};
    __SET_VAR(data__->,STATUS,,temp);
  }
}

// Code part
void FA_body__(FA *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,STATUS,.STOERUNG,__BOOL_LITERAL(TRUE));

  goto __end;

__end:
  return;
} // FA_body__() 





