/* Include files */

#include "blascompat32.h"
#include "MuscleSpindle_sfun.h"
#include "c6_MuscleSpindle.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MuscleSpindle_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[16] = { "nargin", "nargout", "L", "dL",
  "ddL", "Lsr0", "Ksr", "M", "C", "Beta", "a", "R", "Kpr", "Lpr0", "Gamma", "T0"
};

/* Function Declarations */
static void initialize_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance);
static void initialize_params_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct *
  chartInstance);
static void enable_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance);
static void disable_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_MuscleSpindle
  (SFc6_MuscleSpindleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_MuscleSpindle
  (SFc6_MuscleSpindleInstanceStruct *chartInstance);
static void set_sim_state_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance);
static void sf_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct *chartInstance);
static void initSimStructsc6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_T0, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[14]);
static real_T c6_mpower(SFc6_MuscleSpindleInstanceStruct *chartInstance, real_T
  c6_a, real_T c6_b);
static void c6_eml_error(SFc6_MuscleSpindleInstanceStruct *chartInstance);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_c_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_d_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_MuscleSpindle, const char_T
  *c6_identifier);
static uint8_T c6_e_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_MuscleSpindleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance)
{
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_MuscleSpindle = 0U;
}

static void initialize_params_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct *
  chartInstance)
{
}

