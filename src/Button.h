 /**
  * @brief This library allows to manage a button.
  *  It can specify if the pressure is long or not. Morevoer, is possible to assign a time (in milliseconds) to consider the long press.
  * Copyright (c) 2020 Davide Palladino. 
  * All right reserved.
  * 
  * @author Davide Palladino
  * @contact me@davidepalladino.com
  * @website www.davidepalladino.com
  * @version 2.0.0
  * @date 1st June, 2021
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
        #include <Arduino.h>
    #endif

    #define DEFAULT_LONG_PRESS 0                                                                // Default value in milliseconds for the long press.

    typedef enum input : uint8_t {B_PULLUP, B_NOPULLUP} input_t;                                // Symbolic constants to indicate, respectively, if is "INPUT_PULLUP" or "INPUT".

    class Button {
        public:            
            /** 
             * @brief This constructor creates the object setting only the pin button. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @warning The pin will be set to "B_NOPULLUP" mode, respectively "INPUT" of "pinMode".
             */
            Button(uint8_t pin);

            /** 
             * @brief This constructor creates the object setting the pin button and the mode of the input. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @param mode Mode of the input, between "INPUT" (with "B_NOPULLUP" constant) and "INPUT_PULLUP" (with "B_PULLUP" constant).
             */
            Button(uint8_t pin, input_t mode);

            /** 
             * @brief This constructor creates the object setting the pin button and the time to define the long press. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @param timeLongPress Time in milliseconds for long press.
             * @warning The pin will be set to "B_NOPULLUP" mode, respectively "INPUT" of "pinMode".
             */
            Button(uint8_t pin, uint32_t timeLongPress);

            /** 
             * @brief This constructor creates the object setting the pin button, the mode of the input and the time to define the long press. Moreover, it calls "pinMode".
             * @param pin Digital pin of the button.
             * @param mode Mode of the input, between "INPUT" (with "B_NOPULLUP" constant) and "INPUT_PULLUP" (with "B_PULLUP" constant).
             * @param timeLongPress Time in milliseconds for long press.
             */
            Button(uint8_t pin, input_t mode, uint32_t timeLongPress);

            /**
             * @brief This method sets the time for the long press.
             * @param timeLongPress Time in milliseconds for long press.
             */
            void setTimeLongPress(uint32_t timeLongPress);

            /**
             * @brief This method gets the time for the long press.
             * @return Time in milliseconds for long press.
             */          
            uint32_t getTimeLongPress();

            /**
             * @brief This method gets the actual press, both for short and long. For short press there is the debouncing.
             * @return Value -1 if the pressure is long; 0 if there is not any pressure; 1 if the pressure is short.
             */     
            int8_t checkPress();

        private:
            uint8_t pin;                                // Pin of the button to read the status.
            uint8_t mode;                               // Mode of the input, between "INPUT" (with "B_NOPULLUP" constant) and "INPUT_PULLUP" (with "B_PULLUP" constant).
            uint32_t timeLongPress;                     // Time in milliseconds for the long press.
            uint8_t valuePress;                         // This variable will contain the value where the button will be considered pressed. In example, "HIGH" if the "pinMode" is set to "INPUT"; "LOW" if the "pinMode" is set to "INPUT_PULLUP".
            uint32_t timeOut;                           // End of time, calculated with the actual time plus "timeLongPress".
            bool isPressed;                             // Flag to indicate if the button was already pressed.
            bool isLongPressed;                         // Flag to indicate if the last press was long or not.
            int8_t actualValue;                         // Actual value of the button.

            /**
             * @brief This method sets the input mode.
             * @param mode Mode of the input.
             */
            void setMode(input_t mode);

            /**
             * @brief This method sets the value where the button will be considered pressed.
             */
            void setValuePress();  
    };
#endif
