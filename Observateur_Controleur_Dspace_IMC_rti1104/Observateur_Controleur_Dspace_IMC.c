/*
 * Observateur_Controleur_Dspace_IMC.c
 *
 * Code generation for model "Observateur_Controleur_Dspace_IMC".
 *
 * Model version              : 1.373
 * Simulink Coder version : 8.3 (R2012b) 20-Jul-2012
 * C source code generated on : Wed Sep 28 15:55:49 2016
 *
 * Target selection: rti1104.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "Observateur_Controleur_Dspace_IMC_trc_ptr.h"
#include "Observateur_Controleur_Dspace_IMC.h"
#include "Observateur_Controleur_Dspace_IMC_private.h"

/* Block signals (auto storage) */
BlockIO_Observateur_Controleur_ Observateur_Controleur_Dspace_B;

/* Continuous states */
ContinuousStates_Observateur_Co Observateur_Controleur_Dspace_X;

/* Block states (auto storage) */
D_Work_Observateur_Controleur_D Observateur_Controleur_Ds_DWork;

/* Real-time model */
RT_MODEL_Observateur_Controleur Observateur_Controleur_Dspac_M_;
RT_MODEL_Observateur_Controleur *const Observateur_Controleur_Dspac_M =
  &Observateur_Controleur_Dspac_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Observateur_Controleur_Dspace_IMC_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  Observateur_Controleur_Dspace_IMC_output();
  Observateur_Controleur_Dspace_IMC_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  Observateur_Controleur_Dspace_IMC_output();
  Observateur_Controleur_Dspace_IMC_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  Observateur_Controleur_Dspace_IMC_output();
  Observateur_Controleur_Dspace_IMC_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Observateur_Controleur_Dspace_IMC_output(void)
{
  real_T u;
  real_T u_0;
  real_T u_1;
  if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
    /* set solver stop time */
    if (!(Observateur_Controleur_Dspac_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Observateur_Controleur_Dspac_M->solverInfo,
                            ((Observateur_Controleur_Dspac_M->Timing.clockTickH0
        + 1) * Observateur_Controleur_Dspac_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Observateur_Controleur_Dspac_M->solverInfo,
                            ((Observateur_Controleur_Dspac_M->Timing.clockTick0
        + 1) * Observateur_Controleur_Dspac_M->Timing.stepSize0 +
        Observateur_Controleur_Dspac_M->Timing.clockTickH0 *
        Observateur_Controleur_Dspac_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Observateur_Controleur_Dspac_M)) {
    Observateur_Controleur_Dspac_M->Timing.t[0] = rtsiGetT
      (&Observateur_Controleur_Dspac_M->solverInfo);
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  Observateur_Controleur_Dspace_B.TransferFcn =
    Observateur_Controleur_Dspace_P.TransferFcn_C*
    Observateur_Controleur_Dspace_X.TransferFcn_CSTATE;

  /* Gain: '<S1>/Gain1' */
  Observateur_Controleur_Dspace_B.Gain1 =
    Observateur_Controleur_Dspace_P.Gain1_Gain *
    Observateur_Controleur_Dspace_B.TransferFcn;
  if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
    /* DiscreteStateSpace: '<Root>/Observateur Controleur2' */
    {
      Observateur_Controleur_Dspace_B.ObservateurControleur2[0] =
        (Observateur_Controleur_Dspace_P.ObservateurControleur2_C[0])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0];
      Observateur_Controleur_Dspace_B.ObservateurControleur2[1] =
        (Observateur_Controleur_Dspace_P.ObservateurControleur2_C[1])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[1];
      Observateur_Controleur_Dspace_B.ObservateurControleur2[2] =
        (Observateur_Controleur_Dspace_P.ObservateurControleur2_C[2])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[2];
      Observateur_Controleur_Dspace_B.ObservateurControleur2[3] =
        (Observateur_Controleur_Dspace_P.ObservateurControleur2_C[3])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[3];
    }

    /* Gain: '<Root>/Matrix Gain ' */
    u = Observateur_Controleur_Dspace_P.MatrixGain_Gain[0] *
      Observateur_Controleur_Dspace_B.ObservateurControleur2[0];
    u += Observateur_Controleur_Dspace_P.MatrixGain_Gain[1] *
      Observateur_Controleur_Dspace_B.ObservateurControleur2[1];
    u += Observateur_Controleur_Dspace_P.MatrixGain_Gain[2] *
      Observateur_Controleur_Dspace_B.ObservateurControleur2[2];
    u += Observateur_Controleur_Dspace_P.MatrixGain_Gain[3] *
      Observateur_Controleur_Dspace_B.ObservateurControleur2[3];
    Observateur_Controleur_Dspace_B.MatrixGain = u;

    /* S-Function (rti_commonblock): '<S6>/S-Function' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:ADC Group:NON_MUX */
    Observateur_Controleur_Dspace_B.SFunction = (real_T) ds1104_adc_read_conv(2);

    /* Gain: '<S2>/gain2' */
    Observateur_Controleur_Dspace_B.gain2 =
      Observateur_Controleur_Dspace_P.gain2_Gain *
      Observateur_Controleur_Dspace_B.SFunction;

    /* Gain: '<S2>/gain4' */
    Observateur_Controleur_Dspace_B.gain4 =
      Observateur_Controleur_Dspace_P.gain4_Gain *
      Observateur_Controleur_Dspace_B.gain2;

    /* RateTransition: '<S2>/theta' */
    if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
      Observateur_Controleur_Dspace_B.theta =
        Observateur_Controleur_Dspace_B.gain4;
    }

    /* End of RateTransition: '<S2>/theta' */

    /* Gain: '<S9>/Gain' */
    Observateur_Controleur_Dspace_B.Gain =
      Observateur_Controleur_Dspace_P.Gain_Gain *
      Observateur_Controleur_Dspace_B.theta;

    /* RateTransition: '<S2>/theta_Volt' incorporates:
     *  RateTransition: '<S2>/theta_deg'
     */
    if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
      Observateur_Controleur_Dspace_B.theta_Volt =
        Observateur_Controleur_Dspace_B.gain2;
      Observateur_Controleur_Dspace_B.theta_deg =
        Observateur_Controleur_Dspace_B.Gain;
    }

    /* End of RateTransition: '<S2>/theta_Volt' */

    /* S-Function (rti_commonblock): '<S7>/S-Function' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:ADC Group:NON_MUX */
    Observateur_Controleur_Dspace_B.SFunction_k = (real_T) ds1104_adc_read_conv
      (3);

    /* Gain: '<S2>/gain1' */
    Observateur_Controleur_Dspace_B.gain1 =
      Observateur_Controleur_Dspace_P.gain1_Gain *
      Observateur_Controleur_Dspace_B.SFunction_k;

    /* Gain: '<S2>/gain5' */
    Observateur_Controleur_Dspace_B.gain5 =
      Observateur_Controleur_Dspace_P.gain5_Gain *
      Observateur_Controleur_Dspace_B.gain1;

    /* RateTransition: '<S2>/alpha' */
    if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
      Observateur_Controleur_Dspace_B.alpha =
        Observateur_Controleur_Dspace_B.gain5;
    }

    /* End of RateTransition: '<S2>/alpha' */

    /* Gain: '<S8>/Gain' */
    Observateur_Controleur_Dspace_B.Gain_f =
      Observateur_Controleur_Dspace_P.Gain_Gain_b *
      Observateur_Controleur_Dspace_B.alpha;

    /* RateTransition: '<S2>/alpha_Volt' incorporates:
     *  RateTransition: '<S2>/alpha_deg'
     */
    if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
      Observateur_Controleur_Dspace_B.alpha_Volt =
        Observateur_Controleur_Dspace_B.gain1;
      Observateur_Controleur_Dspace_B.alpha_deg =
        Observateur_Controleur_Dspace_B.Gain_f;
    }

    /* End of RateTransition: '<S2>/alpha_Volt' */

    /* Gain: '<S14>/Gain' */
    Observateur_Controleur_Dspace_B.Gain_b =
      Observateur_Controleur_Dspace_P.Gain_Gain_j *
      Observateur_Controleur_Dspace_B.alpha;

    /* Abs: '<S4>/Abs1' */
    Observateur_Controleur_Dspace_B.Abs1 = fabs
      (Observateur_Controleur_Dspace_B.Gain_b);

    /* RelationalOperator: '<S4>/Relational Operator1' incorporates:
     *  Constant: '<S4>/Alpha Threshold1'
     */
    Observateur_Controleur_Dspace_B.RelationalOperator1 = (real_T)
      (Observateur_Controleur_Dspace_B.Abs1 <
       Observateur_Controleur_Dspace_P.AlphaThreshold1_Value);

    /* Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    if (Observateur_Controleur_Dspace_B.RelationalOperator1 > 0.0) {
      /* Inport: '<S13>/In1' incorporates:
       *  Constant: '<S4>/Alpha Reached zero'
       */
      Observateur_Controleur_Dspace_B.In1 =
        Observateur_Controleur_Dspace_P.AlphaReachedzero_Value;
    }

    /* End of Outputs for SubSystem: '<S4>/Enabled Subsystem' */

    /* Gain: '<S15>/Gain' */
    Observateur_Controleur_Dspace_B.Gain_j =
      Observateur_Controleur_Dspace_P.Gain_Gain_bd *
      Observateur_Controleur_Dspace_B.alpha;

    /* Abs: '<S4>/Abs' */
    Observateur_Controleur_Dspace_B.Abs = fabs
      (Observateur_Controleur_Dspace_B.Gain_j);

    /* RelationalOperator: '<S4>/Relational Operator' incorporates:
     *  Constant: '<S4>/Alpha Threshold'
     */
    Observateur_Controleur_Dspace_B.RelationalOperator = (real_T)
      (Observateur_Controleur_Dspace_B.Abs <
       Observateur_Controleur_Dspace_P.AlphaThreshold_Value);

    /* Logic: '<S4>/Logical Operator' */
    Observateur_Controleur_Dspace_B.LogicalOperator = (real_T)
      ((Observateur_Controleur_Dspace_B.In1 != 0.0) &&
       (Observateur_Controleur_Dspace_B.RelationalOperator != 0.0));

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Control'
     */
    if (Observateur_Controleur_Dspace_B.LogicalOperator >=
        Observateur_Controleur_Dspace_P.Switch_Threshold) {
      Observateur_Controleur_Dspace_B.Switch =
        Observateur_Controleur_Dspace_B.MatrixGain;
    } else {
      Observateur_Controleur_Dspace_B.Switch =
        Observateur_Controleur_Dspace_P.Control_Value;
    }

    /* End of Switch: '<Root>/Switch' */

    /* ZeroOrderHold: '<Root>/Zero-Order Hold' */
    Observateur_Controleur_Dspace_B.ZeroOrderHold =
      Observateur_Controleur_Dspace_B.Switch;

    /* Gain: '<S2>/Direction Convention: (Right-Hand) system' */
    Observateur_Controleur_Dspace_B.DirectionConventionRightHandsys =
      Observateur_Controleur_Dspace_P.DirectionConventionRightHandsys *
      Observateur_Controleur_Dspace_B.ZeroOrderHold;

    /* Saturate: '<S2>/Saturation' */
    u = Observateur_Controleur_Dspace_B.DirectionConventionRightHandsys;
    u_0 = Observateur_Controleur_Dspace_P.Saturation_LowerSat;
    u_1 = Observateur_Controleur_Dspace_P.Saturation_UpperSat;
    if (u >= u_1) {
      Observateur_Controleur_Dspace_B.Saturation = u_1;
    } else if (u <= u_0) {
      Observateur_Controleur_Dspace_B.Saturation = u_0;
    } else {
      Observateur_Controleur_Dspace_B.Saturation = u;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Gain: '<S2>/gain3' */
    Observateur_Controleur_Dspace_B.gain3 =
      Observateur_Controleur_Dspace_P.gain3_Gain *
      Observateur_Controleur_Dspace_B.Saturation;

    /* S-Function (rti_commonblock): '<S5>/S-Function1' */
    /* This comment workarounds a Real-Time Workshop code generation problem */

    /* dSPACE I/O Board DS1104 #1 Unit:DAC */
    ds1104_dac_write(1, Observateur_Controleur_Dspace_B.gain3);

    /* Gain: '<S2>/gain6' */
    Observateur_Controleur_Dspace_B.ControlSignal =
      Observateur_Controleur_Dspace_P.gain6_Gain * 0.0;
  }

  /* Sum: '<Root>/Sum1' */
  Observateur_Controleur_Dspace_B.Sum1 = Observateur_Controleur_Dspace_B.theta -
    Observateur_Controleur_Dspace_B.Gain1;
  if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
    /* Gain: '<Root>/Theta Setpoint (deg)' incorporates:
     *  Constant: '<Root>/Consigne'
     */
    Observateur_Controleur_Dspace_B.ThetaSetpointdeg =
      Observateur_Controleur_Dspace_P.ThetaSetpointdeg_Gain *
      Observateur_Controleur_Dspace_P.Consigne_Value;
  }
}

