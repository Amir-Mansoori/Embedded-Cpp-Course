volatile uint32_t* control = (uint32_t*)0x40001000;
volatile uint32_t* status = (uint32_t*)0x40001004;

*control = 0x01; // Send a command
while((*status & 0x01) == 0); //Wait for ACK
//Rest of the code
