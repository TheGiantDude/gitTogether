#include <Arduino.h>

int choiceMenu; // Menu choice global var
int Addition(int a, int b);
int Multiplication(int a, int b);
void runAddition();
int readNumber();

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
    choiceMenu = readNumber(); // The choice of the menu option
  } else {
    return;
  }

  if (choiceMenu == 1) {
    // Here, the addition function should execute
    runAddition();
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
  return a + b;
}

void runAddition() {
  Serial.print("\nEnter first number: ");
  int a = readNumber();

  Serial.print("Enter second number: ");
  int b = readNumber();

  int result = Addition(a, b);
  Serial.print("Sum = ");
  Serial.println(result);
}

int readNumber() {
  while (true) {
    while (Serial.available() == 0) {}

    String input = Serial.readStringUntil('\n');
    input.trim();

    int start = 0;
    if (input.length() > 0 && (input[0] == '-' || input[0] == '+')) {
      start = 1;
    }

    bool valid = start < input.length();

    for (int i = start; i < input.length(); i++) {
      if (input[i] < '0' || input[i] > '9') {
        valid = false;
        break;
      }
    }

    if (valid) {
      return input.toInt();
    }

    Serial.println("Invalid input. Please enter a whole number.");
  }
}

// Multiplication function: (Rooh) >>>
int Multiplication(int a, int b) {
  int result = a * b;

  Serial.print("Product = ");
  Serial.println(result);

  return result;
}