/*
 * This function is used to print the current 
 * game-card statuc on the screen, the very initial 
 * screen once the first cards are deal.
 */
void game_screen()
{
      tft.fillScreen(TFT_BLACK); //fill background
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setCursor(53,2,4);
      tft.println("21");
      tft.setCursor(0, 66, 1);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.print("House Cards: ");
      tft.println(house_card_display);
      tft.setCursor(0, 81, 1);
      tft.print("Your Cards: ");
      tft.println(player_cards);
      tft.setCursor(0, 140, 2);
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.println("STAY");
      tft.setCursor(103, 140, 2);
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.println("HIT");
}

/*
 * This function updates the cards values on the screen
 * for the user, minimum deletion and screen update
 */
void screen_update_player_cards()
{
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setCursor(0, 81, 1);
  tft.print("Your Cards: ");
  tft.println(player_cards);
}


/*
 * This function updates the cards values on the screen
 * for the house, minimum deletion and screen update
 */
void screen_update_house_cards()
{
  tft.setCursor(0, 66, 1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.print("House Cards: ");
  tft.println(house_cards_internal);
}
