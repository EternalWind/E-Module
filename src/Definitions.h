#ifndef E_MODULE_DEFINITIONS
#define E_MODULE_DEFINITIONS

#include <cstdint>

#ifdef E_Module_EXPORTS
#define E_MODULE __declspec(dllexport)
#else
#define E_MODULE __declspec(dllimport)
#endif

#define OUT
#define IN
#define interface class
#define implements public

typedef int8_t byte;
typedef int16_t byte2;
typedef int32_t byte4;
typedef int64_t byte8;

#endif