/**
* @mainpage
* @section intro Einleitung
* Es soll abstrakter Datentyp Counter implementiert werden, welcher einen
* Zählers realisiert.
*
* @section example Beispiel
* Die Codesequenz um einen Zähler zu bekommen und diesen dann in Fünferschritten
* von 255 auf 0 zählen zu lassen wäre folgendermaßen:

* @code
* Counter c = new_counter(DOWN);
* set_value(c, 255);
* set_increment_value(5);
* while (get_value(c) >= 0) {
*   printf("%d\n", get_value(c));
*   increment(c);
* }
* @endcode
*
* @section assignment Aufgabe
* -# Erstellen Sie alle notwendigen Komponenten, damit der abstrakte Datentyp
* (und damit das Gesamtprojekt) baut. Es sollen bis zu acht verschiedene Counter
* erzeugt werden können.
* (POS_PRPR_09, POS_PRPR_10, POS_PRPR_11, POS_PRPR_13).
* -# Implementieren Sie die Funktionen von <code>counter</code> so, dass alle
* Unit Tests erfolgreich durchlaufen (die Descriptors sind bei den einzelnen
* Unit Tests angegeben).
* -# Refactoren Sie die Funktion <code>init()</code> so, dass Sie die einzelnen
* Initialisierungsschritte in der Schleife (Eintrag auf frei setzen,
* <code>increment_value</code> und <code>value</code> auf 0 setzen etc.) in eine
* eigene Funktion <code>init_one_counter_pool_entry</code> ausgelagert werden.
* Beachten Sie, dass die Funktion nur innerhalb des Files <code>counter.cpp</code>
* bekannt sein darf.
* (POS_PRPR_12, POS_PRPR_04, POS_PRPR_06).
* -# Erklären Sie in einem Kommentar über dem enum <code>Direction</code>, warum
* an dieser Stelle die Verwendung eines enum der einer symbolischen Konstante
* vorzuziehen ist (POS_PRPR10).
*/
