/*
 * Will print out won screen
 */
void won_screen()
{
      tft.fillScreen(TFT_GREEN); //fill background
      tft.setTextColor(TFT_RED, TFT_GREEN);
      tft.setCursor(2,67,4);
      tft.println("YOU WON");
      delay(500);
      tft.fillScreen(TFT_RED); //fill background
      tft.setTextColor(TFT_GREEN, TFT_RED);
      tft.setCursor(2,67,4);
      tft.println("YOU WON");
      delay(500);
      tft.fillScreen(TFT_GREEN); //fill background
      tft.setTextColor(TFT_RED, TFT_GREEN);
      tft.setCursor(2,67,4);
      tft.println("YOU WON");
      delay(500);
      tft.fillScreen(TFT_RED); //fill background
      tft.setTextColor(TFT_GREEN, TFT_RED);
      tft.setCursor(2,67,4);
      tft.println("YOU WON");
}
