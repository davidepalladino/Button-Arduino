 /**
  * This library allows to manage a button, specifying if the pressure is long or not. For short press there is the debouncing.
  * Is possible to assign a specific procedure, both for short and long press.
  * Copyright (c) 2020 Davide Palladino. 
  * All right reserved.
  * 
  * @author Davide Palladino
  * @contact davidepalladino@hotmail.com
  * @version 1.1.1
  * @date May 3rd, 2020
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

    #define DEFAULT_LONG_PRESSURE 0                         // Default value in milliseconds for the long press.

    typedef enum {PULLUP, NO_PULLUP} input_t;               // Symbolic costants to indicate, respectively, if is "INPUT_PULLUP" or "INPUT".

    /**
     *  Poiter type to a procdeure, that will be assigned to the member data "ptrActionShort" and "ptrActionLong" through the costructor or
     *  the relative methods.
     *  @warning: The procedures must be without parameters.
     */
    typedef void (*ptrProcedure) ();

    /**
     * Class for initialize and manage the button object.
     */
    class Button {
        public:            
            /** 
             * This constructor creates the object setting only the pin button. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @warning: The pin will be set to "NO_PULLUP" mode, respectively "INPUT" of "pinMode".
             */
            Button(uint8_t pin);

            /** 
             * This constructor creates the object setting the pin button and the mode of the input. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @param mode Mode of the input, between "INPUT" (with "NO_PULLUP" constant) and "INPUT_PULLUP" (with "PULLUP" constant).
             */
            Button(uint8_t pin, input_t mode);

            /** 
             * This constructor creates the object setting the pin button and the time to define the long press. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @param timeLongPress Time in milliseconds for long press.
             * @warning: The pin will be set to "NO_PULLUP" mode, respectively "INPUT" of "pinMode".
             */
            Button(uint8_t pin, uint32_t timeLongPress);

            /** 
             * This constructor creates the object setting the pin button, the mode of the input and the time to define the long press. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @param mode Mode of the input, between "INPUT" (with "NO_PULLUP" constant) and "INPUT_PULLUP" (with "PULLUP" constant).
             * @param timeLongPress Time in milliseconds for long press.
             */
            Button(uint8_t pin, input_t mode, uint32_t timeLongPress);

            /** 
             * This constructor creates the object setting the pin button, the time to define the long press and the procedures for short and long press. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @param timeLongPress Time in milliseconds for long press.
             * @param ptrActionShort Pointer to a procedure for the short press. The procedure must be without parameters.
             * @param ptrActionLong Pointer to a procedure for the long press. The procedure must be without parameters.
             * @warning: The pin will be set to "NO_PULLUP" mode, respectively "INPUT" of "pinMode".
             */
            Button(uint8_t pin, uint32_t timeLongPress, ptrProcedure ptrActionShort, ptrProcedure ptrActionLong);

            /** 
             * This constructor creates the object setting the pin button, the mode of the input, the time to define the long press and the procedures for short and long press. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @param mode Mode of the input, between "INPUT" (with "NO_PULLUP" constant) and "INPUT_PULLUP" (with "PULLUP" constant).
             * @param timeLongPress Time in milliseconds for long press.
             * @param ptrActionShort Pointer to a procedure for the short press. The procedure must be without parameters.
             * @param ptrActionLong Pointer to a procedure for the long press. The procedure must be without parameters.
             */
            Button(uint8_t pin, input_t mode, uint32_t timeLongPress, ptrProcedure ptrActionShort, ptrProcedure ptrActionLong);

            /**
             * This method sets the time for the long press.
             * @param timeLongPress Time in milliseconds for long press.
             */
            void setTimeLongPress(uint32_t timeLongPress);

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
             * This method gets the time for the long press.
             * @return Time in milliseconds for long press.
             */          
            uint32_t getTimeLongPress();

            /**
             * This method gets the actual press, both for short and long. For short press there is the debouncing.
             * @return Value -1 if the pressure is long; 0 if there is not any pressure; 1 if the pressure is short.
             */     
            int8_t checkPress();

        private:
            uint8_t pin;                                // Pin of the button to read the status.
            uint8_t mode;                               // Mode of the input, between "INPUT" (with "NO_PULLUP" constant) and "INPUT_PULLUP" (with "PULLUP" constant).
            uint32_t timeLongPress;                     // Time in milliseconds for the long press.
            ptrProcedure ptrActionLong;                 // Pointer to a procedure for short press.
            ptrProcedure ptrActionShort;                // Pointer to a procedure for long press.
            uint8_t valuePress;                         // This variable will contain the value where the button will be considered pressed.
            uint32_t timeOut;                           // The end of time, calculated with the actual time plus "timeLongPress".
            boolean status;                             // A flag to define if the button was already pressed.
            int8_t actualValue;                         // Actual value of the button.

            /**
             * This method sets the pin button.
             * @param pin Digital pin of the button.
             */
            void setPin(uint8_t pin);

            /**
             * This method sets the input mode.
             * @param mode Mode of the input.
             */
            void setMode(input_t mode);

            /**
             * This method sets the value where the button will be considered pressed.
             */
            void setValuePress();

            /** 
             * This method sets the timeout, that is the time within which the pressure will be considerated short.
             * @param timeOut Time in milliseconds.
             */
            void setTimeOut(uint32_t timeOut);

            /** 
             * This method sets the status of the button, if is pressed or not.
             * @param status Boolean value "true" if the button has been pressed; "false" if not.
             */            
            void setStatus(boolean status);

            /**
             * This method sets a symbolic value of the press in actual time, both for short and long.
             * @param actualValue Symbolic value of press.
             */
            void setActualValue(int8_t actualValue);

            /**
             * This method gets the pin button.
             * @return Digital pin of the button.
             */             
            uint8_t getPin();

            /**
             * This method gets the mode of the button.
             * @return Mode of the button.
             */             
            uint8_t getMode();

            /**
             * This method gets the value where the button will be considered pressed.
             * @return Value of the press.
             */
            uint8_t getValuePress();

            /**
             * This method gets the timeout, that is the end of time within which the press will be considerated short.
             * @return Time in milliseconds.
             */                
            uint32_t getTimeOut();     

            /**
             * This method gets the status of the button, if is pressed or not.
             * @return Boolean value "true" if the button has been pressed; "false" if not.
             */          
            boolean getStatus();           

            /**
             * This method gets a symbolic value of the press in actual time, both for short and long.
             * @return Symbolic value of press.
             */                  
            int8_t getActualValue();
    };
#endif
