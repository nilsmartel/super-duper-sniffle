

typedef enum {
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MODULO
} Operator;

UniversalType arithmetik( UniversalType first, UniversalType second, Operator operator) {
	UniversalType result;
	result.data_type = first.data_type>second.data_type? first.data_type : second.data_type;

	if (first.data_type != result.data_type) {
		first = convert_type(first, result.data_type)
	}

	if (second.data_type != result.data_type) {
		first = convert_type(first, result.data_type)
	} 

	switch (result.data_type) {
		case BOOLEAN:
			quit_programm(error_boolean_operation);
			break;
		case INTEGER:
			switch (operator) {
				case ADD:
					result.value_int = first.value_int + second.value_int;
					break;
				case SUBTRACT:
					result.value_int = first.value_int - second.value_int;
					break;
				case MULTIPLY:
					result.value_int = first.value_int * second.value_int;
					break;
				case DIVIDE:
					result.value_int = first.value_int / second.value_int;
					break;	
				case MODULO:
					result.value_int = first.value_int % second.value_int;
					break;
			}
			break;
		case FLOAT:
			switch (operator) {
				case ADD:
					result.value_float = first.value_float + second.value_float;
					break;
				case SUBTRACT:
					result.value_float = first.value_float - second.value_float;
					break;
				case MULTIPLY:
					result.value_float = first.value_float * second.value_float;
					break;
				case DIVIDE:
					result.value_float = first.value_float / second.value_float;
					break;	
				case MODULO:
					result.value_float = fmod(first.value_float,second.value_float);
					break;
			}
			break;
		case STRING:
			switch (operator) {
				case ADD:
				result.value_string = malloc( strlen(first.value_string) + strlen(second.value_string) +1 );
				strcpy(first.value_string, result.value_string);
				strcat(result.value_string, second.value_string);
				break;
			default:
				quit_programm(error_bad_string_operation);
				break;
			}
			break;	
	}

	return result;
}