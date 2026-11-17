
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {

  Serial.begin(9600);

  SPI.begin();

  rfid.PCD_Init();

  delay(100);

  Serial.println();
  Serial.println("==============================");
  Serial.println("     RFID CARD AND TAG TEST");
  Serial.println("==============================");

  Serial.println("Place card or keychain on reader");
  Serial.println();
}

void loop() {

  // Check for a new card or compatible tag
  if (!rfid.PICC_IsNewCardPresent()) {
    delay(50);
    return;
  }

  Serial.println("CARD OR TAG DETECTED");

  // Read UID
  if (!rfid.PICC_ReadCardSerial()) {

    Serial.println("UID READ FAILED");

    // Stop current communication
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();

    // Reset reader communication
    rfid.PCD_Init();

    delay(500);

    Serial.println("Reader restarted");
    Serial.println("Try scanning again");

    return;
  }

  // UID successfully read
  Serial.println();
  Serial.println("========== UID SUCCESS ==========");

  Serial.print("UID: ");

  for (byte i = 0; i < rfid.uid.size; i++) {

    if (rfid.uid.uidByte[i] < 0x10) {
      Serial.print("0");
    }

    Serial.print(
      rfid.uid.uidByte[i],
      HEX
    );

    if (i < rfid.uid.size - 1) {
      Serial.print(" ");
    }
  }

  Serial.println();

  Serial.print("UID Length: ");

  Serial.print(rfid.uid.size);

  Serial.println(" bytes");

  Serial.print("Tag Type: ");

  MFRC522::PICC_Type type =
    rfid.PICC_GetType(rfid.uid.sak);

  Serial.println(
    rfid.PICC_GetTypeName(type)
  );

  Serial.println("==============================");

  // Stop communication
  rfid.PICC_HaltA();

  rfid.PCD_StopCrypto1();

  delay(1000);

  Serial.println("Remove tag and scan again");
  Serial.println();
}
