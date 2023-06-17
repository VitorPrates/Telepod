#include <Arduino.h>

// display libs 240x240
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Fonts/FreeMono12pt7b.h>

// display 128x64
#include <Wire.h>
#include <U8g2lib.h>

// display configs
#define TFT_CS 10
#define TFT_RST 2
#define TFT_DC 15
Adafruit_ST7789 display(TFT_CS, TFT_DC, TFT_RST);
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/22, /* data=*/21, /* reset=*/U8X8_PIN_NONE);

// botões
#define botB1 27
#define botB2 5
#define botBranco 16
#define botAzul 0
#define botAmarelo 4
#define botVermelho 17
//

// buzer
#define BUZZER_PIN 12
#define PWM_RESOLUTION 8


char *alfabeto_caracteres[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z","9", "8", "7", "6", "5", "4", "3", "2", "1", "0", "-", "_", " "};

void bip(int duracao, int tom)
{
    ledcWriteTone(0, tom);
    delay(duracao);
    ledcWriteTone(0, 0);
}
void setup_hardware()
{
    // 240x240
    display.init(240, 240, SPI_MODE2);
    display.fillScreen(ST77XX_BLACK);
    display.setRotation(0);
    display.setFont(&FreeMono12pt7b);
    display.cp437(true);
    //

    // 128x64
    u8g2.begin();
    u8g2.enableUTF8Print();
    u8g2.setDisplayRotation(U8G2_R2);
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x14_tf);
    u8g2.drawStr(0, 40, "Iniciando...");
    u8g2.sendBuffer();

    pinMode(BUZZER_PIN, OUTPUT);
    ledcSetup(0, 1000, PWM_RESOLUTION);
    ledcAttachPin(BUZZER_PIN, 0);

    pinMode(botB1, INPUT_PULLUP);
    pinMode(botB2, INPUT_PULLUP);
    pinMode(botBranco, INPUT_PULLUP);
    pinMode(botAzul, INPUT_PULLUP);
    pinMode(botAmarelo, INPUT_PULLUP);
    pinMode(botVermelho, INPUT_PULLUP);
}

void drawtext(String text, uint16_t color, int posx, int posy)
{
    display.setCursor(posx, posy);
    display.setTextColor(color);
    display.setTextWrap(true);
    display.print(text);
}

void init_Sys()
{
    setup_hardware();
    drawtext("RANDOOM COLORS", ST77XX_WHITE, 10, 130);
    // drawtext("`- \u00b4", ST77XX_WHITE, 10, 170);
}

void atualizar()
{
    display.fillScreen(ST77XX_BLACK);
}

void display_blocks_30x30(int blocos, int posx, int posy)
{
    for (int i = 0; i <= blocos - 1; i++)
    {
        display.drawRect(posx + (i * 30), posy, 30, 30, ST77XX_WHITE);
    }
}

