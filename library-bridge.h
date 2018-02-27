#pragma once
#ifdef __cplusplus
extern "C" {
#endif

void* LIB_NewFoo(int value);
void LIB_DestroyFoo(void* foo);
int LIB_FooValue(void* foo);

#ifdef __cplusplus
}  // extern "C"
#endif