/* Model update function */
void Observateur_Controleur_Dspace_IMC_update(void)
{
  if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
    /* Update for DiscreteStateSpace: '<Root>/Observateur Controleur2' */
    {
      real_T xnew[4];
      xnew[0] = (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[0])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[1])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[1]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[2])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[2]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[3])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[3];
      xnew[0] += (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[0])*
        Observateur_Controleur_Dspace_B.MatrixGain
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[1])*
        Observateur_Controleur_Dspace_B.Sum1
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[2])*
        Observateur_Controleur_Dspace_B.alpha;
      xnew[1] = (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[4])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[5])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[1]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[6])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[2]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[7])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[3];
      xnew[1] += (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[3])*
        Observateur_Controleur_Dspace_B.MatrixGain
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[4])*
        Observateur_Controleur_Dspace_B.Sum1
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[5])*
        Observateur_Controleur_Dspace_B.alpha;
      xnew[2] = (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[8])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[9])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[1]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[10])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[2]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[11])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[3];
      xnew[2] += (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[6])*
        Observateur_Controleur_Dspace_B.MatrixGain
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[7])*
        Observateur_Controleur_Dspace_B.Sum1
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[8])*
        Observateur_Controleur_Dspace_B.alpha;
      xnew[3] = (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[12])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[13])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[1]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[14])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[2]
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_A[15])*
        Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[3];
      xnew[3] += (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[9])*
        Observateur_Controleur_Dspace_B.MatrixGain
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[10])*
        Observateur_Controleur_Dspace_B.Sum1
        + (Observateur_Controleur_Dspace_P.ObservateurControleur2_B[11])*
        Observateur_Controleur_Dspace_B.alpha;
      (void) memcpy
        (&Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0], xnew,
         sizeof(real_T)*4);
    }
  }

  if (rtmIsMajorTimeStep(Observateur_Controleur_Dspac_M)) {
    rt_ertODEUpdateContinuousStates(&Observateur_Controleur_Dspac_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Observateur_Controleur_Dspac_M->Timing.clockTick0)) {
    ++Observateur_Controleur_Dspac_M->Timing.clockTickH0;
  }

  Observateur_Controleur_Dspac_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Observateur_Controleur_Dspac_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.005s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Observateur_Controleur_Dspac_M->Timing.clockTick1)) {
      ++Observateur_Controleur_Dspac_M->Timing.clockTickH1;
    }

    Observateur_Controleur_Dspac_M->Timing.t[1] =
      Observateur_Controleur_Dspac_M->Timing.clockTick1 *
      Observateur_Controleur_Dspac_M->Timing.stepSize1 +
      Observateur_Controleur_Dspac_M->Timing.clockTickH1 *
      Observateur_Controleur_Dspac_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void Observateur_Controleur_Dspace_IMC_derivatives(void)
{
  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  {
    ((StateDerivatives_Observateur_Co *)
      Observateur_Controleur_Dspac_M->ModelData.derivs)->TransferFcn_CSTATE =
      Observateur_Controleur_Dspace_B.ThetaSetpointdeg;
    ((StateDerivatives_Observateur_Co *)
      Observateur_Controleur_Dspac_M->ModelData.derivs)->TransferFcn_CSTATE +=
      (Observateur_Controleur_Dspace_P.TransferFcn_A)*
      Observateur_Controleur_Dspace_X.TransferFcn_CSTATE;
  }
}

