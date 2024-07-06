/*
 * BIT_MATH.h
 *
 * Created: 9/15/2023 10:08:07 AM
 * Author: EyadA
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define  SET_BIT(REG , BIT)      (REG |= (1<<BIT))
#define  CLR_BIT(REG , BIT)      (REG &=~ (1<<BIT))
#define  TOGGLE_BIT(REG , BIT)   (REG ^= (1<<BIT))
#define  GET_BIT(REG , BIT)      ((REG>>BIT) & 0X01)


#endif /* BIT_MATH_H_ */