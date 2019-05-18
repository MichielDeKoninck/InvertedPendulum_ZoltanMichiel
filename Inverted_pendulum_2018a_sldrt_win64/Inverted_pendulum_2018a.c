/*
 * Inverted_pendulum_2018a.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Inverted_pendulum_2018a".
 *
 * Model version              : 1.51
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Wed May 15 18:01:26 2019
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Inverted_pendulum_2018a.h"
#include "Inverted_pendulum_2018a_private.h"
#include "Inverted_pendulum_2018a_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  1.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.005, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCI-6014", 4294967295U, 6, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_Inverted_pendulum_2018a_T Inverted_pendulum_2018a_B;

/* Block states (default storage) */
DW_Inverted_pendulum_2018a_T Inverted_pendulum_2018a_DW;

/* Real-time model */
RT_MODEL_Inverted_pendulum_2018a_T Inverted_pendulum_2018a_M_;
RT_MODEL_Inverted_pendulum_2018a_T *const Inverted_pendulum_2018a_M =
  &Inverted_pendulum_2018a_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Inverted_pendulum_2018a_M->Timing.TaskCounters.TID[1])++;
  if ((Inverted_pendulum_2018a_M->Timing.TaskCounters.TID[1]) > 49) {/* Sample time: [0.25s, 0.0s] */
    Inverted_pendulum_2018a_M->Timing.TaskCounters.TID[1] = 0;
  }

  Inverted_pendulum_2018a_M->Timing.sampleHits[1] =
    (Inverted_pendulum_2018a_M->Timing.TaskCounters.TID[1] == 0);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function */
