In this document there is the story about the various versions. See the [Wiki](https://github.com/davidepalladino/Button-Arduino/wiki) page for detail about the use.

### 1.2.0 - 2020-07-20
**Added**
* Now you can use this library with boards of ESP family. For this board, the symbolic constant for `PULLUP` is `INTERNAL_RESISTOR`, and `NO_PULLUP` is `EXTERNAL_RESISTOR`. This is because the symbolic constant `PULLUP` is already used by the official library of ESP.

### 1.1.1 - 2020-05-03
**Added**
* Now you can specify if you want use the external or internal resistor.

**Changed**
* `unsigned short` type changes in `uint8_t` type.
* `unsigned long` type changes in `uint32_t` type.
* setPin` and `getPin` methods are private.

**Removed**
* Removed the default value for the long press when is used the constructor where is set the only pin.
