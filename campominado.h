// //include "funks.h"

void init_game_minesweeper()
{
    String tabela_campo[225] = {"0"};
    String fake_campo[256] = {
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0",
        };
    int num_bombs = 25;
    int num_inserts = 0;

    // omseror bombas
    // while (num_inserts < num_bombs)
    // {
    //     if (tabela_campo[random(0, 224)] != "B")
    //     {
    //         tabela_campo[random(0, 224)] = "B";
    //         num_inserts++;
    //     }
    // }

    // Ler campo
    // for (int i = 0; i <= 224; i++)
    // {
    //     int pos = i;
    //     int quant_bomb = 0;
    //     try
    //     {
    //         if (tabela_campo[i] == "■")
    //         {
    //             int row = pos / 15;
    //             int col = pos % 15;
    //             // Verificar a posição leste
    //             if (col < 14 && tabela_campo[pos + 1] == "B")
    //             {
    //                 quant_bomb += 1;
    //             }
    //             // Verificar a posição oeste
    //             if (col > 0 && tabela_campo[pos - 1] == "B")
    //             {
    //                 quant_bomb += 1;
    //             }
    //             // Verificar a posição noroeste
    //             if (row > 0 && col > 0 && tabela_campo[pos - 16] == "B")
    //             {
    //                 quant_bomb += 1;
    //             }
    //             // Verificar a posição norte
    //             if (row > 0 && tabela_campo[pos - 15] == "B")
    //             {
    //                 quant_bomb += 1;
    //             }
    //             // Verificar a posição nordeste
    //             if (row > 0 && col < 14 && tabela_campo[pos - 14] == "B")
    //             {
    //                 quant_bomb += 1;
    //             }
    //             // Verificar a posição sudeste
    //             if (row < 14 && col < 14 && tabela_campo[pos + 16] == "B")
    //             {
    //                 quant_bomb += 1;
    //             }
    //             // Verificar a posição sul
    //             if (row < 14 && tabela_campo[pos + 15] == "B")
    //             {
    //                 quant_bomb += 1;
    //             }
    //             // Verificar a posição sudoeste
    //             if (row < 14 && col > 0 && tabela_campo[pos + 14] == "B")
    //             {
    //                 quant_bomb += 1;
    //             }
    //         }
    //     }
    //     catch (const std::exception &e)
    //     {
    //         // Tratamento de exceção vazio
    //     }
    //     if (quant_bomb != 0)
    //     {
    //         tabela_campo[i] = String(quant_bomb).c_str();
    //     }

    //     // for (int c = 0; c <= 15; c++)
    //     // {
    //     //     for (int l = 0; l <= 15; l++)
    //     //     {

    //     //         // display.drawRect(c*15, l*15, 15, 15, ST77XX_CYAN);
    //     //     }
    //     //     // display.setCursor(0,c*15);
    //     // }
    // }
    
    //desenhar campo
    int posx = 0;
    int posy = -16;
    for (int i = 0; i <= 254; i++)
    {
        if(i % 16 == 0)
        {
            posy += 16;
            posx = 0;
        }
        if(fake_campo[i] == "0")
        {
            display.drawRect(posx,posy,15,15,ST77XX_CYAN);
        }
        // drawtext(fake_campo[i],ST77XX_CYAN,posx,posy);
        posx += 16;
    }
}