void Inverted_pendulum_2018a_output(void)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput[2];
  real_T rtb_Gain_h;
  real_T rtb_Add2;
  real_T rtb_Add1;
  real_T Add_tmp;
  real_T Add_tmp_0;

  /* S-Function (sldrtai): '<S1>/Analog Input' */
  /* S-Function Block: <S1>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) Inverted_pendulum_2018a_P.AnalogInput_RangeMode;
    parm.rangeidx = Inverted_pendulum_2018a_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 2,
                   Inverted_pendulum_2018a_P.AnalogInput_Channels,
                   &rtb_AnalogInput[0], &parm);
  }

  /* Sum: '<S1>/Add2' incorporates:
   *  Constant: '<S1>/Offset_x (volts)'
   */
  rtb_Add2 = Inverted_pendulum_2018a_P.AnalogInputsInvertedPendulum_offset_x +
    rtb_AnalogInput[0];

  /* Gain: '<S1>/Convertion actor' */
  Inverted_pendulum_2018a_B.Convertionactor =
    Inverted_pendulum_2018a_P.AnalogInputsInvertedPendulum_v2m * rtb_Add2;

  /* Gain: '<S6>/Gain' incorporates:
   *  Gain: '<S5>/Gain'
   */
  Add_tmp = Inverted_pendulum_2018a_P.Omega_c * Inverted_pendulum_2018a_P.T_s;
  Add_tmp /= Add_tmp + 1.0;

  /* Gain: '<S6>/Gain1' incorporates:
   *  Gain: '<S5>/Gain1'
   */
  Add_tmp_0 = 1.0 / (Inverted_pendulum_2018a_P.Omega_c *
                     Inverted_pendulum_2018a_P.T_s + 1.0);

  /* Sum: '<S6>/Add' incorporates:
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Quantizer: '<Root>/Quantizer1'
   *  UnitDelay: '<S6>/Unit Delay'
   */
  Inverted_pendulum_2018a_B.Add = Add_tmp * (rt_roundd_snf
    (Inverted_pendulum_2018a_B.Convertionactor /
     Inverted_pendulum_2018a_P.Q_interval) *
    Inverted_pendulum_2018a_P.Q_interval) + Add_tmp_0 *
    Inverted_pendulum_2018a_DW.UnitDelay_DSTATE;

  /* Sum: '<S1>/Add1' incorporates:
   *  Constant: '<S1>/Offset_alfa (volt)'
   */
  rtb_Add1 = rtb_AnalogInput[1] +
    Inverted_pendulum_2018a_P.AnalogInputsInvertedPendulum_offset_alfa;

  /* Gain: '<S1>/Convertion ' */
  Inverted_pendulum_2018a_B.Convertion =
    Inverted_pendulum_2018a_P.AnalogInputsInvertedPendulum_v2r * rtb_Add1;

  /* Quantizer: '<Root>/Quantizer2' */
  rtb_Gain_h = rt_roundd_snf(Inverted_pendulum_2018a_B.Convertion /
    Inverted_pendulum_2018a_P.Q_interval) * Inverted_pendulum_2018a_P.Q_interval;

  /* Sum: '<S5>/Add' incorporates:
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  Inverted_pendulum_2018a_B.Add_k = Add_tmp * rtb_Gain_h + Add_tmp_0 *
    Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_j;

  /* Gain: '<S3>/Gain2' incorporates:
   *  Sum: '<S3>/Subtract'
   *  UnitDelay: '<S3>/Unit Delay'
   */
  Inverted_pendulum_2018a_B.Gain2 = 1.0 / Inverted_pendulum_2018a_P.T_s *
    (Inverted_pendulum_2018a_B.Add -
     Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_n);

  /* Gain: '<S4>/Gain2' incorporates:
   *  Sum: '<S4>/Subtract'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  Inverted_pendulum_2018a_B.Gain2_o = 1.0 / Inverted_pendulum_2018a_P.T_s *
    (Inverted_pendulum_2018a_B.Add_k -
     Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_o);

  /* ManualSwitch: '<Root>/Switch  1' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (Inverted_pendulum_2018a_P.Switch1_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Switch  2' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Constant: '<Root>/Constant5'
     */
    if (Inverted_pendulum_2018a_P.Switch2_CurrentSetting == 1) {
      Inverted_pendulum_2018a_B.Switch1[0] =
        Inverted_pendulum_2018a_P.Constant4_Value[0];
      Inverted_pendulum_2018a_B.Switch1[1] =
        Inverted_pendulum_2018a_P.Constant4_Value[1];
      Inverted_pendulum_2018a_B.Switch1[2] =
        Inverted_pendulum_2018a_P.Constant4_Value[2];
      Inverted_pendulum_2018a_B.Switch1[3] =
        Inverted_pendulum_2018a_P.Constant4_Value[3];
    } else {
      Inverted_pendulum_2018a_B.Switch1[0] =
        Inverted_pendulum_2018a_P.Constant5_Value[0];
      Inverted_pendulum_2018a_B.Switch1[1] =
        Inverted_pendulum_2018a_P.Constant5_Value[1];
      Inverted_pendulum_2018a_B.Switch1[2] =
        Inverted_pendulum_2018a_P.Constant5_Value[2];
      Inverted_pendulum_2018a_B.Switch1[3] =
        Inverted_pendulum_2018a_P.Constant5_Value[3];
    }

    /* End of ManualSwitch: '<Root>/Switch  2' */
  } else {
    Inverted_pendulum_2018a_B.Switch1[0] =
      Inverted_pendulum_2018a_P.reference_State[0];
    Inverted_pendulum_2018a_B.Switch1[1] =
      Inverted_pendulum_2018a_P.reference_State[1];
    Inverted_pendulum_2018a_B.Switch1[2] =
      Inverted_pendulum_2018a_P.reference_State[2];
    Inverted_pendulum_2018a_B.Switch1[3] =
      Inverted_pendulum_2018a_P.reference_State[3];
  }

  /* End of ManualSwitch: '<Root>/Switch  1' */

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Add2'
   */
  Inverted_pendulum_2018a_B.Gain1 = (((Inverted_pendulum_2018a_B.Add -
    Inverted_pendulum_2018a_B.Switch1[0]) *
    -Inverted_pendulum_2018a_P.K_realsetup[0] + (Inverted_pendulum_2018a_B.Add_k
    - Inverted_pendulum_2018a_B.Switch1[1]) *
    -Inverted_pendulum_2018a_P.K_realsetup[1]) +
    (Inverted_pendulum_2018a_B.Gain2 - Inverted_pendulum_2018a_B.Switch1[2]) *
    -Inverted_pendulum_2018a_P.K_realsetup[2]) +
    (Inverted_pendulum_2018a_B.Gain2_o - Inverted_pendulum_2018a_B.Switch1[3]) *
    -Inverted_pendulum_2018a_P.K_realsetup[3];

  /* ManualSwitch: '<Root>/Switch  ' incorporates:
   *  Constant: '<Root>/Off'
   */
  if (Inverted_pendulum_2018a_P.Switch_CurrentSetting == 1) {
    /* Saturate: '<Root>/Saturation1' */
    if (Inverted_pendulum_2018a_B.Gain1 > Inverted_pendulum_2018a_P.V_max) {
      Inverted_pendulum_2018a_B.Switch = Inverted_pendulum_2018a_P.V_max;
    } else if (Inverted_pendulum_2018a_B.Gain1 <
               -Inverted_pendulum_2018a_P.V_max) {
      Inverted_pendulum_2018a_B.Switch = -Inverted_pendulum_2018a_P.V_max;
    } else {
      Inverted_pendulum_2018a_B.Switch = Inverted_pendulum_2018a_B.Gain1;
    }

    /* End of Saturate: '<Root>/Saturation1' */
  } else {
    Inverted_pendulum_2018a_B.Switch = Inverted_pendulum_2018a_P.Off_Value;
  }

  /* End of ManualSwitch: '<Root>/Switch  ' */

  /* Saturate: '<S2>/-5v to 5v' */
  if (Inverted_pendulum_2018a_B.Switch >
      Inverted_pendulum_2018a_P.uvto5v_UpperSat) {
    rtb_Gain_h = Inverted_pendulum_2018a_P.uvto5v_UpperSat;
  } else if (Inverted_pendulum_2018a_B.Switch <
             Inverted_pendulum_2018a_P.uvto5v_LowerSat) {
    rtb_Gain_h = Inverted_pendulum_2018a_P.uvto5v_LowerSat;
  } else {
    rtb_Gain_h = Inverted_pendulum_2018a_B.Switch;
  }

  /* End of Saturate: '<S2>/-5v to 5v' */

  /* Gain: '<S2>/Gain' */
  rtb_Gain_h *= Inverted_pendulum_2018a_P.Gain_Gain;

  /* S-Function (sldrtao): '<S2>/Analog Output' */
  /* S-Function Block: <S2>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Inverted_pendulum_2018a_P.AnalogOutput_RangeMode;
      parm.rangeidx = Inverted_pendulum_2018a_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Inverted_pendulum_2018a_P.AnalogOutput_Channels, ((real_T*)
        (&rtb_Gain_h)), &parm);
    }
  }

  /* ToAsyncQueueBlock: '<Root>/HiddenToAsyncQueue_InsertedFor_Analog Inputs Inverted Pendulum_at_outport_0' */
  {
    {
      double time = Inverted_pendulum_2018a_M->Timing.t[0];
      void *pData = (void *)&Inverted_pendulum_2018a_B.Convertionactor;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(519176298U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock: '<Root>/HiddenToAsyncQueue_InsertedFor_Analog Inputs Inverted Pendulum_at_outport_1' */
  {
    {
      double time = Inverted_pendulum_2018a_M->Timing.t[0];
      void *pData = (void *)&Inverted_pendulum_2018a_B.Convertion;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(7291499U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock: '<Root>/HiddenToAsyncQueue_InsertedFor_Switch  1_at_outport_0' */
  {
    {
      double time = Inverted_pendulum_2018a_M->Timing.t[0];
      void *pData = (void *)&Inverted_pendulum_2018a_B.Switch1[0];
      int32_T size = 4*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(1125411573U, time, pData, size);
    }
  }

  /* ToAsyncQueueBlock: '<Root>/HiddenToAsyncQueue_InsertedFor_Switch  _at_outport_0' */
  {
    {
      double time = Inverted_pendulum_2018a_M->Timing.t[0];
      void *pData = (void *)&Inverted_pendulum_2018a_B.Switch;
      int32_T size = 1*sizeof(real_T);
      sendToAsyncQueueTgtAppSvc(2939800355U, time, pData, size);
    }
  }

  /* RateTransition: '<S1>/Rate Transition1' */
  if (Inverted_pendulum_2018a_M->Timing.TaskCounters.TID[1] == 0) {
    Inverted_pendulum_2018a_B.RateTransition1[0] =
      Inverted_pendulum_2018a_B.Convertionactor;
    Inverted_pendulum_2018a_B.RateTransition1[1] =
      Inverted_pendulum_2018a_B.Convertion;

    /* Gain: '<S7>/Gain' */
    Inverted_pendulum_2018a_B.Gain = Inverted_pendulum_2018a_P.Gain_Gain_b *
      Inverted_pendulum_2018a_B.RateTransition1[1];

    /* RateTransition: '<S1>/Rate Transition' */
    Inverted_pendulum_2018a_B.RateTransition[0] = rtb_Add2;
    Inverted_pendulum_2018a_B.RateTransition[1] = rtb_Add1;
  }

  /* End of RateTransition: '<S1>/Rate Transition1' */
}

/* Model update function */
void Inverted_pendulum_2018a_update(void)
{
  /* Update for UnitDelay: '<S6>/Unit Delay' */
  Inverted_pendulum_2018a_DW.UnitDelay_DSTATE = Inverted_pendulum_2018a_B.Add;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_j =
    Inverted_pendulum_2018a_B.Add_k;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_n = Inverted_pendulum_2018a_B.Add;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_o =
    Inverted_pendulum_2018a_B.Add_k;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Inverted_pendulum_2018a_M->Timing.clockTick0)) {
    ++Inverted_pendulum_2018a_M->Timing.clockTickH0;
  }

  Inverted_pendulum_2018a_M->Timing.t[0] =
    Inverted_pendulum_2018a_M->Timing.clockTick0 *
    Inverted_pendulum_2018a_M->Timing.stepSize0 +
    Inverted_pendulum_2018a_M->Timing.clockTickH0 *
    Inverted_pendulum_2018a_M->Timing.stepSize0 * 4294967296.0;
  if (Inverted_pendulum_2018a_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.25s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Inverted_pendulum_2018a_M->Timing.clockTick1)) {
      ++Inverted_pendulum_2018a_M->Timing.clockTickH1;
    }

    Inverted_pendulum_2018a_M->Timing.t[1] =
      Inverted_pendulum_2018a_M->Timing.clockTick1 *
      Inverted_pendulum_2018a_M->Timing.stepSize1 +
      Inverted_pendulum_2018a_M->Timing.clockTickH1 *
      Inverted_pendulum_2018a_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void Inverted_pendulum_2018a_initialize(void)
{
  /* Start for S-Function (sldrtao): '<S2>/Analog Output' */

  /* S-Function Block: <S2>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Inverted_pendulum_2018a_P.AnalogOutput_RangeMode;
      parm.rangeidx = Inverted_pendulum_2018a_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Inverted_pendulum_2018a_P.AnalogOutput_Channels,
                     &Inverted_pendulum_2018a_P.AnalogOutput_InitialValue, &parm);
    }
  }

  /* InitializeConditions for UnitDelay: '<S6>/Unit Delay' */
  Inverted_pendulum_2018a_DW.UnitDelay_DSTATE =
    Inverted_pendulum_2018a_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_j =
    Inverted_pendulum_2018a_P.UnitDelay_InitialCondition_l;

  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
  Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_n =
    Inverted_pendulum_2018a_P.UnitDelay_InitialCondition_b;

  /* InitializeConditions for UnitDelay: '<S4>/Unit Delay' */
  Inverted_pendulum_2018a_DW.UnitDelay_DSTATE_o =
    Inverted_pendulum_2018a_P.UnitDelay_InitialCondition_m;
}

/* Model terminate function */
void Inverted_pendulum_2018a_terminate(void)
{
  /* Terminate for S-Function (sldrtao): '<S2>/Analog Output' */

  /* S-Function Block: <S2>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Inverted_pendulum_2018a_P.AnalogOutput_RangeMode;
      parm.rangeidx = Inverted_pendulum_2018a_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Inverted_pendulum_2018a_P.AnalogOutput_Channels,
                     &Inverted_pendulum_2018a_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Inverted_pendulum_2018a_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Inverted_pendulum_2018a_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  Inverted_pendulum_2018a_initialize();
}

void MdlTerminate(void)
{
  Inverted_pendulum_2018a_terminate();
}

/* Registration function */
RT_MODEL_Inverted_pendulum_2018a_T *Inverted_pendulum_2018a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Inverted_pendulum_2018a_M, 0,
                sizeof(RT_MODEL_Inverted_pendulum_2018a_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Inverted_pendulum_2018a_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Inverted_pendulum_2018a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Inverted_pendulum_2018a_M->Timing.sampleTimes =
      (&Inverted_pendulum_2018a_M->Timing.sampleTimesArray[0]);
    Inverted_pendulum_2018a_M->Timing.offsetTimes =
      (&Inverted_pendulum_2018a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Inverted_pendulum_2018a_M->Timing.sampleTimes[0] = (0.005);
    Inverted_pendulum_2018a_M->Timing.sampleTimes[1] = (0.25);

    /* task offsets */
    Inverted_pendulum_2018a_M->Timing.offsetTimes[0] = (0.0);
    Inverted_pendulum_2018a_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Inverted_pendulum_2018a_M,
             &Inverted_pendulum_2018a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Inverted_pendulum_2018a_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Inverted_pendulum_2018a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Inverted_pendulum_2018a_M, -1);
  Inverted_pendulum_2018a_M->Timing.stepSize0 = 0.005;
  Inverted_pendulum_2018a_M->Timing.stepSize1 = 0.25;

  /* External mode info */
  Inverted_pendulum_2018a_M->Sizes.checksums[0] = (2416031737U);
  Inverted_pendulum_2018a_M->Sizes.checksums[1] = (640436642U);
  Inverted_pendulum_2018a_M->Sizes.checksums[2] = (529683781U);
  Inverted_pendulum_2018a_M->Sizes.checksums[3] = (2466065626U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Inverted_pendulum_2018a_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Inverted_pendulum_2018a_M->extModeInfo,
      &Inverted_pendulum_2018a_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Inverted_pendulum_2018a_M->extModeInfo,
                        Inverted_pendulum_2018a_M->Sizes.checksums);
    rteiSetTPtr(Inverted_pendulum_2018a_M->extModeInfo, rtmGetTPtr
                (Inverted_pendulum_2018a_M));
  }

  Inverted_pendulum_2018a_M->solverInfoPtr =
    (&Inverted_pendulum_2018a_M->solverInfo);
  Inverted_pendulum_2018a_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&Inverted_pendulum_2018a_M->solverInfo, 0.005);
  rtsiSetSolverMode(&Inverted_pendulum_2018a_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Inverted_pendulum_2018a_M->blockIO = ((void *) &Inverted_pendulum_2018a_B);
  (void) memset(((void *) &Inverted_pendulum_2018a_B), 0,
                sizeof(B_Inverted_pendulum_2018a_T));

  /* parameters */
  Inverted_pendulum_2018a_M->defaultParam = ((real_T *)
    &Inverted_pendulum_2018a_P);

  /* states (dwork) */
  Inverted_pendulum_2018a_M->dwork = ((void *) &Inverted_pendulum_2018a_DW);
  (void) memset((void *)&Inverted_pendulum_2018a_DW, 0,
                sizeof(DW_Inverted_pendulum_2018a_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Inverted_pendulum_2018a_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  Inverted_pendulum_2018a_M->Sizes.numContStates = (0);/* Number of continuous states */
  Inverted_pendulum_2018a_M->Sizes.numY = (0);/* Number of model outputs */
  Inverted_pendulum_2018a_M->Sizes.numU = (0);/* Number of model inputs */
  Inverted_pendulum_2018a_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Inverted_pendulum_2018a_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Inverted_pendulum_2018a_M->Sizes.numBlocks = (56);/* Number of blocks */
  Inverted_pendulum_2018a_M->Sizes.numBlockIO = (12);/* Number of block outputs */
  Inverted_pendulum_2018a_M->Sizes.numBlockPrms = (49);/* Sum of parameter "widths" */
  return Inverted_pendulum_2018a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
