typedef enum {
	BOOLEAN,
	INTEGER,
	FLOAT,
	STRING
} TypeTag;

typedef struct {
	TypeTag data_type;
	union {
		int value_boolean;
		int value_int;
		double value_float;
		char* value_string;
	};
} UniversalType;

UniversalType new_int(int value) {
	UniversalType data = {
		.data_type = INTEGER,
		.value_int = value
	};

	return data;
}

UniversalType new_bool(int value) {
	if (value != 0) value = 1;

	UniversalType data = {
		.data_type = BOOLEAN,
		.value_boolean = value
	};

	return data;
}

UniversalType new_float(double value) {
	UniversalType data = {
		.data_type = FLOAT,
		.value_float = value
	};

	return data;
}

UniversalType new_string(const char* value) {
	UniversalType data = {
		.data_type = STRING,
		.value_string = malloc(strlen(value) + 1)
	};
	
	strcpy(data.value_string, value);

	return data;
}

UniversalType new_string_from_int(int value) {
	UniversalType data = {
		.data_type = STRING,
		.value_string = malloc(12)
	};

	sprintf(data.value_string, "%i", value);

	return data;
}

UniversalType new_string_from_float(double value) {
	UniversalType data = {
		.data_type = STRING,
		.value_string = malloc(32)
	};

	sprintf(data.value_string, "%f", value);

	return data;
}

UniversalType convert_type(UniversalType input, TypeTag type) {
	if (input.data_type == type) return input;

	switch (type) {

		case BOOLEAN:
			switch (input.data_type) {
				default: return new_bool(0);
				case INTEGER: return new_bool(input.value_int);
				case FLOAT: return new_bool( (int) input.value_float);
				case STRING: return new_bool( strlen(input.value_string));
			}
			break;

		case INTEGER:
			switch (input.data_type) {
				default: return new_int(0);
				case BOOLEAN: return new_int(input.value_boolean);
				case FLOAT: return new_int( (int) input.value_float);
			}
			break;

		case FLOAT:
			switch (input.data_type) {
				default: return new_float(0.0);
				case BOOLEAN: return new_float( (double) input.value_boolean);
				case INTEGER: return new_float( (double) input.value_int);
			}
			break;

		case STRING:
			switch (input.data_type) {
				case BOOLEAN: return input.value_boolean ? new_string("true") : new_string("false");
				case INTEGER: return new_string_from_int(input.value_int);
				case FLOAT: return new_string_from_float(input.value_float);
				case STRING: return input;
			}
			break;
	}
}

void print_universal(UniversalType input) {
	switch (input.data_type) {
		case BOOLEAN:
			if (input.value_boolean) {
				printf("true");
			} else {
				printf("false");
			}
			break;
		case INTEGER:
			printf("%i", input.value_int);
			break;
		case FLOAT:
			printf("%f", input.value_float);
			break;
		case STRING:
			printf("%s", input.value_string);
			break;
	}
}

void println_universal(UniversalType input) {
	print_universal(input);
	printf("\n");
}
