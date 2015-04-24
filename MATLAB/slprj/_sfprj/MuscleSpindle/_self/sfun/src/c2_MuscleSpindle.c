/* Include files */

#include "blascompat32.h"
#include "MuscleSpindle_sfun.h"
#include "c2_MuscleSpindle.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MuscleSpindle_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[19] = { "LTerm", "nargin", "nargout",
  "dT", "T", "L", "dL", "ddL", "Lsr0", "Ksr", "M", "C", "Beta", "a", "R", "Kpr",
  "Lpr0", "Gamma", "ddT" };

/* Function Declarations */
static void initialize_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance);
static void initialize_params_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct *
  chartInstance);
static void enable_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance);
static void disable_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_MuscleSpindle
  (SFc2_MuscleSpindleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_MuscleSpindle
  (SFc2_MuscleSpindleInstanceStruct *chartInstance);
static void set_sim_state_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance);
static void sf_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct *chartInstance);
static void initSimStructsc2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_ddT, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[14]);
static void c2_eml_error(SFc2_MuscleSpindleInstanceStruct *chartInstance);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_MuscleSpindle, const char_T
  *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_MuscleSpindleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_MuscleSpindle = 0U;
}

static void initialize_params_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct *
  chartInstance)
{
}

static void enable_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_MuscleSpindle
  (SFc2_MuscleSpindleInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_MuscleSpindle
  (SFc2_MuscleSpindleInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_ddT;
  c2_ddT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_hoistedGlobal = *c2_ddT;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_MuscleSpindle;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_ddT;
  c2_ddT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_ddT = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "ddT");
  chartInstance->c2_is_active_c2_MuscleSpindle = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_MuscleSpindle");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_MuscleSpindle(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void sf_c2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_g_hoistedGlobal;
  real_T c2_h_hoistedGlobal;
  real_T c2_i_hoistedGlobal;
  real_T c2_j_hoistedGlobal;
  real_T c2_k_hoistedGlobal;
  real_T c2_l_hoistedGlobal;
  real_T c2_m_hoistedGlobal;
  real_T c2_n_hoistedGlobal;
  real_T c2_o_hoistedGlobal;
  real_T c2_dT;
  real_T c2_T;
  real_T c2_L;
  real_T c2_dL;
  real_T c2_ddL;
  real_T c2_Lsr0;
  real_T c2_Ksr;
  real_T c2_M;
  real_T c2_C;
  real_T c2_Beta;
  real_T c2_a;
  real_T c2_R;
  real_T c2_Kpr;
  real_T c2_Lpr0;
  real_T c2_Gamma;
  uint32_T c2_debug_family_var_map[19];
  real_T c2_LTerm;
  real_T c2_nargin = 15.0;
  real_T c2_nargout = 1.0;
  real_T c2_ddT;
  real_T c2_A;
  real_T c2_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_b_A;
  real_T c2_b_B;
  real_T c2_c_x;
  real_T c2_d_y;
  real_T c2_d_x;
  real_T c2_e_y;
  real_T c2_f_y;
  real_T c2_b_a;
  real_T c2_b;
  real_T c2_g_y;
  real_T c2_c_A;
  real_T c2_c_B;
  real_T c2_e_x;
  real_T c2_h_y;
  real_T c2_f_x;
  real_T c2_i_y;
  real_T c2_j_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_c_a;
  real_T c2_b_b;
  real_T c2_k_y;
  real_T c2_d_A;
  real_T c2_d_B;
  real_T c2_i_x;
  real_T c2_l_y;
  real_T c2_j_x;
  real_T c2_m_y;
  real_T c2_n_y;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_o_y;
  real_T c2_d_a;
  real_T c2_c_b;
  real_T c2_e_a;
  real_T c2_d_b;
  real_T c2_ak;
  real_T c2_bk;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_c;
  real_T c2_f_a;
  real_T c2_e_b;
  real_T c2_p_y;
  real_T c2_g_a;
  real_T c2_f_b;
  real_T c2_q_y;
  real_T c2_h_a;
  real_T c2_g_b;
  real_T c2_r_y;
  real_T c2_i_a;
  real_T c2_h_b;
  real_T c2_s_y;
  real_T c2_j_a;
  real_T c2_i_b;
  real_T *c2_b_Gamma;
  real_T *c2_b_Lpr0;
  real_T *c2_b_Kpr;
  real_T *c2_b_R;
  real_T *c2_k_a;
  real_T *c2_b_Beta;
  real_T *c2_b_C;
  real_T *c2_b_M;
  real_T *c2_b_Ksr;
  real_T *c2_b_Lsr0;
  real_T *c2_b_ddL;
  real_T *c2_b_dL;
  real_T *c2_b_L;
  real_T *c2_b_T;
  real_T *c2_b_dT;
  real_T *c2_b_ddT;
  c2_b_Gamma = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c2_b_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c2_b_Kpr = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c2_b_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c2_k_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c2_b_Beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c2_b_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c2_b_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c2_b_ddT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c2_b_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_ddL = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_dL = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_dT = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_dT, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_T, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_L, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_dL, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_ddL, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Lsr0, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Ksr, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_b_ddT, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_b_M, 8U);
  _SFD_DATA_RANGE_CHECK(*c2_b_C, 9U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Beta, 10U);
  _SFD_DATA_RANGE_CHECK(*c2_k_a, 11U);
  _SFD_DATA_RANGE_CHECK(*c2_b_R, 12U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Kpr, 13U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Lpr0, 14U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Gamma, 15U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_dT;
  c2_b_hoistedGlobal = *c2_b_T;
  c2_c_hoistedGlobal = *c2_b_L;
  c2_d_hoistedGlobal = *c2_b_dL;
  c2_e_hoistedGlobal = *c2_b_ddL;
  c2_f_hoistedGlobal = *c2_b_Lsr0;
  c2_g_hoistedGlobal = *c2_b_Ksr;
  c2_h_hoistedGlobal = *c2_b_M;
  c2_i_hoistedGlobal = *c2_b_C;
  c2_j_hoistedGlobal = *c2_b_Beta;
  c2_k_hoistedGlobal = *c2_k_a;
  c2_l_hoistedGlobal = *c2_b_R;
  c2_m_hoistedGlobal = *c2_b_Kpr;
  c2_n_hoistedGlobal = *c2_b_Lpr0;
  c2_o_hoistedGlobal = *c2_b_Gamma;
  c2_dT = c2_hoistedGlobal;
  c2_T = c2_b_hoistedGlobal;
  c2_L = c2_c_hoistedGlobal;
  c2_dL = c2_d_hoistedGlobal;
  c2_ddL = c2_e_hoistedGlobal;
  c2_Lsr0 = c2_f_hoistedGlobal;
  c2_Ksr = c2_g_hoistedGlobal;
  c2_M = c2_h_hoistedGlobal;
  c2_C = c2_i_hoistedGlobal;
  c2_Beta = c2_j_hoistedGlobal;
  c2_a = c2_k_hoistedGlobal;
  c2_R = c2_l_hoistedGlobal;
  c2_Kpr = c2_m_hoistedGlobal;
  c2_Lpr0 = c2_n_hoistedGlobal;
  c2_Gamma = c2_o_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 19U, 19U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_LTerm, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_dT, 3U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_T, 4U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_L, 5U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_dL, 6U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_ddL, 7U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Lsr0, 8U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Ksr, 9U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_M, 10U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_C, 11U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Beta, 12U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_a, 13U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_R, 14U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Kpr, 15U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Lpr0, 16U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c2_Gamma, 17U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_ddT, 18U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 3);
  c2_A = c2_T;
  c2_B = c2_Ksr;
  c2_x = c2_A;
  c2_y = c2_B;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_c_y = c2_b_x / c2_b_y;
  c2_LTerm = (c2_L - c2_Lsr0) - c2_c_y;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  c2_b_A = c2_Ksr;
  c2_b_B = c2_M;
  c2_c_x = c2_b_A;
  c2_d_y = c2_b_B;
  c2_d_x = c2_c_x;
  c2_e_y = c2_d_y;
  c2_f_y = c2_d_x / c2_e_y;
  c2_b_a = c2_C;
  c2_b = c2_Beta;
  c2_g_y = c2_b_a * c2_b;
  c2_c_A = c2_dT;
  c2_c_B = c2_Ksr;
  c2_e_x = c2_c_A;
  c2_h_y = c2_c_B;
  c2_f_x = c2_e_x;
  c2_i_y = c2_h_y;
  c2_j_y = c2_f_x / c2_i_y;
  c2_g_x = c2_dL - c2_j_y;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarSign(c2_h_x);
  c2_c_a = c2_g_y;
  c2_b_b = c2_h_x;
  c2_k_y = c2_c_a * c2_b_b;
  c2_d_A = c2_dT;
  c2_d_B = c2_Ksr;
  c2_i_x = c2_d_A;
  c2_l_y = c2_d_B;
  c2_j_x = c2_i_x;
  c2_m_y = c2_l_y;
  c2_n_y = c2_j_x / c2_m_y;
  c2_k_x = c2_dL - c2_n_y;
  c2_l_x = c2_k_x;
  c2_o_y = muDoubleScalarAbs(c2_l_x);
  c2_d_a = c2_o_y;
  c2_c_b = c2_a;
  c2_e_a = c2_d_a;
  c2_d_b = c2_c_b;
  c2_ak = c2_e_a;
  c2_bk = c2_d_b;
  if (c2_ak < 0.0) {
    c2_m_x = c2_bk;
    c2_n_x = c2_m_x;
    c2_n_x = muDoubleScalarFloor(c2_n_x);
    if (c2_n_x != c2_bk) {
      c2_eml_error(chartInstance);
    }
  }

  c2_c = muDoubleScalarPower(c2_ak, c2_bk);
  c2_f_a = c2_k_y;
  c2_e_b = c2_c;
  c2_p_y = c2_f_a * c2_e_b;
  c2_g_a = c2_p_y;
  c2_f_b = c2_LTerm - c2_R;
  c2_q_y = c2_g_a * c2_f_b;
  c2_h_a = c2_Kpr;
  c2_g_b = c2_LTerm - c2_Lpr0;
  c2_r_y = c2_h_a * c2_g_b;
  c2_i_a = c2_M;
  c2_h_b = c2_ddL;
  c2_s_y = c2_i_a * c2_h_b;
  c2_j_a = c2_f_y;
  c2_i_b = (((c2_q_y + c2_r_y) + c2_s_y) + c2_Gamma) - c2_T;
  c2_ddT = c2_j_a * c2_i_b;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  *c2_b_ddT = c2_ddT;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  sf_debug_check_for_state_inconsistency(_MuscleSpindleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_MuscleSpindle(SFc2_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc2_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_ddT, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ddT), &c2_thisId);
  sf_mex_destroy(&c2_ddT);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_ddT;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc2_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c2_ddT = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ddT), &c2_thisId);
  sf_mex_destroy(&c2_ddT);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_MuscleSpindle_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[14];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c2_i0 = 0; c2_i0 < 14; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[14])
{
  c2_info[0].context = "";
  c2_info[0].name = "mrdivide";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[0].fileTimeLo = 1325156538U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 1319762366U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[1].name = "rdivide";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[1].fileTimeLo = 1286851244U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[2].name = "eml_div";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[2].fileTimeLo = 1313380210U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "";
  c2_info[3].name = "mtimes";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[3].fileTimeLo = 1289552092U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "";
  c2_info[4].name = "sign";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[4].fileTimeLo = 1286851150U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/sign.m";
  c2_info[5].name = "eml_scalar_sign";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c2_info[5].fileTimeLo = 1307683638U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "";
  c2_info[6].name = "abs";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[6].fileTimeLo = 1286851094U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[7].name = "eml_scalar_abs";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[7].fileTimeLo = 1286851112U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "mpower";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[8].fileTimeLo = 1286851242U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[9].name = "power";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[9].fileTimeLo = 1307683640U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[10].name = "eml_scalar_eg";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[10].fileTimeLo = 1286851196U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[11].name = "eml_scalexp_alloc";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[11].fileTimeLo = 1286851196U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[12].name = "eml_scalar_floor";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[12].fileTimeLo = 1286851126U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[13].name = "eml_error";
  c2_info[13].dominantType = "char";
  c2_info[13].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[13].fileTimeLo = 1305350400U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
}

