/* date = October 4th 2023 1:33 am */

#ifndef LANG_V2_H
#define LANG_V2_H

typedef uint8_t _u8;
typedef uint16_t _u16;
typedef uint32_t _u32;
typedef uint64_t _u64;
typedef int8_t _i8;
typedef int16_t _i16;
typedef int32_t _i32;
typedef int64_t _i64;

typedef float _f32;
typedef double _f64;
typedef _i32 _bool;
typedef _f64 _real;

typedef _real _matrix[16];

#define TNONE 0
#define TU8  1
#define TU16 2
#define TU32 3
#define TU64 4
#define TI8 5
#define TI16 6
#define TI32 7
#define TI64 8
#define TF32 9
#define TF64 10
#define TBOOL 11
#define TREAL 12
#define TVEC2 13
#define TVEC3 14
#define TVEC4 15
#define TMAT2 16
#define TMAT3 17
#define TMAT4 18

#define DECL_T(type) _##type type

typedef
struct
{
    _u32 type;
    union
    {
        DECL_T(u8);
        DECL_T(u16);
        DECL_T(u32);
        DECL_T(u64);
        DECL_T(i8);
        DECL_T(i16);
        DECL_T(i32);
        DECL_T(i64);
        DECL_T(f32);
        DECL_T(f64);
        DECL_T(bool);
        DECL_T(real);
        DECL_T(matrix);
    };
} Type;

#define MAX_VAR_NAME_LEN 256
typedef char VString[MAX_VAR_NAME_LEN+1];

typedef
struct
{
    VString name;
    Type data;
} _Variable;

typedef
struct
_HshNode
{
    _Variable var;
    struct _HshNode *next;
} HshNode;

#define HASH_SZ 1113
typedef HshNode* HshTable[HASH_SZ];

#define VT_VAR 0
#define VT_CONST 1
#define VT_SYNTREE 2

typedef
struct
{
    int vtype;
    union
    {
        VString varName;
        Type _const;
        void *synTree;
    };
} Var;

#define ST_OP 0
#define ST_VAR 1

typedef
struct
_SynTree
{
    int stype;
    struct _SynTree *next;
    struct _SynTree *children;
    union
    {
        _u32 op;
        Var var;
    };
} SynTree;

#define MAX_NODES 1024
#define MAX_TREES 1024
#define MAX_OPS 1024
#define MAX_VARS 1024

typedef
struct
{
    HshTable varTbl;
    int allocCount;
    
    HshNode nodes[MAX_NODES];
    SynTree synTrees[MAX_TREES];
    char opStk[MAX_OPS];
    Var varStk[MAX_VARS];
} Lang;

#define ERR_CONST 0
#define ERR_VAR 1
#define ERR_OPERAND 2

typedef
struct
{
    char *loc;
    int type;
} SyntaxError;

typedef
struct
{
    _bool success;
    union
    {
        SyntaxError err;
        Var var;
    };
} VarResult;

#define OP_NONE 0
#define OP_ADD 1
#define OP_SUB 2
#define OP_MUL 3
#define OP_DIV 4
#define OP_PWR 5
#define OP_SR 6
#define OP_SL 7
#define OP_BAND 8
#define OP_AND 9
#define OP_BOR 10
#define OP_OR 11
#define OP_CMT 12
#define OP_CLT 13
#define OP_CMTEQ 14
#define OP_CLTEQ 15
#define OP_CEQ 16
#define OP_CNEQ 17
#define OP_EQ 18
#define OP_ASG 19
#define OP_FUNC 20
#define OP_OBRAK 21
#define OP_CBRAK 22
#define OP_COMMA 23

typedef
struct
{
    _bool success;
    union
    {
        SyntaxError err;
        SynTree *tree;
    };
} SyntaxResult;

#define LR_OP 0
#define LR_TYPE 1
#define LR_VAR 2
#define LR_FUNC 3
#define LR_CALC 4

typedef
struct
{
    _bool success;
    union
    {
        int err;
        Type result;
    };
} LogicResult;

typedef
struct
{
    int oCount;
    int vCount;
    int offset;
    int synTreeAllocated;
    
    int varOffsets[256];
    int ofCount;
} StackContext;


#define H_NONE 0
#define H_OP 1
#define H_VAR 2
#define H_CONST 3
#define H_WSPACE 4

#endif