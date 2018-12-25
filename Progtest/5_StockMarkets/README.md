Úkolem je vytvořit program, který bude zaúčtovávat obchody na burze.

Předpokládáme, že na burze obchodujeme různé akcie. Akcie je vždy určena číslem v rozsahu 0 až nějaké maximum, toto maximum <tt>maxID</tt> je zadáno programu po spuštění. Po zadání tohoto maxima jsou programem zpracovávány požadavky na nákup a prodej.

Požadavek na prodej má tvar <tt>+ id cena</tt>, kde <tt>id</tt> identifikuje akcie a cena udává požadovanou cenu za akcii. Pokud jednou dostaneme požadavek na prodej, je tento požadavek i cena zaznamenána a akcie od tohoto okamžiku může být prodána. Požadavky na prodej přicházejí průběžně, akcii v systému může existovat v daném okamžiku mnoho, požadavky na prodej akcií stejných <tt>id</tt> mohou požadovat různé ceny.

Požadavek na nákup má tvar <tt>- id cena</tt>, kde <tt>id</tt> identifikuje druh akcie a <tt>cena</tt> udává maximální cenu, za kterou jsme ochotni akcii daného <tt>id</tt> koupit. Pokud je k dispozici, program akcii "prodá", tedy zobrazí informaci o prodeji, ceně akcie a akcii již dále nenabízí. Pokud je k dispozici více akcií zadaného druhu s různými cenami, je přednostně prodávaná akcie nejlevnější. Pokud při požadavku na nákup nejsou k dispozici žádné akcie žádaného <tt>id</tt> nebo jsou k dispozici pouze za cenu vyšší než je zadané maximum, program zobrazí informaci, že transakci nelze uskutečnit.

Vstupem programu je nejprve celé číslo <tt>maxID</tt>, za ním následují požadavky na prodej a nákup akcií. Číslo <tt>maxID</tt> udává počet různých akcií, které lze obchodovat, <tt>id</tt> akcie musí být v rozsahu 0 až <tt>maxID</tt> včetně.

Požadavky na prodej a nákup jsou popsané výše. Zadávání požadavků na prodej a nákup končí dosažením EOF.

Program zobrazuje informaci o uskutečněných nákupech. Po zadání každého požadavku na nákup je buď zobrazena informace o úspěchu a o prodejní ceně, nebo informace o neúspěchu (akcie není nabízena nebo je nabízena za cenu vyšší než mez).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

*   hodnota <tt>maxID</tt> není celé číslo, je záporná nebo nulová,
*   požadavek na nákup/prodej nezačíná znakem - resp. +,
*   <tt>id</tt> nebo cena v požadavku na nákup/prodej není celé číslo,
*   <tt>id</tt> akcie v požadavku na nákup/prodej je mimo meze 0 až <tt>maxID</tt>,
*   cena v požadavku na nákup/prodej je nulová nebo záporná.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení) a dále je omezena i velikost dostupné paměti. Před vlastním programováním si rozmyslete, jakým způsobem budete ukládat informace o prodávaných akciích. Dále uvažte, že není explicitně omezen ani počet nabízených akcií, ani rozsah <tt>maxID</tt>. Správné řešení musí paměť alokovat dynamicky podle aktuálních požadavků.

Časová náročnost výpočtu velmi záleží na použitém způsobu ukládání nabízených akcií. Rozumná implementace naivního algoritmu postačuje pro limity v závazných testech. Pro zvládnutí bonusového testu je potřeba výkonnější algoritmus, který dokáže rychle zpracovat velký objem nabízených a prodávaných akcií.

**Ukázka práce programu:**

* * *

<pre>Nejvyssi ID:
10
Nabidka a poptavka:
- 3 100
Neni k dispozici.
+ 3 100
+ 3 200
+ 3 50
+ 3 70
+ 5 1
+ 5 1000000000
- 7 1
Neni k dispozici.
- 3 10
Neni k dispozici.
- 3 60
Prodano za 50
- 3 100
Prodano za 70
- 3 100
Prodano za 100
- 3 199
Neni k dispozici.
- 3 1000
Prodano za 200
+ 5 1
+ 5 1
+ 5 1
- 5 10
Prodano za 1
- 5 7
Prodano za 1
</pre>

* * *

<pre>Nejvyssi ID:
10
Nabidka a poptavka:
+ 3 100
+ 11 20
Nespravny vstup.
</pre>

* * *

<pre>Nejvyssi ID:
10
Nabidka a poptavka:
* 30 120
Nespravny vstup.
</pre>

* * *

<pre>Nejvyssi ID:
hello
Nespravny vstup.
</pre>

* * *

**Poznámky:**

*   Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
*   Při testování nezadávejte data ručně, využijte přesměrování vstupu.
*   Maximální délka vstupu není určena. V této úloze je potřeba paměť alokovat dynamicky.
*   Při návrhu implementace je vhodné reprezentovat akcie jednotlivých <tt>id</tt> odděleně. Protože <tt>id</tt> akcie je celé číslo, lze toto číslo použít přímo jako index ve vhodně velkém poli.
*   Zvažte použití struktur pro seskupení informací o akciích daného <tt>id</tt>.
*   Seznamy akcií jednotlivých <tt>id</tt> mohou být různě dlouhé. Je rozumné tyto seznamy vytvářet postupně, tj. nejprve je alokovat malé a rozšiřovat je podle potřeby.
*   Pro rozšiřování se může hodit funkce <tt>realloc</tt>.
*   Při implementaci používejte prostředky jazyka C. C++ knihovna STL je pro tuto úlohu úmyslně vyřazena.
*   Slovní popis struktury platných vstupních dat není zcela exaktní. Proto na výtky některých studentů přikládáme i popis vstupního jazyka v EBNF:

<pre>    input      ::= { whiteSpace } number { whiteSpace } { sell | buy } { whiteSpace }
whiteSpace ::= ' ' | '\t' | '\n' | '\r'
sell       ::= '+' whiteSpace { whiteSpace } number whiteSpace { whiteSpace }
number whiteSpace { whiteSpace }
buy        ::= '-' whiteSpace { whiteSpace } number whiteSpace { whiteSpace }
number whiteSpace { whiteSpace }
number     ::= [ '+' ] digit { digit }
digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
</pre>

Poznámka: EBNF nepopisuje statickou sémantiku. Tedy např. povolené meze zadávaných hodnot jsou vysvětlené pouze v textové podobě.