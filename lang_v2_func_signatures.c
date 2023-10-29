CalcResult
_add_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u8 =t0->u8 +t1->u8;
    return result;
}

CalcResult
_add_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =t0->u16 + t1->u16;
    return result;
}

CalcResult
_add_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =t0->u32 + t1->u32;
    return result;
}

CalcResult
_add_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =t0->u64 + t1->u64;
    return result;
}

CalcResult
_add_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =t0->i8 + t1->i8;
    return result;
}

CalcResult
_add_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =t0->i16 + t1->i16;
    return result;
}

CalcResult
_add_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =t0->i32 + t1->i32;
    return result;
}

CalcResult
_add_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =t0->i64 + t1->i64;
    return result;
}

CalcResult
_add_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF32;
    result._const.f32 =t0->f32 + t1->f32;
    return result;
}

CalcResult
_add_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF64;
    result._const.f64 =t0->f64 + t1->f64;
    return result;
}

CalcResult
_add_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TREAL;
    result._const.real =t0->real + t1->real;
    return result;
}

CalcResult
_add_vec2_vec2(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC2;
    result._const.matrix[0] =t0->matrix[0] + t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] + t1->matrix[1];
    
    return result;
}

CalcResult
_add_vec3_vec3(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC3;
    result._const.matrix[0] =t0->matrix[0] + t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] + t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] + t1->matrix[2];
    
    return result;
}

CalcResult
_add_vec4_vec4(Type* t0, Type* t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC4;
    result._const.matrix[0] =t0->matrix[0] +t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] +t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] +t1->matrix[2];
    result._const.matrix[3] =t0->matrix[3] +t1->matrix[3];
    
    return result;
}

CalcResult
_add_mat2_mat2(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT2;
    result._const.matrix[0] = t0->matrix[0] +t1->matrix[0];
    result._const.matrix[1] = t0->matrix[1] +t1->matrix[1];
    result._const.matrix[2] = t0->matrix[2] +t1->matrix[2];
    result._const.matrix[3] = t0->matrix[3] +t1->matrix[3];
    
    return result;
}

CalcResult
_add_mat3_mat3(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT3;
    result._const.matrix[0] =t0->matrix[0] +t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] +t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] +t1->matrix[2];
    result._const.matrix[3] =t0->matrix[3] +t1->matrix[3];
    result._const.matrix[4] =t0->matrix[4] +t1->matrix[4];
    result._const.matrix[5] =t0->matrix[5] +t1->matrix[5];
    result._const.matrix[6] =t0->matrix[6] +t1->matrix[6];
    result._const.matrix[7] =t0->matrix[7] +t1->matrix[7];
    result._const.matrix[8] =t0->matrix[8] +t1->matrix[8];
    
    return result;
}

CalcResult
_add_mat4_mat4(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT4;
    result._const.matrix[0] =t0->matrix[0];
    result._const.matrix[0] =t0->matrix[0] +t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] +t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] +t1->matrix[2];
    result._const.matrix[3] =t0->matrix[3] +t1->matrix[3];
    result._const.matrix[4] =t0->matrix[4] +t1->matrix[4];
    result._const.matrix[5] =t0->matrix[5] +t1->matrix[5];
    result._const.matrix[6] =t0->matrix[6] +t1->matrix[6];
    result._const.matrix[7] =t0->matrix[7] +t1->matrix[7];
    result._const.matrix[8] =t0->matrix[8] +t1->matrix[8];
    result._const.matrix[9] =t0->matrix[9] +t1->matrix[9];
    result._const.matrix[10] =t0->matrix[10] +t1->matrix[10];
    result._const.matrix[11] =t0->matrix[11] +t1->matrix[11];
    result._const.matrix[12] =t0->matrix[12] +t1->matrix[12];
    result._const.matrix[13] =t0->matrix[13] +t1->matrix[13];
    result._const.matrix[14] =t0->matrix[14] +t1->matrix[14];
    result._const.matrix[15] =t0->matrix[15] +t1->matrix[15];
    
    return result;
}

