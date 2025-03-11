#include <Wire.h>
#include <BME280I2C.h>

// 創建 BME280 傳感器對象
BME280I2C bme;

void setup() {
  Serial.begin(115200);
  Wire.begin();  // 啟動 I2C

  // 初始化 BME280 傳感器
  if (!bme.begin()) {
    Serial.println("Cannot find BME280 sensor, please check the wiring!");
    while (1);  // 如果找不到傳感器，停止程式運行
  }

  Serial.println("BME280 sensor initialized successfully!");
}

void loop() {
  // 宣告變數來存儲讀取的數據
  float temperature, humidity;

  // 讀取傳感器數據
  bme.read(temperature, humidity);

  // 顯示數據
  Serial.print("temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\t");

  Serial.print("humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");

  delay(2000);  // 每 2 秒更新一次數據
}
