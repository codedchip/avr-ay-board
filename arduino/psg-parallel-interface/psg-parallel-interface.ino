
byte serial_read()
{
    while (!Serial.available()) _delay_us(1);
    return Serial.read();
}

void setup()
{
    PSG_Init();
    Serial.begin(57600);
}

void loop()
{
    while (true)
    {
        // wait for register number
        byte reg = serial_read();
        if (reg > 13) continue;

        // read data and send everything to PSG
        byte data = serial_read();
        PSG_Send(reg, data);
    }
}
