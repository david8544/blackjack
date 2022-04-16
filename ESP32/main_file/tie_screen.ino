/*
 * Will print out tie screen
 */
void tie_screen()
{
  tft.fillScreen(TFT_BLUE); //fill background
  tft.setTextColor(TFT_WHITE, TFT_BLUE);
  tft.setCursor(2,67,4);
  tft.println("TIE");
  delay(500);
}
