## Adaptation of [3 channel code](https://github.com/mharizanov/ESP8266_Relay_Board) to work with [new 1 channel relay module](https://guide.openenergymonitor.org/integrations/mqtt-relay/) (Relay 2 and Relay 3 code stripped out)

Adapted by @trystanlea
OpenEnergyMonitor.org

***

#One Channel WiFi Relay/Thermostat Board

The One Channel WiFi Relay/Thermostat Board is a WiFi connected multi-purpose relay board based on the [ESP8266 SoC].

**NOTE**: The board connects to and controls high voltage, knowledge and care is required to handle it


###Highlights

- Option for on-board power supply
- Powered by the WiFi [ESP8266 SoC] module
- HTTP API to control the relays
- [MQTT] support
- [NTP] for network time
- HTTP daemon settings, including security/authentication setup
- HTTP UI for configuration and control
 - Thermostat function with weekly scheduling
 - Manual relay control
- Broadcast using HTTP GET to services like [ThingSpeak] and [emonCMS]
- Integration with [ThingSpeak] for charting/analytics visualization
- Temperature sensor support
 - DS18B20
 - DHT22

See more at the [Three Channel WiFi Relay/Thermostat Board WiKi]

## Using serial input for an external temperature sensor

Details thanks to Felix Paliuc:

- First setup the "serial" as the input for the sensor.

The temperature value must be sent in a particular way: 

- First you have to send an "\n" which gets interpreted as a command.

- After that, you have to send the temperature value like this: serialremotetemp=

- The value of the temperature must be between -3000 and 12000 which gets divided by 100 later.

- Practically, I hooked a moteino to the Rx of the ESP8266 and configured the sketch to send temperature with a line like this:

    Serial.print("\nserialremotetemp=1500");

#Author
[Martin Harizanov]

#License
This project is licensed under [Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License]. 

[![License](http://i.creativecommons.org/l/by-nc-sa/3.0/88x31.png)](http://creativecommons.org/licenses/by-nc-sa/3.0/)

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

[Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License]: http://creativecommons.org/licenses/by-nc-sa/3.0/
[Three Channel WiFi Relay/Thermostat Board WiKi]: http://harizanov.com/wiki/wiki-home/three-channel-wifi-relaythermostat-board/
[emonCMS]: http://emoncms.org 
[ThingSpeak]: http://thingspeak.com
[10A relays]: http://www.te.com/catalog/pn/en/3-1393239-6
[ESP8266 SoC]: https://espressif.com/en/products/esp8266/
[MQTT]: http://en.wikipedia.org/wiki/MQTT
[NTP]: http://en.wikipedia.org/wiki/Network_Time_Protocol
[Martin Harizanov]:http://harizanov.com/
[@mharizanov]:http://twitter.com/mharizanov
