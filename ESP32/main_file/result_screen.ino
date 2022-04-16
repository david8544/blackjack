/*
 * This will pring out the result screen 
 * after a round. Will be different if the user won, tie, lost
 */
void result_screen(bool won, bool tie)
{
    tft.fillScreen(TFT_BLACK); //fill background
    tft.setTextColor(TFT_RED, TFT_BLACK);
    tft.setCursor(53,2,4);
    tft.println("21");
    tft.setCursor(0, 66, 1);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    if (won)
    {
      tft.print("You Won: ");
      tft.println(current_bet_amount);
    }
    if (tie)
    {
      tft.print("You Won: ");
      tft.println("0");
    }
    if (!won && !tie)
    {
      tft.print("You Lost: ");
      tft.println(current_bet_amount);
    }
    tft.setCursor(0, 81, 1);
    tft.print("Total Money: ");
    tft.println(total_money);
    tft.setCursor(0, 140, 2);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    reset();
    if (total_money >0)
    {
      tft.println("PLAY");
      tft.setCursor(83, 140, 2);
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.println("RESET");
      game_state = RESULT_SCREEN;
      
    }
    else
    {
      tft.println("LOST ALL MONEY");
      delay(1500);
      reset_button_states();
      shuffle_deck();
      total_money = 1000;
      game_state = WELCOME;
    }
    
}
