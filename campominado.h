// //include "funks.h"

void init_game_minesweeper()
{
    atualizar();
    // bomba
    static const uint16_t bombcat_data[1][450] = {
        {0x0000, 0x0000, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xff00, 0x0000, 0x0000,
         0x0000, 0xff00, 0xffff, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xff00, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xff00, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xff00, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xff00, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xff00, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff00, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xffff, 0xffff, 0xff00, 0xffff, 0xffff, 0xffff, 0xffff, 0xff00, 0xffff, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xffff, 0xffff, 0xff00, 0xffff, 0xffff, 0xffff, 0xffff, 0xff00, 0xffff, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xff00, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff00, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xffff, 0xff00, 0xffff, 0xffff, 0xff00, 0xffff, 0xffff, 0xff00, 0xffff, 0xffff, 0xff00, 0x0000,
         0x0000, 0xff00, 0xffff, 0xffff, 0xffff, 0xff00, 0xff00, 0xffff, 0xff00, 0xff00, 0xffff, 0xffff, 0xffff, 0xff00, 0x0000,
         0x0000, 0x0000, 0xff00, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xff00, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000}};

    // bandeira
    static const uint16_t banderola_data[1][225] = {
        {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0x0000, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
         0x0000, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0xff00, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}};

    String tabela_campo[225] = {};

    String fake_campo[225] = {};

    char pos_jogador_campo[225] = {};

    for (int i = 0; i < 225; i++)
    {
        tabela_campo[i] = "0";
        fake_campo[i] = "0";
        pos_jogador_campo[i] = '0';
    }
    int num_bombs = random(30,51);
    int num_inserts = 0;
    int num_flags = num_bombs;
    int num_flags_venceu = 0;

    // inseror bombas
    while (num_inserts < num_bombs)
    {
        if (tabela_campo[random(0, 224)] != "B")
        {
            tabela_campo[random(0, 224)] = "B";
            num_inserts++;
        }
    }

    // Ler campo
    for (int i = 0; i <= 224; i++)
    {
        int pos = i;
        int quant_bomb = 0;
        try
        {
            if (tabela_campo[i] == "0")
            {
                int row = pos / 15;
                int col = pos % 15;
                // Verificar a posição leste
                if (col < 14 && tabela_campo[pos + 1] == "B")
                {
                    quant_bomb += 1;
                }
                // Verificar a posição oeste
                if (col > 0 && tabela_campo[pos - 1] == "B")
                {
                    quant_bomb += 1;
                }
                // Verificar a posição noroeste
                if (row > 0 && col > 0 && tabela_campo[pos - 16] == "B")
                {
                    quant_bomb += 1;
                }
                // Verificar a posição norte
                if (row > 0 && tabela_campo[pos - 15] == "B")
                {
                    quant_bomb += 1;
                }
                // Verificar a posição nordeste
                if (row > 0 && col < 14 && tabela_campo[pos - 14] == "B")
                {
                    quant_bomb += 1;
                }
                // Verificar a posição sudeste
                if (row < 14 && col < 14 && tabela_campo[pos + 16] == "B")
                {
                    quant_bomb += 1;
                }
                // Verificar a posição sul
                if (row < 14 && tabela_campo[pos + 15] == "B")
                {
                    quant_bomb += 1;
                }
                // Verificar a posição sudoeste
                if (row < 14 && col > 0 && tabela_campo[pos + 14] == "B")
                {
                    quant_bomb += 1;
                }
            }
        }
        catch (const std::exception &e)
        {
            // pass :3
        }
        if (quant_bomb != 0)
        {
            tabela_campo[i] = String(quant_bomb).c_str();
        }

        // for (int c = 0; c <= 15; c++)
        // {
        //     for (int l = 0; l <= 15; l++)
        //     {

        //         // display.drawRect(c*15, l*15, 15, 15, ST77XX_CYAN);
        //     }
        //     // display.setCursor(0,c*15);
        // }
    }

    // desenhar campo
    int posx = 0;
    int posy = -15;
    int cursor = 0;
    bool new_frame = true;
    int limpando = 1;
    bool fim_de_jogo = false;
    display.setFont(&FreeMono9pt7b);
    while (fim_de_jogo == false)
    {
        pos_jogador_campo[cursor] = '1';
        pos_jogador_campo[cursor + 1] = '0';
        pos_jogador_campo[cursor - 1] = '0';
        pos_jogador_campo[cursor + 15] = '0';
        pos_jogador_campo[cursor - 15] = '0';
        if (new_frame == true)
        {
            atualizar();
            // limpesa de campo
            while (true)
            {
                for (int i = 0; i < 224; i++)
                {
                    int pos = i;
                    try
                    {
                        if (tabela_campo[i] == "z")
                        {
                            int row = pos / 15;
                            int col = pos % 15;

                            // Verificar a posição leste
                            if (col < 14 && tabela_campo[pos + 1] == "0")
                            {
                                tabela_campo[pos + 1] = "z";
                                fake_campo[pos + 1] = "z";
                                limpando += 1;
                            }
                            else
                            {
                                if (col < 14 && tabela_campo[pos + 1] != "B")
                                {
                                    fake_campo[pos + 1] = tabela_campo[pos + 1];
                                }
                            }

                            // Verificar a posição oeste
                            if (col > 0 && tabela_campo[pos - 1] == "0")
                            {
                                tabela_campo[pos - 1] = "z";
                                fake_campo[pos - 1] = "z";
                                limpando += 1;
                            }
                            else
                            {
                                if (col > 0 && tabela_campo[pos - 1] != "B")
                                {
                                    fake_campo[pos - 1] = tabela_campo[pos - 1];
                                }
                            }

                            // Verificar a posição norte
                            if (row > 0 && tabela_campo[pos - 15] == "0")
                            {
                                tabela_campo[pos - 15] = "z";
                                fake_campo[pos - 15] = "z";
                                limpando += 1;
                            }
                            else
                            {
                                if (row > 0 && tabela_campo[pos - 15] != "B")
                                {
                                    fake_campo[pos - 15] = tabela_campo[pos - 15];
                                }
                            }

                            // Verificar a posição sul
                            if (row < 14 && tabela_campo[pos + 15] == "0")
                            {
                                tabela_campo[pos + 15] = "z";
                                fake_campo[pos + 15] = "z";
                                limpando += 1;
                            }
                            else
                            {
                                if (row < 14 && tabela_campo[pos + 15] != "B")
                                {
                                    fake_campo[pos + 15] = tabela_campo[pos + 15];
                                }
                            }
                        }
                    }
                    catch (...)
                    {
                        // Lidar com exceções, se necessário
                    }
                }
                if (limpando == 1)
                {
                    break;
                }
                limpando = 1;
            }

            // campo falso
            posx = 0;
            posy = -15;
            for (int i = 0; i <= 224; i++)
            {
                if (i % 15 == 0)
                {
                    posy += 16;
                    posx = 0;
                }
                if (fake_campo[i] == "0")
                {
                    display.fillRect(posx, posy, 15, 15, ST77XX_BLUE);
                }
                else
                {
                    if (fake_campo[i] != "z")
                    {
                        if (fake_campo[i] == "B")
                        {
                            display.drawRGBBitmap(posx, posy, (uint16_t *)bombcat_data, 15, 15);
                        }
                        else
                        {
                            if (fake_campo[i] == "F")
                            {
                                display.drawRGBBitmap(posx, posy, (uint16_t *)banderola_data, 15, 15);
                            }
                            else
                            {
                                drawtext(String(fake_campo[i]).c_str(), ST77XX_WHITE, posx + 2, posy + 13);
                            }
                        }
                    }
                    display.drawRect(posx, posy, 15, 15, ST77XX_BLUE);
                    // display.fillRect(posx, posy, 15, 15, ST77XX_GREEN);
                }
                posx += 16;
            }

            // campo jogador
            posx = 0;
            posy = -15;
            for (int i = 0; i <= 224; i++)
            {
                if (i % 15 == 0)
                {
                    posy += 16;
                    posx = 0;
                }
                if (pos_jogador_campo[i] == '1')
                {
                    display.drawRect(posx, posy, 15, 15, ST77XX_GREEN);
                }
                posx += 16;
            }
            // campo verdadeiro
            //  posx = 0;
            //  posy = -15;
            //  for (int i = 0; i <= 224; i++)
            //  {
            //      if (i % 15 == 0)
            //      {
            //          posy += 16;
            //          posx = 0;
            //      }
            //  drawtext(String(tabela_campo[i]).c_str(),ST77XX_WHITE, posx, posy+13);
            //     posx += 16;
            // }

            // display.drawRGBBitmap(cursor_x*15, (cursor_y*15)-10, (uint16_t *)bombtest_data, 15, 15);

            u8g2.clearBuffer();
            u8g2.setFont(u8g2_font_streamline_all_t);
            u8g2.drawUTF8(0, 32, "\u0172");
            u8g2.setFont(u8g2_font_9x15_tf);
            // u8g2.drawStr(0, 32, String(cursor).c_str());
            u8g2.drawStr(22, 32, String(num_flags).c_str());
            u8g2.sendBuffer();
        }
        if (num_flags == 0)
        {
            for (int i = 0; i <= 224; i++)
            {
                if (fake_campo[i] == "F")
                {
                    if (tabela_campo[i] == "B")
                    {
                        num_flags_venceu += 1;
                    }
                }
            }
            if (num_flags_venceu == num_bombs)
            {
                break;
            }
        }

        switch (read_buttons())
        {
        case 1:
            if (tabela_campo[cursor] == "B")
            {
                atualizar();
                bool a = false;
                posx = 0;
                posy = -15;
                for (int i = 0; i <= 224; i++)
                {
                    if (i % 15 == 0)
                    {
                        posy += 16;
                        posx = 0;
                    }
                    if (fake_campo[i] != "9")
                    {
                        if (a == false)
                        {
                            drawtext(String("H").c_str(), ST77XX_WHITE, posx + 2, posy + random(0, 13));
                            bip(10, 500);
                        }
                        else
                        {
                            drawtext(String("A").c_str(), ST77XX_WHITE, posx + 2, posy + random(0, 13));
                            bip(10, 700);
                        }
                        a = !a;
                    }
                    posx += 16;
                    delay(5);
                }
                fim_de_jogo = true;
            }
            else
            {
                if (tabela_campo[cursor] == "0")
                {
                    fake_campo[cursor] = "z";
                    tabela_campo[cursor] = "z";
                }
                else
                {
                    fake_campo[cursor] = tabela_campo[cursor];
                }
            }
            new_frame = true;
            break;
        case 2:
            if (fake_campo[cursor] == "0")
            {
                fake_campo[cursor] = "F";
                num_flags -= 1;
            }
            else
            {
                if (fake_campo[cursor] == "F")
                {
                    fake_campo[cursor] = "0";
                }
                num_flags += 1;
            }
            new_frame = true;
            break;
        case 3:
            if (cursor < 210)
            {
                cursor += 15;
                new_frame = true;
            }
            break;
        case 4:
            if (cursor > 0)
            {
                cursor -= 1;
                new_frame = true;
            }
            break;
        case 5:
            if (cursor > 14)
            {
                cursor -= 15;
                new_frame = true;
            }
            break;
        case 6:
            if (cursor < 224)
            {
                cursor += 1;
                new_frame = true;
            }
            break;

        default:
            new_frame = false;
            break;
        }
    }
    atualizar();

    drawtext("Fim de jogo!", ST77XX_WHITE, 0, 15);

    if (fim_de_jogo == true)
    {
        display.drawRGBBitmap(0, 20, (uint16_t *)bombcat_data, 15, 15);
        drawtext("Venceram!", ST77XX_RED, 18, 33);
        u8g2.clearDisplay();
        u8g2.setFont(u8g2_font_streamline_all_t);
        u8g2.drawUTF8(0, 22, "\u016e");
    }
    else
    {
        bip(100, 500);
        bip(100, 600);
        bip(100, 400);
        bip(100, 300);
        bip(100, 500);
        bip(100, 700);
        display.drawRGBBitmap(0, 20, (uint16_t *)bombcat_data, 15, 15);
        drawtext("Eliminados!", ST77XX_GREEN, 18, 33);
        u8g2.clearDisplay();
        u8g2.setFont(u8g2_font_streamline_all_t);
        u8g2.drawUTF8(0, 22, "\u01f6");
    }
    display.setFont(&FreeMono12pt7b);
    drawtext("Jogar novamente?", ST77XX_WHITE, 5, 130);

    u8g2.setFont(u8g2_font_9x15_tf);
    u8g2.drawDisc(42, 15, 7, U8G2_DRAW_ALL);
    u8g2.drawCircle(42, 35, 7, U8G2_DRAW_ALL);
    u8g2.drawStr(55, 20, "Lez go");
    u8g2.drawStr(55, 40, "nah");
    u8g2.sendBuffer();
    while (true)
    {
        if (read_buttons() == 1)
        {
            init_game_minesweeper();
        }
        if (read_buttons() == 2)
        {
            break;
        }
    }
    u8g2.clearBuffer();
    delay(100);
}