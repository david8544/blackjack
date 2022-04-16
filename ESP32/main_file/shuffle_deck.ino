/*
 * Since we are using the same deck,
 * If the user chooses to reset game, we will
 * shuffle the deck to start fresh
 */
void shuffle_deck()
{
    sprintf(request_buffer,
    "GET /sandbox/sc/davidmag/blackjack/shuffledeck.py?deck=%s HTTP/1.1\r\n", deck_id);
    strcat(request_buffer,
    "Host: 608dev-2.net\r\n"); //add more to the end
    strcat(request_buffer,"\r\n"); //add blank line!
    do_http_GET(
    "608dev-2.net", 
    request_buffer, 
    response_buffer,
    OUT_BUFFER_SIZE, 
    RESPONSE_TIMEOUT,true, true);
}