static void c2_eml_error(SFc2_MuscleSpindleInstanceStruct *chartInstance)
{
  int32_T c2_i1;
  static char_T c2_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_u[31];
  const mxArray *c2_y = NULL;
  for (c2_i1 = 0; c2_i1 < 31; c2_i1++) {
    c2_u[c2_i1] = c2_varargin_1[c2_i1];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 31), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc2_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i2, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc2_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_MuscleSpindle, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_MuscleSpindle), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_MuscleSpindle);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_MuscleSpindle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1647964782U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3482713306U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2656741442U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(614443288U);
}

mxArray *sf_c2_MuscleSpindle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7Epm3D04SGhkoANuUOnVaF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,15,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_MuscleSpindle(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ddT\",},{M[8],M[0],T\"is_active_c2_MuscleSpindle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_MuscleSpindle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_MuscleSpindleInstanceStruct *chartInstance;
    chartInstance = (SFc2_MuscleSpindleInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_MuscleSpindleMachineNumber_,
           2,
           1,
           1,
           16,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_MuscleSpindleMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_MuscleSpindleMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_MuscleSpindleMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"dT");
          _SFD_SET_DATA_PROPS(1,1,1,0,"T");
          _SFD_SET_DATA_PROPS(2,1,1,0,"L");
          _SFD_SET_DATA_PROPS(3,1,1,0,"dL");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ddL");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Lsr0");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Ksr");
          _SFD_SET_DATA_PROPS(7,2,0,1,"ddT");
          _SFD_SET_DATA_PROPS(8,1,1,0,"M");
          _SFD_SET_DATA_PROPS(9,1,1,0,"C");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Beta");
          _SFD_SET_DATA_PROPS(11,1,1,0,"a");
          _SFD_SET_DATA_PROPS(12,1,1,0,"R");
          _SFD_SET_DATA_PROPS(13,1,1,0,"Kpr");
          _SFD_SET_DATA_PROPS(14,1,1,0,"Lpr0");
          _SFD_SET_DATA_PROPS(15,1,1,0,"Gamma");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,341);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c2_dT;
          real_T *c2_T;
          real_T *c2_L;
          real_T *c2_dL;
          real_T *c2_ddL;
          real_T *c2_Lsr0;
          real_T *c2_Ksr;
          real_T *c2_ddT;
          real_T *c2_M;
          real_T *c2_C;
          real_T *c2_Beta;
          real_T *c2_a;
          real_T *c2_R;
          real_T *c2_Kpr;
          real_T *c2_Lpr0;
          real_T *c2_Gamma;
          c2_Gamma = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c2_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c2_Kpr = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c2_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c2_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c2_Beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c2_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c2_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c2_ddT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c2_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_ddL = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_dL = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_dT = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_dT);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_T);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_L);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_dL);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_ddL);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_Lsr0);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_Ksr);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_ddT);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_M);
          _SFD_SET_DATA_VALUE_PTR(9U, c2_C);
          _SFD_SET_DATA_VALUE_PTR(10U, c2_Beta);
          _SFD_SET_DATA_VALUE_PTR(11U, c2_a);
          _SFD_SET_DATA_VALUE_PTR(12U, c2_R);
          _SFD_SET_DATA_VALUE_PTR(13U, c2_Kpr);
          _SFD_SET_DATA_VALUE_PTR(14U, c2_Lpr0);
          _SFD_SET_DATA_VALUE_PTR(15U, c2_Gamma);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_MuscleSpindleMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "vS4hkj9wASYLpg5pFEfJZG";
}