static void enable_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_MuscleSpindle
  (SFc6_MuscleSpindleInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_MuscleSpindle
  (SFc6_MuscleSpindleInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T *c6_T0;
  c6_T0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2), FALSE);
  c6_hoistedGlobal = *c6_T0;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = chartInstance->c6_is_active_c6_MuscleSpindle;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_T0;
  c6_T0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  *c6_T0 = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
    "T0");
  chartInstance->c6_is_active_c6_MuscleSpindle = c6_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_MuscleSpindle");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_MuscleSpindle(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void sf_c6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_hoistedGlobal;
  real_T c6_e_hoistedGlobal;
  real_T c6_f_hoistedGlobal;
  real_T c6_g_hoistedGlobal;
  real_T c6_h_hoistedGlobal;
  real_T c6_i_hoistedGlobal;
  real_T c6_j_hoistedGlobal;
  real_T c6_k_hoistedGlobal;
  real_T c6_l_hoistedGlobal;
  real_T c6_m_hoistedGlobal;
  real_T c6_L;
  real_T c6_dL;
  real_T c6_ddL;
  real_T c6_Lsr0;
  real_T c6_Ksr;
  real_T c6_M;
  real_T c6_C;
  real_T c6_Beta;
  real_T c6_a;
  real_T c6_R;
  real_T c6_Kpr;
  real_T c6_Lpr0;
  real_T c6_Gamma;
  uint32_T c6_debug_family_var_map[16];
  real_T c6_nargin = 13.0;
  real_T c6_nargout = 1.0;
  real_T c6_T0;
  real_T c6_b_a;
  real_T c6_b;
  real_T c6_y;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_a;
  real_T c6_b_b;
  real_T c6_b_y;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_c_y;
  real_T c6_d_a;
  real_T c6_c_b;
  real_T c6_d_y;
  real_T c6_e_a;
  real_T c6_d_b;
  real_T c6_e_y;
  real_T c6_f_a;
  real_T c6_e_b;
  real_T c6_f_y;
  real_T c6_g_a;
  real_T c6_f_b;
  real_T c6_g_y;
  real_T c6_h_a;
  real_T c6_g_b;
  real_T c6_h_y;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_i_a;
  real_T c6_h_b;
  real_T c6_i_y;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_j_y;
  real_T c6_j_a;
  real_T c6_i_b;
  real_T c6_k_y;
  real_T c6_A;
  real_T c6_B;
  real_T c6_i_x;
  real_T c6_l_y;
  real_T c6_j_x;
  real_T c6_m_y;
  real_T c6_n_y;
  real_T c6_b_A;
  real_T c6_b_B;
  real_T c6_k_x;
  real_T c6_o_y;
  real_T c6_l_x;
  real_T c6_p_y;
  real_T *c6_b_Gamma;
  real_T *c6_b_Lpr0;
  real_T *c6_b_Kpr;
  real_T *c6_b_R;
  real_T *c6_k_a;
  real_T *c6_b_Beta;
  real_T *c6_b_C;
  real_T *c6_b_M;
  real_T *c6_b_Ksr;
  real_T *c6_b_Lsr0;
  real_T *c6_b_ddL;
  real_T *c6_b_dL;
  real_T *c6_b_L;
  real_T *c6_b_T0;
  c6_b_Gamma = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
  c6_b_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c6_b_Kpr = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c6_b_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c6_k_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c6_b_Beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c6_b_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c6_b_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c6_b_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c6_b_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_b_ddL = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_b_dL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_b_T0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_b_T0, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_b_L, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_b_dL, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_b_ddL, 3U);
  _SFD_DATA_RANGE_CHECK(*c6_b_Lsr0, 4U);
  _SFD_DATA_RANGE_CHECK(*c6_b_Ksr, 5U);
  _SFD_DATA_RANGE_CHECK(*c6_b_M, 6U);
  _SFD_DATA_RANGE_CHECK(*c6_b_C, 7U);
  _SFD_DATA_RANGE_CHECK(*c6_b_Beta, 8U);
  _SFD_DATA_RANGE_CHECK(*c6_k_a, 9U);
  _SFD_DATA_RANGE_CHECK(*c6_b_R, 10U);
  _SFD_DATA_RANGE_CHECK(*c6_b_Kpr, 11U);
  _SFD_DATA_RANGE_CHECK(*c6_b_Lpr0, 12U);
  _SFD_DATA_RANGE_CHECK(*c6_b_Gamma, 13U);
  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  c6_hoistedGlobal = *c6_b_L;
  c6_b_hoistedGlobal = *c6_b_dL;
  c6_c_hoistedGlobal = *c6_b_ddL;
  c6_d_hoistedGlobal = *c6_b_Lsr0;
  c6_e_hoistedGlobal = *c6_b_Ksr;
  c6_f_hoistedGlobal = *c6_b_M;
  c6_g_hoistedGlobal = *c6_b_C;
  c6_h_hoistedGlobal = *c6_b_Beta;
  c6_i_hoistedGlobal = *c6_k_a;
  c6_j_hoistedGlobal = *c6_b_R;
  c6_k_hoistedGlobal = *c6_b_Kpr;
  c6_l_hoistedGlobal = *c6_b_Lpr0;
  c6_m_hoistedGlobal = *c6_b_Gamma;
  c6_L = c6_hoistedGlobal;
  c6_dL = c6_b_hoistedGlobal;
  c6_ddL = c6_c_hoistedGlobal;
  c6_Lsr0 = c6_d_hoistedGlobal;
  c6_Ksr = c6_e_hoistedGlobal;
  c6_M = c6_f_hoistedGlobal;
  c6_C = c6_g_hoistedGlobal;
  c6_Beta = c6_h_hoistedGlobal;
  c6_a = c6_i_hoistedGlobal;
  c6_R = c6_j_hoistedGlobal;
  c6_Kpr = c6_k_hoistedGlobal;
  c6_Lpr0 = c6_l_hoistedGlobal;
  c6_Gamma = c6_m_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 16U, 16U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_L, 2U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_dL, 3U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_ddL, 4U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Lsr0, 5U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Ksr, 6U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_M, 7U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_C, 8U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Beta, 9U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_a, 10U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_R, 11U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Kpr, 12U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Lpr0, 13U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_Gamma, 14U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_T0, 15U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  c6_b_a = c6_C;
  c6_b = c6_Beta;
  c6_y = c6_b_a * c6_b;
  c6_x = c6_dL;
  c6_b_x = c6_x;
  c6_b_x = muDoubleScalarSign(c6_b_x);
  c6_c_a = c6_y;
  c6_b_b = c6_b_x;
  c6_b_y = c6_c_a * c6_b_b;
  c6_c_x = c6_dL;
  c6_d_x = c6_c_x;
  c6_c_y = muDoubleScalarAbs(c6_d_x);
  c6_d_a = c6_b_y;
  c6_c_b = c6_mpower(chartInstance, c6_c_y, c6_a);
  c6_d_y = c6_d_a * c6_c_b;
  c6_e_a = c6_d_y;
  c6_d_b = (c6_L - c6_Lsr0) - c6_R;
  c6_e_y = c6_e_a * c6_d_b;
  c6_f_a = c6_Kpr;
  c6_e_b = (c6_L - c6_Lsr0) - c6_Lpr0;
  c6_f_y = c6_f_a * c6_e_b;
  c6_g_a = c6_M;
  c6_f_b = c6_ddL;
  c6_g_y = c6_g_a * c6_f_b;
  c6_h_a = c6_C;
  c6_g_b = c6_Beta;
  c6_h_y = c6_h_a * c6_g_b;
  c6_e_x = c6_dL;
  c6_f_x = c6_e_x;
  c6_f_x = muDoubleScalarSign(c6_f_x);
  c6_i_a = c6_h_y;
  c6_h_b = c6_f_x;
  c6_i_y = c6_i_a * c6_h_b;
  c6_g_x = c6_dL;
  c6_h_x = c6_g_x;
  c6_j_y = muDoubleScalarAbs(c6_h_x);
  c6_j_a = c6_i_y;
  c6_i_b = c6_mpower(chartInstance, c6_j_y, c6_a);
  c6_k_y = c6_j_a * c6_i_b;
  c6_A = c6_Kpr;
  c6_B = c6_Ksr;
  c6_i_x = c6_A;
  c6_l_y = c6_B;
  c6_j_x = c6_i_x;
  c6_m_y = c6_l_y;
  c6_n_y = c6_j_x / c6_m_y;
  c6_b_A = ((c6_e_y + c6_f_y) + c6_g_y) + c6_Gamma;
  c6_b_B = (c6_k_y + c6_n_y) + 1.0;
  c6_k_x = c6_b_A;
  c6_o_y = c6_b_B;
  c6_l_x = c6_k_x;
  c6_p_y = c6_o_y;
  c6_T0 = c6_l_x / c6_p_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c6_b_T0 = c6_T0;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  sf_debug_check_for_state_inconsistency(_MuscleSpindleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc6_MuscleSpindle(SFc6_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc6_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_T0, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_T0), &c6_thisId);
  sf_mex_destroy(&c6_T0);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_T0;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc6_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c6_T0 = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_T0), &c6_thisId);
  sf_mex_destroy(&c6_T0);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_MuscleSpindle_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[14];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i0;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c6_i0 = 0; c6_i0 < 14; c6_i0++) {
    c6_r0 = &c6_info[c6_i0];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i0);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c6_nameCaptureInfo);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[14])
{
  c6_info[0].context = "";
  c6_info[0].name = "mtimes";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[0].fileTimeLo = 1289552092U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "";
  c6_info[1].name = "sign";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/sign.m";
  c6_info[1].fileTimeLo = 1286851150U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/sign.m";
  c6_info[2].name = "eml_scalar_sign";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m";
  c6_info[2].fileTimeLo = 1307683638U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context = "";
  c6_info[3].name = "abs";
  c6_info[3].dominantType = "double";
  c6_info[3].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[3].fileTimeLo = 1286851094U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/abs.m";
  c6_info[4].name = "eml_scalar_abs";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c6_info[4].fileTimeLo = 1286851112U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context = "";
  c6_info[5].name = "mpower";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[5].fileTimeLo = 1286851242U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mpower.m";
  c6_info[6].name = "power";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[6].fileTimeLo = 1307683640U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[7].name = "eml_scalar_eg";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[7].fileTimeLo = 1286851196U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[8].name = "eml_scalexp_alloc";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[8].fileTimeLo = 1286851196U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[9].name = "eml_scalar_floor";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c6_info[9].fileTimeLo = 1286851126U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/power.m";
  c6_info[10].name = "eml_error";
  c6_info[10].dominantType = "char";
  c6_info[10].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_error.m";
  c6_info[10].fileTimeLo = 1305350400U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context = "";
  c6_info[11].name = "mrdivide";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[11].fileTimeLo = 1325156538U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 1319762366U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[12].name = "rdivide";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[12].fileTimeLo = 1286851244U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[13].name = "eml_div";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved =
    "[ILXE]/Applications/MATLAB_R2012a.app/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[13].fileTimeLo = 1313380210U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
}

