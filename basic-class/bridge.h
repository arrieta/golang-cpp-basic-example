#pragma once
#ifdef __cplusplus
extern "C" {
#endif

void*  DEMO_CircleNew(double radius);
void   DEMO_CircleDestroy(void* circle);
double DEMO_CircleArea(const void* circle);

void*  DEMO_CylinderNew(double radius, double height);
void   DEMO_CylinderDestroy(void* cylinder);
double DEMO_CylinderVolume(const void* cylinder);

#ifdef __cplusplus
}  // extern "C"
#endif
