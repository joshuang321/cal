typedef
struct
{
    int unexpType;
    int expType;
} CalcError;

typedef
struct
{
    _bool success;
    union
    {
        Type _const;
        CalcError err;
    };
} CalcResult;


_bool
IsRealConst(CalcResult *calc, Type *t0)
{
    if (t0->type !=TREAL)
    {
        calc->success =0;
        calc->err.unexpType =t0->type;
        calc->err.expType =TREAL;
    }
    return calc->success;
}

CalcResult
__u8(Type *t0)
{
    CalcResult result ={.success =1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TU8;
        result._const.u8 =(_u8)t0->real;
    }
    return result;
}

CalcResult
__u16(Type *t0)
{
    CalcResult result ={.success=1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TU16;
        result._const.u16 =(_u16)t0->real;
    }
    return result;
}

CalcResult
__u32(Type *t0)
{
    CalcResult result ={.success=1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TU32;
        result._const.u32 =(_u32)t0->real;
    }
    return result;
}

CalcResult
__u64(Type *t0)
{
    CalcResult result ={.success=1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TU64;
        result._const.u64 =(_u64)t0->real;
    }
    return result;
}

CalcResult
__i8(Type *t0)
{
    CalcResult result ={.success=1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TI8;
        result._const.i8 =(_i8)t0->real;
    }
    return result;
}

CalcResult
__i16(Type *t0)
{
    CalcResult result ={.success=1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TI16;
        result._const.i16 =(_i16)t0->real;
    }
    return result;
}

CalcResult
__i32(Type *t0)
{
    CalcResult result ={.success=1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TI32;
        result._const.i32 =(_i32)t0->real;
    }
    return result;
}

CalcResult
__i64(Type *t0)
{
    CalcResult result ={0};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TI64;
        result._const.i64 =(_i64)t0->real;
    }
    return result;
}

CalcResult
__f32(Type *t0)
{
    CalcResult result ={0};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TF32;
        result._const.f32 =(_f32)t0->real;
    }
    return result;
}

CalcResult
__f64(Type *t0)
{
    CalcResult result ={.success=1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TF64;
        result._const.f64 =t0->real;
    }
    return result;
}

CalcResult
__bool(Type *t0)
{
    CalcResult result ={.success=1};
    if (IsRealConst(&result, t0))
    {
        result._const.type =TBOOL;
        result._const.bool =(_bool)t0->real;
    }
    return result;
}

void
GetReals(va_list vArgs, CalcResult *calc, int c)
{
    int n=0;
    while (n++<c)
    {
        Type *t =va_arg(vArgs, Type *);
        if (IsRealConst(calc, t))
        {
            calc->_const.matrix[n] =t->real;
        }
        else
        {
            break;
        }
    }
}

CalcResult
__vec2(Type *t0, ...)
{
    CalcResult result ={.success=1};
    va_list vArgs;
    
    result._const.type =TVEC2;
    if (IsRealConst(&result, t0))
    {
        result._const.matrix[0] =t0->real;
        va_start(vArgs, t0);
        GetReals(vArgs, &result, 1);
        va_end(vArgs);
    }
    return result;
}

CalcResult
__vec3(Type *t0, ...)
{
    CalcResult result ={.success=1};
    va_list vArgs;
    
    result._const.type =TVEC3;
    if (IsRealConst(&result, t0))
    {
        result._const.matrix[0] =t0->real;
        va_start(vArgs, t0);
        GetReals(vArgs, &result, 2);
        va_end(vArgs);
    }
    return result;
}

CalcResult
__vec4(Type *t0, ...)
{
    CalcResult result ={.success=1};
    va_list vArgs;
    
    result._const.type =TVEC4;
    if (IsRealConst(&result, t0))
    {
        result._const.matrix[0] =t0->real;
        va_start(vArgs, t0);
        GetReals(vArgs, &result, 3);
        va_end(vArgs);
    }
    return result;
}

CalcResult
__mat2(Type *t0, ...)
{
    CalcResult result ={.success=1};
    va_list vArgs;
    
    result._const.type =TMAT2;
    if (IsRealConst(&result, t0))
    {
        result._const.matrix[0] =t0->real;
        va_start(vArgs, t0);
        GetReals(vArgs, &result, 3);
        va_end(vArgs);
    }
    return result;
}

CalcResult
__mat3(Type *t0, ...)
{
    CalcResult result ={.success=1};
    va_list vArgs;
    
    result._const.type =TMAT3;
    if (IsRealConst(&result, t0))
    {
        result._const.matrix[0] =t0->real;
        va_start(vArgs, t0);
        GetReals(vArgs, &result, 8);
        va_end(vArgs);
    }
    return result;
}

