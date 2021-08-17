// VGA Text Mode = 0xB8000
// VGA Graphics Mode = 0xA0000
volatile unsigned char *video = 0xB8000;

int textCurrPos = 0;
int currLine = 0;

void print( char * );
void println();
void printi( int );

void kernel_main()
{
	print( "Welcome to 539kernel!" );
	println();
	print( "We are now in Protected-mode" );
	println();
	printi( 539 );
	println();
	
	while( 1 );
}

void print( char *str )
{
	while ( *str != '\0' )
	{
		video[ textCurrPos++ ] = *str;
		video[ textCurrPos++ ] = 15;
		
		str++;
	}
}

void println()
{
	textCurrPos = ++currLine * ( 80 * 2 );
}

void printi( int number )
{
	char* digitToStr[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	
	if ( number >= 0 && number <= 9 )
	{
		print( digitToStr[ number ] );
		return;
	}
	else
	{
		int remaining = number % 10;
		number = number / 10;
		
		printi( number );
		printi( remaining );
	}
}
