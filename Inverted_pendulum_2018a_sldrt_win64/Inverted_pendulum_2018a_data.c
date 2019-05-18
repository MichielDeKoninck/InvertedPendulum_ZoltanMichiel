/*
 * Inverted_pendulum_2018a_data.c
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

/* Block parameters (default storage) */
P_Inverted_pendulum_2018a_T Inverted_pendulum_2018a_P = {
  /* Variable: K_realsetup
   * Referenced by: '<Root>/Gain1'
   */
  { -17.320508075687879, -42.723705833384336, -17.046378841870123,
    -7.607445845959421 },

  /* Variable: Omega_c
   * Referenced by:
   *   '<S5>/Gain'
   *   '<S5>/Gain1'
   *   '<S6>/Gain'
   *   '<S6>/Gain1'
   */
  157.07963267948966,

  /* Variable: Q_interval
   * Referenced by:
   *   '<Root>/Quantizer1'
   *   '<Root>/Quantizer2'
   */
  0.000152587890625,

  /* Variable: T_s
   * Referenced by:
   *   '<S3>/Gain2'
   *   '<S4>/Gain2'
   *   '<S5>/Gain'
   *   '<S5>/Gain1'
   *   '<S6>/Gain'
   *   '<S6>/Gain1'
   */
  0.005,

  /* Variable: V_max
   * Referenced by: '<Root>/Saturation1'
   */
  5.0,

  /* Variable: reference_State
   * Referenced by: '<Root>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: AnalogOutput_FinalValue
   * Referenced by: '<S2>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_InitialValue
   * Referenced by: '<S2>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<S1>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<S2>/Analog Output'
   */
  10.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<S1>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<S2>/Analog Output'
   */
  0.0,

  /* Mask Parameter: AnalogInputsInvertedPendulum_offset_alfa
   * Referenced by: '<S1>/Offset_alfa (volt)'
   */
  0.1437,

  /* Mask Parameter: AnalogInputsInvertedPendulum_offset_x
   * Referenced by: '<S1>/Offset_x (volts)'
   */
  -0.3421,

  /* Mask Parameter: AnalogInputsInvertedPendulum_v2m
   * Referenced by: '<S1>/Convertion actor'
   */
  0.1033,

  /* Mask Parameter: AnalogInputsInvertedPendulum_v2r
   * Referenced by: '<S1>/Convertion '
   */
  0.2482,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<S1>/Analog Input'
   */
  { 0, 1 },

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<S2>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<S1>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<S2>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<S1>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<S2>/Analog Output'
   */
  0,

  /* Expression: [-0.15;0;0;0]
   * Referenced by: '<Root>/Constant5'
   */
  { -0.15, 0.0, 0.0, 0.0 },

  /* Expression: [0.2;0;0;0]
   * Referenced by: '<Root>/Constant4'
   */
  { 0.2, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Off'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S5>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Unit Delay'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S2>/-5v to 5v'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S2>/-5v to 5v'
   */
  -5.0,

  /* Expression: -1
   * Referenced by: '<S2>/Gain'
   */
  -1.0,

  /* Expression: 180/pi
   * Referenced by: '<S7>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: Switch2_CurrentSetting
   * Referenced by: '<Root>/Switch  2'
   */
  1U,

  /* Computed Parameter: Switch1_CurrentSetting
   * Referenced by: '<Root>/Switch  1'
   */
  0U,

  /* Computed Parameter: Switch_CurrentSetting
   * Referenced by: '<Root>/Switch  '
   */
  0U
};
