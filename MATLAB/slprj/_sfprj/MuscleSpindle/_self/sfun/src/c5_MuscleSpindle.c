/* Include files */

#include "blascompat32.h"
#include "MuscleSpindle_sfun.h"
#include "c5_MuscleSpindle.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MuscleSpindle_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[19] = { "LTerm", "nargin", "nargout",
  "dT", "T", "L", "dL", "ddL", "Lsr0", "Ksr", "M", "C", "Beta", "a", "R", "Kpr",
  "Lpr0", "Gamma", "ddT" };

/* Function Declarations */
static void initialize_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance);
static void initialize_params_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct *
  chartInstance);
static void enable_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance);
static void disable_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_MuscleSpindle
  (SFc5_MuscleSpindleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_MuscleSpindle
  (SFc5_MuscleSpindleInstanceStruct *chartInstance);
static void set_sim_state_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance);
static void sf_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct *chartInstance);
static void initSimStructsc5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static real_T c5_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_ddT, const char_T *c5_identifier);
static real_T c5_b_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[14]);
static void c5_eml_error(SFc5_MuscleSpindleInstanceStruct *chartInstance);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_c_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_d_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_MuscleSpindle, const char_T
  *c5_identifier);
static uint8_T c5_e_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_MuscleSpindleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_MuscleSpindle = 0U;
}

static void initialize_params_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct *
  chartInstance)
{
}

