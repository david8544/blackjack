import requests

"""
request handler function:
    will provide a new card upon request
    J,Q,K,A -> 11,12,13,1
    all other cards will be represented with their values
    If less than 4 card remain, will shuffle automatically
"""
def request_handler(request: dict) -> str:
    if request['method'] != 'GET':
        return -1
    deck_id = request['values']['deck']
    request_url = f"https://deckofcardsapi.com/api/deck/{deck_id}/draw/?count=1"
    response = requests.get(request_url)
    if response.status_code != 200:
        return -1
    response = response.json()
    res = parse_response(response)
    if res['remain'] < 4:
        shuffle_deck(deck_id)
    return res['card']

def parse_response(response: dict) -> dict:
    res = dict()
    res['remain'] = response['remaining']
    res['card'] = response['cards'][0]['value']
    if res['card'] == 'KING':
        res['card'] = 'K'
    elif res['card'] == 'ACE':
        res['card'] = 'A'
    elif res['card'] == 'QUEEN':
        res['card'] = 'Q'
    elif res['card'] == 'JACK':
        res['card'] = 'J'
    return res

def shuffle_deck(deck_id: str) -> None:
    request_url = f"https://deckofcardsapi.com/api/deck/{deck_id}/shuffle/"
    requests.get(request_url)


