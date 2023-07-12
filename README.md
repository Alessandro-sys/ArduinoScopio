# ArduinoScopio
Telescope mount with Arduino

This is my project to guide the EQ2 mount of my telescope more precisely, avoiding the vibrations created by touching the telescope and facilitating the use for amateur astrophotography. 

## Telescope
The telescope i'm using is a SkyWatcher 130/900 f6.9, with a non-motorized EQ2 equatorial mount. It is an entry level telescope, mainly used for planetary observation, but with the right compromise it can also be used for astrophotography.
This is a reflecting telescope. There are mainly 3 types of telescopes:
1. Refracting Telescope
2. Reflecting Telescope
3. Catadioptric Telescope

The [refracting telescope](https://en.wikipedia.org/wiki/Refracting_telescope) is a telescope with lenses that bends light, directing it into the eyepiece. It has a wheel to focus the image, which basically moves the eyepiece towards or away from the lens, changing where it meets the light. These telescopes are characterized by a low zoom, ideal for astrophotography of deep space objects. They are usually very expensive

The [reflector telescope](https://en.wikipedia.org/wiki/Reflecting_telescope) is a very simple telescope. It is a tube of variable length with a parabolic mirror at the bottom, which concentrates the light on a secondary mirror placed at the opening of the tube. This secondary mirror reflects the light into the eyepiece, equipped with a focusing wheel with the same function as that of the refracting telescope, it moves the eyepiece away and towards the secondary mirror. These telescopes are much cheaper and with a very high zoom, ideal for observing objects in the solar system, a little less than those in deep space.

The [catadioptric telescope](https://en.wikipedia.org/wiki/Catadioptric_system) is a combination of the two previous telescopes, with a lens at the front and a mirror at the bottom, a secondary mirror in the center of the lens which concentrates the light on the eyepiece. These telescopes have a very high quality, at the expense of a very high price.

The [equatorial mount](https://en.wikipedia.org/wiki/Equatorial_mount) is a particular mount. Unlike the altazimuth mounts (those of cameras, to be clear) it does not move on the x, y, z axis, but on the axis of right ascension and declination. The axis of rotation of the earth, in fact, points roughly to the pole star, changing position by a few degrees. Therefore, by aiming the mount at the North Star, we can rotate only one axis of the telescope, the right ascension axis, to keep the star always in the center of the eyepiece. However, the tracking speed of the stars is extremely slow. A star in the sky moves 361° every 24 hours, so about 15arcseconds per second (where an arcsecond is 1/3600th of a degree), so you need a motor that is powerful enough to move the entire telescope and slow to track the stars.

## Materials
1. [RA-Motor](https://www.astroshop.it/kit-motori-e-sistemi-goto/skywatcher-motore-ra-per-eq-1/p,1531?utm_medium=cpc&utm_term=1531&utm_campaign=2307&utm_source=froogle-it&gclid=CjwKCAjw2K6lBhBXEiwA5RjtCU1okDMWhpc3hHXgdOJ9-9ABBHrxcbmZdpyxXS5IeCFoqms-IWOFAhoCS7wQAvD_BwE&utm_content=)
2. [Arduino Mega](https://store.arduino.cc/products/arduino-mega-2560-rev3)
3. [H Bridge L293D](https://www.progettiarduino.com/15-arduino-motore-ponte-h-l293d-sn754410.html)
4. 9V Battery
5. [LCD Screen](https://www.amazon.it/Arduino-Lcd-Display/s?k=Arduino+Lcd+Display)
6. [Potentiometer](https://www.amazon.it/dp/B00H3CW32G?tag=progettiardui-21&camp=3458&creative=23838&linkCode=as1&creativeASIN=B00H3CW32G&adid=1WD82EBCTTB2SMBVEHYY&)
7. [Jumpers (M-M, M-F)](https://www.amazon.it/maschio-maschio-cavetti-raspberry-arduino-Arduino/dp/B01BKN8UX4/ref=sr_1_3_sspa?__mk_it_IT=ÅMÅŽÕÑ&crid=3O0HMKS5B91H&keywords=arduino%2Bjumper&qid=1689014978&s=industrial&sprefix=arduino%2Bjumper%2Cindustrial%2C98&sr=1-3-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1)
8. [Numpad 4x4](https://www.amazon.it/ANGEEK-Membrane-Switch-Keyboard-arduino/dp/B07X5VL58V/ref=sr_1_1_sspa?__mk_it_IT=ÅMÅŽÕÑ&crid=1MFVXQJOIKMSZ&keywords=keypad+4x4+arduino&qid=1689015098&sprefix=keypad+4x4+arduino%2Caps%2C93&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

## Circuit
![lcd](https://github.com/Alessandro-sys/ArduinoScopio/assets/71657415/c5ddfb40-449c-487e-b541-2b8605a9b0c0)
![Motore](https://github.com/Alessandro-sys/ArduinoScopio/assets/71657415/6346d255-c4ec-4b30-96f6-dd50993c1e9e)
There's no numpad on Tinkercad, so no scheme. But the numpad pins are connected left to right to the pins from 22 to 29.

## Functioning
The operation of the project is very simple, by pressing the keys on the numeric keypad the motor moves in a different way. Thanks to the H-Bridge it might also move backwards, it might be a future implementation.
- (1) Minimum speed
- (3) Half speed
- (9) Maximum speed
- (A) Increases speed by 0.5 
- (B) Decreases speed by 0.5 
- (C) Increases speed by 1 
- (D) Decreases speed by 1 
- (*) Increases speed by 10 
- (#) Decreases speed by 10

The main code is located in the src/main/main.ino directory. The necessary libraries are those of the lcd display (LiquidCrystal.h) and of the keypad (Keypad.h).
