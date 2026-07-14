#include <HijelHID_BLEMouse.h>

// הגדרת פינים ומשתנים
const int buttonPin = 4; 

// --- כאן אתה קובע כמה קליקים ישלחו בכל לחיצה בודדת! ---
const int CLICKS_PER_PRESS = 30; 

// יצירת אובייקט העכבר
HijelBLEMouse bleMouse("ESP32 Autoclicker", "Espressif", 100);

// משתנים למעקב אחרי מצב המפסק (למניעת כפילויות)
int lastButtonState = HIGH; 

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  bleMouse.begin();
}

void loop() {
  // קריאת המצב הנוכחי של המפסק
  int buttonState = digitalRead(buttonPin);

  // בדיקה: האם המצב השתנה מ"לא לחוץ" (HIGH) ל"לחוץ" (LOW) - כלומר לחיצה חדשה!
  if (buttonState == LOW && lastButtonState == HIGH) {
    
    // ברגע שזוהתה לחיצה בודדת, נריץ לולאה שתבצע בדיוק X קליקים
    for (int i = 0; i < CLICKS_PER_PRESS; i++) {
      
      // אם מסיבה כלשהי ה-Bluetooth התנתק באמצע, נעצור
      if (!bleMouse.isConnected()) break;

      // הדפסה לפלוטר (קפיצה מהירה למעלה)
      Serial.println("CLICK:1");
      
      // שליחת הקליק למחשב
      bleMouse.press((MouseButton)1);   
      delay(10);                         
      bleMouse.release((MouseButton)1); 
      
      // השהייה קלה בפלוטר כדי שנספיק לראות את הירידה של הגרף
      Serial.println("CLICK:0");
      
      // השהייה קצרצרה בין קליק לקליק בתוך המטח (במילישניות)
      delay(10); 
    }
    
    // השהיית הגנה קטנה כדי למנוע רעשים חשמליים מהמפסק (Debouncing)
    delay(50); 
  } else {
    // אם לא לוחצים, הגרף נשאר על 0
    Serial.println("CLICK:0");
    delay(10);
  }

  // שמירת המצב הנוכחי של המפסק לפעם הבאה
  lastButtonState = buttonState;
}
