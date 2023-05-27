#include <Servo.h>

Servo servoMotor;

const int servoPin = 9; // Pin servo motor
const int foodSensorPin = A0; // Pin sensor tingkat makanan
const int feedingTime = 5000; // Waktu pemberian makan dalam milidetik (ms)
const int foodThreshold = 500; // Ambang batas sensor tingkat makanan

void setup() {
  servoMotor.attach(servoPin); // Menghubungkan servo motor ke pin yang ditentukan
  pinMode(foodSensorPin, INPUT); // Mengatur pin sensor tingkat makanan sebagai input
}

void loop() {
  int foodLevel = analogRead(foodSensorPin); // Membaca tingkat makanan dari sensor
  
  // Jika tingkat makanan di bawah ambang batas, pemberian makan akan dilakukan
  if (foodLevel < foodThreshold) {
    dispenseFood(); // Memanggil fungsi untuk memberikan makanan
    delay(feedingTime); // Memberi jeda waktu setelah pemberian makan
  }
}

void dispenseFood() {
  servoMotor.write(180); // Menggerakkan servo motor untuk memberikan makanan
  delay(1000); // Memberi waktu untuk makanan keluar dari wadah
  servoMotor.write(0); // Mengembalikan posisi servo motor
}
