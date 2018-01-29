











void NameList_init(void);

int newName(void);								//Writing a new name

void DisplayList(void);							//Displaying all the name list
	
void SavingName (char [], char []);				//Saving the name

unsigned char EEPROM_read(unsigned int);		//Getting the saved name from EEPROM

void EEPROM_write(unsigned int,unsigned char);	//Saving the name in the EEPROM