static real_T c6_mpower(SFc6_MuscleSpindleInstanceStruct *chartInstance, real_T
  c6_a, real_T c6_b)
{
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_ak;
  real_T c6_bk;
  real_T c6_x;
  real_T c6_b_x;
  c6_b_a = c6_a;
  c6_b_b = c6_b;
  c6_ak = c6_b_a;
  c6_bk = c6_b_b;
  if (c6_ak < 0.0) {
    c6_x = c6_bk;
    c6_b_x = c6_x;
    c6_b_x = muDoubleScalarFloor(c6_b_x);
    if (c6_b_x != c6_bk) {
      c6_eml_error(chartInstance);
    }
  }

  return muDoubleScalarPower(c6_ak, c6_bk);
}

static void c6_eml_error(SFc6_MuscleSpindleInstanceStruct *chartInstance)
{
  int32_T c6_i1;
  static char_T c6_varargin_1[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm',
    'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c6_u[31];
  const mxArray *c6_y = NULL;
  for (c6_i1 = 0; c6_i1 < 31; c6_i1++) {
    c6_u[c6_i1] = c6_varargin_1[c6_i1];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 10, 0U, 1U, 0U, 2, 1, 31), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c6_y));
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc6_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_c_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i2;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i2, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i2;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc6_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_d_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_MuscleSpindle, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_MuscleSpindle), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_MuscleSpindle);
  return c6_y;
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_MuscleSpindle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(938013965U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3446924524U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1555899280U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(668937475U);
}