static void sf_opaque_initialize_c2_MuscleSpindle(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_MuscleSpindleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
  initialize_c2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_MuscleSpindle(void *chartInstanceVar)
{
  enable_c2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_MuscleSpindle(void *chartInstanceVar)
{
  disable_c2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_MuscleSpindle(void *chartInstanceVar)
{
  sf_c2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_MuscleSpindle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_MuscleSpindle
    ((SFc2_MuscleSpindleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_MuscleSpindle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_MuscleSpindle(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_MuscleSpindle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_MuscleSpindle(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_MuscleSpindle(S);
}

static void sf_opaque_set_sim_state_c2_MuscleSpindle(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_MuscleSpindle(S, st);
}

static void sf_opaque_terminate_c2_MuscleSpindle(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_MuscleSpindleInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_MuscleSpindle_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_MuscleSpindle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_MuscleSpindle((SFc2_MuscleSpindleInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MuscleSpindle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,15);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(654543777U));
  ssSetChecksum1(S,(1984327007U));
  ssSetChecksum2(S,(1865630177U));
  ssSetChecksum3(S,(335866748U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_MuscleSpindle(SimStruct *S)
{
  SFc2_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc2_MuscleSpindleInstanceStruct *)malloc(sizeof
    (SFc2_MuscleSpindleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_MuscleSpindleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_MuscleSpindle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_MuscleSpindle;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_MuscleSpindle;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_MuscleSpindle;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_MuscleSpindle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_MuscleSpindle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_MuscleSpindle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_MuscleSpindle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_MuscleSpindle;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_MuscleSpindle;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_MuscleSpindle;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c2_MuscleSpindle_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_MuscleSpindle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_MuscleSpindle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
