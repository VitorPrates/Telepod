#include "funks.h"
#include "communication.h"
#include "campominado.h"

String mensagem = "";

void setup()
{
  init_Sys();//main, init hardware, inicia o hardware
  bip(100,500);
  bip(100,1000);
  atualizar();
  init_game_minesweeper();
  // delay(500);
  // atualizar();
  // initconect(escrita("Nome do WIFI:"),escrita("Senha do WIFI:"));
  // // init_senha();
  // delay(200);
  // atualizar();
  // bip(100, 1000);
  // drawtext("Done :D", ST77XX_CYAN, 50, 200);
  // delay(300);
  // atualizar();
  // mensagem = escrita("mensagem ");
  // drawtext("Mensagem eviada.", ST77XX_GREEN, 1, 15);
  // drawtext(mensagem, ST77XX_WHITE, 0, 150);
  // // drawtext("`´",ST77XX_WHITE, 0, 150);
  // enviar_mensagem(mensagem);
  // delay(100);
}

void loop()
{
  // int buttonState = digitalRead(19);

  // // Verifica se o botão foi pressionado
  // if (buttonState == HIGH) {
  //   u8g2.clearBuffer();
  //   u8g2.drawStr(2, 32, String("A").c_str());
  //   u8g2.sendBuffer();
  //   delay(100);
  // }
  // else
  // {
  //   u8g2.clearBuffer();
  //   u8g2.drawStr(2, 32, String("a").c_str());
  //   u8g2.sendBuffer();
  // }
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