
/*------------------
 * get_deck Function:
 * This function will make the calls to all of the necessary function in order
 * get a deck for the current game. This deck will be used throughout all of the games
 * until reset
 */

void get_deck()
{
  
    sprintf(request_buffer,
    "GET /sandbox/sc/davidmag/blackjack/createdeck.py HTTP/1.1\r\n", deck_id);
    strcat(request_buffer,
    "Host: 608dev-2.net\r\n"); //add more to the end
    strcat(request_buffer,"\r\n"); //add blank line!
    do_http_GET(
    "608dev-2.net", 
    request_buffer, 
    response_buffer,
    OUT_BUFFER_SIZE, 
    RESPONSE_TIMEOUT,true, true);
    sprintf(deck_id, response_buffer);
    Serial.println("_____++++_____");
    Serial.println(deck_id);
    Serial.println("_____++++_____");
    
}
