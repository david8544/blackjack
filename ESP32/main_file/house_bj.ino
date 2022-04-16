/*
 * Screen for house got bj
 */
void house_bj()
{
    tft.fillScreen(TFT_RED); //fill background
    tft.setTextColor(TFT_BLACK, TFT_RED);
    tft.setCursor(0,67,4);
    tft.println("HOUSE GOT BJ");
    delay(1000);
}
