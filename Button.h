 /**
  * This library allows to manage a button, specifying if the pressure is long or not. For short press there is the debouncing.
  * Is possible to assign a specific procedure, both for short and long press.
  * Copyright (c) 2020 Davide Palladino. 
  * All right reserved.
  * 
  * @author Davide Palladino
  * @contact davidepalladino@hotmail.com
  * @version 1.0
  * @date April 20th, 2020
  * 
  * This library is free software; you can redistribute it and/or
  *  modify it under the terms of the GNU General Public
  *  License as published by the Free Software Foundation; either
  *  version 3.0 of the License, or (at your option) any later version
  * 
  * This library is distributed in the hope that it will be useful,
  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
  *  GNU Lesser General Public License for more details.
  * 

  */

#ifndef BUTTON_H
    #define BUTTON_H
    #ifndef ARDUINO_H
        #include <Arduino.h>                                // Import the Arduino library.
    #endif

    #define DEFAULT_LONG_PRESSURE 5000                      // Default value in milliseconds for the long press.

    /**
     *  Poiter type to a procdeure, that will be assigned to the member data "ptrActionShort" and "ptrActionLong" through the costructor or
     *  the relative methods.
     *  CAUTION: The procedures must be without parameters.
     */
    typedef void (*ptrProcedure) ();

    /**
     * Class for initialize and manage the button object.
     */
    class Button {
        public:            
            /** 
             * This constructor creates the object setting only the pin button. 
             * @param pinButton Digital pin of the button.
             */
            Button(unsigned short pinButton);

            /** 
             * This constructor creates the object setting the pin button and the time to define the long press.
             * @param pinButton Digital pin of the button.
             * @param timeLongPress Time in milliseconds for long press.
             */
            Button(unsigned short pinButton, unsigned long timeLongPress);

            /** 
             * This constructor creates the object setting the pin button and the time to define the long press.
             * @param pinButton Digital pin of the button.
             * @param timeLongPress Time in milliseconds for long press.
             * @param ptrActionShort Pointer to a procedure for the short press. The procedure must be without parameters.
             * @param ptrActionLong Pointer to a procedure for the long press. The procedure must be without parameters.
             */
            Button(unsigned short pinButton, unsigned long timeLongPress, ptrProcedure ptrActionShort, ptrProcedure ptrActionLong);
            
            /**
             * This method sets the pin button.
             * @param pinButton Digital pin of the button.
             */
            void setPinButton(unsigned short pinButton);

            /**
             * This method sets the time for the long press.
             * @param timeLongPress Time in milliseconds for long press.
             */
            void setTimeLongPress(unsigned long timeLongPress);

            /**
             * This method sets the pointer to the procedure, for the short press.
             * @param ptrActionShort Pointer to a procedure for the short press. The procedure must be without parameters.
             */            
            void setPtrActionShort(ptrProcedure ptrActionShort);

            /**
             * This method sets the pointer to the procedure, for the long press.
             * @param ptrActionLong Pointer to a procedure for the long press. The procedure must be without parameters.
             */   
            void setPtrActionLong(ptrProcedure ptrActionLong);

            /**
             * This method gets the pin button.
             * @return Digital pin of the button.
             */             
            unsigned short getPinButton();

            /**
             * This method gets the time for the long press.
             * @return Time in milliseconds for long press.
             */          
            unsigned long getTimeLongPress();

            /**
             * This method gets the actual press, both for short and long. For short press there is the debouncing.
             * @return Value -1 if the pressure is long; 0 if there is not any pressure; 1 if the pressure is short.
             */     
            unsigned short checkPress();

        private:
            unsigned short pinButton;                       // Pin of the button to read the status.
            unsigned long timeLongPress;                    // Time in milliseconds for the long press.
            ptrProcedure ptrActionLong;                     // Pointer to a procedure for short press.
            ptrProcedure ptrActionShort;                    // Pointer to a procedure for long press.
            unsigned long timeOut;                          // The end of time, calculated with the actual time plus "timeLongPress".
            boolean pressed;                                // A flag to define if the button was already pressed.
            short valuePress;                               // The return value of method "checkPress".

            /** 
             * This method sets the timeout, that is the time within which the pressure will be considerated short.
             * @param timeOut Time in milliseconds.
             */
            void setTimeOut(unsigned long timeOut);

            /** 
             * This method sets the status of the button, if is pressed or not.
             * @param pressed Boolean value "true" if the button has been pressed; "false" if not.
             */            
            void setPressed(boolean pressed);

            /**
             * This method sets a symbolic value of the press in actual time, both for short and long.
             * @param valuePress Symbolic value of press.
             */
            void setValuePress(short valuePress);

            /**
             * This method gets the timeout, that is the end of time within which the press will be considerated short.
             * @return Time in milliseconds.
             */                
            unsigned long getTimeOut();     

            /**
             * This method gets the status of the button, if is pressed or not.
             * @return Boolean value "true" if the button has been pressed; "false" if not.
             */          
            boolean getPressed();           

            /**
             * This method gets a symbolic value of the press in actual time, both for short and long.
             * @return Symbolic value of press.
             */                  
            short getValuePress();
    };
#endif