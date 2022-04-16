/*
 * Will print out welcome screen
 */
void welcome_screen()
{
      tft.fillScreen(TFT_BLACK); //fill background
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setCursor(53,2,4);
      tft.println("21");
      tft.setCursor(28, 30, 2);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.println("Welcome to");
      tft.setCursor(22, 45, 2);
      tft.println("Blackjack 21!");
      tft.setCursor(0, 100, 2);
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.println("Press any button to start playing");
}
