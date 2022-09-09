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
int prints(char *s)
{
	while(*s)
	{
		putchar(*s);
		s++;
	}
}
int printu(u32 x)
{
	(x==0)? putchar('0') : rpu(x);
	putchar(' ');
}

int printx(u32 x)
{
	BASE = 16; // base for hex
	putchar('0');
	putchar('x');
	if(x==0)
	{
		putchar('0');
	}
	else
	{
		rpu(x);
	}
}
int printd(int x)
{
	if(x < 0)
	{
		putchar('-');
	}
	printu(x);

}
int myprintf(char *fmt, ...)
{
	char *cp = fmt; // pointer to format string
	int *ip = ((int *)getebp()) + 3; // gets the ebp stack frame then moves 3 positions
	while(*cp)
	{
		if(*cp == "%")
		{
			cp++;
			if(*cp == 'c')
			{
				putchar(*ip);
			}
			if(*cp == 's')
			{
				prints(*ip);
			}
			if(*cp == 'u')
			{
				printu(*ip);
			}
			if(*cp == 'x')
			{
				printx(*ip);
			}
			if(*cp == 'd')
			{
				printd(*ip);
			}
			
		}
		else
		{
			putchar(*cp);
			if(*cp == '\n')
			{
				putchar('\r');
			}
		}

	}
}
int main(int argc, char *argv[], char *env[])
{
	myprintf("argc = %d\nargv[0]=%s\nenv[0]=%s", argc, argv[0], env[0]);
	myprintf("char=%c string=%s dec=%u hex=%x neg=%d\n", 'A', "this is a test", 100, 100, -100);
}


// put your main and code in this file. All contained.
// Use the provided mk script to compile your code. You are welcome to change the mk script if you'd like
// but know that is how we will be batch compiling code using mk on the back end so your code will need to be able
// to run when that bash script is ran.
// Most code can be grabbed from the .html file in the root.
