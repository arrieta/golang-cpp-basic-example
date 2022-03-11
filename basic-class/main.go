package main

// #cgo LDFLAGS: -L. -lbridge
// #include "bridge.h"
import "C"

import (
	"log"
	"unsafe"
)

type Circle struct {
	ptr unsafe.Pointer
}

func NewCircle(radius float64) Circle {
	return Circle{
		ptr: C.DEMO_CircleNew(C.double(radius)),
	}
}

func (circle Circle) Destroy() {
	C.DEMO_CircleDestroy(circle.ptr)
}

func (circle Circle) Area() float64 {
	return float64(C.DEMO_CircleArea(circle.ptr))
}

type Cylinder struct {
	ptr unsafe.Pointer
}

func NewCylinder(radius float64, height float64) Cylinder {
	return Cylinder{
		ptr: C.DEMO_CylinderNew(C.double(radius), C.double(height)),
	}
}

func (cylinder Cylinder) Destroy() {
	C.DEMO_CylinderDestroy(cylinder.ptr)
}

func (cylinder Cylinder) Volume() float64 {
	return float64(C.DEMO_CylinderVolume(cylinder.ptr))
}

func main() {
	circ := NewCircle(42.0)
	defer circ.Destroy()

	log.Printf("circ.Area() = %23.16e", circ.Area())

	cyl := NewCylinder(42.0, 20)
	defer cyl.Destroy()

	log.Printf("cyl.Volume() = %23.16e", cyl.Volume())
}
