#include "lang_v2_func_signatures.c"

typedef
struct
{
    int type0;
    int type1;
    CalcFunction function;
}OpSignature;

typedef
struct
{
    int op;
    OpSignature *signatureTbl;
    int size;
} Ops;

#define DECL_S(t0, t1, func) {.type0=t0, .type1=t1, .function=func}

OpSignature _addSignatures[]=
{
    DECL_S(TU8, TU8, _add_u8_u8),
    DECL_S(TU16, TU16, _add_u16_u16),
    DECL_S(TU32, TU32, _add_u32_u32),
    DECL_S(TU64, TU64, _add_u64_u64),
    DECL_S(TI8, TI8, _add_i8_i8),
    DECL_S(TI16, TI16, _add_i16_i16),
    DECL_S(TI32, TI32, _add_i32_i32),
    DECL_S(TI64, TI64, _add_i64_i64),
    DECL_S(TF32, TF32, _add_f32_f32),
    DECL_S(TF64, TF64, _add_f64_f64),
    DECL_S(TREAL, TREAL, _add_real_real),
    DECL_S(TVEC2, TVEC2, _add_vec2_vec2),
    DECL_S(TVEC3, TVEC3, _add_vec3_vec3),
    DECL_S(TVEC4, TVEC4, _add_vec4_vec4),
    DECL_S(TMAT2, TMAT2, _add_mat2_mat2),
    DECL_S(TMAT3, TMAT3, _add_mat3_mat3),
    DECL_S(TMAT4, TMAT4, _add_mat4_mat4)
};

OpSignature _subSignatures[]=
{
    DECL_S(TU8, TU8, _sub_u8_u8),
    DECL_S(TU16, TU16, _sub_u16_u16),
    DECL_S(TU32, TU32, _sub_u32_u32),
    DECL_S(TU64, TU64, _sub_u64_u64),
    DECL_S(TI8, TI8, _sub_i8_i8),
    DECL_S(TI16, TI16, _sub_i16_i16),
    DECL_S(TI32, TI32, _sub_i32_i32),
    DECL_S(TI64, TI64, _sub_i64_i64),
    DECL_S(TF32, TF32, _sub_f32_f32),
    DECL_S(TF64, TF64, _sub_f64_f64),
    DECL_S(TREAL, TREAL, _sub_real_real),
    DECL_S(TVEC2, TVEC2, _sub_vec2_vec2),
    DECL_S(TVEC3, TVEC3, _sub_vec3_vec3),
    DECL_S(TVEC4, TVEC4, _sub_vec4_vec4),
    DECL_S(TMAT2, TMAT2, _sub_mat2_mat2),
    DECL_S(TMAT3, TMAT3, _sub_mat3_mat3),
    DECL_S(TMAT4, TMAT4, _sub_mat4_mat4)
};

OpSignature _mulSignatures[]=
{
    DECL_S(TU8, TU8, _mul_u8_u8),
    DECL_S(TU16, TU16, _mul_u16_u16),
    DECL_S(TU32, TU32, _mul_u32_u32),
    DECL_S(TU64, TU64, _mul_u64_u64),
    DECL_S(TI8, TI8, _mul_i8_i8),
    DECL_S(TI16, TI16, _mul_i16_i16),
    DECL_S(TI32, TI32, _mul_i32_i32),
    DECL_S(TI64, TI64, _mul_i64_i64),
    DECL_S(TF32, TF32, _mul_f32_f32),
    DECL_S(TF64, TF64, _mul_f64_f64),
    DECL_S(TREAL, TREAL, _mul_real_real),
    DECL_S(TVEC2, TVEC2, _mul_vec2_vec2),
    DECL_S(TVEC3, TVEC3, _mul_vec3_vec3),
    DECL_S(TVEC4, TVEC4, _mul_vec4_vec4),
    DECL_S(TMAT2, TMAT2, _mul_mat2_mat2),
    DECL_S(TMAT3, TMAT3, _mul_mat3_mat3),
    DECL_S(TMAT4, TMAT4, _mul_mat4_mat4)
};

OpSignature _divSignatures[]=
{
    DECL_S(TU8, TU8, _div_u8_u8),
    DECL_S(TU16, TU16, _div_u16_u16),
    DECL_S(TU32, TU32, _div_u32_u32),
    DECL_S(TU64, TU64, _div_u64_u64),
    DECL_S(TI8, TI8, _div_i8_i8),
    DECL_S(TI16, TI16, _div_i16_i16),
    DECL_S(TI32, TI32, _div_i32_i32),
    DECL_S(TI64, TI64, _div_i64_i64),
    DECL_S(TF32, TF32, _div_f32_f32),
    DECL_S(TF64, TF64, _div_f64_f64),
    DECL_S(TREAL, TREAL, _div_real_real)
};

