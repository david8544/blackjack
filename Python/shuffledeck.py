import requests

"""
request handler function:
    Will shuffle the deck
"""
def request_handler(request: dict) -> str:
    if request['method'] != 'GET':
        return -1
    deck_id = request['values']['deck']
    return shuffle_deck(deck_id)


def shuffle_deck(deck_id: str) -> None:
    request_url = f"https://deckofcardsapi.com/api/deck/{deck_id}/shuffle/"
    response = requests.get(request_url)
    if response.status_code != 200:
        return -1
    return 1