mxArray *sf_c6_MuscleSpindle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tmXCbYZfjKH4frOh5GgQ4");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c6_MuscleSpindle(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[13],T\"T0\",},{M[8],M[0],T\"is_active_c6_MuscleSpindle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_MuscleSpindle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_MuscleSpindleInstanceStruct *chartInstance;
    chartInstance = (SFc6_MuscleSpindleInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_MuscleSpindleMachineNumber_,
           6,
           1,
           1,
           14,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"T0");
          _SFD_SET_DATA_PROPS(1,1,1,0,"L");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dL");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ddL");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Lsr0");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Ksr");
          _SFD_SET_DATA_PROPS(6,1,1,0,"M");
          _SFD_SET_DATA_PROPS(7,1,1,0,"C");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Beta");
          _SFD_SET_DATA_PROPS(9,1,1,0,"a");
          _SFD_SET_DATA_PROPS(10,1,1,0,"R");
          _SFD_SET_DATA_PROPS(11,1,1,0,"Kpr");
          _SFD_SET_DATA_PROPS(12,1,1,0,"Lpr0");
          _SFD_SET_DATA_PROPS(13,1,1,0,"Gamma");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,346);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c6_T0;
          real_T *c6_L;
          real_T *c6_dL;
          real_T *c6_ddL;
          real_T *c6_Lsr0;
          real_T *c6_Ksr;
          real_T *c6_M;
          real_T *c6_C;
          real_T *c6_Beta;
          real_T *c6_a;
          real_T *c6_R;
          real_T *c6_Kpr;
          real_T *c6_Lpr0;
          real_T *c6_Gamma;
          c6_Gamma = (real_T *)ssGetInputPortSignal(chartInstance->S, 12);
          c6_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c6_Kpr = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c6_R = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c6_a = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c6_Beta = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c6_C = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c6_M = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c6_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c6_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c6_ddL = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_dL = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c6_T0 = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_T0);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_L);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_dL);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_ddL);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_Lsr0);
          _SFD_SET_DATA_VALUE_PTR(5U, c6_Ksr);
          _SFD_SET_DATA_VALUE_PTR(6U, c6_M);
          _SFD_SET_DATA_VALUE_PTR(7U, c6_C);
          _SFD_SET_DATA_VALUE_PTR(8U, c6_Beta);
          _SFD_SET_DATA_VALUE_PTR(9U, c6_a);
          _SFD_SET_DATA_VALUE_PTR(10U, c6_R);
          _SFD_SET_DATA_VALUE_PTR(11U, c6_Kpr);
          _SFD_SET_DATA_VALUE_PTR(12U, c6_Lpr0);
          _SFD_SET_DATA_VALUE_PTR(13U, c6_Gamma);
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
  return "q0bLWDmxnDxpaSZP3och4";
}

static void sf_opaque_initialize_c6_MuscleSpindle(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_MuscleSpindleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
  initialize_c6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_MuscleSpindle(void *chartInstanceVar)
{
  enable_c6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_MuscleSpindle(void *chartInstanceVar)
{
  disable_c6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_MuscleSpindle(void *chartInstanceVar)
{
  sf_c6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_MuscleSpindle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_MuscleSpindle
    ((SFc6_MuscleSpindleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_MuscleSpindle();/* state var info */
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

extern void sf_internal_set_sim_state_c6_MuscleSpindle(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_MuscleSpindle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_MuscleSpindle(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_MuscleSpindle(S);
}

static void sf_opaque_set_sim_state_c6_MuscleSpindle(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c6_MuscleSpindle(S, st);
}

static void sf_opaque_terminate_c6_MuscleSpindle(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_MuscleSpindleInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_MuscleSpindle_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_MuscleSpindle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_MuscleSpindle((SFc6_MuscleSpindleInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MuscleSpindle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,6,
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,13);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2736793953U));
  ssSetChecksum1(S,(2266369597U));
  ssSetChecksum2(S,(369080983U));
  ssSetChecksum3(S,(1669966295U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_MuscleSpindle(SimStruct *S)
{
  SFc6_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc6_MuscleSpindleInstanceStruct *)malloc(sizeof
    (SFc6_MuscleSpindleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_MuscleSpindleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_MuscleSpindle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_MuscleSpindle;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_MuscleSpindle;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_MuscleSpindle;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_MuscleSpindle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_MuscleSpindle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_MuscleSpindle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_MuscleSpindle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_MuscleSpindle;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_MuscleSpindle;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_MuscleSpindle;
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

void c6_MuscleSpindle_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_MuscleSpindle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_MuscleSpindle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
