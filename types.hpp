#ifndef TYPES_H_
#define TYPES_H_

#include <string>
#include <list>

typedef long long Int;
typedef double Float;
typedef std::string Symbol;


typedef enum {NIL, INT, FLOAT, PROC, LAMBDA, SYMBOL, SUBEXPR} dataType;

#endif