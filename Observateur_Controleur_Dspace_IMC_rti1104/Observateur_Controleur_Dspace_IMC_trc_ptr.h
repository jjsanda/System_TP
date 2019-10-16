  /*********************** dSPACE target specific file *************************

   Header file Observateur_Controleur_Dspace_IMC_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1104 6.9.1 (02-Nov-2012)
   Wed Sep 28 15:55:49 2016

   (c) Copyright 2008, dSPACE GmbH. All rights reserved.

  *****************************************************************************/
  #ifndef RTI_HEADER_Observateur_Controleur_Dspace_IMC_trc_ptr_h_
  #define RTI_HEADER_Observateur_Controleur_Dspace_IMC_trc_ptr_h_
  /* Include the model header file. */
  #include "Observateur_Controleur_Dspace_IMC.h"
  #include "Observateur_Controleur_Dspace_IMC_private.h"

  #ifdef EXTERN_C
  #undef EXTERN_C
  #endif

  #ifdef __cplusplus
  #define EXTERN_C                       extern "C"
  #else
  #define EXTERN_C                       extern
  #endif

  /*
   *  Declare the global TRC pointers
   */
              EXTERN_C volatile  real_T *p_Observateur_Controleur_Dspace_B_real_T_0;
              EXTERN_C volatile  real_T *p_Observateur_Controleur_Dspace_P_real_T_0;
              EXTERN_C volatile  real_T *p_Observateur_Controleur_Ds_DWork_real_T_0;
              EXTERN_C volatile  real_T *p_Observateur_Controleur_Dspace_X_real_T_0;

   #define RTI_INIT_TRC_POINTERS() \
              p_Observateur_Controleur_Dspace_B_real_T_0 = &Observateur_Controleur_Dspace_B.TransferFcn;\
              p_Observateur_Controleur_Dspace_P_real_T_0 = &Observateur_Controleur_Dspace_P.Control_Value;\
              p_Observateur_Controleur_Ds_DWork_real_T_0 = &Observateur_Controleur_Ds_DWork.ObservateurControleur2_DSTATE[0];\
              p_Observateur_Controleur_Dspace_X_real_T_0 = &Observateur_Controleur_Dspace_X.TransferFcn_CSTATE;\

   #endif                       /* RTI_HEADER_Observateur_Controleur_Dspace_IMC_trc_ptr_h_ */
