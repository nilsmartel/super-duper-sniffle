#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "universal_types.c"
#include "error.c"
#include "arithmetik.c"

int main(int args_count, char** args ) {
	UniversalType integer_number = new_int(314); 
	println_universal(integer_number);
	UniversalType real_number = new_float(1.23);
	println_universal(real_number);
	UniversalType word = new_string("Hello, World!");	//BUS ERROR: 10
	println_universal(word);
	UniversalType likes_programming = new_bool(1);
	println_universal(likes_programming);
	UniversalType result = arithmetic(new_int(24), new_float(3.2), MULTIPLY);
	UniversalType wtf = arithmetic(new_string("what "), new_string("the"), ADD);
	append_to_string(&wtf, new_string(" fuck?"));
	println_universal(wtf);
	return 0;
}