CalcResult
__mat4(Type *t0, ...)
{
    CalcResult result ={.success=1};
    va_list vArgs;
    
    result._const.type =TMAT4;
    if (IsRealConst(&result, t0))
    {
        result._const.matrix[0] =t0->real;
        va_start(vArgs, t0);
        GetReals(vArgs, &result, 15);
        va_end(vArgs);
    }
    return result;
}

CalcResult
__h(Type *t0)
{
    CalcResult result ={.success=1};
    
    result._const.type =TREAL;
    if (IsRealConst(&result, t0))
    {
        result._const.real =4.0f * t0->real;
    }
    return result;
}

CalcResult
__g(Type *t0)
{
    CalcResult result ={.success=1};
    result._const.type =TREAL;
    if (IsRealConst(&result, t0))
    {
        result._const.real =1.0f+t0->real;
    }
    return result;
}

void
_normalize_vec2(Type *result, _real x, _real y)
{
    _real norm =1.0/sqrt(x*x +y*y);
    
    result->type =TVEC2;
    result->matrix[0] =x*norm;
    result->matrix[1] =y*norm;
}

void
_normalize_vec3(Type *result, _real x, _real y, _real z)
{
    _real norm =1.0/sqrt(x*x +y*y +z*z);
    
    result->type =TVEC3;
    result->matrix[0] =x*norm;
    result->matrix[1] =y*norm;
    result->matrix[2] =z*norm;
}

void
_normalize_vec4(Type *result, _real x, _real y, _real z, _real w)
{
    _real norm =1.0/sqrt(x*x +y*y +z*z +w*w);
    
    result->type =TVEC4;
    result->matrix[0] =x*norm;
    result->matrix[1] =y*norm;
    result->matrix[2] =z*norm;
    result->matrix[3] =w*norm;
}

CalcResult
__normalize(Type *t0)
{
    CalcResult result ={.success=1};
    
    switch (t0->type)
    {
        case TVEC2:
        _normalize_vec2(&result._const, t0->matrix[0], t0->matrix[1]);
        break;
        case TVEC3:
        _normalize_vec3(&result._const, t0->matrix[0], t0->matrix[1], t0->matrix[2]);
        break;
        case TVEC4:
        _normalize_vec4(&result._const, t0->matrix[0], t0->matrix[1], t0->matrix[2], t0->matrix[3]);
        break;
        default:
        result.success =0;
        break;
    }
    return result;
}

void
_magnitude_vec2(Type *result, _real x, _real y)
{
    result->real =sqrt(x*x +y*y);
}

void
_magnitude_vec3(Type *result, _real x, _real y, _real z)
{
    result->real =sqrt(x*x +y*y +z*z);
}

void
_magnitude_vec4(Type *result, _real x, _real y, _real z, _real w)
{
    result->real =sqrt(x*x +y*y +z*z +w*w);
}

CalcResult
__magnitude(Type *t0)
{
    CalcResult result={.success=1};
    
    result._const.type =TREAL;
    switch (t0->type)
    {
        case TVEC2:
        _magnitude_vec2(&result._const, t0->matrix[0], t0->matrix[1]);
        break;
        case TVEC3:
        _magnitude_vec3(&result._const, t0->matrix[0], t0->matrix[1], t0->matrix[2]);
        break;
        case TVEC4:
        _magnitude_vec4(&result._const, t0->matrix[0], t0->matrix[1], t0->matrix[2], t0->matrix[3]);
        break;
        default:
        result.success=0;
    }
    return result;
}

typedef CalcResult (*CalcFunction) (Type *t0, ...);
typedef int (* StringFunction) (char *buf, int c, Type *t0);

#define STRINGFUNC(type) \
int \
_##type##_toString(char *buf, int c, Type *t0)

typedef
struct
{
    char *name;
    CalcFunction function;
    int numArgs;
} Function;

#define DECL_F(func, _numArgs) {#func,__##func, _numArgs}

Function _functions[] =
{
    DECL_F(u8, 1),
    DECL_F(u16, 1),
    DECL_F(u32, 1),
    DECL_F(u64, 1),
    DECL_F(i8, 1),
    DECL_F(i16, 1),
    DECL_F(i32, 1),
    DECL_F(i64, 1),
    DECL_F(f32, 1),
    DECL_F(f64, 1),
    DECL_F(bool, 1),
    DECL_F(vec2, 2),
    DECL_F(vec3, 3),
    DECL_F(vec4, 4),
    DECL_F(mat2, 4),
    DECL_F(mat3, 9),
    DECL_F(mat4, 16),
    DECL_F(g, 1),
    DECL_F(h, 1),
    DECL_F(normalize, 1),
    DECL_F(magnitude, 1),
};