/* Sub functions */

CalcResult
_sub_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u16 =t0->u8 -t1->u8;
    return result;
}

CalcResult
_sub_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =t0->u16 -t1->u16;
    return result;
}

CalcResult
_sub_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =t0->u32 -t1->u32;
    return result;
}

CalcResult
_sub_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =t0->u64 -t1->u64;
    return result;
}

CalcResult
_sub_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =t0->i8 -t1->i8;
    return result;
}

CalcResult
_sub_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =t0->i16 -t1->i16;
    return result;
}

CalcResult
_sub_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =t0->i32 -t1->i32;
    return result;
}

CalcResult
_sub_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =t0->i64 -t1->i64;
    return result;
}

CalcResult
_sub_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF32;
    result._const.f32 =t0->f32 -t1->f32;
    return result;
}

CalcResult
_sub_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF64;
    result._const.f64 =t0->f64 -t1->f64;
    return result;
}

CalcResult
_sub_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TREAL;
    result._const.real =t0->real -t1->real;
    return result;
}

CalcResult
_sub_vec2_vec2(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC2;
    result._const.matrix[0] =t0->matrix[0] -t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] -t1->matrix[1];
    
    return result;
}

CalcResult
_sub_vec3_vec3(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC3;
    result._const.matrix[0] =t0->matrix[0] -t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] -t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] -t1->matrix[2];
    
    return result;
}

CalcResult
_sub_vec4_vec4(Type* t0, Type* t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC4;
    result._const.matrix[0] =t0->matrix[0] -t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] -t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] -t1->matrix[2];
    result._const.matrix[3] =t0->matrix[3] -t1->matrix[3];
    
    return result;
}

CalcResult
_sub_mat2_mat2(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT2;
    result._const.matrix[0] = t0->matrix[0] -t1->matrix[0];
    result._const.matrix[1] = t0->matrix[1] -t1->matrix[1];
    result._const.matrix[2] = t0->matrix[2] -t1->matrix[2];
    result._const.matrix[3] = t0->matrix[3] -t1->matrix[3];
    
    return result;
}

CalcResult
_sub_mat3_mat3(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT3;
    result._const.matrix[0] =t0->matrix[0] -t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] -t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] -t1->matrix[2];
    result._const.matrix[3] =t0->matrix[3] -t1->matrix[3];
    result._const.matrix[4] =t0->matrix[4] -t1->matrix[4];
    result._const.matrix[5] =t0->matrix[5] -t1->matrix[5];
    result._const.matrix[6] =t0->matrix[6] -t1->matrix[6];
    result._const.matrix[7] =t0->matrix[7] -t1->matrix[7];
    result._const.matrix[8] =t0->matrix[8] -t1->matrix[8];
    
    return result;
}

CalcResult
_sub_mat4_mat4(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT4;
    result._const.matrix[0] =t0->matrix[0];
    result._const.matrix[0] =t0->matrix[0] -t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] -t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] -t1->matrix[2];
    result._const.matrix[3] =t0->matrix[3] -t1->matrix[3];
    result._const.matrix[4] =t0->matrix[4] -t1->matrix[4];
    result._const.matrix[5] =t0->matrix[5] -t1->matrix[5];
    result._const.matrix[6] =t0->matrix[6] -t1->matrix[6];
    result._const.matrix[7] =t0->matrix[7] -t1->matrix[7];
    result._const.matrix[8] =t0->matrix[8] -t1->matrix[8];
    result._const.matrix[9] =t0->matrix[9] -t1->matrix[9];
    result._const.matrix[10] =t0->matrix[10] -t1->matrix[10];
    result._const.matrix[11] =t0->matrix[11] -t1->matrix[11];
    result._const.matrix[12] =t0->matrix[12] -t1->matrix[12];
    result._const.matrix[13] =t0->matrix[13] -t1->matrix[13];
    result._const.matrix[14] =t0->matrix[14] -t1->matrix[14];
    result._const.matrix[15] =t0->matrix[15] -t1->matrix[15];
    
    return result;
}

