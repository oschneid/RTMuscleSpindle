/* Include files */

#include <stddef.h>
#include "blas.h"
#include "MuscleSpindle_sfun.h"
#include "c3_MuscleSpindle.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "MuscleSpindle_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[16] = { "term1", "term2", "term",
  "nargin", "nargout", "Gsnd", "T", "Ksr", "X", "Lsnd", "Lsr0", "LsrN", "Lpr0",
  "LprN", "L", "ScndryAffrntCntrbtn" };

/* Function Declarations */
static void initialize_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance);
static void initialize_params_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct *
  chartInstance);
static void enable_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance);
static void disable_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_MuscleSpindle
  (SFc3_MuscleSpindleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_MuscleSpindle
  (SFc3_MuscleSpindleInstanceStruct *chartInstance);
static void set_sim_state_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance);
static void sf_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct *chartInstance);
static void initSimStructsc3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance);
static void registerMessagesc3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_ScndryAffrntCntrbtn, const char_T
  *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_MuscleSpindle, const char_T
  *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_MuscleSpindleInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_MuscleSpindle = 0U;
}

static void initialize_params_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct *
  chartInstance)
{
}

static void enable_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_MuscleSpindle
  (SFc3_MuscleSpindleInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_MuscleSpindle
  (SFc3_MuscleSpindleInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_ScndryAffrntCntrbtn;
  c3_ScndryAffrntCntrbtn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  c3_hoistedGlobal = *c3_ScndryAffrntCntrbtn;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_is_active_c3_MuscleSpindle;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_ScndryAffrntCntrbtn;
  c3_ScndryAffrntCntrbtn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_ScndryAffrntCntrbtn = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 0)), "ScndryAffrntCntrbtn");
  chartInstance->c3_is_active_c3_MuscleSpindle = c3_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
     "is_active_c3_MuscleSpindle");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_MuscleSpindle(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void sf_c3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_g_hoistedGlobal;
  real_T c3_h_hoistedGlobal;
  real_T c3_i_hoistedGlobal;
  real_T c3_j_hoistedGlobal;
  real_T c3_Gsnd;
  real_T c3_T;
  real_T c3_Ksr;
  real_T c3_X;
  real_T c3_Lsnd;
  real_T c3_Lsr0;
  real_T c3_LsrN;
  real_T c3_Lpr0;
  real_T c3_LprN;
  real_T c3_L;
  uint32_T c3_debug_family_var_map[16];
  real_T c3_term1;
  real_T c3_term2;
  real_T c3_term;
  real_T c3_nargin = 10.0;
  real_T c3_nargout = 1.0;
  real_T c3_ScndryAffrntCntrbtn;
  real_T c3_A;
  real_T c3_B;
  real_T c3_x;
  real_T c3_y;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_c_y;
  real_T c3_b_A;
  real_T c3_b_B;
  real_T c3_c_x;
  real_T c3_d_y;
  real_T c3_d_x;
  real_T c3_e_y;
  real_T c3_f_y;
  real_T c3_a;
  real_T c3_b;
  real_T c3_c_A;
  real_T c3_c_B;
  real_T c3_e_x;
  real_T c3_g_y;
  real_T c3_f_x;
  real_T c3_h_y;
  real_T c3_i_y;
  real_T c3_d_A;
  real_T c3_d_B;
  real_T c3_g_x;
  real_T c3_j_y;
  real_T c3_h_x;
  real_T c3_k_y;
  real_T c3_l_y;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_m_y;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_n_y;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T *c3_b_L;
  real_T *c3_b_LprN;
  real_T *c3_b_Lpr0;
  real_T *c3_b_LsrN;
  real_T *c3_b_Lsr0;
  real_T *c3_b_Lsnd;
  real_T *c3_b_X;
  real_T *c3_b_Ksr;
  real_T *c3_b_T;
  real_T *c3_b_Gsnd;
  real_T *c3_b_ScndryAffrntCntrbtn;
  c3_b_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c3_b_LprN = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
  c3_b_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_LsrN = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_Lsnd = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_ScndryAffrntCntrbtn = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_Gsnd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c3_b_Gsnd, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_T, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Ksr, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_X, 3U);
  _SFD_DATA_RANGE_CHECK(*c3_b_ScndryAffrntCntrbtn, 4U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Lsnd, 5U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Lsr0, 6U);
  _SFD_DATA_RANGE_CHECK(*c3_b_LsrN, 7U);
  _SFD_DATA_RANGE_CHECK(*c3_b_Lpr0, 8U);
  _SFD_DATA_RANGE_CHECK(*c3_b_LprN, 9U);
  _SFD_DATA_RANGE_CHECK(*c3_b_L, 10U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_Gsnd;
  c3_b_hoistedGlobal = *c3_b_T;
  c3_c_hoistedGlobal = *c3_b_Ksr;
  c3_d_hoistedGlobal = *c3_b_X;
  c3_e_hoistedGlobal = *c3_b_Lsnd;
  c3_f_hoistedGlobal = *c3_b_Lsr0;
  c3_g_hoistedGlobal = *c3_b_LsrN;
  c3_h_hoistedGlobal = *c3_b_Lpr0;
  c3_i_hoistedGlobal = *c3_b_LprN;
  c3_j_hoistedGlobal = *c3_b_L;
  c3_Gsnd = c3_hoistedGlobal;
  c3_T = c3_b_hoistedGlobal;
  c3_Ksr = c3_c_hoistedGlobal;
  c3_X = c3_d_hoistedGlobal;
  c3_Lsnd = c3_e_hoistedGlobal;
  c3_Lsr0 = c3_f_hoistedGlobal;
  c3_LsrN = c3_g_hoistedGlobal;
  c3_Lpr0 = c3_h_hoistedGlobal;
  c3_LprN = c3_i_hoistedGlobal;
  c3_L = c3_j_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_term1, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_term2, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_term, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 4U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Gsnd, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_T, 6U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Ksr, 7U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_X, 8U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Lsnd, 9U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Lsr0, 10U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_LsrN, 11U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_Lpr0, 12U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_LprN, 13U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_L, 14U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ScndryAffrntCntrbtn, 15U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_A = c3_Lsnd;
  c3_B = c3_Lsr0;
  c3_x = c3_A;
  c3_y = c3_B;
  c3_b_x = c3_x;
  c3_b_y = c3_y;
  c3_c_y = c3_b_x / c3_b_y;
  c3_b_A = c3_T;
  c3_b_B = c3_Ksr;
  c3_c_x = c3_b_A;
  c3_d_y = c3_b_B;
  c3_d_x = c3_c_x;
  c3_e_y = c3_d_y;
  c3_f_y = c3_d_x / c3_e_y;
  c3_a = c3_c_y;
  c3_b = c3_f_y - (c3_LsrN - c3_Lsr0);
  c3_term1 = c3_a * c3_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_c_A = c3_Lsnd;
  c3_c_B = c3_Lpr0;
  c3_e_x = c3_c_A;
  c3_g_y = c3_c_B;
  c3_f_x = c3_e_x;
  c3_h_y = c3_g_y;
  c3_i_y = c3_f_x / c3_h_y;
  c3_d_A = c3_T;
  c3_d_B = c3_Ksr;
  c3_g_x = c3_d_A;
  c3_j_y = c3_d_B;
  c3_h_x = c3_g_x;
  c3_k_y = c3_j_y;
  c3_l_y = c3_h_x / c3_k_y;
  c3_b_a = c3_i_y;
  c3_b_b = ((c3_L - c3_l_y) - c3_Lsr0) - c3_LprN;
  c3_term2 = c3_b_a * c3_b_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_c_a = c3_X;
  c3_c_b = c3_term1;
  c3_m_y = c3_c_a * c3_c_b;
  c3_d_a = 1.0 - c3_X;
  c3_d_b = c3_term2;
  c3_n_y = c3_d_a * c3_d_b;
  c3_term = c3_m_y + c3_n_y;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_e_a = c3_Gsnd;
  c3_e_b = c3_term;
  c3_ScndryAffrntCntrbtn = c3_e_a * c3_e_b;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_ScndryAffrntCntrbtn = c3_ScndryAffrntCntrbtn;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_MuscleSpindleMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc3_MuscleSpindle(SFc3_MuscleSpindleInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc3_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_ScndryAffrntCntrbtn, const char_T
  *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_ScndryAffrntCntrbtn),
    &c3_thisId);
  sf_mex_destroy(&c3_ScndryAffrntCntrbtn);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_ScndryAffrntCntrbtn;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc3_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c3_ScndryAffrntCntrbtn = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_ScndryAffrntCntrbtn),
    &c3_thisId);
  sf_mex_destroy(&c3_ScndryAffrntCntrbtn);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_MuscleSpindle_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[5];
  c3_ResolvedFunctionInfo (*c3_b_info)[5];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i0;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[5])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "mrdivide";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[0].fileTimeLo = 1357947948U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 1319726366U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c3_b_info)[1].name = "rdivide";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[1].fileTimeLo = 1346506788U;
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[2].name = "eml_scalexp_compatible";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c3_b_info)[2].fileTimeLo = 1286815196U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c3_b_info)[3].name = "eml_div";
  (*c3_b_info)[3].dominantType = "double";
  (*c3_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c3_b_info)[3].fileTimeLo = 1313344210U;
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context = "";
  (*c3_b_info)[4].name = "mtimes";
  (*c3_b_info)[4].dominantType = "double";
  (*c3_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c3_b_info)[4].fileTimeLo = 1289516092U;
  (*c3_b_info)[4].fileTimeHi = 0U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 5), FALSE);
  for (c3_i0 = 0; c3_i0 < 5; c3_i0++) {
    c3_r0 = &c3_info[c3_i0];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i0);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i0);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc3_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i1;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i1, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc3_MuscleSpindleInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_MuscleSpindle, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_MuscleSpindle), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_MuscleSpindle);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn(SFc3_MuscleSpindleInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_MuscleSpindleInstanceStruct
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

void sf_c3_MuscleSpindle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2927169710U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3875967505U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2948318806U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2847105181U);
}

