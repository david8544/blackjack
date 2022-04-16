/*
 * Screen for setting the bet, Will not allow the user to bet more
 * than what he has.
 */
void set_bet_main_screen()
{
      tft.fillScreen(TFT_BLACK); //fill background
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setCursor(53,2,4);
      tft.println("21");
      tft.setCursor(0, 66, 1);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.print("Total Money: ");
      tft.print(total_money);
      tft.println("$");
      tft.setCursor(0, 81, 1);
      tft.print("Current bet: ");
      tft.print(current_bet_amount);
      tft.println("$");
      tft.setCursor(0, 140, 2);
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.println("PLAY");
      tft.setCursor(90, 140, 2);
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.println("RAISE");
}

void update_bet_amount()
{
  if (total_money >= current_bet_amount+100)
  {
    current_bet_amount += 100;
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setCursor(0, 81, 1);
    tft.print("Current bet: ");
    tft.print(current_bet_amount);
    tft.println("$");
  }
  
  
}
