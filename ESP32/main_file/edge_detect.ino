/*----------------------------------
 * edge_detect Function:
 * Arguments:
 *    int input the current input from the button
 *    int* button_state the cuurent state the state machine checked is in
 * Return value:
 *    void (none)
 *    changes gloabl variable of the state
 */
 void edge_detect(int input, int* button_state) {
  if (*button_state == UNPUSHED)
  {
    if (input == PUSHED)
    {
      *button_state = PUSHED;
    }
  }
  else if (*button_state == PUSHED)
  {
    if (input == UNPUSHED)
    {
      *button_state = BRELEASED;
    }
  }
}