mxArray *sf_c3_MuscleSpindle_get_autoinheritance_info(void)
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

mxArray *sf_c3_MuscleSpindle_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_MuscleSpindle(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ScndryAffrntCntrbtn\",},{M[8],M[0],T\"is_active_c3_MuscleSpindle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_MuscleSpindle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_MuscleSpindleInstanceStruct *chartInstance;
    chartInstance = (SFc3_MuscleSpindleInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _MuscleSpindleMachineNumber_,
           3,
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
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c3_Gsnd;
          real_T *c3_T;
          real_T *c3_Ksr;
          real_T *c3_X;
          real_T *c3_ScndryAffrntCntrbtn;
          real_T *c3_Lsnd;
          real_T *c3_Lsr0;
          real_T *c3_LsrN;
          real_T *c3_Lpr0;
          real_T *c3_LprN;
          real_T *c3_L;
          c3_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c3_LprN = (real_T *)ssGetInputPortSignal(chartInstance->S, 8);
          c3_Lpr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
          c3_LsrN = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_Lsr0 = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c3_Lsnd = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c3_ScndryAffrntCntrbtn = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          c3_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c3_Ksr = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_T = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_Gsnd = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_Gsnd);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_T);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_Ksr);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_X);
          _SFD_SET_DATA_VALUE_PTR(4U, c3_ScndryAffrntCntrbtn);
          _SFD_SET_DATA_VALUE_PTR(5U, c3_Lsnd);
          _SFD_SET_DATA_VALUE_PTR(6U, c3_Lsr0);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_LsrN);
          _SFD_SET_DATA_VALUE_PTR(8U, c3_Lpr0);
          _SFD_SET_DATA_VALUE_PTR(9U, c3_LprN);
          _SFD_SET_DATA_VALUE_PTR(10U, c3_L);
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

