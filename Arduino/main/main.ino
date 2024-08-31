#define BAUD_RATE 9600
#define COLUMNS_X_PIN A0
#define ROWS_A_PIN 14 // LSB
#define ROWS_B_PIN 15
#define ROWS_C_PIN 16
#define ROWS_D_PIN 17
#define COLUMNS_A_PIN 18
#define COLUMNS_B_PIN 19
#define COLUMNS_C_PIN 20
#define COLUMNS_D_PIN 21 // MSB

// #include "Karnaugh.h"
// Karnaugh<4, 4> Map;

byte StudentBordersTable_Position[40] = {
    1,  3,   5,   7,   16,  18,  20,  22,  24,  33,  35,  37, 39, 48,
    50, 52,  54,  56,  65,  67,  69,  71,  80,  82,  84,  86, 88, 97,
    99, 101, 103, 112, 114, 116, 118, 120, 129, 131, 133, 135};

byte StudentGrayTable_Position[16] = {17, 19, 21, 23, 49,  51,  53,  55,
                                      81, 83, 85, 87, 113, 115, 117, 119};

byte EducatorTruthTable_Position[16] = {9,   25, 41, 57, 73, 89, 105, 121,
                                        137, 10, 26, 42, 58, 74, 90,  106};

bool StudentBordersTable[40];
bool StudentGrayTable[16];
bool EducatorTruthTable[16];

void setPorts(int lsbPin, int msbPin, int binaryCode) {
  int bitSize = msbPin - lsbPin;
  for (int i = 0; i < bitSize; i++) {
    digitalWrite(lsbPin + i, (binaryCode >> i) & 1);
  }
};

void readPorts() {
  for (int i = 0; i < 16; i++) {
    setPorts(ROWS_A_PIN, COLUMNS_D_PIN, StudentGrayTable_Position[i]);
    StudentGrayTable[i] = digitalRead(COLUMNS_X_PIN);
  }
}

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(COLUMNS_X_PIN, INPUT);
  pinMode(ROWS_A_PIN, OUTPUT);
  pinMode(ROWS_B_PIN, OUTPUT);
  pinMode(ROWS_C_PIN, OUTPUT);
  pinMode(ROWS_D_PIN, OUTPUT);
  pinMode(COLUMNS_A_PIN, OUTPUT);
  pinMode(COLUMNS_B_PIN, OUTPUT);
  pinMode(COLUMNS_C_PIN, OUTPUT);
  pinMode(COLUMNS_D_PIN, OUTPUT);

  // pinMode(SO_PIN, INPUT);
  // pinMode(CLK_PIN, OUTPUT);
  // digitalWrite(CLK_PIN, LOW);
  // pinMode(INH_PIN, OUTPUT);
  // digitalWrite(INH_PIN, HIGH);
  // pinMode(SH_PIN, OUTPUT);
  // digitalWrite(SH_PIN, HIGH);
}

void loop() {
  readPorts();
  for (int i = 0; i < 16; i++) {
    Serial.println(StudentGrayTable[i]);
  }
  delay(5000);
  //  readPorts();
  //  Array<byte, 16> tableState;
  //  for (int i = 0; i < 16; i++)
  //    tableState[i] = portsState[i];
  //  Map.solve(tableState);
  //  delay(1000);
}
