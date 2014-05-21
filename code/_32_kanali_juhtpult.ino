void setup()
{
  for (char i = 22; i <= 53; i++)
  {
    digitalWrite(i, LOW);
    pinMode(i, OUTPUT);
  }
  
  Serial.begin(115200);
}

void loop()
{
  char buffer [] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
  while (!Serial.available());
  Serial.readBytesUntil('\n', buffer, 5);
  int num = String(buffer).substring(1).toInt(); //get number from user
  int io = (num + 22) ^ 1; //convert to io number
  
  if (buffer[0] == 'I')
  {
    if ((buffer[1] < 48) || (buffer[1] > 57) ) //when there is no number, switch all
    {
      for (char i = 22; i <= 53; i++) digitalWrite(i, HIGH);
      Serial.println("On all");
    }
    else
    {
      digitalWrite(io, HIGH);
      Serial.print("On ");
      Serial.println(num);
    }
  }
  else if (buffer[0] == 'O')
  {
    if ((buffer[1] < 48) || (buffer[1] > 57) ) //when there is no number, switch all
    {
      for (char i = 22; i <= 53; i++) digitalWrite(i, LOW);
      Serial.println("Off all");
    }
    else
    {
      digitalWrite(io, LOW);
      Serial.print("Off ");
      Serial.println(num);
    }
  }
  delay(200);
}