static void enable_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_MuscleSpindle
  (SFc5_MuscleSpindleInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_MuscleSpindle
  (SFc5_MuscleSpindleInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T *c5_ddT;
  c5_ddT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  c5_hoistedGlobal = *c5_ddT;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_active_c5_MuscleSpindle;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_ddT;
  c5_ddT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_ddT = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
    "ddT");
  chartInstance->c5_is_active_c5_MuscleSpindle = c5_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_MuscleSpindle");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_MuscleSpindle(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void sf_c5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  real_T c5_e_hoistedGlobal;
  real_T c5_f_hoistedGlobal;
  real_T c5_g_hoistedGlobal;
  real_T c5_h_hoistedGlobal;
  real_T c5_i_hoistedGlobal;
  real_T c5_j_hoistedGlobal;
  real_T c5_k_hoistedGlobal;
  real_T c5_l_hoistedGlobal;
  real_T c5_m_hoistedGlobal;
  real_T c5_n_hoistedGlobal;
  real_T c5_o_hoistedGlobal;
  real_T c5_dT;
  real_T c5_T;
  real_T c5_L;
  real_T c5_dL;
  real_T c5_ddL;
  real_T c5_Lsr0;
  real_T c5_Ksr;
  real_T c5_M;
  real_T c5_C;
  real_T c5_Beta;
  real_T c5_a;
  real_T c5_R;
  real_T c5_Kpr;
  real_T c5_Lpr0;
  real_T c5_Gamma;
  uint32_T c5_debug_family_var_map[19];
  real_T c5_LTerm;
  real_T c5_nargin = 15.0;
  real_T c5_nargout = 1.0;
  real_T c5_ddT;
  real_T c5_A;
  real_T c5_B;
  real_T c5_x;
  real_T c5_y;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_c_y;
  real_T c5_b_A;
  real_T c5_b_B;
  real_T c5_c_x;
  real_T c5_d_y;
  real_T c5_d_x;
  real_T c5_e_y;
  real_T c5_f_y;
  real_T c5_b_a;
  real_T c5_b;
  real_T c5_g_y;
  real_T c5_c_A;
  real_T c5_c_B;
  real_T c5_e_x;
  real_T c5_h_y;
  real_T c5_f_x;
  real_T c5_i_y;
  real_T c5_j_y;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_c_a;
  real_T c5_b_b;
  real_T c5_k_y;
  real_T c5_d_A;
  real_T c5_d_B;
  real_T c5_i_x;
  real_T c5_l_y;
  real_T c5_j_x;
  real_T c5_m_y;
  real_T c5_n_y;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_o_y;
  real_T c5_d_a;
  real_T c5_c_b;
  real_T c5_e_a;
  real_T c5_d_b;
  real_T c5_ak;
  real_T c5_bk;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_c;
  real_T c5_f_a;
  real_T c5_e_b;
  real_T c5_p_y;
  real_T c5_g_a;
  real_T c5_f_b;
  real_T c5_q_y;
  real_T c5_h_a;
  real_T c5_g_b;
  real_T c5_r_y;
  real_T c5_i_a;
  real_T c5_h_b;
  real_T c5_s_y;
  real_T c5_j_a;
  real_T c5_i_b;
  real_T *c5_b_Gamma;
  real_T *c5_b_Lpr0;
  real_T *c5_b_Kpr;
  real_T *c5_b_R;
  real_T *c5_k_a;
  real_T *c5_b_Beta;
  real_T *c5_b_C;
  real_T *c5_b_M;
  real_T *c5_b_Ksr;
  real_T *c5_b_Lsr0;
  real_T *c5_b_ddL;
  real_T *c5_b_dL;
  real_T *c5_b_L;
  real_T *c5_b_T;
  real_T *c5_b_dT;
  real_T *c5_b_ddT;
  c5_b_Gamma = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
  c5_b_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c5_b_Kpr = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c5_b_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c5_k_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c5_b_Beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c5_b_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c5_b_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c5_b_ddT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c5_b_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c5_b_ddL = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c5_b_dL = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_dT = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c5_b_dT, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_b_T, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_L, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_dL, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_b_ddL, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Lsr0, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Ksr, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_b_ddT, 7U);
  _SFD_DATA_RANGE_CHECK(*c5_b_M, 8U);
  _SFD_DATA_RANGE_CHECK(*c5_b_C, 9U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Beta, 10U);
  _SFD_DATA_RANGE_CHECK(*c5_k_a, 11U);
  _SFD_DATA_RANGE_CHECK(*c5_b_R, 12U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Kpr, 13U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Lpr0, 14U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Gamma, 15U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_dT;
  c5_b_hoistedGlobal = *c5_b_T;
  c5_c_hoistedGlobal = *c5_b_L;
  c5_d_hoistedGlobal = *c5_b_dL;
  c5_e_hoistedGlobal = *c5_b_ddL;
  c5_f_hoistedGlobal = *c5_b_Lsr0;
  c5_g_hoistedGlobal = *c5_b_Ksr;
  c5_h_hoistedGlobal = *c5_b_M;
  c5_i_hoistedGlobal = *c5_b_C;
  c5_j_hoistedGlobal = *c5_b_Beta;
  c5_k_hoistedGlobal = *c5_k_a;
  c5_l_hoistedGlobal = *c5_b_R;
  c5_m_hoistedGlobal = *c5_b_Kpr;
  c5_n_hoistedGlobal = *c5_b_Lpr0;
  c5_o_hoistedGlobal = *c5_b_Gamma;
  c5_dT = c5_hoistedGlobal;
  c5_T = c5_b_hoistedGlobal;
  c5_L = c5_c_hoistedGlobal;
  c5_dL = c5_d_hoistedGlobal;
  c5_ddL = c5_e_hoistedGlobal;
  c5_Lsr0 = c5_f_hoistedGlobal;
  c5_Ksr = c5_g_hoistedGlobal;
  c5_M = c5_h_hoistedGlobal;
  c5_C = c5_i_hoistedGlobal;
  c5_Beta = c5_j_hoistedGlobal;
  c5_a = c5_k_hoistedGlobal;
  c5_R = c5_l_hoistedGlobal;
  c5_Kpr = c5_m_hoistedGlobal;
  c5_Lpr0 = c5_n_hoistedGlobal;
  c5_Gamma = c5_o_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 19U, 19U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_LTerm, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c5_dT, 3U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_T, 4U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_L, 5U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_dL, 6U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_ddL, 7U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Lsr0, 8U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Ksr, 9U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_M, 10U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_C, 11U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Beta, 12U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_a, 13U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_R, 14U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Kpr, 15U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Lpr0, 16U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_Gamma, 17U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_ddT, 18U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  c5_A = c5_T;
  c5_B = c5_Ksr;
  c5_x = c5_A;
  c5_y = c5_B;
  c5_b_x = c5_x;
  c5_b_y = c5_y;
  c5_c_y = c5_b_x / c5_b_y;
  c5_LTerm = (c5_L - c5_Lsr0) - c5_c_y;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 5);
  c5_b_A = c5_Ksr;
  c5_b_B = c5_M;
  c5_c_x = c5_b_A;
  c5_d_y = c5_b_B;
  c5_d_x = c5_c_x;
  c5_e_y = c5_d_y;
  c5_f_y = c5_d_x / c5_e_y;
  c5_b_a = c5_C;
  c5_b = c5_Beta;
  c5_g_y = c5_b_a * c5_b;
  c5_c_A = c5_dT;
  c5_c_B = c5_Ksr;
  c5_e_x = c5_c_A;
  c5_h_y = c5_c_B;
  c5_f_x = c5_e_x;
  c5_i_y = c5_h_y;
  c5_j_y = c5_f_x / c5_i_y;
  c5_g_x = c5_dL - c5_j_y;
  c5_h_x = c5_g_x;
  c5_h_x = muDoubleScalarSign(c5_h_x);
  c5_c_a = c5_g_y;
  c5_b_b = c5_h_x;
  c5_k_y = c5_c_a * c5_b_b;
  c5_d_A = c5_dT;
  c5_d_B = c5_Ksr;
  c5_i_x = c5_d_A;
  c5_l_y = c5_d_B;
  c5_j_x = c5_i_x;
  c5_m_y = c5_l_y;
  c5_n_y = c5_j_x / c5_m_y;
  c5_k_x = c5_dL - c5_n_y;
  c5_l_x = c5_k_x;
  c5_o_y = muDoubleScalarAbs(c5_l_x);
  c5_d_a = c5_o_y;
  c5_c_b = c5_a;
  c5_e_a = c5_d_a;
  c5_d_b = c5_c_b;
  c5_ak = c5_e_a;
  c5_bk = c5_d_b;
  if (c5_ak < 0.0) {
    c5_m_x = c5_bk;
    c5_n_x = c5_m_x;
    c5_n_x = muDoubleScalarFloor(c5_n_x);
    if (c5_n_x != c5_bk) {
      c5_eml_error(chartInstance);
    }
  }

  c5_c = muDoubleScalarPower(c5_ak, c5_bk);
  c5_f_a = c5_k_y;
  c5_e_b = c5_c;
  c5_p_y = c5_f_a * c5_e_b;
  c5_g_a = c5_p_y;
  c5_f_b = c5_LTerm - c5_R;
  c5_q_y = c5_g_a * c5_f_b;
  c5_h_a = c5_Kpr;
  c5_g_b = c5_LTerm - c5_Lpr0;
  c5_r_y = c5_h_a * c5_g_b;
  c5_i_a = c5_M;
  c5_h_b = c5_ddL;
  c5_s_y = c5_i_a * c5_h_b;
  c5_j_a = c5_f_y;
  c5_i_b = (((c5_q_y + c5_r_y) + c5_s_y) + c5_Gamma) - c5_T;
  c5_ddT = c5_j_a * c5_i_b;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  *c5_b_ddT = c5_ddT;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  sf_debug_check_for_state_inconsistency(_MuscleSpindleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_MuscleSpindle(SFc5_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc5_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_ddT, const char_T *c5_identifier)
{
  real_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_ddT), &c5_thisId);
  sf_mex_destroy(&c5_ddT);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_ddT;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc5_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c5_ddT = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_ddT), &c5_thisId);
  sf_mex_destroy(&c5_ddT);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_MuscleSpindle_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[14];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i0;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c5_i0 = 0; c5_i0 < 14; c5_i0++) {
    c5_r0 = &c5_info[c5_i0];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i0);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[14])
{
  c5_info[0].context = "";
  c5_info[0].name = "mrdivide";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[0].fileTimeLo = 1325156538U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 1319762366U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[1].name = "rdivide";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[1].fileTimeLo = 1286851244U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[2].name = "eml_div";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[2].fileTimeLo = 1313380210U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context = "";
  c5_info[3].name = "mtimes";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[3].fileTimeLo = 1289552092U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context = "";
  c5_info[4].name = "sign";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/sign.m";
  c5_info[4].fileTimeLo = 1286851150U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/sign.m";
  c5_info[5].name = "eml_scalar_sign";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c5_info[5].fileTimeLo = 1307683638U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context = "";
  c5_info[6].name = "abs";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[6].fileTimeLo = 1286851094U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[7].name = "eml_scalar_abs";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[7].fileTimeLo = 1286851112U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context = "";
  c5_info[8].name = "mpower";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[8].fileTimeLo = 1286851242U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[9].name = "power";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[9].fileTimeLo = 1307683640U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[10].name = "eml_scalar_eg";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[10].fileTimeLo = 1286851196U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[11].name = "eml_scalexp_alloc";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[11].fileTimeLo = 1286851196U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[12].name = "eml_scalar_floor";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[12].fileTimeLo = 1286851126U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 0U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[13].name = "eml_error";
  c5_info[13].dominantType = "char";
  c5_info[13].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[13].fileTimeLo = 1305350400U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
}

