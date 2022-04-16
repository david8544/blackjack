/*
 * This function will deal cards as the real game,
 * one for user, one for house, and back.
 * It immeditely checks if the house has 21, if so, only a tie will save the user from loosing
 * If the user has 21, he wins
 */
void start_playing()
{
  int player_first_card = get_player_card();
  int house_first_card = get_house_card(true);
  int player_second_card = get_player_card();
  int house_second_card = get_house_card(false);
  player_value = player_first_card + player_second_card;
  house_value = house_first_card + house_second_card;
  if (player_value == 22)
  {
    player_value = 12;
  }
  if (house_value == 22)
  {
    house_value = 12;
  }
  update_game_status_player_on(true);
  delay(1500);
}

/*
 * If the player chooses to stay, this function will keep on
 * dealing cards to the house until it has more than 16 points
 * then it will check who won
 */
void player_stay()
{
  screen_update_house_cards();
  delay(500);
  while (house_value < 16)
  {
    int house_card = get_house_card(false);
    house_value = house_value + house_card;
    screen_update_house_cards();
    delay(1000);
  }
  delay(1000);
  update_game_status_player_off();
  
}

/*
 * This function deals the player a card
 * then checks if he has over 21, which means he lost
 */
void player_hit()
{
  int player_card = get_player_card();
  player_value = player_value + player_card;
  screen_update_player_cards();
  delay(1000);
  update_game_status_player_on(false);
}

/*
 * This function is used for checking game status
 * after the user decided to stay
 */
void update_game_status_player_off()
{
  if (tie(player_value,house_value))
  {
    tie_state();
  }
  else if ((player_value > house_value) ||
            over_21(house_value))
  {
    won_state();
  }
  else if (house_value > player_value)
  {
    lost_state();
  }
}

/*
 * Calls the tie screen
 */
void tie_state()
{
  tie_screen();
  delay(200);
  result_screen(false, true);
}

/*
 * Calls the won screen
 * and adds money
 */
void won_state()
{
  total_money += current_bet_amount;
  won_screen();
  delay(200);
  result_screen(true, false);
}

/*
 * calls the lost screen 
 * and takes money lost
 */
void lost_state()
{
  total_money -= current_bet_amount;
  lost_screen();
  delay(200);
  result_screen(false, false);
}

/*
 * This function is used for checking game status
 * when we just starts a game -> if first = true
 * then it is only used to check if the player is over 21
 */
void update_game_status_player_on(bool first)
{
   if (bj(player_value) && first)
  {
    if (tie(player_value, house_value))
    {
      tie_state();
    }
    else
    {
      won_state();
    }
  }
  else if (bj(house_value) && first)
  {
    house_bj();
    lost_state();
  }
  else if (over_21(player_value))
  {
    if (strcmp(last_card, "A") == 0)
    {
      player_value = player_value -10;
    }
    else
    {
      lost_state();
    }
  }
}


bool over_21(int value)
{
  if (value > 21)
  {
    return true;
  }
  return false;
}

bool bj(int value)
{
  if (value == 21)
  {
    return true;
  }
  return false;
}

bool tie(int player, int house)
{
  if (player == house)
  {
    return true;
  }
  return false;
}

/*
 * gets a new card for the player
 * and sets its value
 */
int get_player_card()
{
  get_card();
  int value = parse_card();
  strncat(player_cards, last_card, 2);
  return value;
}

/*
 * gets a new card for the house
 * and sets its value
 */
int get_house_card(bool first)
{
  get_card();
  int value = parse_card();
  if (first)
  {
    strncat(house_card_display, last_card,2);
  }
  strncat(house_cards_internal, last_card,2);
  return value;
}

/*
 * takes the card value, if its KQJ, sets the value to 10
 * if it is A, sets the value to 11
 * otherwise, parses int
 */
int parse_card()
{
  int value;
  if (strcmp(last_card, "K") == 0 ||
      strcmp(last_card, "J") == 0 ||
      strcmp(last_card, "Q") == 0)
      {
        value = 10;
      }
 else if (strcmp(last_card, "A") == 0)
 {
  value = 11;
 }
 else
 {
  value = atoi(last_card);
 }
 return value;
}
