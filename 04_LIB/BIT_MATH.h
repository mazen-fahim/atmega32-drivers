
#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define 	SET_BIT(variable, bit)    variable |= (1 << bit)
#define 	CLR_BIT(variable, bit)    variable &= ~(1 << bit)
#define 	TOGGLE_BIT(variable, bit) variable ^= (1 << bit)
#define 	GET_BIT(variable, bit)	  ((variable >> bit) & 1)

#endif
