TYPE
  S_FA_STATUS : STRUCT
    BART_Hand : BOOL := true;
    BART_Auto : BOOL := false;
    Stoerung : BOOL := false;
    Stoer_Quit : BOOL := false;
    NotHalt : BOOL := false;
    Takt : BOOL := false;
  END_STRUCT;
END_TYPE

FUNCTION_BLOCK AKT_5_2_MV
  VAR_INPUT
    Hand_P1 : BOOL;
    Hand_P2 : BOOL;
  END_VAR
  VAR
    SR0 : SR;
    DebugBoolean : BOOL;
  END_VAR

  SR0(S1 := Hand_P2, R := Hand_P1);
  DebugBoolean := SR0.Q1;
END_FUNCTION_BLOCK

FUNCTION FA_SERV : BOOL
  VAR_INPUT
    status : S_FA_STATUS;
    BART_Hand : BOOL;
    BART_Auto : BOOL;
    Stoerung : BOOL;
    Stoer_Quit : BOOL;
    NotHalt : BOOL;
  END_VAR

  status.BART_Hand := BART_Hand;
  FA_SERV := status.BART_Hand;
  status.BART_Auto := BART_Auto;
  status.Stoerung := Stoerung;
  status.Stoer_Quit := Stoer_Quit;
  status.NotHalt := NotHalt;
END_FUNCTION

PROGRAM program0_POU
  VAR
    FA_Start_T_HMI : BOOL;
    FA_Init_T_HMI : BOOL;
    FA_Sonder_T_HMI : BOOL;
    FA_Stop_T_HMI : BOOL;
    FA_BART_Hand_T_HMI : BOOL;
    FA_BART_Auto_T_HMI : BOOL;
    FA_BART_Auto_Einzel_T_HMI : BOOL;
    FA_Stoerung_T_HMI : BOOL;
    FA_Stoer_Quit_T_HMI : BOOL;
    FA_NotHalt_T_HMI : BOOL;
    DebugBoolean : BOOL;
    FA_Status : S_FA_STATUS;
  END_VAR
  VAR_EXTERNAL
    global_status : S_FA_STATUS;
  END_VAR
  VAR
    AKT_5_2_MV0 : AKT_5_2_MV;
    Zyl1_T_P1_HMI : BOOL;
    Zyl1_T_P2_HMI : BOOL;
    _TMP_FA_SERV1_OUT : BOOL;
  END_VAR

  FA_Status.BART_Hand := FA_Start_T_HMI;
  global_status.BART_Hand := FA_Start_T_HMI;
  _TMP_FA_SERV1_OUT := FA_SERV(global_status, FA_BART_Hand_T_HMI, FA_BART_Auto_T_HMI, FA_Stoerung_T_HMI, FA_Stoer_Quit_T_HMI, FA_NotHalt_T_HMI);
  DebugBoolean := _TMP_FA_SERV1_OUT;
  AKT_5_2_MV0(Hand_P1 := Zyl1_T_P1_HMI, Hand_P2 := Zyl1_T_P2_HMI);
END_PROGRAM

FUNCTION_BLOCK FA
  VAR
    Status : S_FA_STATUS;
  END_VAR

  Status.Stoerung := TRUE;
END_FUNCTION_BLOCK


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    VAR_GLOBAL
      global_status : S_FA_STATUS;
    END_VAR
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0_POU;
  END_RESOURCE
END_CONFIGURATION
