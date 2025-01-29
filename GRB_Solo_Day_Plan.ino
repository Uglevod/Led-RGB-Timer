#include <Adafruit_NeoPixel.h>

#define LED_PIN 12 // Pin connected to the NeoPixels
#define LED_COUNT 64 // Number of NeoPixels
#define BRIGHTNESS 50 // NeoPixel brightness

Adafruit_NeoPixel strip( LED_COUNT, LED_PIN, NEO_RGB + NEO_KHZ800); // NEO_RGB ,

uint16_t co = 0;
 

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "Wifi";
const char* password = "pwd";

#define BOTtoken "--you bot token ----"
#define CHAT_ID "---you chat id ------"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

  
String day1[64] = { 

          "utro","utro","utro","utro" ,"utro" ,"utro","utro" ,"utro",
          "svoy","svoy","svoy","svoy","svoy","svoy","svoy","svoy",
          "obed","obed","obed","rlx" ,"gul"  ,"gul" ,"gul"  ,"gul" ,

          "work","work","work","rlx","work","work","work","rlx",
          "work","work","work","rlx","work","work","work","rlx",

          "len","len","len","len","plan","plan","plan","rlx",

          "free","free","free","free","rlx","free","free","free",
          "pson","pson","pson","pson" ,"son" ,"son" ,"son" ,"son"
        };


String day2[64] = { 

          "utro","utro","utro","utro" ,"utro", "gul","gul" ,"gul",
          "svoy","svoy","svoy","svoy","rlx","obed","obed","rlx",
           
          "work1","work1","work1","rlx1","work2","work2","work2","rlx1",
          "work3","work3","work3","rlx2","work4","work4","work4","rlx2",
          "work5","work5","work5","rlx3","work6","work6","work6","rlx3",

          "len","len","len","len","plan","plan","plan","rlx5",

          "free","free","free","free","rlx5","free","free","free",
          "pson","pson","pson","pson" ,"son" ,"son" ,"son" ,"son"
        };


String day[64] = { 

          "utro","utro","utro","utro" ,"utro", "gul","gul" ,"gul",
          "svoy","svoy","svoy","svoy","rlx","obed","obed","rlx",
           
          "work1","work1","work1","rlx1","work2","work2","work2","rlx1",
          "work3","work3","len",  "len", "len",  "len",  "work4","work4",
          "work5","work5","work5","rlx3","work6","work6","work6","rlx3",

          "gul","gul","gul","obed","plan","plan","len","obed",

          "free","free","free","free","rlx6","free","free","free",
          "pson","pson","pson","pson" ,"son" ,"son" ,"son" ,"son"
        };

 


String atb = "utro";

