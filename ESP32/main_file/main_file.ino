#include<string.h>
#include<math.h>
#include <WiFi.h> //Connect to WiFi Network
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h> //Used in support of TFT Display
TFT_eSPI tft = TFT_eSPI();

char network[] = "MIT";  //SSID for 6.08 Lab
char password[] = ""; //Password for 6.08 Lab


const uint8_t LOOP_PERIOD = 10; //milliseconds
uint32_t primary_timer = 0;

//Some constants and some resources:
const int RESPONSE_TIMEOUT = 6000; //ms to wait for response from host
const int POSTING_PERIOD = 6000; //periodicity of getting a number fact.
const uint16_t IN_BUFFER_SIZE = 1000; //size of buffer to hold HTTP request
const uint16_t OUT_BUFFER_SIZE = 1000; //size of buffer to hold HTTP response
char request_buffer[IN_BUFFER_SIZE]; //char array buffer to hold HTTP request
char response_buffer[OUT_BUFFER_SIZE]; //char array buffer to hold HTTP response

const uint8_t INPUT_PIN1 = 16; //pin connected to button
const uint8_t INPUT_PIN2 = 5; //pin connected to button

// game variables
char deck_id[15]; // variable to store the deck id from the card api
int total_money = 1000;
int current_bet_amount = 100;
char house_cards_internal[10]; // initial house cards for view (only one)
char house_card_display[10];
char player_cards[10];
int house_value = 0;
int player_value = 0;
char last_card[3];

// game states
int game_state = 0;
#define WELCOME 0
#define SET_BET 1
#define GAME_IS_ON 2
#define RESULT_SCREEN 3
#define WAITING_WELCOME_RESPONSE 4

// button states
#define UNPUSHED 0
#define PUSHED 1
#define BRELEASED 2

// button response
int left_button_state = UNPUSHED;
int right_button_state = UNPUSHED;



void setup() {
  tft.init();  //init screen
  tft.setRotation(2); //adjust rotation
  tft.setTextSize(1); //default font size
  tft.fillScreen(TFT_BLACK); //fill background
  tft.setTextColor(TFT_RED, TFT_BLACK); //set color of font to green foreground, black background
  Serial.begin(115200); //begin serial comms
  delay(100); //wait a bit (100 ms)
  connect_to_wifi();
  pinMode(INPUT_PIN1, INPUT_PULLUP); //set input pin as an input!
  pinMode(INPUT_PIN2, INPUT_PULLUP); //set input pin as an input!
  get_deck();
}
void loop() {
  uint8_t left_button = digitalRead(INPUT_PIN1);
  uint8_t right_button = digitalRead(INPUT_PIN2);
  fsm_general_bj(left_button, right_button);
  while (millis() - primary_timer < LOOP_PERIOD); //wait for primary timer to increment
  primary_timer = millis();
}

void reset_button_states()
{
  left_button_state = UNPUSHED;
  right_button_state = UNPUSHED;
}

void fsm_general_bj(int left_button, int right_button)
{
  switch(game_state)
  {
    case WELCOME:
    {
      welcome_screen();
      game_state = WAITING_WELCOME_RESPONSE;
    }
    break;
    case WAITING_WELCOME_RESPONSE:
    {
      edge_detect(left_button, &left_button_state);
      edge_detect(right_button, &right_button_state);
      if (left_button_state == BRELEASED || right_button_state == BRELEASED)
      {
        reset_button_states();
        game_state = SET_BET;
        set_bet_main_screen();
      }
    }
    break;
    case SET_BET:
    {
      edge_detect(left_button, &left_button_state);
      edge_detect(right_button, &right_button_state);
      if (right_button_state == BRELEASED)
      {
        update_bet_amount();
        right_button_state = UNPUSHED;
      }
      if (left_button_state == BRELEASED)
      {
        reset_button_states();
        game_state = GAME_IS_ON;
        start_playing();
        game_screen();
      }
    }
    break;
    case GAME_IS_ON:
    {
      edge_detect(left_button, &left_button_state);
      edge_detect(right_button, &right_button_state);
      if (right_button_state == BRELEASED)
      {
        right_button_state = UNPUSHED;
        player_hit();
      }
      else if (left_button_state == BRELEASED)
      {
        reset_button_states();
        player_stay();
      }
      
    }
    break;
    case RESULT_SCREEN:
    {
      edge_detect(left_button, &left_button_state);
      edge_detect(right_button, &right_button_state);

      if (right_button_state == BRELEASED)
      {
        // reset
        reset_button_states();
        shuffle_deck();
        total_money = 1000;
        game_state = WELCOME;
      }
      else if (left_button_state == BRELEASED)
      {
        reset_button_states();
        game_state = SET_BET;
        set_bet_main_screen();
      }
    }
  }
}
