# To do for MIC Project

* Refectoring
  * ~~Ampel auslagern~~
  * ~~Comm Schnittstelle raus aus der main --> Transver in UART (Felix)~~
  * ~~Code kommentieren~~
  * ~~imports sortieren~~
  * Errorhandling mit Errorstate und globalem Errorstring? (Julian)
  * ~~change x and k in comm to more meaningfull letters --> Switch Case letter change (R = Red; G = Green; Y= Yellow)~~
  * ~~Im Switch Case einen Fall einbauen , wenn die Eingabe nicht Y || R ist~~
    * ~~Negative Eingaben für Humidity sollten nicht möglich sein~~
  * ~~Kommentare und Ausgaben einheitliche Sprache~~
    * ~~Ich würde einfach alles in Englisch machen~~
* OLED update (better desinge)
  * ~~Als durchlaufender Text "Achtung" schreiben~~
    * ~~Bei Hum zu hoch oder niedrig --> Diesen in ampel.c verschieben?~~
* Walking Text
  * Maybe Error text or informations
  * walking text mit timer neu drawen (Julian)
* gated Timer verwenden für dht (Julian)
* Presentation (Felix)
  * Grund Rahmen
  * Pictures
  * Explanations
  * Benötige Bilder des Aufbaues
  * Was wir noch benötigen:
1. Bild von unseren Board 
2. Kennzeichnung, wie wir alles verkabeln --> Auf die Folie des dsPIC33
3. Was macht RB8 und was RB9 --> hinsichtlich I2C (Kontrolle der Beschriftung OLED-Folie)
4. Bilder vom OLED, Ampel, Testen der Funktionen
				Hitze = Erwärmen
				Kälte = Kühlakku
				Luftfeutigkeit = Anzeigen nach Anhauchen
5. Ablaufdiagramm? --> Sollten wir ein ABlaifdigramm schreiben?