/* Model initialize function */
void Observateur_Controleur_Dspace_IMC_initialize(void)
{
  /* Start for Enabled SubSystem: '<S4>/Enabled Subsystem' */
  /* VirtualOutportStart for Outport: '<S13>/Out1' */
  Observateur_Controleur_Dspace_B.In1 = Observateur_Controleur_Dspace_P.Out1_Y0;

  /* End of Start for SubSystem: '<S4>/Enabled Subsystem' */

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  Observateur_Controleur_Dspace_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for DiscreteStateSpace: '<Root>/Observateur Controleur2' */
  Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0] =
    Observateur_Controleur_Dspace_P.ObservateurControleur2_X0[0];
  Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[1] =
    Observateur_Controleur_Dspace_P.ObservateurControleur2_X0[1];
  Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[2] =
    Observateur_Controleur_Dspace_P.ObservateurControleur2_X0[2];
  Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[3] =
    Observateur_Controleur_Dspace_P.ObservateurControleur2_X0[3];
}

/* Model terminate function */
void Observateur_Controleur_Dspace_IMC_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  Observateur_Controleur_Dspace_IMC_output();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  Observateur_Controleur_Dspace_IMC_update();

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
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
  Observateur_Controleur_Dspace_IMC_initialize();
}

void MdlTerminate(void)
{
  Observateur_Controleur_Dspace_IMC_terminate();
}

