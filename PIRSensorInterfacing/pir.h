/*
 * pir.h
 *
 * Created: 10-Oct-19 06:10:28 PM
 * Modified: 03-Oct-19 2:52:12 PM
 * Author: Debdut
 * Modifier: Debdut
 */ 

void pir_port_config(void);
void pir_init();
int update_pir_sensor();

//Function to config sensor port
void pir_port_config(void)
{
	DDRL |= 0x00; //set sensor port io direction
	//PORTL &= 0xFF; //clear data to port
}

//Function to initialize sensor
void pir_init()
{
	pir_port_config();
}

//Function to get sensor digital data
int update_pir_sensor()
{
	if(PINL == 0x80) return 0;
	return 1;
}