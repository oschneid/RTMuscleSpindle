/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MuscleSpindle_sfun.h"
#include "c4_MuscleSpindle.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MuscleSpindle_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[16] = { "term1", "term2", "term",
  "nargin", "nargout", "Gsnd", "T", "Ksr", "X", "Lsnd", "Lsr0", "LsrN", "Lpr0",
  "LprN", "L", "ScndryAffrntCntrbtn" };

/* Function Declarations */
static void initialize_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance);
static void initialize_params_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct *
  chartInstance);
static void enable_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance);
static void disable_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_MuscleSpindle
  (SFc4_MuscleSpindleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_MuscleSpindle
  (SFc4_MuscleSpindleInstanceStruct *chartInstance);
static void set_sim_state_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance);
static void sf_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct *chartInstance);
static void initSimStructsc4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance);
static void registerMessagesc4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_ScndryAffrntCntrbtn, const char_T
  *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_c_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_d_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_MuscleSpindle, const char_T
  *c4_identifier);
static uint8_T c4_e_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_MuscleSpindleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_MuscleSpindle = 0U;
}

static void initialize_params_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct *
  chartInstance)
{
}

static void enable_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_MuscleSpindle
  (SFc4_MuscleSpindleInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_MuscleSpindle
  (SFc4_MuscleSpindleInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  uint8_T c4_b_hoistedGlobal;
  uint8_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T *c4_ScndryAffrntCntrbtn;
  c4_ScndryAffrntCntrbtn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(2), FALSE);
  c4_hoistedGlobal = *c4_ScndryAffrntCntrbtn;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_is_active_c4_MuscleSpindle;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_ScndryAffrntCntrbtn;
  c4_ScndryAffrntCntrbtn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_ScndryAffrntCntrbtn = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "ScndryAffrntCntrbtn");
  chartInstance->c4_is_active_c4_MuscleSpindle = c4_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)),
     "is_active_c4_MuscleSpindle");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_MuscleSpindle(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void sf_c4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_f_hoistedGlobal;
  real_T c4_g_hoistedGlobal;
  real_T c4_h_hoistedGlobal;
  real_T c4_i_hoistedGlobal;
  real_T c4_j_hoistedGlobal;
  real_T c4_Gsnd;
  real_T c4_T;
  real_T c4_Ksr;
  real_T c4_X;
  real_T c4_Lsnd;
  real_T c4_Lsr0;
  real_T c4_LsrN;
  real_T c4_Lpr0;
  real_T c4_LprN;
  real_T c4_L;
  uint32_T c4_debug_family_var_map[16];
  real_T c4_term1;
  real_T c4_term2;
  real_T c4_term;
  real_T c4_nargin = 10.0;
  real_T c4_nargout = 1.0;
  real_T c4_ScndryAffrntCntrbtn;
  real_T c4_A;
  real_T c4_B;
  real_T c4_x;
  real_T c4_y;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_y;
  real_T c4_b_A;
  real_T c4_b_B;
  real_T c4_c_x;
  real_T c4_d_y;
  real_T c4_d_x;
  real_T c4_e_y;
  real_T c4_f_y;
  real_T c4_a;
  real_T c4_b;
  real_T c4_c_A;
  real_T c4_c_B;
  real_T c4_e_x;
  real_T c4_g_y;
  real_T c4_f_x;
  real_T c4_h_y;
  real_T c4_i_y;
  real_T c4_d_A;
  real_T c4_d_B;
  real_T c4_g_x;
  real_T c4_j_y;
  real_T c4_h_x;
  real_T c4_k_y;
  real_T c4_l_y;
  real_T c4_b_a;
  real_T c4_b_b;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_m_y;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_n_y;
  real_T c4_e_a;
  real_T c4_e_b;
  real_T *c4_b_L;
  real_T *c4_b_LprN;
  real_T *c4_b_Lpr0;
  real_T *c4_b_LsrN;
  real_T *c4_b_Lsr0;
  real_T *c4_b_Lsnd;
  real_T *c4_b_X;
  real_T *c4_b_Ksr;
  real_T *c4_b_T;
  real_T *c4_b_Gsnd;
  real_T *c4_b_ScndryAffrntCntrbtn;
  c4_b_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c4_b_LprN = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c4_b_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c4_b_LsrN = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c4_b_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c4_b_Lsnd = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_ScndryAffrntCntrbtn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_Gsnd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_b_Gsnd, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_b_T, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_Ksr, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_X, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_b_ScndryAffrntCntrbtn, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_b_Lsnd, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_b_Lsr0, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_b_LsrN, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_b_Lpr0, 8U);
  _SFD_DATA_RANGE_CHECK(*c4_b_LprN, 9U);
  _SFD_DATA_RANGE_CHECK(*c4_b_L, 10U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_Gsnd;
  c4_b_hoistedGlobal = *c4_b_T;
  c4_c_hoistedGlobal = *c4_b_Ksr;
  c4_d_hoistedGlobal = *c4_b_X;
  c4_e_hoistedGlobal = *c4_b_Lsnd;
  c4_f_hoistedGlobal = *c4_b_Lsr0;
  c4_g_hoistedGlobal = *c4_b_LsrN;
  c4_h_hoistedGlobal = *c4_b_Lpr0;
  c4_i_hoistedGlobal = *c4_b_LprN;
  c4_j_hoistedGlobal = *c4_b_L;
  c4_Gsnd = c4_hoistedGlobal;
  c4_T = c4_b_hoistedGlobal;
  c4_Ksr = c4_c_hoistedGlobal;
  c4_X = c4_d_hoistedGlobal;
  c4_Lsnd = c4_e_hoistedGlobal;
  c4_Lsr0 = c4_f_hoistedGlobal;
  c4_LsrN = c4_g_hoistedGlobal;
  c4_Lpr0 = c4_h_hoistedGlobal;
  c4_LprN = c4_i_hoistedGlobal;
  c4_L = c4_j_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_term1, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_term2, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_term, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Gsnd, 5U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_T, 6U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Ksr, 7U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_X, 8U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Lsnd, 9U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Lsr0, 10U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_LsrN, 11U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_Lpr0, 12U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_LprN, 13U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_L, 14U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_ScndryAffrntCntrbtn, 15U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_A = c4_Lsnd;
  c4_B = c4_Lsr0;
  c4_x = c4_A;
  c4_y = c4_B;
  c4_b_x = c4_x;
  c4_b_y = c4_y;
  c4_c_y = c4_b_x / c4_b_y;
  c4_b_A = c4_T;
  c4_b_B = c4_Ksr;
  c4_c_x = c4_b_A;
  c4_d_y = c4_b_B;
  c4_d_x = c4_c_x;
  c4_e_y = c4_d_y;
  c4_f_y = c4_d_x / c4_e_y;
  c4_a = c4_c_y;
  c4_b = c4_f_y - (c4_LsrN - c4_Lsr0);
  c4_term1 = c4_a * c4_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 5);
  c4_c_A = c4_Lsnd;
  c4_c_B = c4_Lpr0;
  c4_e_x = c4_c_A;
  c4_g_y = c4_c_B;
  c4_f_x = c4_e_x;
  c4_h_y = c4_g_y;
  c4_i_y = c4_f_x / c4_h_y;
  c4_d_A = c4_T;
  c4_d_B = c4_Ksr;
  c4_g_x = c4_d_A;
  c4_j_y = c4_d_B;
  c4_h_x = c4_g_x;
  c4_k_y = c4_j_y;
  c4_l_y = c4_h_x / c4_k_y;
  c4_b_a = c4_i_y;
  c4_b_b = ((c4_L - c4_l_y) - c4_Lsr0) - c4_LprN;
  c4_term2 = c4_b_a * c4_b_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 7);
  c4_c_a = c4_X;
  c4_c_b = c4_term1;
  c4_m_y = c4_c_a * c4_c_b;
  c4_d_a = 1.0 - c4_X;
  c4_d_b = c4_term2;
  c4_n_y = c4_d_a * c4_d_b;
  c4_term = c4_m_y + c4_n_y;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_e_a = c4_Gsnd;
  c4_e_b = c4_term;
  c4_ScndryAffrntCntrbtn = c4_e_a * c4_e_b;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  *c4_b_ScndryAffrntCntrbtn = c4_ScndryAffrntCntrbtn;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MuscleSpindleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc4_MuscleSpindle(SFc4_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc4_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_ScndryAffrntCntrbtn, const char_T
  *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ScndryAffrntCntrbtn),
    &c4_thisId);
  sf_mex_destroy(&c4_ScndryAffrntCntrbtn);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_ScndryAffrntCntrbtn;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc4_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c4_ScndryAffrntCntrbtn = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_ScndryAffrntCntrbtn),
    &c4_thisId);
  sf_mex_destroy(&c4_ScndryAffrntCntrbtn);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_MuscleSpindle_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[5];
  c4_ResolvedFunctionInfo (*c4_b_info)[5];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[5])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mrdivide";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[0].fileTimeLo = 1357947948U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 1319726366U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[1].name = "rdivide";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[1].fileTimeLo = 1346506788U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[2].name = "eml_scalexp_compatible";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c4_b_info)[2].fileTimeLo = 1286815196U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[3].name = "eml_div";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c4_b_info)[3].fileTimeLo = 1313344210U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context = "";
  (*c4_b_info)[4].name = "mtimes";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[4].fileTimeLo = 1289516092U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c4_i0 = 0; c4_i0 < 5; c4_i0++) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i0);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc4_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_c_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i1;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i1, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc4_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_d_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_MuscleSpindle, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_MuscleSpindle), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_MuscleSpindle);
  return c4_y;
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c4_MuscleSpindle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2927169710U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3875967505U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2948318806U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2847105181U);
}

