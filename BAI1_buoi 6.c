#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char *message;
char loi1[] = "loi b =0\n";
char loi2[] = "loi a>100\n";
char loi3[] = "loi b>100\n";

#define TRY if ((exception_code = setjmp(buf)) == 0) 
#define CATCH(x) else if (exception_code == (x)) 
//#define THROW(x,name_error) xl((x),(name_error))



void THROW(int data,char *name)
{
    message = name;
    longjmp(buf,data);
   
    
}



double divide(int a, int b) {
    if (b == 0) {
        THROW(1,loi1); 
		
    }
	else if(a >100)
	{
		THROW(2,message =loi2);
	}
	else if( b >100)
	{
		THROW(3,message =loi3);
	}
	else{
	}
		
    return (double)a / b;
}

int main() {
    int a = 110;
    int b = 10;
    double result = 0.0;
    
   // xl(1,loi1);

    TRY {
        result = divide(a, b);
        printf("Result: %f\n", result);
    } CATCH(1) {
        printf("%s",message);
    } CATCH(2) {
        printf("%s",message);
    } CATCH(3) {
        printf("%s",message);
    }


    // Các xử lý khác của chương trình
    return 0;
}