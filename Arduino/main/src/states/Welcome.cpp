#include "Welcome.h"

void Welcome::onEnter() {
  currentCredit = 0;
}

void Welcome::onPressButtonA() {
  stateMachine.setState(preparationState, true);
}

void Welcome::onPressButtonC() {
  StateUtils::wrapIndexInRange(&currentCredit, 1, 1, 4);
  show();
}

void Welcome::onPressButtonD() {
  stateMachine.setState(grayState, true);
}

void Welcome::show() {
  switch (currentCredit) {
    case 0:
      return display.show("Welcome!\n\nPress a button!");
    case 1:
      return display.show("Ufpel Brazil\nLaboratory 337\n\n\nStart: 06/11/24");
    case 2:
      return display.show("Organizers:\nPlaceHolder\nPlaceHolder");
    case 3:
      return display.show("Hardware/Idea:\nPlaceHolder\nPlaceHolder");
    case 4:
      return display.show("Software/Schematic:\nDecio Luvier");
  }
}