static void sf_opaque_initialize_c3_MuscleSpindle(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_MuscleSpindleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
  initialize_c3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_MuscleSpindle(void *chartInstanceVar)
{
  enable_c3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_MuscleSpindle(void *chartInstanceVar)
{
  disable_c3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_MuscleSpindle(void *chartInstanceVar)
{
  sf_c3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_MuscleSpindle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_MuscleSpindle
    ((SFc3_MuscleSpindleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_MuscleSpindle();/* state var info */
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

extern void sf_internal_set_sim_state_c3_MuscleSpindle(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_MuscleSpindle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_MuscleSpindle(SimStruct* S)
{
  return sf_internal_get_sim_state_c3_MuscleSpindle(S);
}

static void sf_opaque_set_sim_state_c3_MuscleSpindle(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c3_MuscleSpindle(S, st);
}

static void sf_opaque_terminate_c3_MuscleSpindle(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_MuscleSpindleInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_MuscleSpindle_optimization_info();
    }

    finalize_c3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_MuscleSpindle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_MuscleSpindle((SFc3_MuscleSpindleInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_MuscleSpindle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
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
        infoStruct,3,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
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

static void mdlRTW_c3_MuscleSpindle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_MuscleSpindle(SimStruct *S)
{
  SFc3_MuscleSpindleInstanceStruct *chartInstance;
  chartInstance = (SFc3_MuscleSpindleInstanceStruct *)utMalloc(sizeof
    (SFc3_MuscleSpindleInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_MuscleSpindleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_MuscleSpindle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_MuscleSpindle;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_MuscleSpindle;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_MuscleSpindle;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_MuscleSpindle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_MuscleSpindle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_MuscleSpindle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_MuscleSpindle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_MuscleSpindle;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_MuscleSpindle;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_MuscleSpindle;
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

void c3_MuscleSpindle_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_MuscleSpindle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_MuscleSpindle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_MuscleSpindle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