typedef struct LEDStruct_s
{
  private:
    uint8_t     ledNo;
    uint8_t     state; // active brigtt or no

    uint16_t    r;
    uint16_t    g;
    uint16_t    b;

    String      typ;  // тип urto svoy work obed len free sport chat plan predson son , progul

    uint16_t    index;

    struct color {
      uint16_t r;
      uint16_t g;
      uint16_t b;
    };

    color clrUtro   = { 255, 164, 16 };  // orange

    color clrSvoy   = { 0, 230, 0    };     // green
    
    color clrRlx    = { 43, 56, 237  };   // sligth blue  
    //-----------------------------
    color clrObed  =  { 13, 184, 84  };   // салатовый


    //uint32_t clrUtro = strip.Color( 255, 164, 16 );

    //uint32_t clrSvoy = strip.Color(255, 0, 255);

    //uint32_t clrRlx  = strip.Color(255, 0, 255);

    //uint32_t clrObed = strip.Color(255, 0, 255);





    color clrGul   =  { 139, 224, 247}; // светло голубой

    color clrWork  =  { 161, 107, 21 };  // 'эмм оранжж 

    color clrPlan  =  { 161, 21, 100 };  // краснорозовый возможно красный или физуха красный

    color clrLen   =  { 8, 15, 115   };  // deep blue  

    color clrFree  =  { 255, 69, 0   };  //  oraaanggg

    color clrPson  =  { 86, 8, 50   };  // pink

    color clrSon   =  { 228, 44, 228    };   // deep фиолет .. и после завершения .. ту анимашку   

    color arrRGB[16] = { 

                        clrUtro, clrUtro, clrUtro , clrUtro , clrUtro , clrUtro , clrUtro , clrUtro ,
                        clrSvoy, clrSvoy, clrRlx  , clrSvoy , clrSvoy , clrRlx  , clrSvoy , clrRlx

                      };

    color arrRGBs[3] = { 

                        clrUtro, clrSvoy, clrRlx 

                      };

  public:

    void Init( uint8_t ledIdx , String tp )
    {
        ledNo = ledIdx;
        typ   = tp;
        //pulseBright = random(10, 200);
        index = 100;// random(5, 200);
        //tDelay = random( 5, 90 );
        //tUpdate = millis();
        //tDelay = random(5, 200);


        
    }//Init

    //void Act     ( color cl ) {  strip.setPixelColor(ledNo, strip.Color( cl.r    , cl.g    , cl.b   ) , 100);      }

    //void Sup_act ( color cl ) {  strip.setPixelColor(ledNo, strip.Color( 50 , 50 , 50 ) , 150 );      }

    //void Other   ( color cl ) {  strip.setPixelColor(ledNo, strip.Color( cl.r  , cl.g  , cl.b   ) ,20 );      }


    void Act     ( color cl ) {  

      uint32_t clr = strip.Color( cl.r, cl.g, cl.b  );
      
      strip.setPixelColor( ledNo,  clr  );      }

    void Sup_act ( color cl ) {  

      //uint32_t clr = strip.Color(  cl.r , cl.g , cl.b   );

      uint32_t clr = strip.Color(  0 , 0 , 0  );
      
      strip.setPixelColor(ledNo, clr   );      
      
      }

    void Other   ( color cl ) {  

        uint32_t clr = strip.Color( cl.r/14, cl.g/14, cl.b/14 );
        

        strip.setPixelColor(ledNo, clr  );     
      
      }


   




    void Update(uint16_t co , String atb )
    {
         

        if ( typ==atb ){

          if ( typ == "utro" ){ Act( clrUtro  ); if (ledNo==co) { Sup_act( clrUtro );}  }

          if ( typ == "svoy"  ){ Act( clrSvoy ); if (ledNo==co) { Sup_act( clrSvoy );}  }
          if ( typ == "svoy2" ){ Act( clrSvoy ); if (ledNo==co) { Sup_act( clrSvoy );}  }
          if ( typ == "svoy3" ){ Act( clrSvoy ); if (ledNo==co) { Sup_act( clrSvoy );}  }
          if ( typ == "svoy4" ){ Act( clrSvoy ); if (ledNo==co) { Sup_act( clrSvoy );}  }

          if ( typ == "rlx"   ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }
          if ( typ == "rlx1"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }
          if ( typ == "rlx2"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }  
          if ( typ == "rlx3"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }
          if ( typ == "rlx4"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }
          if ( typ == "rlx5"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }

          if ( typ == "rlx6"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }
          if ( typ == "rlx7"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }

          if ( typ == "rlx8"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }
          if ( typ == "rlx9"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }

          if ( typ == "rlx10"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }
          if ( typ == "rlx11"  ){ Act( clrRlx  ); if (ledNo==co) { Sup_act( clrRlx  );}  }

          if ( typ == "obed"  ){ Act( clrObed  ); if (ledNo==co) { Sup_act( clrObed  );}  }

          if ( typ == "gul"   ){ Act( clrGul   ); if (ledNo==co) { Sup_act( clrGul   );}  }

          if ( typ == "work"  ){ Act( clrWork  ); if (ledNo==co) { Sup_act( clrWork  );}  }
          if ( typ == "work1"  ){ Act( clrWork  ); if (ledNo==co) { Sup_act( clrWork  );}  }
          if ( typ == "work2"  ){ Act( clrWork  ); if (ledNo==co) { Sup_act( clrWork  );}  }
          if ( typ == "work3"  ){ Act( clrWork  ); if (ledNo==co) { Sup_act( clrWork  );}  }
          if ( typ == "work4"  ){ Act( clrWork  ); if (ledNo==co) { Sup_act( clrWork  );}  }
          if ( typ == "work5"  ){ Act( clrWork  ); if (ledNo==co) { Sup_act( clrWork  );}  }
          if ( typ == "work6"  ){ Act( clrWork  ); if (ledNo==co) { Sup_act( clrWork  );}  }


          
          if ( typ == "len"  ){ Act( clrLen  ); if (ledNo==co) { Sup_act( clrLen  );}  }


          if ( typ == "plan"  ){ Act( clrPlan  ); if (ledNo==co) { Sup_act( clrPlan  );}  }

          if ( typ == "free"  ){ Act( clrFree  ); if (ledNo==co) { Sup_act( clrFree  );}  }


          if ( typ == "pson"  ){ Act( clrPson  ); if (ledNo==co) { Sup_act( clrPson  );}  }

          if ( typ == "son"  ){ Act( clrSon  ); if (ledNo==co) { Sup_act( clrSon  );}  }




        } else {

          if ( typ == "utro"  ){  Other( clrUtro  );   }

          if ( typ == "svoy"  ){  Other( clrSvoy  );   }
          if ( typ == "svoy2" ){  Other( clrSvoy  );   }
          if ( typ == "svoy3" ){  Other( clrSvoy  );   }
          if ( typ == "svoy4" ){  Other( clrSvoy  );   }
          if ( typ == "svoy5" ){  Other( clrSvoy  );   }  

          if ( typ == "rlx"   ){  Other( clrRlx   );   }
          if ( typ == "rlx1"  ){  Other( clrRlx   );   }
          if ( typ == "rlx2"  ){  Other( clrRlx   );   }
          if ( typ == "rlx3"  ){  Other( clrRlx   );   }
          if ( typ == "rlx4"  ){  Other( clrRlx   );   }
          if ( typ == "rlx5"  ){  Other( clrRlx   );   }
          if ( typ == "rlx6"  ){  Other( clrRlx   );   }
          if ( typ == "rlx7"  ){  Other( clrRlx   );   }
          if ( typ == "rlx8"  ){  Other( clrRlx   );   }
          if ( typ == "rlx9"  ){  Other( clrRlx   );   }
          if ( typ == "rlx10"  ){  Other( clrRlx   );   }
          if ( typ == "rlx11"  ){  Other( clrRlx   );   }
          

          if ( typ == "obed"  ){  Other( clrObed  );   }

          if ( typ == "gul"   ){  Other( clrGul   );   }

          if ( typ == "work"  ){  Other( clrWork  );   }
          if ( typ == "work1"  ){  Other( clrWork  );   }
          if ( typ == "work2"  ){  Other( clrWork  );   }
          if ( typ == "work3"  ){  Other( clrWork  );   }
          if ( typ == "work4"  ){  Other( clrWork  );   }
          if ( typ == "work5"  ){  Other( clrWork  );   }
          if ( typ == "work6"  ){  Other( clrWork  );   }

          if ( typ == "len"   ){  Other( clrLen  );   }

          if ( typ == "plan"  ){  Other( clrPlan  );   }

          if ( typ == "free"  ){  Other( clrFree  );   }

          if ( typ == "pson"  ){  Other( clrPson  );   }

          if ( typ == "son"  ){  Other( clrSon  );   }


        }




        
    }
        




}LEDStruct_t;

LEDStruct_t 
    LEDStruct[LED_COUNT];




void setup() 
{
    Serial.begin(9600);

    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
    strip.setBrightness( BRIGHTNESS );
    randomSeed( analogRead(0) ); // Seed the random number generator
    
    // Initialize last update time for each LED
    for (int i = 0; i < LED_COUNT; i++){
        
        LEDStruct[i].Init( i , day[i] );

    }


     WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, password);
      client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("");
      Serial.println("WiFi connected");  


      bot.sendMessage(CHAT_ID, "Timer Start");




}


void loop() 
{
  atb = day[co]; // Получаем имя бокса по счетчику

  for (int i = 0; i < LED_COUNT; i++) 
        LEDStruct[i].Update(co, atb );
    
    strip.show();

  //delay( random( 5, 100 ));
  //local a = load ("return atb");
  Serial.print   ( co  );
  Serial.print   ( "" );
  Serial.println ( atb );

  String msg = "";
  msg =" Го "+  String(co) + " " + atb;
  bot.sendMessage(CHAT_ID, msg);

  //delay( 1000 );

  delay( 1000*60*15 );

  co++; 

}
  
