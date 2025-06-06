volatile uint32_t* status_reg = (uint32_t*)0x40000010;
while ((*status_reg & 0x1) == 0) {
  // Wait until the READY bit is set
}
