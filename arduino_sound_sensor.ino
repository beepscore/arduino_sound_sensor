/****************************************
  Example Sound Level Sketch for the 
  Adafruit Microphone Amplifier
http://learn.adafruit.com/adafruit-microphone-amplifier-breakout/measuring-sound-levels
 ****************************************/

// Pin 13 has an LED connected
const int led = 13;

const int mvMax = 100;

// if sampleWindow == 50, barGraph printing doesn't work correctly
// Sample window width in mS (50 mS = 20 Hz)
const int sampleWindow = 1000;

unsigned int sample;

int barLength = 0;
const int barLengthTotal = 120;
char barGraph[barLengthTotal] = "";

void setup() 
{
    Serial.begin(9600);
    // initialize the digital pin as an output.
    pinMode(led, OUTPUT);
}


void loop() 
{
    unsigned long startMillis= millis();  // Start of sample window
    unsigned int peakToPeak = 0;   // peak-to-peak level

    unsigned int signalMax = 0;
    unsigned int signalMin = 1024;

    // collect data for sampleWindow mS
    while (millis() - startMillis < sampleWindow)
    {
        sample = analogRead(0);
        if (sample < 1024)  // toss out spurious readings
        {
            if (sample > signalMax)
            {
                signalMax = sample;  // save just the max levels
            }
            else if (sample < signalMin)
            {
                signalMin = sample;  // save just the min levels
            }
        }
    }

    peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
    // convert to volts
    //double volts = (3.3 * peakToPeak) / 1024;
    // convert to millivolts
    int millivolts = int(1000 * (3.3 * peakToPeak) / 1024);

    Serial.println(millivolts);
    if (millivolts > mvMax) {
        // turn the LED on (HIGH is the voltage level)
        digitalWrite(led, HIGH);
    } else {
        // turn the LED off by making the voltage LOW
        digitalWrite(led, LOW);
    }

    barLength = int(millivolts/10);
    for (int i = 0; i < barLengthTotal; i++) {
        if (i <= barLength) {
            barGraph[i] = '*';
        } else {
            barGraph[i] = ' ';
        }
    }
    Serial.println(barGraph);
}