/* Mul Functions */

CalcResult
_mul_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u8 =t0->u8 *t1->u8;
    return result;
}

CalcResult
_mul_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =t0->u16 *t1->u16;
    return result;
}

CalcResult
_mul_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =t0->u32 *t1->u32;
    return result;
}

CalcResult
_mul_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =t0->u64 *t1->u64;
    return result;
}

CalcResult
_mul_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =t0->i8 *t1->i8;
    return result;
}

CalcResult
_mul_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =t0->i16 *t1->i16;
    return result;
}

CalcResult
_mul_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =t0->i32 *t1->i32;
    return result;
}

CalcResult
_mul_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =t0->i64 *t1->i64;
    return result;
}

CalcResult
_mul_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF32;
    result._const.f32 =t0->f32 *t1->f32;
    return result;
}

CalcResult
_mul_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF64;
    result._const.f64 =t0->f64 *t1->f64;
    return result;
}

CalcResult
_mul_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TREAL;
    result._const.real =t0->real*t1->real;
    return result;
}

CalcResult
_mul_vec2_vec2(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC2;
    result._const.matrix[0] =t0->matrix[0] *t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] *t1->matrix[1];
    
    return result;
}

CalcResult
_mul_vec3_vec3(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC3;
    result._const.matrix[0] =t0->matrix[0] *t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] *t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] *t1->matrix[2];
    
    return result;
}

CalcResult
_mul_vec4_vec4(Type* t0, Type* t1)
{
    CalcResult result ={.success=1};
    
    result._const.type =TVEC4;
    result._const.matrix[0] =t0->matrix[0] *t1->matrix[0];
    result._const.matrix[1] =t0->matrix[1] *t1->matrix[1];
    result._const.matrix[2] =t0->matrix[2] *t1->matrix[2];
    result._const.matrix[3] =t0->matrix[3] *t1->matrix[3];
    
    return result;
}

CalcResult
_mul_mat2_mat2(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT2;
    result._const.matrix[0] = t0->matrix[0] *t1->matrix[0] + t0->matrix[2] *t1->matrix[1];
    result._const.matrix[2] = t0->matrix[0] *t1->matrix[2] + t0->matrix[2] *t1->matrix[3];
    
    result._const.matrix[1] = t0->matrix[1] *t1->matrix[0] + t0->matrix[3] *t1->matrix[1];
    result._const.matrix[3] = t0->matrix[1] *t1->matrix[2] + t0->matrix[3] *t1->matrix[3];
    
    return result;
}

CalcResult
_mul_mat3_mat3(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT3;
    result._const.matrix[0] =t0->matrix[0] *t1->matrix[0]
        +t0->matrix[3] *t1->matrix[1]
        +t0->matrix[6] *t1->matrix[2];
    result._const.matrix[3] =t0->matrix[0] *t1->matrix[3]
        +t0->matrix[3] *t1->matrix[4]
        +t0->matrix[6] *t1->matrix[5];
    result._const.matrix[6] =t0->matrix[0] *t1->matrix[6]
        +t0->matrix[3] *t1->matrix[7]
        +t0->matrix[6] *t1->matrix[8];
    
    result._const.matrix[1] =t0->matrix[1] *t1->matrix[0]
        +t0->matrix[4] *t1->matrix[1]
        +t0->matrix[7] *t1->matrix[2];
    result._const.matrix[4] =t0->matrix[1] *t1->matrix[3]
        +t0->matrix[4] *t1->matrix[4]
        +t0->matrix[7] *t1->matrix[5];
    result._const.matrix[7] =t0->matrix[1] *t1->matrix[6]
        +t0->matrix[4] *t1->matrix[7]
        +t0->matrix[7] *t1->matrix[8];
    
    result._const.matrix[2] =t0->matrix[2] *t1->matrix[0]
        +t0->matrix[5] *t1->matrix[1]
        +t0->matrix[8] *t1->matrix[2];
    result._const.matrix[5] =t0->matrix[2] *t1->matrix[3]
        +t0->matrix[5] *t1->matrix[4]
        +t0->matrix[8] *t1->matrix[5];
    result._const.matrix[8] =t0->matrix[2] *t1->matrix[6]
        +t0->matrix[5] *t1->matrix[7]
        +t0->matrix[8] *t1->matrix[8];
    
    return result;
}

