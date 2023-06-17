// #include "funks.h"
// conect libs
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// conect configs
// #define WIFI_SSID "VIVOFIBRA-6C40"
// #define WIFI_PASSWORD "A647ED4AA0"
#define BOT_TOKEN "5757591912:AAGc4jZfNuIC0QNZYdGNC9BdtIv_kz564-M"
#define CHAT_ID "2142229619"

WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

bool initconect(String nome_rede, String senha)
{
  drawtext("Conectando...", ST77XX_BLUE, 20, 130);
  // WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  WiFi.begin(String(nome_rede).c_str(),String(senha).c_str());
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED)
  {
    // Serial.print(".");
    delay(500);
  }
  int ponto = 0;
  for (int i = 0; i < 210; i++)
  {
    display.drawRect(10, 140, 220, 30, ST77XX_BLUE);
    display.fillRect(15, 145, i, 20, ST77XX_BLUE);
    switch (ponto)
    {
    case 1:
      drawtext("Conectando.", ST77XX_BLUE, 20, 130);
      break;
    case 2:
      drawtext("Conectando..", ST77XX_BLUE, 20, 130);
      break;
    case 3:
      drawtext("Conectando...", ST77XX_BLUE, 20, 130);
      break;
    default:
      ponto = 0;
      break;
    }
    ponto++;
    delay(random(1, 50));
  }
  return true;
}

void enviar_mensagem(String mensagem)
{
  bot.sendMessage(CHAT_ID, mensagem, "");
}