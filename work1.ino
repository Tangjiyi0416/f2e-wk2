void setup() {
  Serial.begin(115200); //設定傳輸鮑率，跟電腦傳輸資料的頻率
  pinMode(12, INPUT); //設定腳位為輸入用

  ledcSetup(0, 5000, 8);   //頻率5000，頻道0，解析度8;
  ledcAttachPin(14, 0);  //將上述頻道0附加到ledPin腳位14上
}

void loop() {
  int input = analogRead(12);
  input=input>150?150:input;
  int input_map = map(input, 0, 150, 0, 255);
  Serial.println(input);

  ledcWrite(0,255- input_map);  //頻道0
}