OpSignature _pwrSignatures[]=
{
    DECL_S(TU8, TU8, _pwr_u8_u8),
    DECL_S(TU16, TU16, _pwr_u16_u16),
    DECL_S(TU32, TU32, _pwr_u32_u32),
    DECL_S(TU64, TU64, _pwr_u64_u64),
    DECL_S(TI8, TI8, _pwr_i8_i8),
    DECL_S(TI16, TI16, _pwr_i16_i16),
    DECL_S(TI32, TI32, _pwr_i32_i32),
    DECL_S(TI64, TI64, _pwr_i64_i64),
    DECL_S(TF32, TF32, _pwr_f32_f32),
    DECL_S(TF64, TF64, _pwr_f64_f64),
    DECL_S(TREAL, TREAL, _pwr_real_real)
};

OpSignature _srSignatures[]=
{
    DECL_S(TU8, TU8, _sr_u8_u8),
    DECL_S(TU16, TU16, _sr_u16_u16),
    DECL_S(TU32, TU32, _sr_u32_u32),
    DECL_S(TU64, TU64, _sr_u64_u64),
    DECL_S(TI8, TI8, _sr_i8_i8),
    DECL_S(TI16, TI16, _sr_i16_i16),
    DECL_S(TI32, TI32, _sr_i32_i32),
    DECL_S(TI64, TI64, _sr_i64_i64)
};

OpSignature _slSignatures[]=
{
    DECL_S(TU8, TU8, _sl_u8_u8),
    DECL_S(TU16, TU16, _sl_u16_u16),
    DECL_S(TU32, TU32, _sl_u32_u32),
    DECL_S(TU64, TU64, _sl_u64_u64),
    DECL_S(TI8, TI8, _sl_i8_i8),
    DECL_S(TI16, TI16, _sl_i16_i16),
    DECL_S(TI32, TI32, _sl_i32_i32),
    DECL_S(TI64, TI64, _sl_i64_i64)
};

OpSignature _bandSignatures[]=
{
    DECL_S(TU8, TU8, _band_u8_u8),
    DECL_S(TU16, TU16, _band_u16_u16),
    DECL_S(TU32, TU32, _band_u32_u32),
    DECL_S(TU64, TU64, _band_u64_u64),
    DECL_S(TI8, TI8, _band_i8_i8),
    DECL_S(TI16, TI16, _band_i16_i16),
    DECL_S(TI32, TI32, _band_i32_i32),
    DECL_S(TI64, TI64, _band_i64_i64)
};

OpSignature _andSignatures[]=
{
    DECL_S(TBOOL, TBOOL, _and_bool_bool)
};

OpSignature _borSignatures[]=
{
    DECL_S(TU8, TU8, _bor_u8_u8),
    DECL_S(TU16, TU16, _bor_u16_u16),
    DECL_S(TU32, TU32, _bor_u32_u32),
    DECL_S(TU64, TU64, _bor_u64_u64),
    DECL_S(TI8, TI8, _bor_i8_i8),
    DECL_S(TI16, TI16, _bor_i16_i16),
    DECL_S(TI32, TI32, _bor_i32_i32),
    DECL_S(TI64, TI64, _bor_i64_i64)
};

OpSignature _orSignatures[]=
{
    DECL_S(TBOOL, TBOOL, _or_bool_bool)
};

OpSignature _cmtSignatures[]=
{
    DECL_S(TU8, TU8, _cmt_u8_u8),
    DECL_S(TU16, TU16, _cmt_u16_u16),
    DECL_S(TU32, TU32, _cmt_u32_u32),
    DECL_S(TU64, TU64, _cmt_u64_u64),
    DECL_S(TI8, TI8, _cmt_i8_i8),
    DECL_S(TI16, TI16, _cmt_i16_i16),
    DECL_S(TI32, TI32, _cmt_i32_i32),
    DECL_S(TI64, TI64, _cmt_i64_i64),
    DECL_S(TF32, TF32, _cmt_f32_f32),
    DECL_S(TF64, TF64, _cmt_f64_f64),
    DECL_S(TREAL, TREAL, _cmt_real_real)
};

OpSignature _cltSignatures[]=
{
    DECL_S(TU8, TU8, _clt_u8_u8),
    DECL_S(TU16, TU16, _clt_u16_u16),
    DECL_S(TU32, TU32, _clt_u32_u32),
    DECL_S(TU64, TU64, _clt_u64_u64),
    DECL_S(TI8, TI8, _clt_i8_i8),
    DECL_S(TI16, TI16, _clt_i16_i16),
    DECL_S(TI32, TI32, _clt_i32_i32),
    DECL_S(TI64, TI64, _clt_i64_i64),
    DECL_S(TF32, TF32, _clt_f32_f32),
    DECL_S(TF64, TF64, _clt_f64_f64),
    DECL_S(TREAL, TREAL, _clt_real_real)
};