CalcResult
_mul_mat4_mat4(Type* t0, Type* t1)
{
    CalcResult result={.success=1};
    
    result._const.type =TMAT4;
    result._const.matrix[0] =t0->matrix[0] *t1->matrix[0]
        +t0->matrix[4] *t1->matrix[1]
        +t0->matrix[8] *t1->matrix[2]
        +t0->matrix[12] *t1->matrix[3];
    result._const.matrix[4] =t0->matrix[0] *t1->matrix[4]
        +t0->matrix[4] *t1->matrix[5]
        +t0->matrix[8] *t1->matrix[6]
        +t0->matrix[12] *t1->matrix[7];
    result._const.matrix[8] =t0->matrix[0] *t1->matrix[8]
        +t0->matrix[4] *t1->matrix[9]
        +t0->matrix[8] *t1->matrix[10]
        +t0->matrix[12] *t1->matrix[11];
    result._const.matrix[12] =t0->matrix[0] *t1->matrix[12]
        +t0->matrix[4] *t1->matrix[13]
        +t0->matrix[8] *t1->matrix[14]
        +t0->matrix[12] *t1->matrix[15];
    
    result._const.matrix[1] =t0->matrix[1] *t1->matrix[0]
        +t0->matrix[5] *t1->matrix[1]
        +t0->matrix[9] *t1->matrix[2]
        +t0->matrix[13] *t1->matrix[3];
    result._const.matrix[5] =t0->matrix[1] *t1->matrix[4]
        +t0->matrix[5] *t1->matrix[5]
        +t0->matrix[9] *t1->matrix[6]
        +t0->matrix[13] *t1->matrix[7];
    result._const.matrix[9] =t0->matrix[1] *t1->matrix[8]
        +t0->matrix[5] *t1->matrix[9]
        +t0->matrix[9] *t1->matrix[10]
        +t0->matrix[13] *t1->matrix[11];
    result._const.matrix[13] =t0->matrix[1] *t1->matrix[12]
        +t0->matrix[5] *t1->matrix[13]
        +t0->matrix[9] *t1->matrix[14]
        +t0->matrix[13] *t1->matrix[15];
    
    result._const.matrix[2] =t0->matrix[2] *t1->matrix[0]
        +t0->matrix[6] *t1->matrix[1]
        +t0->matrix[10] *t1->matrix[2]
        +t0->matrix[14] *t1->matrix[3];
    result._const.matrix[6] =t0->matrix[2] *t1->matrix[4]
        +t0->matrix[6] *t1->matrix[5]
        +t0->matrix[10] *t1->matrix[6]
        +t0->matrix[14] *t1->matrix[7];
    result._const.matrix[10] =t0->matrix[2] *t1->matrix[8]
        +t0->matrix[6] *t1->matrix[9]
        +t0->matrix[10] *t1->matrix[10]
        +t0->matrix[14] *t1->matrix[11];
    result._const.matrix[14] =t0->matrix[2] *t1->matrix[12]
        +t0->matrix[6] *t1->matrix[13]
        +t0->matrix[10] *t1->matrix[14]
        +t0->matrix[14] *t1->matrix[15];
    
    result._const.matrix[3] =t0->matrix[3] *t1->matrix[0]
        +t0->matrix[7] *t1->matrix[1]
        +t0->matrix[11] *t1->matrix[2]
        +t0->matrix[15] *t1->matrix[3];
    result._const.matrix[3] =t0->matrix[13] *t1->matrix[4]
        +t0->matrix[7] *t1->matrix[5]
        +t0->matrix[11] *t1->matrix[6]
        +t0->matrix[15] *t1->matrix[7];
    result._const.matrix[3] =t0->matrix[14] *t1->matrix[8]
        +t0->matrix[7] *t1->matrix[9]
        +t0->matrix[11] *t1->matrix[10]
        +t0->matrix[15] *t1->matrix[11];
    result._const.matrix[3] =t0->matrix[15] *t1->matrix[12]
        +t0->matrix[7] *t1->matrix[13]
        +t0->matrix[11] *t1->matrix[14]
        +t0->matrix[15] *t1->matrix[15];
    
    return result;
}


