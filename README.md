# ArduinoScopio
Telescope mount with Arduino

Questo è il mio progetto per guidare la montatura EQ2 del mio telescopio in maniera più precisa, evitando le vibrazioni che si creano toccando il telescopio e agevolando l'utilizzo per astrofotografia amatoriale. 

## Telescopio
Il telescopio in questione è uno SkyWatcher 130/900 f6.9, con montatura equatoriale EQ2 non motorizzata. È un telescopio entry level, principalmente usato per l'osservazione planetaria, ma con il giusto compromesso si può usare anche per astrofotografia. 
Questo è un telescopio riflettore. Esistono principalmente 3 tipi di telescopio:
1. rifrattore
2. riflettore
3. catadiottrico

Il [telescopio rifrattore](https://en.wikipedia.org/wiki/Refracting_telescope) è il telescopio con le lenti, che piega la luce dirigendola nell'oculare. Ha una rotella per mettere a fuoco l'immagine, che fondamentalmente allontana o avvicina l'oculare alla lente, cambiando il punto di incontro con la luce. Questi telescopi sono caratterizzati da un basso zoom, ideali per astrofotografia di oggetti dello spazio profondo. Generalmente sono molto costosi

Il [telescopio riflettore](https://en.wikipedia.org/wiki/Reflecting_telescope) è un telescopio molto semplice. È un tubo di lunghezza variabile con uno specchio parabolico sul fondo, che concentra la luce su uno specchio secondario posto all'apertura del tubo. Questo specchio secondario riflette la luce nell'oculare, anche qui dotato di una rotella per la messa a fuoco con lo stesso funzionamento di quella del telescopio riflettore, allontana e avvicina l'oculare dallo specchio secondario. Questi telescopi sono molto più economici e con uno zoom molto elevato, ideali per l'osservazione di oggetti del sistema solare, un po' meno di quelli di spazio profondo.

Il [telescopio catadiottrico](https://en.wikipedia.org/wiki/Catadioptric_system) è un insieme dei due telescopi precedenti, con una lente all'inizio ed uno specchio sul fondo, uno specchio secondario al centro della lente che concentra la luce sull'oculare. Questi telescopi hanno una qualità molto elevata, a discapito di un prezzo anch'esso molto elevato.

La [montatura equatoriale](https://en.wikipedia.org/wiki/Equatorial_mount) è una montatura particolare. A differenza delle montature altazimutali (quelle delle macchine fotografiche, per intenderci) non si muove sull'asse x, y, z, ma sull'asse di ascensione retta e declinazione. L'asse di rotazione della terra, infatti, punta grossomodo alla stella polare, cambiando posizione di pochi gradi. Puntando, quindi, la montatura alla stella polare possiamo ruotare solo un'asse del telescopio, l'asse di ascensione retta, per tenere la stella sempre al centro dell'oculare. La velocità di tracciamento delle stelle, però, è estremamente bassa. Una stella nel cielo, si muove di 361° ogni 24 ore, quindi circa 15arcsecondi al secondo (dove un arcsecondo è 1/3600 di grado), per questo seve un motore che sia abbastanza potente da far muovere tutto il telescopio e lento per tracciare le stelle.

## Materiali
1. [RA-Motor](https://www.astroshop.it/kit-motori-e-sistemi-goto/skywatcher-motore-ra-per-eq-1/p,1531?utm_medium=cpc&utm_term=1531&utm_campaign=2307&utm_source=froogle-it&gclid=CjwKCAjw2K6lBhBXEiwA5RjtCU1okDMWhpc3hHXgdOJ9-9ABBHrxcbmZdpyxXS5IeCFoqms-IWOFAhoCS7wQAvD_BwE&utm_content=)
2. [Arduino Mega](https://store.arduino.cc/products/arduino-mega-2560-rev3)
3. [H Bridge L293D](https://www.progettiarduino.com/15-arduino-motore-ponte-h-l293d-sn754410.html)
4. 9V Battery
5. [LCD Screen](https://www.amazon.it/Arduino-Lcd-Display/s?k=Arduino+Lcd+Display)
6. [Potentiometer](https://www.amazon.it/dp/B00H3CW32G?tag=progettiardui-21&camp=3458&creative=23838&linkCode=as1&creativeASIN=B00H3CW32G&adid=1WD82EBCTTB2SMBVEHYY&)
7. [Jumpers (M-M, M-F)](https://www.amazon.it/maschio-maschio-cavetti-raspberry-arduino-Arduino/dp/B01BKN8UX4/ref=sr_1_3_sspa?__mk_it_IT=ÅMÅŽÕÑ&crid=3O0HMKS5B91H&keywords=arduino%2Bjumper&qid=1689014978&s=industrial&sprefix=arduino%2Bjumper%2Cindustrial%2C98&sr=1-3-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&th=1)
8. [Numpad 4x4](https://www.amazon.it/ANGEEK-Membrane-Switch-Keyboard-arduino/dp/B07X5VL58V/ref=sr_1_1_sspa?__mk_it_IT=ÅMÅŽÕÑ&crid=1MFVXQJOIKMSZ&keywords=keypad+4x4+arduino&qid=1689015098&sprefix=keypad+4x4+arduino%2Caps%2C93&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

## Circuit


## Funzionamento
Il funzionamento del progetto è molto semplice, premendo i tasti sul tastuerino numerico il motore si muove in modo diverso:
- (1) Imposta velocità al minimo
- (3) Imposta velocità a metà
- (9) Imposta velocità al massimo 
- (A) Aumenta la velocità di 0.5 
- (B) Diminuisce la velocità di 0.5 
- (C) Aumenta la velocità di 1 
- (D) Diminuisce la velocità di 1 
- (*) Aumenta la velocità di 10 
- (#) Diminuisce la velocità di 10

Il codice principale si trova nella directory src/main/main.ino. Le librerie necessarie sono quelle del display lcd (LiquidCrystal.h) e del keypad (Keypad.h).
