Úkolem je vytvořit program, který bude zobrazovat nápovědu při zadání vyhledávaného výrazu.

Chceme realizovat program, který bude implementovat část funkcionality našeptávání - autocomplete. Program si pamatuje seznam často zadávaných frází. Pro každou frázi si pamatujeme její četnost. Chceme realizovat program, který načte seznam často zadávaných frází a následně bude schopen v tomto seznamu vyhledávat pravděpodobné fráze na základě zadání jejich částí.

Vstupem programu je seznam často zadávaných frází. Tyto fráze jsou zadané v podobě:

<pre>číslo:text fráze
</pre>

kde číslo je četnost dotazu (desetinné číslo) a text fráze je řetězec. Často hledaných frází je dopředu neznámý počet, jejich zadávání končí zadáním prázdného řádku. Po zadání často vyhledávaných frází následuje vlastní vyhodnocování našeptávání. Na řádce vstupu je zadaný text dotazu, tento text tvoří frázi nebo její část. Texty dotazu jsou zadávané na jednotlivých řádkách, jejich zpracování skončí po dosažení konce vstupu (EOF).

Výstupem programu je počet frází, které vyhoví zadanému textu dotazu. Text dotazu se může ve frázi vyskytovat kdekoliv (nemusí být na začátku), při porovnávání nerozlišujeme malá a velká písmena. Za výpisem počtu vyhovujících frází následuje jejich výpis v pořadí klesající četnosti. Zobrazeno bude nejvýše 50 frází s nejvyšší četností. Tento výstup bude zobrazen pro každý text dotazu na vstupu.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

*   u zadávané fráze není uvedena četnost nebo četnost není desetinné číslo,
*   chybí dvojtečka oddělující četnost a frázi,
*   byl zadán nulový počet frází.

Váš program bude spouštěn v omezeném testovacím prostředí. Je omezen dobou běhu (limit je vidět v logu referenčního řešení). V povinných testech jsou zadávané rozumné dotazy (frází je málo). Pro zvládnutí povinných testů postačuje rozumná implementace naivního algoritmu. Úloha nabízí bonusový test, kde je objem zpracovávaných dat velký (fráze jsou dlouhé, je jich mnoho). Pro zvládnutí bonusového testu je potřeba použít lepší algoritmu, který dokáže rychle eliminovat neperspektivní fráze.

**Ukázka práce programu:**

* * *

<pre>Casto hledane fraze:
80:Progtest random test failed
70:Segmentation fault
40:Progtest homework #2
80:Invalid input data
50.5:Program has stopped working
15:Validator result
20:Lid is open
60:Test in progress

Hledani:
test
Nalezeno: 3
> Progtest random test failed
> Test in progress
> Progtest homework #2
test fail
Nalezeno: 1
> Progtest random test failed
lid
Nalezeno: 3
> Invalid input data
> Lid is open
> Validator result
prog
Nalezeno: 4
> Progtest random test failed
> Test in progress
> Program has stopped working
> Progtest homework #2
data
Nalezeno: 1
> Invalid input data
ISO
Nalezeno: 0
exception
Nalezeno: 0
</pre>

* * *

<pre>Casto hledane fraze:
80 foo
Nespravny vstup.
</pre>

* * *

<pre>Casto hledane fraze:
Progtest. Progtest never changes.
Nespravny vstup.
</pre>

* * *

**Poznámky:**

*   Znak odřádkování (\n) je i za poslední řádkou výstupu (i za případným chybovým hlášením).
*   Maximální délka vstupu není určena. V této úloze je potřeba paměť alokovat dynamicky.
*   Maximální délka řádky není omezena. Řetězce nelze rozumně realizovat pomocí polí fixní délky.
*   Pro načítání řádek textu se hodí funkce <tt>getline</tt> případně <tt>fgets</tt>. Nepoužívejte funkci <tt>gets</tt>.
*   Při implementaci používejte prostředky jazyka C. C++ knihovna STL je pro tuto úlohu úmyslně vyřazena.
*   Pro řazení se hodí knihovní funkce <tt>qsort</tt>.
*   Při optimalizaci v bonusové části můžete předpokládat, že dotazů je mnoho, tedy vyplatí se předzpracování načtených frází.
*   Slovní popis struktury platných vstupních dat není zcela exaktní. Proto na výtky některých studentů přikládáme i popis vstupního jazyka v EBNF:

<pre>    input      ::= phrase { phrase } '\n' { search }
phrase     ::= decimal ':' text '\n'
search     ::= text '\n'
text       ::= ' ' | '!' | '"' | '#' | '/pre> | ... | '{' | '|' | '}' | '~'
decimal    ::= [ '+' | '-' ] number [ '.' number ] [ ( 'e' | 'E' ) [ '+' | '-' ] number ] |
[ '+' | '-' ] '.' number [ ( 'e' | 'E' ) [ '+' | '-' ] number ]
number     ::= digit { digit }
digit      ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
</pre>

Pozn.: text je tvořen libovolnými ASCII znaky kromě znaků řídících.