/* Div Functions */

CalcResult
_div_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u8 =t0->u8 /t1->u8;
    return result;
}

CalcResult
_div_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =t0->u16 /t1->u16;
    return result;
}

CalcResult
_div_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =t0->u32 /t1->u32;
    return result;
}

CalcResult
_div_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =t0->u64 /t1->u64;
    return result;
}

CalcResult
_div_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =t0->i8 /t1->i8;
    return result;
}

CalcResult
_div_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =t0->i16 /t1->i16;
    return result;
}

CalcResult
_div_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =t0->i32 /t1->i32;
    return result;
}

CalcResult
_div_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =t0->i64 /t1->i64;
    return result;
}

CalcResult
_div_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF32;
    result._const.f32 =t0->f32 /t1->f32;
    return result;
}

CalcResult
_div_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF64;
    result._const.f64 =t0->f64 /t1->f64;
    return result;
}

CalcResult
_div_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TREAL;
    result._const.real =t0->real /t1->real;
    return result;
}

/* Pwr Functions */

CalcResult
_pwr_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u8 =pow((double)t0->u8, (double)t1->u8);
    return result;
}

CalcResult
_pwr_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =pow((double)t0->u16 ,(double)t1->u16);
    return result;
}

CalcResult
_pwr_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =pow((double)t0->u32, (double)t1->u32);
    return result;
}

CalcResult
_pwr_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =pow((double)t0->u64,(double)t1->u64);
    return result;
}

CalcResult
_pwr_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =pow((double)t0->i8, (double)t1->i8);
    return result;
}

CalcResult
_pwr_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =pow((double)t0->i16, (double)t1->i16);
    return result;
}

CalcResult
_pwr_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =pow((double)t0->i32 ,(double)t1->i32);
    return result;
}

CalcResult
_pwr_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =pow((double)t0->i64 ,(double)t1->i64);
    return result;
}

CalcResult
_pwr_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF32;
    result._const.f32 =powf(t0->f32 ,t1->f32);
    return result;
}

CalcResult
_pwr_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TF64;
    result._const.f64 =pow(t0->f64 ,t1->f64);
    return result;
}

CalcResult
_pwr_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TREAL;
    result._const.real =pow(t0->real, t1->real);
    return result;
}

/* Sr Functions */


CalcResult
_sr_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u8 =t0->u8 <<t1->u8;
    return result;
}

CalcResult
_sr_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =t0->u16 <<t1->u16;
    return result;
}

CalcResult
_sr_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =t0->u32 <<t1->u32;
    return result;
}

CalcResult
_sr_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =t0->u64 <<t1->u64;
    return result;
}

CalcResult
_sr_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =t0->i8 <<t1->i8;
    return result;
}

CalcResult
_sr_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =t0->i16 <<t1->i16;
    return result;
}

CalcResult
_sr_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =t0->i32 <<t1->i32;
    return result;
}

CalcResult
_sr_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =t0->i64 <<t1->i64;
    return result;
}

/* Sl Functions */

CalcResult
_sl_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u8 =t0->u8 >>t1->u8;
    return result;
}

CalcResult
_sl_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =t0->u16 >>t1->u16;
    return result;
}

CalcResult
_sl_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =t0->u32 >>t1->u32;
    return result;
}

