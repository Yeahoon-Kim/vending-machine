# vending-machine
## Objective
* make GUI vending machine using Qt
## Component
* main.cpp
  * import Widget and show
* widget.h
  * header file of widget.cpp 
* widget.cpp
  * make lcdNumber and several pushButtons to show vending machine
  * lcdNumber : show left money
  * pushButton : consist of money buttons and order buttons, and reset button
* widget.ui
  * save exact location of GUI units
  * use XML
## Requirements
* lcdNumber always shows the number of money left right after every events
* money button add assigned money to total money
* drink button substract assigned money to total money
* if there is not enough money to buy drink, disable drink button
* reset button show messagebox to show remained total money and reset money
