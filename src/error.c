const char* error_boolean_operation = 
"Bad Operation Performed:\n  Boolean arithmetic";
const char* error_bad_string_operation = 
"Bad Operation Performed:\n  String arithmetic";

void quit_programm(const char* error_message) {
	printf("%s\n", error_message);
	exit(1);
}