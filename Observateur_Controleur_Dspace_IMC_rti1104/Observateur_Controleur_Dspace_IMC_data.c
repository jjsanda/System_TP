/*
 * Observateur_Controleur_Dspace_IMC_data.c
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
#include "Observateur_Controleur_Dspace_IMC.h"
#include "Observateur_Controleur_Dspace_IMC_private.h"

/* Block parameters (auto storage) */
Parameters_Observateur_Controle Observateur_Controleur_Dspace_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Control'
                                        */
  0.0,                                 /* Expression: [0]
                                        * Referenced by: '<S13>/Out1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Consigne'
                                        */
  -0.2,                                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  0.2,                                 /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  0.017453292519943295,                /* Expression: pi/180
                                        * Referenced by: '<S1>/Gain1'
                                        */

  /*  Computed Parameter: ObservateurControleur2_A
   * Referenced by: '<Root>/Observateur Controleur2'
   */
  { 0.656462549355568, -0.0017387941008219499, 0.0045623810269103983,
    9.3680017448349929E-7, 0.11860945787746752, 0.4901499314453992,
    -0.00030962812326353257, 0.005001577950301637, 4.7376595467879365,
    -0.016936408815003468, 0.83020243830636509, 0.000553640915614014,
    8.5403516072602947, -7.3306033244227677, -0.12014845224289337,
    1.0009408344243083 },

  /*  Computed Parameter: ObservateurControleur2_B
   * Referenced by: '<Root>/Observateur Controleur2'
   */
  { 0.00078670180158677732, 0.343537450644432, 0.0022924350164359635,
    0.00055661435488876744, -0.11860945787746752, 0.51079090297890906,
    0.30524281601948339, -4.7376595467879365, 0.23177186500108757,
    0.21598927297421808, -8.5403516072602947, 7.7022875711534855 },

  /*  Computed Parameter: ObservateurControleur2_C
   * Referenced by: '<Root>/Observateur Controleur2'
   */
  { 1.0, 1.0, 1.0, 1.0 },

  /*  Expression: [0 0 0 0]'
   * Referenced by: '<Root>/Observateur Controleur2'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /*  Expression: -Kcd
   * Referenced by: '<Root>/Matrix Gain '
   */
  { 14.789816318802997, -66.327665190853452, 6.3267602185441012,
    -9.880401733256063 },
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/gain2'
                                        */
  0.614355896702004,                   /* Expression: pi*352/1800
                                        * Referenced by: '<S2>/gain4'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S9>/Gain'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S2>/gain1'
                                        */
  0.26179938779914941,                 /* Expression: pi/12
                                        * Referenced by: '<S2>/gain5'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Alpha Reached zero'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S14>/Gain'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S4>/Alpha Threshold1'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S15>/Gain'
                                        */
  23.0,                                /* Expression: 23
                                        * Referenced by: '<S4>/Alpha Threshold'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S2>/Direction Convention: (Right-Hand) system'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S2>/Saturation'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S2>/gain3'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<S2>/gain6'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Theta Setpoint (deg)'
                                        */
};
