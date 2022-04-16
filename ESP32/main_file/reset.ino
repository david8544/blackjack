/*
 * resets everything needed for a new game
 */
void reset()
{
    current_bet_amount = 100;
    memset(house_cards_internal,0 ,10);
    memset(house_card_display, 0, 10);
    memset(player_cards,0,10);
    house_value = 0;
    player_value = 0;
    memset(last_card, 0 ,3);
}
