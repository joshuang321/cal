/*
//def x = y^2
def x = u ^2;
plot(x)

x -> y;

def z = x + y;

//z -> x ->y, y -> y
z = x ->u, y -> u, y

def g = z(u=1)
g = x -> u^2 -> 1^2, y -> y

1-2
1+2
1*2
1/2
1^2

*/

#define MAX_STACK_SZ 256

#define RET_FUNC 	0
#define RET_VAL	  1
#define RET_ERROR	2

#define ERR_COSUME   0
#define ERR_OPERAND  1
#define ERR_VAL      2

typedef double Func;
typedef double Val;

typedef
struct
{
	int type;
	char *loc;
} Error;


typedef
struct
{
	int type;
	union
	{
		Func func;
		Val val;
		Error error;
	};
} ReturnVal;



typedef
struct
{
	int success;
	double val;
	char *end;
} CosumeResult;


CosumeResult
CosumeVal(char *statement)
{
	CosumeResult result ={0};
	result.val = strtod(statement, &result.end);
	result.success =result.end!=statement;
    
	return result;
}

char *
EatWhitespace(char *statement)
{
	while (statement[1] ==' ')
	{
		statement++;
	}
	return statement;
}

double
DoOp(double val0, double val1, char op)
{
    switch (op)
    {
        case '-':
        return val0-val1;
        case '+':
        return val0+val1;
        case '*':
        return val0*val1;
        case '/':
        return val0/val1;
        case '^':
        return pow(val0, val1);
    }
    return 0.0;
}

int
GetOpPred(char c)
{
    switch (c)
    {
        case '-':
        case '+':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        case '(':
        return 4;
        case ')':
        return 0;
    }
}

int
IsBiggerOrEqPred(char c0, char c1)
{
    return (GetOpPred(c0) >= GetOpPred(c1));
}

int
GetErrorDesc(Error err, char *buf)
{
    int c0=0;
    int c1=0;
    const char err_cosume[] ="Failed to determine value.";
    const char err_operand[] ="Expected missing operand.";
    const char err_val[] ="Expected missing value.";
    const char err_def[] ="Error occured while parsing string.";
    
    switch (err.type)
    {
        case ERR_COSUME:
        c0 =sizeof(err_cosume)-1;
        memcpy(buf, err_cosume, sizeof(err_cosume)-1);
        break;
        
        case ERR_OPERAND:
        c0 =sizeof(err_operand)-1;
        memcpy(buf, err_operand, sizeof(err_operand)-1);
        break;
        
        case ERR_VAL:
        c0=sizeof(err_val)-1;
        memcpy(buf, err_val, sizeof(err_val)-1);
        break;
        
        default:
        c0=sizeof(err_def)-1;
        memcpy(buf, err_def, sizeof(err_def)-1);
        break;
    }
    c1=snprintf(buf+c0, 256-c0, " Unexpected \'%c\'\n", *err.loc);
    return c0+c1;
}

ReturnVal
ParseStatement(char *statement, int c)
{
	ReturnVal ret ={ 0 };
	CosumeResult cosumed ={ 0 };
    
    ret.type =RET_VAL;
	int brackets =0;
	int expectValue=1;
    int len =c;
    
	static double values[MAX_STACK_SZ];
	static char operands[MAX_STACK_SZ];
    
	int vCount=-1;
	int oCount=-1;
    
	while (c--)
	{
		if (*statement =='-'
			|| *statement =='+'
			|| *statement =='*'
			|| *statement =='/'
			|| *statement == '^')
		{
			if (expectValue)
			{
				ret.type =RET_ERROR;
                ret.error.type = ERR_OPERAND;
				ret.error.loc =statement;
				break; 
			}
			else
			{
                while (oCount!=-1
                       && IsBiggerOrEqPred(operands[oCount], *statement))
                {
                    double val1 =values[vCount--];
                    double val0 =values[vCount--];
                    double res =DoOp(val0, val1, operands[oCount--]);
                    values[++vCount] =res;
                }
                operands[++oCount] =*statement;
				expectValue =1;
			}
		}
		else if (*statement ==' ')
		{
			char *newptr =EatWhitespace(statement);
			c -= newptr -statement;
			statement =statement;
		}
		else
		{
			if (!expectValue)
			{
				ret.type =RET_ERROR;
                ret.error.type =ERR_VAL;
				ret.error.loc =statement;
				break;
            }
			else
			{
				cosumed =CosumeVal(statement);
				if (!cosumed.success)
				{
					ret.type =RET_ERROR;
					ret.error.type =ERR_COSUME;
                    ret.error.loc =cosumed.end;
					break;
				}
				else
				{
					values[++vCount] =cosumed.val;
					c -=cosumed.end-statement-1;
					statement =cosumed.end;	
				}
                expectValue =0;
                continue;
			}
		}
		statement++;
	}
    while (oCount!=-1
           && vCount >0)
    {
        double val1 =values[vCount--];
        double val0 =values[vCount--];
        double res = DoOp(val0, val1, operands[oCount--]);
        values[++vCount] =res;
    }
    if (ret.type ==RET_VAL)
    {
        if (vCount !=0)
        {
            ret.type =RET_ERROR;
            ret.error.type =RET_VAL;
            ret.error.loc = statement +len-1;
        }
        else
        {
            ret.val =values[vCount--];
        }
    }
    return ret;
}