# communication-Uart
## Description

Send a Receive message with arduino using UART In arduino uno and show the message writed an read in a lcd 16x2

upside show the current message writing/downside show the message received

## Install and run:
- First of all you need to include the library IRreceiver because you need for the input with the controll
- Second if you dont have the control of set arduino lego need to configure the method MakeMessage

## How to use

- for the lcd connect to arduino in this form LiquidCrystal(rs, enable, d4, d5, d6, d7)
- The buzzer conect to Pin 9
- Write the message using a remote control from kit eleego(or modify the method makemessage to put your remote control)
- if you receive a message this will show automatically in the lcd

![20220913_162104](https://user-images.githubusercontent.com/49890569/190310673-00ebd67f-c8c8-4c5d-b94f-66ceb0db73ef.jpg)

![20220913_162703](https://user-images.githubusercontent.com/49890569/190311160-d185d6f0-9c02-4e5e-9f0b-16bf4e27a092.jpg)


![20220913_162540](https://user-images.githubusercontent.com/49890569/190310699-efd850ee-c462-49f1-bca1-5e07f6b594de.jpg)

Copyright (c) [2022] [Moises Alejandro Patino Hernandez]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