static void c5_eml_error(SFc5_MuscleSpindleInstanceStruct *chartInstance)
{
  int32_T c5_i1;
  static char_T c5_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c5_u[31];
  const mxArray *c5_y = NULL;
  for (c5_i1 = 0; c5_i1 < 31; c5_i1++) {
    c5_u[c5_i1] = c5_varargin_1[c5_i1];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 31), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c5_y));
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc5_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_c_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i2;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i2, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i2;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc5_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_d_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_MuscleSpindle, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_MuscleSpindle), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_MuscleSpindle);
  return c5_y;
}

static uint8_T c5_e_emlrt_marshallIn(SFc5_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_MuscleSpindle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1354727709U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2102368257U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2131688995U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1523311011U);
}

mxArray *sf_c5_MuscleSpindle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xDnnGj7T4ueVOH7NVCE1mD");
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

static const mxArray *sf_get_sim_state_info_c5_MuscleSpindle(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ddT\",},{M[8],M[0],T\"is_active_c5_MuscleSpindle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_MuscleSpindle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_MuscleSpindleInstanceStruct *chartInstance;
    chartInstance = (SFc5_MuscleSpindleInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_MuscleSpindleMachineNumber_,
           5,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,340);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)c5_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c5_dT;
          real_T *c5_T;
          real_T *c5_L;
          real_T *c5_dL;
          real_T *c5_ddL;
          real_T *c5_Lsr0;
          real_T *c5_Ksr;
          real_T *c5_ddT;
          real_T *c5_M;
          real_T *c5_C;
          real_T *c5_Beta;
          real_T *c5_a;
          real_T *c5_R;
          real_T *c5_Kpr;
          real_T *c5_Lpr0;
          real_T *c5_Gamma;
          c5_Gamma = (real_T *)ssGetInputPortSignal(chartInstance->S, 14);
          c5_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c5_Kpr = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c5_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c5_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c5_Beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c5_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c5_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c5_ddT = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c5_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c5_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c5_ddL = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c5_dL = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c5_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_dT = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_dT);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_T);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_L);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_dL);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_ddL);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_Lsr0);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_Ksr);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_ddT);
          _SFD_SET_DATA_VALUE_PTR(8U, c5_M);
          _SFD_SET_DATA_VALUE_PTR(9U, c5_C);
          _SFD_SET_DATA_VALUE_PTR(10U, c5_Beta);
          _SFD_SET_DATA_VALUE_PTR(11U, c5_a);
          _SFD_SET_DATA_VALUE_PTR(12U, c5_R);
          _SFD_SET_DATA_VALUE_PTR(13U, c5_Kpr);
          _SFD_SET_DATA_VALUE_PTR(14U, c5_Lpr0);
          _SFD_SET_DATA_VALUE_PTR(15U, c5_Gamma);
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
  return "ycYIpW7uLL3gXRMLAbVLtF";
}

