#include "funks.h"
#include "communication.h"

String mensagem = "";
String wifi_nome;
String wifi_password;
void setup()
{
  init_Sys();
  delay(500);
  bip(100,500);
  bip(100,1000);
  atualizar();
  wifi_nome = escrita("Nome do WIFI:");
  wifi_password = escrita("Senha do WIFI:");
  initconect(wifi_nome,wifi_password);
  // init_senha();
  delay(200);
  atualizar();
  bip(100, 1000);
  drawtext("Done :D", ST77XX_CYAN, 50, 200);
  delay(300);
  atualizar();

  mensagem = escrita("mensagem ");
  drawtext("Mensagem eviada.", ST77XX_GREEN, 1, 15);
  drawtext(mensagem, ST77XX_WHITE, 0, 150);
  // drawtext("`´",ST77XX_WHITE, 0, 150);
  enviar_mensagem(mensagem);
  delay(100);
}

void loop()
{
  if(digitalRead(botB1) == LOW && digitalRead(botB2) == LOW)
  {
    setup();
  }
}

// A:  - 1 - 1 1 1 - ↓ ↓ ↓
// B:  - 2 - 1 1 2 - ↓ ↓ ←
// C:  - 3 - 1 1 3 - ↓ ↓ ↑
// D:  - 4 - 1 1 4 - ↓ ↓ →
// E:  - 5 - 1 2 1 - ↓ ← ↓
// F:  - 6 - 1 2 2 - ↓ ← ←
// G:  - 7 - 1 2 3 - ↓ ← ↑
// H:  - 8 - 1 2 4 - ↓ ← →
// I:  - 9 - 1 3 1 - ↓ ↑ ↓
// J:  - 10 - 1 3 2 - ↓ ↑ ←
// K:  - 11 - 1 3 3 - ↓ ↑ ↑
// L:  - 12 - 1 3 4 - ↓ ↑ →
// M:  - 13 - 1 4 1 - ↓ → ↓
// N:  - 14 - 1 4 2 - ↓ → ←
// O:  - 15 - 1 4 3 - ↓ → ↑
// P:  - 16 - 1 4 4 - ↓ → →
// Q:  - 17 - 2 1 1 - ← ↓ ↓
// R:  - 18 - 2 1 2 - ← ↓ ←
// S:  - 19 - 2 1 3 - ← ↓ ↑
// T:  - 20 - 2 1 4 - ← ↓ →
// U:  - 21 - 2 2 1 - ← ← ↓
// V:  - 22 - 2 2 2 - ← ← ←
// W:  - 23 - 2 2 3 - ← ← ↑
// X:  - 24 - 2 2 4 - ← ← →
// Y:  - 25 - 2 3 1 - ← ↑ ↓
// Z:  - 26 - 2 3 2 - ← ↑ ←
// 9:  - 27 - 2 3 3 - ← ↑ ↑
// 8:  - 28 - 2 3 4 - ← ↑ →
// 7:  - 29 - 2 4 1 - ← → ↓
// 6:  - 30 - 2 4 2 - ← → ←
// 5:  - 31 - 2 4 3 - ← → ↑
// 4:  - 32 - 2 4 4 - ← → →
// 3:  - 33 - 3 1 1 - ↑ ↓ ↓
// 2:  - 34 - 3 1 2 - ↑ ↓ ←
// 1:  - 35 - 3 1 3 - ↑ ↓ ↑
// 0:  - 36 - 3 1 4 - ↑ ↓ →
// -:  - 37 - 3 2 1 - ↑ ← ↓
// _:  - 38 - 3 2 2 - ↑ ← ←
//  :  - 39 - 3 2 3 - ↑ ← ↑