CalcResult
_sl_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =t0->u64 >>t1->u64;
    return result;
}

CalcResult
_sl_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =t0->i8 >>t1->i8;
    return result;
}

CalcResult
_sl_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =t0->i16 >>t1->i16;
    return result;
}

CalcResult
_sl_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =t0->i32 >>t1->i32;
    return result;
}

CalcResult
_sl_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =t0->i64 >>t1->i64;
    return result;
}

/* Band Functions */

CalcResult
_band_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u8 =t0->u8 &t1->u8;
    return result;
}

CalcResult
_band_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =t0->u16 &t1->u16;
    return result;
}

CalcResult
_band_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =t0->u32 &t1->u32;
    return result;
}

CalcResult
_band_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =t0->u64 &t1->u64;
    return result;
}

CalcResult
_band_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =t0->i8 &t1->i8;
    return result;
}

CalcResult
_band_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =t0->i16 &t1->i16;
    return result;
}

CalcResult
_band_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =t0->i32 &t1->i32;
    return result;
}

CalcResult
_band_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =t0->i64 &t1->i64;
    return result;
}

/* And Functions */

CalcResult
_and_bool_bool(Type *t0, Type* t1)
{
    CalcResult result={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->bool &&t1->bool;
    return result;
}

/* Bor Functions */

CalcResult
_bor_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU8;
    result._const.u8 =t0->u8 |t1->u8;
    return result;
}

CalcResult
_bor_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU16;
    result._const.u16 =t0->u16 |t1->u16;
    return result;
}

CalcResult
_bor_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU32;
    result._const.u32 =t0->u32 |t1->u32;
    return result;
}

CalcResult
_bor_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TU64;
    result._const.u64 =t0->u64 |t1->u64;
    return result;
}

CalcResult
_bor_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI8;
    result._const.i8 =t0->i8 |t1->i8;
    return result;
}

CalcResult
_bor_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI16;
    result._const.i16 =t0->i16 |t1->i16;
    return result;
}

CalcResult
_bor_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI32;
    result._const.i32 =t0->i32 |t1->i32;
    return result;
}

CalcResult
_bor_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TI64;
    result._const.i64 =t0->i64 |t1->i64;
    return result;
}

/* Or Functions */

CalcResult
_or_bool_bool(Type* t0, Type* t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->bool || t1->bool;
    return result;
}

/* Cmt Functions */

CalcResult
_cmt_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u8 >t1->u8;
    return result;
}

CalcResult
_cmt_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u16 >t1->u16;
    return result;
}

CalcResult
_cmt_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u32 >t1->u32;
    return result;
}

CalcResult
_cmt_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u64 >t1->u64;
    return result;
}

CalcResult
_cmt_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i8 >t1->i8;
    return result;
}

CalcResult
_cmt_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i16 >t1->i16;
    return result;
}

CalcResult
_cmt_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i32 >t1->i32;
    return result;
}

CalcResult
_cmt_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i64 >t1->i64;
    return result;
}

CalcResult
_cmt_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f32 >t1->f32;
    return result;
}

CalcResult
_cmt_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f64 >t1->f64;
    return result;
}

CalcResult
_cmt_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->real >t1->real;
    return result;
}

/* Clt Functions */

CalcResult
_clt_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u8 <t1->u8;
    return result;
}

CalcResult
_clt_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u16 <t1->u16;
    return result;
}

CalcResult
_clt_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u32 <t1->u32;
    return result;
}

CalcResult
_clt_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u64 <t1->u64;
    return result;
}

CalcResult
_clt_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i8 <t1->i8;
    return result;
}

CalcResult
_clt_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i16 <t1->i16;
    return result;
}

CalcResult
_clt_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i32 <t1->i32;
    return result;
}

CalcResult
_clt_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i64 <t1->i64;
    return result;
}

CalcResult
_clt_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f32 <t1->f32;
    return result;
}

CalcResult
_clt_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f64 <t1->f64;
    return result;
}