static void sf_opaque_initialize_c5_MuscleSpindle(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_MuscleSpindleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
  initialize_c5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_MuscleSpindle(void *chartInstanceVar)
{
  enable_c5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_MuscleSpindle(void *chartInstanceVar)
{
  disable_c5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_MuscleSpindle(void *chartInstanceVar)
{
  sf_c5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_MuscleSpindle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_MuscleSpindle
    ((SFc5_MuscleSpindleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_MuscleSpindle();/* state var info */
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

extern void sf_internal_set_sim_state_c5_MuscleSpindle(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_MuscleSpindle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_MuscleSpindle(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_MuscleSpindle(S);
}

static void sf_opaque_set_sim_state_c5_MuscleSpindle(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_MuscleSpindle(S, st);
}

static void sf_opaque_terminate_c5_MuscleSpindle(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_MuscleSpindleInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_MuscleSpindle_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_MuscleSpindle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_MuscleSpindle((SFc5_MuscleSpindleInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MuscleSpindle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
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
        infoStruct,5,15);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1930901454U));
  ssSetChecksum1(S,(1384310163U));
  ssSetChecksum2(S,(3717849801U));
  ssSetChecksum3(S,(2631616217U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_MuscleSpindle(SimStruct *S)
{
  SFc5_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc5_MuscleSpindleInstanceStruct *)malloc(sizeof
    (SFc5_MuscleSpindleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_MuscleSpindleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_MuscleSpindle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_MuscleSpindle;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_MuscleSpindle;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_MuscleSpindle;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_MuscleSpindle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_MuscleSpindle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_MuscleSpindle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_MuscleSpindle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_MuscleSpindle;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_MuscleSpindle;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_MuscleSpindle;
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

void c5_MuscleSpindle_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_MuscleSpindle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_MuscleSpindle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
