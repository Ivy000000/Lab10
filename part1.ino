#include <IRremote.h>

const int irReceiverPin = 2; // 使用數位腳位2接收紅外線訊號
IRrecv irrecv(irReceiverPin); // 初始化紅外線訊號輸入
decode_results results; // 儲存訊號的結構

void setup()
{
  Serial.begin(9600);

  irrecv.enableIRIn(); // 啟動接收
}

void loop() {
  if (irrecv.decode(&results)) { // 接收紅外線訊號並解碼
    Serial.print("irCode: "); // 輸出解碼後的資料
    Serial.print(results.value, HEX);
    Serial.print(", bits: ");
    Serial.println(results.bits);
    irrecv.resume(); // 準備接收下一個訊號
  }
  delay(1000);
}