mxArray *sf_c4_MuscleSpindle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6MdPBYbz53whJT5GuBWJbE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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

mxArray *sf_c4_MuscleSpindle_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_MuscleSpindle(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ScndryAffrntCntrbtn\",},{M[8],M[0],T\"is_active_c4_MuscleSpindle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_MuscleSpindle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_MuscleSpindleInstanceStruct *chartInstance;
    chartInstance = (SFc4_MuscleSpindleInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MuscleSpindleMachineNumber_,
           4,
           1,
           1,
           11,
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
            (sfGlobalDebugInstanceStruct,_MuscleSpindleMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _MuscleSpindleMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Gsnd");
          _SFD_SET_DATA_PROPS(1,1,1,0,"T");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Ksr");
          _SFD_SET_DATA_PROPS(3,1,1,0,"X");
          _SFD_SET_DATA_PROPS(4,2,0,1,"ScndryAffrntCntrbtn");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Lsnd");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Lsr0");
          _SFD_SET_DATA_PROPS(7,1,1,0,"LsrN");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Lpr0");
          _SFD_SET_DATA_PROPS(9,1,1,0,"LprN");
          _SFD_SET_DATA_PROPS(10,1,1,0,"L");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,372);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c4_Gsnd;
          real_T *c4_T;
          real_T *c4_Ksr;
          real_T *c4_X;
          real_T *c4_ScndryAffrntCntrbtn;
          real_T *c4_Lsnd;
          real_T *c4_Lsr0;
          real_T *c4_LsrN;
          real_T *c4_Lpr0;
          real_T *c4_LprN;
          real_T *c4_L;
          c4_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c4_LprN = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c4_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c4_LsrN = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c4_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c4_Lsnd = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c4_ScndryAffrntCntrbtn = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          c4_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_Gsnd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_Gsnd);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_T);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_Ksr);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_X);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_ScndryAffrntCntrbtn);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_Lsnd);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_Lsr0);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_LsrN);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_Lpr0);
          _SFD_SET_DATA_VALUE_PTR(9U, c4_LprN);
          _SFD_SET_DATA_VALUE_PTR(10U, c4_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _MuscleSpindleMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "EIegXK4lrHvNN24BpctGtD";
}

