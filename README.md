# super-duper-sniffle
Universal Type System in C

```c
// this is how you would use it to create...
UniversalType integer_number = new_int(314);            // integers
UniversalType real_number = new_float(1.23);            // double precision floating point number
UniversalType word = new_string("Hello, World!");       // a string type
UniversalType prefers_rust_programming = new_bool(1);   // simple boolean

arithmetic(new_int(24), new_float(3.2), MULTIPLY); // you can operate with them
arithmetic(new_string("what "), new_string("the fuck?"), ADD); //Automatic String Concation

```
