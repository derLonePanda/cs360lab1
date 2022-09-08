typedef unsigned int u32;

char *ctable = "0123456789ABCDEF";
int BASE = 10;

int rpu(u32 x) 
{
	char c;
	if(x){
		c = ctable[x %BASE];
		rpu(x / BASE);
		putchar(c);
	}
}
int prints(char *s);
int printu(u32 x)
{
	(x==0)? putchar('0') : rpu(x);
	putchar(' ');
}

int printx(u32 x);
int printd(int x);
int myprintf(char *fmt, ...);
int main(int argc, char *argv[], char *env[])
{

}


// put your main and code in this file. All contained.
// Use the provided mk script to compile your code. You are welcome to change the mk script if you'd like
// but know that is how we will be batch compiling code using mk on the back end so your code will need to be able
// to run when that bash script is ran.
// Most code can be grabbed from the .html file in the root.
