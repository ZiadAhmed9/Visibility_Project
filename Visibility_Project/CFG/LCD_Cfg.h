/*
 * LCD_Cfg.h
 *
 * Created: 5/18/2023 12:42:25 PM
 *  Author: COMPUMARTS
 */ 


#ifndef LCD_CFG_H_
#define LCD_CFG_H_




#define _4_BIT   1
#define _8_BIT   0

/* _4_BIT OR _8_BIT*/
#define  LCD_MODE  _4_BIT



#define  RS   PINA3
#define  EN   PINA4

#define  D7   PINA5
#define  D6   PINA6
#define  D5   PINA7
#define  D4   PINB0

#define LCD_PORT  PB





#endif /* LCD_CFG_H_ */