bool init_senha()
{
    atualizar();

    int blocks = 1;
    bool new_frame = false;
    char *senha[4] = {"4", "4", "2", "3"};
    char *digit_senha[4] = {"1", "1", "1", "1"};
    int cursor = 0;
    unsigned long previousMillis = 0;
    const unsigned long delayTime = 100;
    bool top_down = false;
    while (true)
    {
        unsigned long currentMillis = millis();
        drawtext("Senha", ST77XX_WHITE, 60, 130);
        // drawtext(String(cursor).c_str(), ST77XX_WHITE, 60, 100);
        display_blocks_30x30(4, 60, 155);
        for (int i = 0; i <= 3; i++)
        {
            drawtext(digit_senha[i], ST77XX_WHITE, 65 + (30 * i), 178);
        }
        if (currentMillis - previousMillis >= delayTime)
        {
            previousMillis = currentMillis;
            if (digitalRead(botB1) == LOW)
            {
                new_frame = true;
                if (cursor <= 2)
                {
                    cursor++;
                }
                ledcWriteTone(0, 1000);
                delay(100);
                ledcWriteTone(0, 0);
            }
            else if (digitalRead(botB2) == LOW)
            {
                new_frame = true;
                if (cursor > 0)
                {
                    cursor--;
                }
                ledcWriteTone(0, 1000);
                delay(100);
                ledcWriteTone(0, 0);
            }
            else if (digitalRead(botBranco) == LOW)
            {
                new_frame = true;
                digit_senha[cursor] = "1";
            }
            else if (digitalRead(botAzul) == LOW)
            {
                new_frame = true;
                digit_senha[cursor] = "2";
            }
            else if (digitalRead(botAmarelo) == LOW)
            {
                new_frame = true;
                digit_senha[cursor] = "3";
            }
            else if (digitalRead(botVermelho) == LOW)
            {
                new_frame = true;
                digit_senha[cursor] = "4";
            }
            else
            {
                if (new_frame == true)
                {
                    int chave = 0;
                    if (senha[0] == digit_senha[0] &&
                        senha[1] == digit_senha[1] &&
                        senha[2] == digit_senha[2] &&
                        senha[3] == digit_senha[3])
                    {
                        drawtext("Dale :D", ST77XX_WHITE, 60, 230);
                        break;
                    }
                    atualizar();
                    new_frame = false;
                }
                if (top_down == false)
                {
                    display.fillRect(60 + (30 * cursor), 186, 30, 30, ST77XX_BLACK);
                    drawtext("^", ST77XX_WHITE, 65 + (30 * cursor), 205);

                    delay(50);
                }
                else
                {
                    display.fillRect(60 + (30 * cursor), 186, 30, 30, ST77XX_BLACK);
                    drawtext("^", ST77XX_WHITE, 65 + (30 * cursor), 210);
                    delay(50);
                }
                top_down = !top_down;
            }
        }
    }
    return true;
}

// enviando a mensagem, finalmente
int read_buttons()
{
    unsigned long previousMillis = 0;
    const unsigned long delayTime = 200;
    bool new_frame = false;
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= delayTime)
    {
        previousMillis = currentMillis;
        if (digitalRead(botB1) == LOW)
        {
            return 1;
        }
        else if (digitalRead(botB2) == LOW)
        {
            return 2;
        }
        else if (digitalRead(botBranco) == LOW)
        {
            return 3;//baixo
        }
        else if (digitalRead(botAzul) == LOW)
        {
            return 4;//esquerda
        }
        else if (digitalRead(botAmarelo) == LOW)
        {
            return 5;//cima
        }
        else if (digitalRead(botVermelho) == LOW)
        {
            return 6;//direito
        }
        else
        {
            return 0;
        }
    }
}

String escrita(String titulo)
{
    String texto_resposta = "";
    String letra_atual;
    bool maiusculo = false;
    u8g2.clearDisplay();
    u8g2.setFont(u8g2_font_siji_t_6x10);
    int cursor_alfabeto = 0;
    while(digitalRead(botB1) != LOW or digitalRead(botB2) != LOW)
    {
        letra_atual = alfabeto_caracteres[cursor_alfabeto];
        if(maiusculo == true)
        {
            letra_atual.toUpperCase();
        }
        else
        {
            letra_atual.toLowerCase();   
        }
        drawtext(String(titulo).c_str(),ST77XX_CYAN, 2, 15);
        do
          {
            u8g2.drawFrame(10, 20, 20, 20);
            u8g2.setFont(u8g2_font_DigitalDiscoThin_tf);
            u8g2.drawStr(13,36, String(letra_atual).c_str());
        } while (u8g2.nextPage());
        switch (read_buttons())
        {
        case 3:
            cursor_alfabeto--;
            break;
        case 4:
            
            break;
        case 5:
            cursor_alfabeto++;
            break;
        case 6:
            maiusculo = !maiusculo;
            break;
        
        default:
            break;
        }
    }
    return "A$AP";
}


