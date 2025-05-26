volatile bool dataReady = false;

void ISR_Handler() {
  dataReady = true;
}

int main() {
  while (!dataReady) {
      // Wait Until interrupt sets the flag
  }
}
