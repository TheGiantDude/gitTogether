#include <Arduino.h>

int choiceMenu; // Menu choice global var
int Addition(int a, int b);
int Multiplication(int a, int b);

// Menu: (Adam) >>>
void setup() {
  Serial.begin(9600);
  delay(1000); // Delay for the serial monitor to properly start
  Serial.println("Hi!");
  Serial.println("Type [1] for addition.");
  Serial.println("Type [2] for multiplication."); // Menu lines
  return;
}

// Blink: (Semyon) >>>
void loop() {
  // Basic loop for the command line read and if statements (Adam)-- 
  if (Serial.available() > 0) {
    choiceMenu = Serial.read(); // The choice of the menu option
  }

  if (choiceMenu == 1) {
    return; // Here, the addition function should execute
  }
  else if (choiceMenu == 2) {
    return; // Here, the multiplication function should execute
  }
  else {
    Serial.println("The selected option is wrong or does not exist."); // Small error message
  }
  // (Adam)--
  return;
}

// Addition function: (Shaunak) >>>
int Addition(int a, int b) {
  return 0;
}

// Multiplication function: (Rooh) >>>
int Multiplication(int a, int b) {
  Serial.print("\nEnter first number: ");
  while (!Serial.available()); // Wait for input
  int num1 = Serial.parseInt();
  Serial.println(num1);

  Serial.print("Enter second number: ");
  while (!Serial.available()); // Wait for input
  int num2 = Serial.parseInt();
  Serial.println(num2);

  int result = num1 * num2;
  Serial.print("Product = ");
  Serial.println(result);

  return result;
}