/**
 * Operator
 * operators that can be used to perform arithmetic
 */
typedef enum {
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MODULO
} Operator;

/**
 * arithmetic
 * @param  first    [first variable to perform operation on]
 * @param  second   [second variable to perfom operation on]
 * @param  operator [operator to be used on the arithmetic operation]
 * @return          [result of operation]
 */
UniversalType arithmetic(UniversalType first, UniversalType second, Operator operator) {
	UniversalType result;
	result.data_type = first.data_type>second.data_type? first.data_type : second.data_type;

	if (first.data_type != result.data_type) {
		first = convert_type(first, result.data_type);
	}

	if (second.data_type != result.data_type) {
		second = convert_type(second, result.data_type);
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
				result.value_string = malloc( strlen(first.value_string) + strlen(second.value_string) + 1);
				strcpy(result.value_string, first.value_string);
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

void append_to_string(UniversalType *first, UniversalType second) {
	int free_second = 0;
	if (first->data_type != STRING) {
		*first = convert_type(*first, STRING);
	}

	if (second.data_type != STRING) {
		second = convert_type(second, STRING);
		free_second = 1;
	}

	first->value_string = realloc(first->value_string,
		strlen(first->value_string) +
		strlen(first->value_string) + 1);
	strcat(first->value_string, second.value_string);

	if (free_second) free(second.value_string);
}