static void sf_opaque_initialize_c4_MuscleSpindle(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_MuscleSpindleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
  initialize_c4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_MuscleSpindle(void *chartInstanceVar)
{
  enable_c4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_MuscleSpindle(void *chartInstanceVar)
{
  disable_c4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_MuscleSpindle(void *chartInstanceVar)
{
  sf_c4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_MuscleSpindle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_MuscleSpindle
    ((SFc4_MuscleSpindleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_MuscleSpindle();/* state var info */
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

extern void sf_internal_set_sim_state_c4_MuscleSpindle(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_MuscleSpindle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_MuscleSpindle(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_MuscleSpindle(S);
}

static void sf_opaque_set_sim_state_c4_MuscleSpindle(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_MuscleSpindle(S, st);
}

static void sf_opaque_terminate_c4_MuscleSpindle(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_MuscleSpindleInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MuscleSpindle_optimization_info();
    }

    finalize_c4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_MuscleSpindle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_MuscleSpindle((SFc4_MuscleSpindleInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MuscleSpindle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 10; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3271247123U));
  ssSetChecksum1(S,(2205023528U));
  ssSetChecksum2(S,(1044813094U));
  ssSetChecksum3(S,(4222593174U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_MuscleSpindle(SimStruct *S)
{
  SFc4_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc4_MuscleSpindleInstanceStruct *)utMalloc(sizeof
    (SFc4_MuscleSpindleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_MuscleSpindleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_MuscleSpindle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_MuscleSpindle;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_MuscleSpindle;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_MuscleSpindle;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_MuscleSpindle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_MuscleSpindle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_MuscleSpindle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_MuscleSpindle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_MuscleSpindle;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_MuscleSpindle;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_MuscleSpindle;
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

void c4_MuscleSpindle_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_MuscleSpindle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_MuscleSpindle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
