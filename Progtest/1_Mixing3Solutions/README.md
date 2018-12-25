Tato úloha je rozšířením jednodušší varianty míchání roztoku. Doporučujeme nejprve vyřešit jednodušší úlohu míchání dvou roztoků a teprve pak přikročit k řešení této úlohy.

Rozdíl spočívá v tom, že na vstupu jsou zadané tři roztoky různých koncentrací, ze kterým má být připraveno zadané množství roztoku o požadované cílové koncentraci. Toto rozšíření dává více volnosti, kdy ke správnému výsledku může vést mísení v různých poměrech. Program má za úkol nalézt nějaké ze správných řešení.

Vstupem programu je zadání parametrů celkem 4 roztoků:

*   roztok č. 1,
*   roztok č. 2,
*   roztok č. 3 a
*   výsledný roztok.

Každý roztok je určen svým množstvím a koncentrací. Množství i koncentrace jsou desetinná čísla.

Výstupem programu je informace o množství roztoku č. 1, roztoku č. 2 a roztoku č. 3, které je potřeba smíchat, aby vzniklo požadované množství roztoku o zadané cílové koncentraci. Pokud nelze připravit požadované množství cílového roztoku, zobrazí program informaci o nemožnosti vytvoření požadovaného cílového roztoku. V obou případech program zobrazí výsledek výpočtu ve formátu podle ukázky níže. Pozor, za textem je odřádkování (\n).

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

*   nečíselné zadání množství nebo koncentrace,
*   záporné množství,
*   koncentrace mimo interval 0.0 až 1.0.

Veškeré ostatní podmínky (formátování výstupů, robustnost, omezení použitých funkcí, ...) jsou stejné jako v jednodušší variantě.

**Ukázka práce programu:**

* * *

<pre>Hmotnost a koncentrace #1:
6 0.3
Hmotnost a koncentrace #2:
2 0.1
Hmotnost a koncentrace #3:
8 0.5
Hmotnost a koncentrace vysledku:
10 0.35
6.000000 x #1 + 0.750000 x #2 + 3.250000 x #3
</pre>

* * *

<pre>Hmotnost a koncentrace #1:
5 0.3
Hmotnost a koncentrace #2:
1 0.6
Hmotnost a koncentrace #3:
10 0.1
Hmotnost a koncentrace vysledku:
7 0.5
Nelze dosahnout.
</pre>

* * *

<pre>Hmotnost a koncentrace #1:
10 0.3
Hmotnost a koncentrace #2:
10 0.2
Hmotnost a koncentrace #3:
10 0.5
Hmotnost a koncentrace vysledku:
5 0.4
2.500000 x #1 + 0.000000 x #2 + 2.500000 x #3
</pre>

* * *

<pre>Hmotnost a koncentrace #1:
10 0.4
Hmotnost a koncentrace #2:
10 0.2
Hmotnost a koncentrace #3:
12 0.4
Hmotnost a koncentrace vysledku:
18 0.4
10.000000 x #1 + 0.000000 x #2 + 8.000000 x #3
</pre>

* * *

<pre>Hmotnost a koncentrace #1:
1 0.5
Hmotnost a koncentrace #2:
1 1.4
Nespravny vstup.
</pre>

* * *

<pre>Hmotnost a koncentrace #1:
1 abcd
Nespravny vstup.
</pre>

* * *

**Poznámky:**

*   Program lze realizovat bez použití funkcí (tj. celý kód lze umístit do <tt>main</tt>). V této variantě je však mnoho podmínek, které se opakují. Je proto doporučeno program rozdělit do více funkcí (kód je přehlednější, neopakuje se, snáze se ladí).
*   Slovní popis struktury platných vstupních dat není zcela exaktní. Proto na výtky některých studentů přikládáme i popis vstupního jazyka v EBNF:

<pre>    input      ::= { whiteSpace } solution { whiteSpace } solution { whiteSpace }
solution { whiteSpace } solution { whiteSpace }
whiteSpace ::= ' ' | '\t' | '\n' | '\r'
solution   ::= decimal { whiteSpace } decimal
decimal    ::= [ '+' ] integer [ '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ] ]  |
[ '+' ] '.' integer [ ( 'e' | 'E' ) [ '+' | '-' ] integer ]
integer    ::= digit { digit }
digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
</pre>

Poznámka: EBNF nedokáže zachytit statickou sémantiku. Tedy např. v EBNF není zachyceno omezení rozsahu hodnot pro koncentrace.