STRINGFUNC(None)
{
    int result=snprintf(buf, c, "None");
    return result;
}
STRINGFUNC(u8)
{
    int result=snprintf(buf, c, "%uhh", t0->u8);
    return result;
}
STRINGFUNC(u16)
{
    int result=snprintf(buf, c, "%uh", t0->u16);
    return result;
}
STRINGFUNC(u32)
{
    int result=snprintf(buf, c, "%u", t0->u32);
    return result;
}
STRINGFUNC(u64)
{
    int result=snprintf(buf, c, "%ull", t0->u64);
    return result;
}
STRINGFUNC(i8)
{
    int result=snprintf(buf, c, "%dhh", t0->i8);
    return result;
}
STRINGFUNC(i16)
{
    int result=snprintf(buf, c, "%dh", t0->i16);
    return result;
}
STRINGFUNC(i32)
{
    int result=snprintf(buf, c, "%d", t0->i32);
    return result;
}
STRINGFUNC(i64)
{
    int result=snprintf(buf, c, "%dll", t0->i64);
    return result;
}
STRINGFUNC(f32)
{
    int result=snprintf(buf, c, "%f", t0->f32);
    return result;
}
STRINGFUNC(f64)
{
    int result=snprintf(buf, c, "%f", t0->f64);
    return result;
}
STRINGFUNC(bool)
{
    int result=snprintf(buf, c, t0->bool ?"true" :"false");
    return result;
}
STRINGFUNC(real)
{
    int result=snprintf(buf, c, "%f", t0->real);
    return result;
}
STRINGFUNC(vec2)
{
    int result=snprintf(buf, c, "(%f, %f)", t0->matrix[0], t0->matrix[1]);
    return result;
}
STRINGFUNC(vec3)
{
    int result=snprintf(buf, c, "(%f, %f, %f)", t0->matrix[0], t0->matrix[1], t0->matrix[2]);
    return result;
}
STRINGFUNC(vec4)
{
    int result=snprintf(buf, c, "(%f, %f, %f, %f)", t0->matrix[0], t0->matrix[1], t0->matrix[2], t0->matrix[3]);
    return result;
}
STRINGFUNC(mat2)
{
    int result=snprintf(buf, c, "((%f, %f), (%f, %f))", t0->matrix[0], t0->matrix[1], t0->matrix[2], t0->matrix[3]);
    return result;
}
STRINGFUNC(mat3)
{
    int result=snprintf(buf, c, "((%f, %f, %f), (%f, %f, %f), (%f, %f %f))", t0->matrix[0], t0->matrix[1], t0->matrix[2], t0->matrix[3], t0->matrix[4], t0->matrix[5], t0->matrix[6], t0->matrix[7], t0->matrix[8]);
    return 0;
}
STRINGFUNC(mat4)
{
    int result=snprintf(buf, c, "(%f, %f, %f, %f), (%f, %f, %f, %f), (%f, %f, %f, %f), (%f, %f, %f))", t0->matrix[0], t0->matrix[1], t0->matrix[2], t0->matrix[4], t0->matrix[5], t0->matrix[6], t0->matrix[7], t0->matrix[8], t0->matrix[9], t0->matrix[10], t0->matrix[11], t0->matrix[12], t0->matrix[13], t0->matrix[14], t0->matrix[15]);
    return 0;
}

#define DECL_STR(type) _##type##_toString

StringFunction _func_toString[]=
{
    DECL_STR(None),
    DECL_STR(u8),
    DECL_STR(u16),
    DECL_STR(u32),
    DECL_STR(u64),
    DECL_STR(i8),
    DECL_STR(i16),
    DECL_STR(i32),
    DECL_STR(i64),
    DECL_STR(f32),
    DECL_STR(f64),
    DECL_STR(bool),
    DECL_STR(real),
    DECL_STR(vec2),
    DECL_STR(vec3),
    DECL_STR(vec4),
    DECL_STR(mat2),
    DECL_STR(mat3),
    DECL_STR(mat4)
};

int TypeToString(char *buf, int c, Type *t0)
{
    return _func_toString[t0->type](buf, c, t0);
}

_bool
IsStringEqual(char *str0, char *str1)
{
    _u32 count=0;
    _bool result;
    while (str0[count]
           && str1[count]
           && str0[count]==str1[count])
    {
        count++;
    }
    
    result =(str0[count]==str1[count]);
    return result;
}

Function*
LookupFunction(char *funcName)
{
    Function *result=NULL;
    for (int i=0;
         i<(sizeof(_functions)/sizeof(Function));
         i++)
    {
        if (IsStringEqual(funcName, _functions[i].name))
        {
            result =&_functions[i];
            break;
        }
    }
    return result;
}