OpSignature _cmteqSignatures[]=
{
    DECL_S(TU8, TU8, _cmteq_u8_u8),
    DECL_S(TU16, TU16, _cmteq_u16_u16),
    DECL_S(TU32, TU32, _cmteq_u32_u32),
    DECL_S(TU64, TU64, _cmteq_u64_u64),
    DECL_S(TI8, TI8, _cmteq_i8_i8),
    DECL_S(TI16, TI16, _cmteq_i16_i16),
    DECL_S(TI32, TI32, _cmteq_i32_i32),
    DECL_S(TI64, TI64, _cmteq_i64_i64),
    DECL_S(TF32, TF32, _cmteq_f32_f32),
    DECL_S(TF64, TF64, _cmteq_f64_f64),
    DECL_S(TREAL, TREAL, _cmteq_real_real)
};

OpSignature _clteqSignatures[]=
{
    DECL_S(TU8, TU8, _clteq_u8_u8),
    DECL_S(TU16, TU16, _clteq_u16_u16),
    DECL_S(TU32, TU32, _clteq_u32_u32),
    DECL_S(TU64, TU64, _clteq_u64_u64),
    DECL_S(TI8, TI8, _clteq_i8_i8),
    DECL_S(TI16, TI16, _clteq_i16_i16),
    DECL_S(TI32, TI32, _clteq_i32_i32),
    DECL_S(TI64, TI64, _clteq_i64_i64),
    DECL_S(TF32, TF32, _clteq_f32_f32),
    DECL_S(TF64, TF64, _clteq_f64_f64),
    DECL_S(TREAL, TREAL, _clteq_real_real)
};

OpSignature _ceqSignatures[]=
{
    DECL_S(TU8, TU8, _ceq_u8_u8),
    DECL_S(TU16, TU16, _ceq_u16_u16),
    DECL_S(TU32, TU32, _ceq_u32_u32),
    DECL_S(TU64, TU64, _ceq_u64_u64),
    DECL_S(TI8, TI8, _ceq_i8_i8),
    DECL_S(TI16, TI16, _ceq_i16_i16),
    DECL_S(TI32, TI32, _ceq_i32_i32),
    DECL_S(TI64, TI64, _ceq_i64_i64),
    DECL_S(TF32, TF32, _ceq_f32_f32),
    DECL_S(TF64, TF64, _ceq_f64_f64),
    DECL_S(TREAL, TREAL, _ceq_real_real)
};

OpSignature _cneqSignatures[]=
{
    DECL_S(TU8, TU8, _cneq_u8_u8),
    DECL_S(TU16, TU16, _cneq_u16_u16),
    DECL_S(TU32, TU32, _cneq_u32_u32),
    DECL_S(TU64, TU64, _cneq_u64_u64),
    DECL_S(TI8, TI8, _cneq_i8_i8),
    DECL_S(TI16, TI16, _cneq_i16_i16),
    DECL_S(TI32, TI32, _cneq_i32_i32),
    DECL_S(TI64, TI64, _cneq_i64_i64),
    DECL_S(TF32, TF32, _cneq_f32_f32),
    DECL_S(TF64, TF64, _cneq_f64_f64),
    DECL_S(TREAL, TREAL, _cneq_real_real)
};

#define DECL_O(_op, _pSignature) {.op=_op,.signatureTbl=_pSignature,.size=(sizeof(_pSignature)/sizeof(OpSignature))}

Ops _opTbl[]=
{
    DECL_O(OP_ADD, _addSignatures),
    DECL_O(OP_SUB, _subSignatures),
    DECL_O(OP_MUL, _mulSignatures),
    DECL_O(OP_DIV, _divSignatures),
    DECL_O(OP_PWR, _pwrSignatures),
    DECL_O(OP_SR, _srSignatures),
    DECL_O(OP_SL, _slSignatures),
    DECL_O(OP_BAND, _bandSignatures),
    DECL_O(OP_AND, _andSignatures),
    DECL_O(OP_BOR, _borSignatures),
    DECL_O(OP_OR, _orSignatures),
    DECL_O(OP_CMT, _cmtSignatures),
    DECL_O(OP_CLT, _cltSignatures),
    DECL_O(OP_CMTEQ, _cmteqSignatures),
    DECL_O(OP_CLTEQ, _clteqSignatures),
    DECL_O(OP_CEQ, _ceqSignatures),
    DECL_O(OP_CNEQ, _cneqSignatures)
};

CalcFunction
LookupOp(int op, int type0, int type1)
{
    CalcFunction func =NULL;
    _bool isFound =0;
    
    for (int i=0;
         i<(sizeof(_opTbl)/sizeof(Ops));
         i++)
    {
        if (op ==_opTbl[i].op)
        {
            for (int j=0;
                 j<_opTbl[i].size;
                 j++)
            {
                if (type0 ==_opTbl[i].signatureTbl[j].type0
                    && type1 ==_opTbl[i].signatureTbl[j].type1)
                {
                    func =_opTbl[i].signatureTbl[j].function;
                    isFound =1;
                }
            }
            if (isFound)
            {
                break;
            }
        }
        if (isFound)
        {
            break;
        }
    }
    return func;
}