/*
 * screen for user lost
 */
void lost_screen()
{
    tft.fillScreen(TFT_WHITE); //fill background
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.setCursor(2,67,4);
    tft.println("YOU LOST");
    delay(500);
}
