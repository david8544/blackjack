/*------------------
 * get_card Function:
 * This function will make the calls to all of the necessary function in order
 * get a card from the deck.
 */

void get_card()
{
    sprintf(request_buffer,
    "GET /sandbox/sc/davidmag/blackjack/getcard.py?deck=%s HTTP/1.1\r\n", deck_id);
    strcat(request_buffer,
    "Host: 608dev-2.net\r\n"); //add more to the end
    strcat(request_buffer,"\r\n"); //add blank line!
    do_http_GET(
    "608dev-2.net", 
    request_buffer, 
    response_buffer,
    OUT_BUFFER_SIZE, 
    RESPONSE_TIMEOUT,true, false);
    sprintf(last_card, response_buffer);
}
