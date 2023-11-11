#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Keypad.h>

const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols] = {5, 4, 3, 2};

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
int bulb = 12;

char storedPassword[6] = "3B7A1"; // The current stored password is (3B7A1) by deafult max is set as 6 characters
char userInput[16]; // Store user input maximum of 16 characters
int userInputIndex = 0; // Index to track user input

int led = 13;
const int pinBuz = 11;

bool comparePasswords() {
  return strcmp(userInput, storedPassword) == 0;  //Check's if user password matches the stored password
}

void loop() {
  char key = myKeypad.getKey();
  if (key != NO_KEY) {
    digitalWrite(pinBuz, HIGH);
    delay(300);
    digitalWrite(pinBuz, LOW);
    Serial.print(key);
    delay(50);
    switch (key) {
      case 'D': closebrkr(); break;
      case '*': checkpasswd(); break;
      case '#': clearScreen(); lcd.setCursor(0, 0); lcd.print("Enter Password:"); userInputIndex = 0; break; 
      default:
        if (userInputIndex < 16 - 1) {
          userInput[userInputIndex++] = key;
          userInput[userInputIndex] = '\0';
        }
        displayUserInput();
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(bulb, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(pinBuz, OUTPUT);
  lcd.init();
  lcd.backlight();
  clearScreen();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");  //Tells the user to enter a password
}

void displayUserInput() {
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear the second row
  lcd.setCursor(0, 1);
  lcd.print(userInput);
}

void checkpasswd() {
  if (comparePasswords()) {
    lcd.clear();
    Serial.println("OK.");
    lcd.setCursor(0, 0);
    lcd.print("   Successful   "); //Positive feedback
    digitalWrite(led, HIGH);
    digitalWrite(bulb, HIGH);
  } else {
    digitalWrite(led, LOW);
    digitalWrite(bulb, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" Wrong Password! ");  //Negative Feedback
    Serial.println("Wrong password!");
  }
  displayUserInput();
  userInputIndex = 0;
  clearUserInput();
}

void closebrkr() {
    lcd.clear();
    Serial.println("CLOSE.");
    lcd.setCursor(0, 0);
    lcd.print("Output Closed");  //End of system
    digitalWrite(led, LOW);
    digitalWrite(bulb, LOW);
  }

void clearScreen() {
  lcd.clear();
}

void clearUserInput() {
  for (int i = 0; i < 16; i++) {
    userInput[i] = '\0';
  }
}