CalcResult
_clt_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->real <t1->real;
    return result;
}

/* Cmteq Functions */

CalcResult
_cmteq_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u8 >=t1->u8;
    return result;
}

CalcResult
_cmteq_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u16 >=t1->u16;
    return result;
}

CalcResult
_cmteq_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u32 >=t1->u32;
    return result;
}

CalcResult
_cmteq_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u64 >=t1->u64;
    return result;
}

CalcResult
_cmteq_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i8 >=t1->i8;
    return result;
}

CalcResult
_cmteq_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i16 >=t1->i16;
    return result;
}

CalcResult
_cmteq_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i32 >=t1->i32;
    return result;
}

CalcResult
_cmteq_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i64 >=t1->i64;
    return result;
}

CalcResult
_cmteq_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f32 >=t1->f32;
    return result;
}

CalcResult
_cmteq_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f64 >=t1->f64;
    return result;
}

CalcResult
_cmteq_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->real >=t1->real;
    return result;
}

/* Clteq Functions */

CalcResult
_clteq_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u8 <=t1->u8;
    return result;
}

CalcResult
_clteq_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u16 <=t1->u16;
    return result;
}

CalcResult
_clteq_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u32 <=t1->u32;
    return result;
}

CalcResult
_clteq_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u64 <=t1->u64;
    return result;
}

CalcResult
_clteq_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i8 <=t1->i8;
    return result;
}

CalcResult
_clteq_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i16 <=t1->i16;
    return result;
}

CalcResult
_clteq_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i32 <=t1->i32;
    return result;
}

CalcResult
_clteq_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i64 <=t1->i64;
    return result;
}

CalcResult
_clteq_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f32 <=t1->f32;
    return result;
}

CalcResult
_clteq_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f64 <=t1->f64;
    return result;
}

CalcResult
_clteq_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->real <=t1->real;
    return result;
}

/* Ceq Functions */

CalcResult
_ceq_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u8 ==t1->u8;
    return result;
}

CalcResult
_ceq_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u16 ==t1->u16;
    return result;
}

CalcResult
_ceq_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u32 ==t1->u32;
    return result;
}

CalcResult
_ceq_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u64 ==t1->u64;
    return result;
}

CalcResult
_ceq_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i8 ==t1->i8;
    return result;
}

CalcResult
_ceq_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i16 ==t1->i16;
    return result;
}

CalcResult
_ceq_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i32 ==t1->i32;
    return result;
}

CalcResult
_ceq_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i64 ==t1->i64;
    return result;
}

CalcResult
_ceq_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f32 ==t1->f32;
    return result;
}

CalcResult
_ceq_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f64 ==t1->f64;
    return result;
}

CalcResult
_ceq_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->real ==t1->real;
    return result;
}

/* Cneq Functions */

CalcResult
_cneq_u8_u8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u8 !=t1->u8;
    return result;
}

CalcResult
_cneq_u16_u16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u16 !=t1->u16;
    return result;
}

CalcResult
_cneq_u32_u32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u32 !=t1->u32;
    return result;
}

CalcResult
_cneq_u64_u64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->u64 !=t1->u64;
    return result;
}

CalcResult
_cneq_i8_i8(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i8 !=t1->i8;
    return result;
}

CalcResult
_cneq_i16_i16(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i16 !=t1->i16;
    return result;
}

CalcResult
_cneq_i32_i32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i32 !=t1->i32;
    return result;
}

CalcResult
_cneq_i64_i64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->i64 !=t1->i64;
    return result;
}

CalcResult
_cneq_f32_f32(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f32 !=t1->f32;
    return result;
}

CalcResult
_cneq_f64_f64(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->f64 !=t1->f64;
    return result;
}

CalcResult
_cneq_real_real(Type* t0, Type *t1)
{
    CalcResult result ={.success=1};
    result._const.type =TBOOL;
    result._const.bool =t0->real !=t1->real;
    return result;
}