RT_MODEL_Observateur_Controleur *Observateur_Controleur_Dspace_IMC(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Observateur_Controleur_Dspac_M, 0,
                sizeof(RT_MODEL_Observateur_Controleur));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Observateur_Controleur_Dspac_M->solverInfo,
                          &Observateur_Controleur_Dspac_M->Timing.simTimeStep);
    rtsiSetTPtr(&Observateur_Controleur_Dspac_M->solverInfo, &rtmGetTPtr
                (Observateur_Controleur_Dspac_M));
    rtsiSetStepSizePtr(&Observateur_Controleur_Dspac_M->solverInfo,
                       &Observateur_Controleur_Dspac_M->Timing.stepSize0);
    rtsiSetdXPtr(&Observateur_Controleur_Dspac_M->solverInfo,
                 &Observateur_Controleur_Dspac_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Observateur_Controleur_Dspac_M->solverInfo,
                         &Observateur_Controleur_Dspac_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Observateur_Controleur_Dspac_M->solverInfo,
      &Observateur_Controleur_Dspac_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Observateur_Controleur_Dspac_M->solverInfo,
                          (&rtmGetErrorStatus(Observateur_Controleur_Dspac_M)));
    rtsiSetRTModelPtr(&Observateur_Controleur_Dspac_M->solverInfo,
                      Observateur_Controleur_Dspac_M);
  }

  rtsiSetSimTimeStep(&Observateur_Controleur_Dspac_M->solverInfo,
                     MAJOR_TIME_STEP);
  Observateur_Controleur_Dspac_M->ModelData.intgData.y =
    Observateur_Controleur_Dspac_M->ModelData.odeY;
  Observateur_Controleur_Dspac_M->ModelData.intgData.f[0] =
    Observateur_Controleur_Dspac_M->ModelData.odeF[0];
  Observateur_Controleur_Dspac_M->ModelData.intgData.f[1] =
    Observateur_Controleur_Dspac_M->ModelData.odeF[1];
  Observateur_Controleur_Dspac_M->ModelData.intgData.f[2] =
    Observateur_Controleur_Dspac_M->ModelData.odeF[2];
  Observateur_Controleur_Dspac_M->ModelData.intgData.f[3] =
    Observateur_Controleur_Dspac_M->ModelData.odeF[3];
  Observateur_Controleur_Dspac_M->ModelData.contStates = ((real_T *)
    &Observateur_Controleur_Dspace_X);
  rtsiSetSolverData(&Observateur_Controleur_Dspac_M->solverInfo, (void *)
                    &Observateur_Controleur_Dspac_M->ModelData.intgData);
  rtsiSetSolverName(&Observateur_Controleur_Dspac_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Observateur_Controleur_Dspac_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Observateur_Controleur_Dspac_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Observateur_Controleur_Dspac_M->Timing.sampleTimes =
      (&Observateur_Controleur_Dspac_M->Timing.sampleTimesArray[0]);
    Observateur_Controleur_Dspac_M->Timing.offsetTimes =
      (&Observateur_Controleur_Dspac_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Observateur_Controleur_Dspac_M->Timing.sampleTimes[0] = (0.0);
    Observateur_Controleur_Dspac_M->Timing.sampleTimes[1] = (0.005);

    /* task offsets */
    Observateur_Controleur_Dspac_M->Timing.offsetTimes[0] = (0.0);
    Observateur_Controleur_Dspac_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Observateur_Controleur_Dspac_M,
             &Observateur_Controleur_Dspac_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Observateur_Controleur_Dspac_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Observateur_Controleur_Dspac_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Observateur_Controleur_Dspac_M, 9999.0);
  Observateur_Controleur_Dspac_M->Timing.stepSize0 = 0.005;
  Observateur_Controleur_Dspac_M->Timing.stepSize1 = 0.005;
  Observateur_Controleur_Dspac_M->solverInfoPtr =
    (&Observateur_Controleur_Dspac_M->solverInfo);
  Observateur_Controleur_Dspac_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&Observateur_Controleur_Dspac_M->solverInfo, 0.005);
  rtsiSetSolverMode(&Observateur_Controleur_Dspac_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Observateur_Controleur_Dspac_M->ModelData.blockIO = ((void *)
    &Observateur_Controleur_Dspace_B);

  {
    Observateur_Controleur_Dspace_B.TransferFcn = 0.0;
    Observateur_Controleur_Dspace_B.Gain1 = 0.0;
    Observateur_Controleur_Dspace_B.ObservateurControleur2[0] = 0.0;
    Observateur_Controleur_Dspace_B.ObservateurControleur2[1] = 0.0;
    Observateur_Controleur_Dspace_B.ObservateurControleur2[2] = 0.0;
    Observateur_Controleur_Dspace_B.ObservateurControleur2[3] = 0.0;
    Observateur_Controleur_Dspace_B.MatrixGain = 0.0;
    Observateur_Controleur_Dspace_B.SFunction = 0.0;
    Observateur_Controleur_Dspace_B.gain2 = 0.0;
    Observateur_Controleur_Dspace_B.gain4 = 0.0;
    Observateur_Controleur_Dspace_B.theta = 0.0;
    Observateur_Controleur_Dspace_B.Gain = 0.0;
    Observateur_Controleur_Dspace_B.theta_Volt = 0.0;
    Observateur_Controleur_Dspace_B.theta_deg = 0.0;
    Observateur_Controleur_Dspace_B.SFunction_k = 0.0;
    Observateur_Controleur_Dspace_B.gain1 = 0.0;
    Observateur_Controleur_Dspace_B.gain5 = 0.0;
    Observateur_Controleur_Dspace_B.alpha = 0.0;
    Observateur_Controleur_Dspace_B.Gain_f = 0.0;
    Observateur_Controleur_Dspace_B.alpha_Volt = 0.0;
    Observateur_Controleur_Dspace_B.alpha_deg = 0.0;
    Observateur_Controleur_Dspace_B.Gain_b = 0.0;
    Observateur_Controleur_Dspace_B.Abs1 = 0.0;
    Observateur_Controleur_Dspace_B.RelationalOperator1 = 0.0;
    Observateur_Controleur_Dspace_B.Gain_j = 0.0;
    Observateur_Controleur_Dspace_B.Abs = 0.0;
    Observateur_Controleur_Dspace_B.RelationalOperator = 0.0;
    Observateur_Controleur_Dspace_B.LogicalOperator = 0.0;
    Observateur_Controleur_Dspace_B.Switch = 0.0;
    Observateur_Controleur_Dspace_B.ZeroOrderHold = 0.0;
    Observateur_Controleur_Dspace_B.DirectionConventionRightHandsys = 0.0;
    Observateur_Controleur_Dspace_B.Saturation = 0.0;
    Observateur_Controleur_Dspace_B.gain3 = 0.0;
    Observateur_Controleur_Dspace_B.ControlSignal = 0.0;
    Observateur_Controleur_Dspace_B.Sum1 = 0.0;
    Observateur_Controleur_Dspace_B.ThetaSetpointdeg = 0.0;
    Observateur_Controleur_Dspace_B.In1 = 0.0;
  }

  /* parameters */
  Observateur_Controleur_Dspac_M->ModelData.defaultParam = ((real_T *)
    &Observateur_Controleur_Dspace_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Observateur_Controleur_Dspace_X;
    Observateur_Controleur_Dspac_M->ModelData.contStates = (x);
    (void) memset((void *)&Observateur_Controleur_Dspace_X, 0,
                  sizeof(ContinuousStates_Observateur_Co));
  }

  /* states (dwork) */
  Observateur_Controleur_Dspac_M->Work.dwork = ((void *)
    &Observateur_Controleur_Ds_DWork);
  Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0] = 0.0;
  Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[1] = 0.0;
  Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[2] = 0.0;
  Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[3] = 0.0;

  {
    /* user code (registration function declaration) */
    /*Call the macro that initializes the global TRC pointers
       inside the model initialization/registration function. */
    RTI_INIT_TRC_POINTERS();
  }

  /* Initialize Sizes */
  Observateur_Controleur_Dspac_M->Sizes.numContStates = (1);/* Number of continuous states */
  Observateur_Controleur_Dspac_M->Sizes.numY = (0);/* Number of model outputs */
  Observateur_Controleur_Dspac_M->Sizes.numU = (0);/* Number of model inputs */
  Observateur_Controleur_Dspac_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Observateur_Controleur_Dspac_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Observateur_Controleur_Dspac_M->Sizes.numBlocks = (42);/* Number of blocks */
  Observateur_Controleur_Dspac_M->Sizes.numBlockIO = (34);/* Number of block outputs */
  Observateur_Controleur_Dspac_M->Sizes.numBlockPrms = (64);/* Sum of parameter "widths" */
  return Observateur_Controleur_Dspac_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
