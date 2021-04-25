# Button library for Arduino
## Description
This library allows to manage a button. You can specify if the pressure is long or not. Morevoer, is possible to assign a time (in milliseconds) to consider the long press, and a specific procedure both for short and long press. For short press there is the debouncing.

## Manual installation
To install manually this library, you can see this little guides.

### Arduino IDE
1. Download and extract it
2. Open Arudino IDE
3. Select tab `Sketch` -> `Include Library` -> `Add .ZIP Library`
4. Select the zip file inluded in `extras`
You can select the library on `Include Library` -> `Button`. It will be automatically added on you project, like this:
```c++
#include <Button.h>
```

### Other IDE
1. Download and extract it
2. Copy the `src` content in your project folder
3. Open the project with your IDE
4. Use the preprocessor directives to add the library, like this:
```c++
#include "Button.h"
```
## How to use
See the [Wiki](https://github.com/davidepalladino/Button-Arduino/wiki) page for details about the use.

## Changelog
See the [Releases](https://github.com/davidepalladino/Button-Arduino/releases) page for details about the versions.

## Contribute
Your contribute is important for me. Don't hesitate with issues and pull requests for improving this class.

### Special thanks
Special thanks to my cousin [Marco Palladino](https://github.com/PalladinoMarco) for the help to optimize the code.
