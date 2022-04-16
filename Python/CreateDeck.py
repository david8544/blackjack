import requests

def request_handler(request: dict) -> str:
    if request['method'] != 'GET':
        return -1
    request_url = "https://deckofcardsapi.com/api/deck/new/shuffle/?deck_count=6"
    response = requests.get(request_url)
    if response.status_code != 200:
        return -1
    response = response.json()
    print( response['deck_id'])

request_handler({'method':'GET'})

print(((2^12)*(82*1000)*((1/((60+82)*1000)-(1/(110+82)*1000)))/90))

()