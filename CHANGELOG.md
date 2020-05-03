In this document there is the story about the various versions. See the [Wiki](https://github.com/davidepalladino/Button-Arduino/wiki)' page for detail about the use.

### 1.1.1 - 2020-05-03
**Added**
* Now you can specify if you want use the external or internal resistor.

**Changed**
* `unsigned short` type changes in `uint8_t` type.
* `unsigned long` type changes in `uint32_t` type.
* setPin` and `getPin` methods are private.

**Removed**
* Removed the default value for the long press when is used the constructor where is set the only pin.
