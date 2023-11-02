/*
 * KEYPAD_Cfg.h
 *
 * Created: 10/29/2023 8:52:06 PM
 *  Author: COMPUMARTS
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define  FIRST_OUTPUT   PINC0
#define  FIRST_INPUT   PINC4




#define  ROWS   4
#define  COLS   3



const u8 KeysArray[ROWS][COLS]={
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'},
};



#endif /* KEYPAD_CFG_H_ */